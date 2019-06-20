#include "MCCDAQ.h"

MCCDAQ::MCCDAQ(int Gain, int lowChan, int highChan, long Count, long Rate) {
	this->m_Gain = Gain;
	this->m_lowChan = lowChan;
	this->m_highChan = highChan;
	this->m_Count = Count;
	this->m_Rate = Rate;

	this->m_MemHandle = cbWinBufAlloc(Count);
	this->m_ADData = (WORD*)m_MemHandle;

	this->m_channelUnits.assign(8, "");
	this->m_linearCalibration.assign(8, std:: vector<float>(2));

	for (size_t i = 0; i < this->m_linearCalibration.size(); i++) {
		this->m_linearCalibration[i][0] = 50;
		this->m_linearCalibration[i][1] = 500;
	}
}

void MCCDAQ::set_daq_ports() {
	bool validRange = false;
	std::cout << std::endl << "Setting the lower and higher number of DAQ channels used (max. range of 7 channels)" << std::endl;
	do {
		try {
			std::cout << "Enter the lower channel: ";
			std::string lowChanStr;
			std::cin >> lowChanStr;
			this->m_lowChan = stoi(lowChanStr);

			std::cout << "Enter the higher channel: ";
			std::string highChanStr;
			std::cin >> highChanStr;
			this->m_highChan = stoi(highChanStr);

			if (this->m_highChan > 7 || this->m_lowChan < 0 || this->m_highChan - this->m_lowChan < 0 || this->m_highChan - this->m_lowChan > 7) {
				std::cout << "Range of channels must be between 1 and 7, and higher channel must be greater than (or equal to for a single channel) lower channel." << std::endl;
			}
			else {
				validRange = true;
			}
		}
		catch (std::invalid_argument e) {
			std::cout << "Invalid channel input." << std::endl;
		}
	} while (!validRange);

	// MCC sampling
	this->m_Count = 6 * (this->m_highChan - this->m_lowChan + 1); // Total number of samples to be collected (6 samples * # of channels)
	this->m_Rate = 100000 / (this->m_highChan - this->m_lowChan + 1); // Rate that samples are collected per channel
	this->m_MemHandle = cbWinBufAlloc(this->m_Count);
	this->m_ADData = (WORD*)this->m_MemHandle;
}
void MCCDAQ::set_daq_units() {
	std::string response;
	bool unitSet = false;

	std::cout << "\nTo set all the channels to the same unit, enter one of the units below. To set each channel individually, enter y." << std::endl;
	std::cout << "P for Pressure (Psi)" << std::endl;
	std::cout << "C for Temperature (Celsius)" << std::endl;
	std::cout << "N for Force (Newtons)" << std::endl;
	std::cout << "L/s for Flow Rate (Litres/second)" << std::endl;
	std::cout << "Chosen unit: ";

	do {
		std::cin >> response;

		if (response == "P") {
			fill(this->m_channelUnits.begin(), this->m_channelUnits.end(), "P");
			std::cout << "Channels " << this->m_lowChan << " to " << this->m_highChan << " set to Pressure." << std::endl;
			return;
		}
		else if (response == "C") {
			fill(this->m_channelUnits.begin(), this->m_channelUnits.end(), "C");
			std::cout << "Channels " << this->m_lowChan << " to " << this->m_highChan << " set to Temperature." << std::endl;
			return;
		}
		else if (response == "N") {
			fill(this->m_channelUnits.begin(), this->m_channelUnits.end(), "N");
			std::cout << "Channels " << this->m_lowChan << " to " << this->m_highChan << " set to Force." << std::endl;
			return;
		}
		else if (response == "L/s") {
			fill(this->m_channelUnits.begin(), this->m_channelUnits.end(), "L/s");
			std::cout << "Channels " << this->m_lowChan << " to " << this->m_highChan << " set to Flow Rate." << std::endl;
			return;
		}
		else if (response == "y") {
			std::cout << std::endl << "Setting each channel individually..." << std::endl;
			std::cout << "For each channel, enter:" << std::endl;
			std::cout << "P for Pressure (Psi)" << std::endl;
			std::cout << "C for Temperature (Celsius)" << std::endl;
			std::cout << "N for Force (Newtons)" << std::endl;
			std::cout << "L/s for Flow Rate (Litres/second)" << std::endl;

			int channel = this->m_lowChan;
			do {
				std::cout << "Channel " << channel << ": ";
				std::cin >> response;
				if (response == "P" || response == "C" || response == "N" || response == "L/s") {
					this->m_channelUnits.at(channel) = response;
					channel++;
				}
				else {
					std::cout << "Enter P, C, N, or L/s." << std::endl;
				}
			} while (channel <= this->m_highChan);
			return;
		}
		else {
			std::cout << "Enter P, C, N, L/s, or y: ";
		}
	} while (response != "P" && response != "C" && response != "N" && response != "L/s" && response != "y");
}
void MCCDAQ::calibrate_daq() {
	std::string response;
	float calibratedVoltage;
	float calibratedUnit;
	bool validChannel = false;
	bool validUnit = false;
	bool calibrated = false;

	int channelNum = this->m_lowChan;
	std::cout << "An inputted unit will be calibrated with an inputted voltage (ex. 14.696 P at -10 V)." << std::endl;

	do {
		do {
			try {
				std::cout << "Calibrating channel " << channelNum << "..." << std::endl;
				if (this->m_channelUnits.at(channelNum) == "P") {
					std::cout << "Enter a value for pressure: ";
				}
				if (this->m_channelUnits.at(channelNum) == "C") {
					std::cout << "Enter a value for temperature: ";
				}
				if (this->m_channelUnits.at(channelNum) == "N") {
					std::cout << "Enter a value for force: ";
				}
				if (this->m_channelUnits.at(channelNum) == "L/s") {
					std::cout << "Enter a value for flow rate: ";
				}
				std::cin >> response;
				calibratedUnit = stof(response);
				validUnit = true;
			}
			catch (std::invalid_argument e) {
				std::cout << "Invalid input." << std::endl;
			}
		} while (!validUnit);

		std::string unitType;

		do {
			try {
				std::cout << "Enter the corresponding voltage value: ";
				std::cin >> response;
				calibratedVoltage = stof(response);

				if (this->m_channelUnits.at(channelNum) == "P") {
					unitType = "P";
				}
				else if (this->m_channelUnits.at(channelNum) == "C") {
					unitType = "C";
				}

				else if (this->m_channelUnits.at(channelNum) == "N") {
					unitType = "N";
				}

				else if (this->m_channelUnits.at(channelNum) == "L/s") {
					unitType = "L/s";
				}

				this->m_linearCalibration.at(channelNum).at(0) = (1000 - calibratedUnit) / (10 - calibratedVoltage);
				this->m_linearCalibration.at(channelNum).at(1) = 1000 - (this->m_linearCalibration.at(channelNum).at(0) * 10);

				std::cout << "Channel " << channelNum << " calibrated with " << calibratedUnit << " " << unitType << " and " << calibratedVoltage << " V." << std::endl << std::endl;
				calibrated = true;
			}
			catch (std::invalid_argument e) {
				std::cout << "Invalid input." << std::endl;
			}
		} while (!calibrated);
		channelNum++;
	} while (channelNum <= this->m_highChan);
}
int MCCDAQ::get_board_status_single_port() {
	this->m_BoardStatus = cbVIn(BOARD_NUM, this->m_lowChan, this->m_Gain, &this->m_Data, 0);
	return this->m_BoardStatus;
}
int MCCDAQ::get_board_status_multiple_ports() {
	this->m_BoardStatus = cbAInScan(BOARD_NUM, this->m_lowChan, this->m_highChan, this->m_Count, &this->m_Rate, this->m_Gain, this->m_MemHandle, CONVERTDATA);
	return this->m_BoardStatus;
}

