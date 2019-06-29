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
		this->m_linearCalibration[i][0] = 50; // Sample slope
		this->m_linearCalibration[i][1] = 500; // Sample y-intercept
	}
}

bool MCCDAQ::linear_regression(int numOfPoints, std::vector<float> x_voltages, std::vector<float> y_units, float *slope, float *y_intercept) {
	float numerator = 0;
	float denominator = 0;
	float xMean = 0;
	float yMean = 0;

	xMean = std::accumulate(x_voltages.begin(), x_voltages.end(), (float)0.0) / x_voltages.size();
	yMean = std::accumulate(y_units.begin(), y_units.end(), (float)0.0) / y_units.size();
	for (int i = 0; i < numOfPoints; i++) {
		numerator += (x_voltages.at(i) - xMean)*(y_units.at(i) - yMean);
		denominator += pow((x_voltages.at(i) - xMean), 2);
	}
	if (denominator == 0) {
		return false;
	}
	else {
		*slope = numerator / denominator;
		*y_intercept = yMean - (numerator / denominator)*xMean;
		return true;
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
	int channel = this->m_lowChan;
	bool unitSet = false;

	std::cout << "Enter a unit for each channel (ex. P)." << std::endl;

	do {
		std::cout << "Channel " << channel << ": ";
		std::cin >> response;
		this->m_channelUnits.at(channel) = response;
		channel++;
	} while (channel <= this->m_highChan);
}

void MCCDAQ::calibrate_daq() {
	std::cout << "The DAQ can be calibrated in two ways:" << std::endl;
	std::cout << "a. Manually - voltages (x-values) and the corresponding value of the desired units (y-values) would each be inputted individiually" << std::endl;
	std::cout << "b. Automatically - the DAQ would read a voltage (x-value) from a channel and the corresponding value of the desired unit (y-value) would be inputted by the user" << std::endl;
	std::string response;
	do {
		std::cout << "Pick a calibration method (enter a or b): ";
		std::cin >> response;
		if (response == "a") {
			this->calibrate_daq_manually();
		}
		else if (response == "b") {
			this->calibrate_daq_automatically();
		}
	} while (response != "a" && response != "b");
}

void MCCDAQ::calibrate_daq_manually() {
	std::string response;
	std::string numOfPointsResponse;
	std::string pointResponse;
	int numOfPoints;
	bool calibrated = false;
	bool validNumOfPoints = false;
	bool validXPoint = false;
	bool validYPoint = false;

	std::vector<float> x_voltages;
	std::vector<float> y_units;

	int channelNum = this->m_lowChan;
	std::cout << std::endl << "A set of inputted voltages (x-values) will be calibrated with a set of inputted units (y-values) (ex. -10 V and 14.696 P)." << std::endl;
	do {
		do {
			do {
				try {
					std::cout << "Calibrating channel " << channelNum << "..." << std::endl;
					std::cout << "Enter the number of data points that will be used to calibrate this port: ";
					std::cin >> numOfPointsResponse;
					numOfPoints = stoi(numOfPointsResponse);
					if (numOfPoints < 2) {
						std::cout << "Number of data points cannot be 1 or lower." << std::endl;
					}
					else {
						validNumOfPoints = true;
					}
				}
				catch (std::invalid_argument e) {
					std::cout << "Invalid input." << std::endl;
				}
			} while (!validNumOfPoints);

			for (int currentPoint = 1; currentPoint <= numOfPoints; currentPoint++) {
				do {
					try {
						std::cout << std::endl << "Enter voltage value (x-value) for point " << currentPoint << ": ";
						std::cin >> pointResponse;
						x_voltages.push_back(stof(pointResponse));
						validXPoint = true;
					}
					catch (std::invalid_argument e) {
						std::cout << "Invalid input." << std::endl;
					}
				} while (!validXPoint);
				do {
					try {
						std::cout << "Enter unit (" << this->m_channelUnits.at(channelNum) << ") value (y-value) for point " << currentPoint << ": ";
						std::cin >> pointResponse;
						y_units.push_back(stof(pointResponse));
						validYPoint = true;
					}
					catch (std::invalid_argument e) {
						std::cout << "Invalid input." << std::endl;
					}
				} while (!validYPoint);
				validXPoint = false;
				validYPoint = false;
			}

			calibrated = linear_regression(numOfPoints, x_voltages, y_units, &this->m_linearCalibration.at(channelNum).at(0), &this->m_linearCalibration.at(channelNum).at(1));
			if (calibrated) {
				std::cout << "Channel " << channelNum << " calibrated with slope of " << this->m_linearCalibration.at(channelNum).at(0) << " and y-intercept of " << m_linearCalibration.at(channelNum).at(1) << "." << std::endl << std::endl;
			}
			else {
				std::cout << "Error computing slope - vertical line. Double check points and try again." << std::endl;
			}
			x_voltages.clear();
			y_units.clear();
		} while (!calibrated);

		channelNum++;
		calibrated = false;
	} while (channelNum <= this->m_highChan);
}

void MCCDAQ::calibrate_daq_automatically() {
	std::string response;
	std::string numOfPointsResponse;
	std::string pointResponse;
	int numOfPoints;
	int sampleChannel;
	float readVoltage;
	bool calibrated = false;
	bool validNumOfPoints = false;
	bool validChannel = false;
	bool validYPoint = false;

	std::vector<float> x_voltages;
	std::vector<float> y_units;

	int channelNum = this->m_lowChan;
	std::cout << std::endl << "A voltage (x-value) will be read from a selected port, and the corresponding value for the unit (y-value) would be inputted (ex. -10 V and 14.696 P)." << std::endl;
	do {
		do {
			do {
				try {
					std::cout << "Calibrating channel " << channelNum << "..." << std::endl;
					std::cout << "Enter the number of data points that will be used to calibrate this port: ";
					std::cin >> numOfPointsResponse;
					numOfPoints = stoi(numOfPointsResponse);
					if (numOfPoints < 2) {
						std::cout << "Number of data points cannot be 1 or lower." << std::endl;
					}
					else {
						validNumOfPoints = true;
					}
				}
				catch (std::invalid_argument e) {
					std::cout << "Invalid input." << std::endl;
				}
			} while (!validNumOfPoints);

			for (int currentPoint = 1; currentPoint <= numOfPoints; currentPoint++) {
				do {
					try {
						std::cout << std::endl << "Choose a channel to read a voltage from for point " << currentPoint << ": ";
						std::cin >> pointResponse;
						sampleChannel = stoi(pointResponse);

						if (sampleChannel < 0 || sampleChannel > 7) {
							std::cout << "Pick a channel between 0 and 7." << std::endl;
							validChannel = false;
						}
						validChannel = true;
					}
					catch (std::invalid_argument e) {
						std::cout << "Invalid input." << std::endl;
					}
				} while (!validChannel);
				do {
					try {
						cbVIn(BOARD_NUM, sampleChannel, this->m_Gain, &readVoltage, 0);
						x_voltages.push_back(readVoltage);
						std::cout << "The DAQ is reading " << x_voltages.back() << "V on channel " << sampleChannel << "." << std::endl;
						std::cout << "Enter the corresponding unit (" << this->m_channelUnits.at(channelNum) << ") value (y-value) for point " << currentPoint << ": ";
						std::cin >> pointResponse;
						y_units.push_back(stof(pointResponse));
						validYPoint = true;
					}
					catch (std::invalid_argument e) {
						std::cout << "Invalid input." << std::endl;
					}
				} while (!validYPoint);
				validChannel = false;
				validYPoint = false;
			}

			calibrated = linear_regression(numOfPoints, x_voltages, y_units, &this->m_linearCalibration.at(channelNum).at(0), &this->m_linearCalibration.at(channelNum).at(1));
			if (calibrated) {
				std::cout << "Channel " << channelNum << " calibrated with slope of " << this->m_linearCalibration.at(channelNum).at(0) << " and y-intercept of " << m_linearCalibration.at(channelNum).at(1) << "." << std::endl << std::endl;
			}
			else {
				std::cout << "Error computing slope - vertical line. Double check points and try again." << std::endl;
			}
			x_voltages.clear();
			y_units.clear();
		} while (!calibrated);

		channelNum++;
		calibrated = false;
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

void MCCDAQ::collect_data(std::vector<std::string> fileNames) {
	if (get_board_status_multiple_ports() == 0) {
		int portNum = this->m_lowChan;
		//printf("MCC: \n");
		for (int i = 0; (i < this->m_Count); i++)
		{
			cbToEngUnits(BOARD_NUM, this->m_Gain, this->m_ADData[i], &this->m_EngUnits);
			if (portNum > this->m_highChan) {
				portNum = this->m_lowChan;
			}
			this->m_finalUnit = this->m_linearCalibration[portNum][0] * this->m_EngUnits + this->m_linearCalibration[portNum][1]; // -10V to +10V range

			std::cout << "Port " << portNum << ": " << fileNames.back() << " ms, " << this->m_ADData[i] << ", " << this->m_EngUnits << "V, " << this->m_finalUnit << this->m_channelUnits.at(portNum) << std::endl;
			this->m_DAQVoltages.push_back(this->m_EngUnits);
			this->m_DAQData.push_back(this->m_finalUnit);
			portNum++;
		}
	}
	else {
		for (int i = 0; i < this->m_Count; i++) {
			this->m_DAQVoltages.push_back(-1000);
			this->m_DAQData.push_back(-999);
		}
	}
}

std::vector<double> MCCDAQ::get_daq_voltages() {
	return this->m_DAQVoltages;
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
void MCCDAQ::clear_daq_voltages() {
	this->m_DAQVoltages.clear();
}
void MCCDAQ::clear_daq_data() {
	this->m_DAQData.clear();
}