void MCCDAQ::print_data(std::vector<std::string> fileNames) {
	if (get_board_status_multiple_ports() == 0) {
		printf("MCC: \n");
		for (int i = 0; (i < this->m_Count); i++)
		{
			cbToEngUnits(BOARD_NUM, this->m_Gain, this->m_ADData[i], &this->m_EngUnits);
			this->m_finalUnit = this->m_linearCalibration[i / 6 + this->m_lowChan][0] * this->m_EngUnits + this->m_linearCalibration[i / 6 + this->m_lowChan][1]; // -10V to +10V range

			std::cout << "Port " << i / 6 + this->m_lowChan << ": " << fileNames.back() << " ms, " << this->m_ADData[i] << ", " << this->m_EngUnits << "V, " << this->m_finalUnit << this->m_channelUnits.at(i / 6 + this->m_lowChan) << std::endl;
			this->m_DAQData.push_back(this->m_finalUnit);
		}
	}
	else {
		for (int i = 0; i < this->m_Count; i++) {
			this->m_DAQData.push_back(-999);
		}
	}
}

std::vector<double> MCCDAQ::get_daq_data() {
	return this->m_DAQData;
}
std::vector<std::string> MCCDAQ::get_channel_units() {
	return this->m_channelUnits;
}
int MCCDAQ::get_low_chan() {
	return this->m_lowChan;
}
int MCCDAQ::get_high_chan() {
	return this->m_highChan;
}
void MCCDAQ::clear_daq_data() {
	this->m_DAQData.clear();
}