#define AMBIENT_PRESSURE 14.696
#define BOARD_NUM 0

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SerialPort.h"
#include "cbw.h"
#include <algorithm>

#include <conio.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <chrono>
#include <thread>
#include <windows.h>
#include <time.h>
#include <vector>

#include <jsoncpp.cpp> // include from dist in project folder
#include <json/json.h>
#include <json/json-forwards.h>

using namespace std;

void update_filename(vector<string> fileNames) {
	// Create new JSON file (or truncate existing contents)
	std::ofstream jsFile("Output/JSON/JSFileName/FileList.json", std::ofstream::trunc);

	Json::Value data;
	Json::Value name(Json::arrayValue);

	// Add file names to JSON file
	for (size_t i = 0; i < fileNames.size(); i++) {
		name.append(fileNames.at(i) + "ms");
	}
	
	data["File Name"] = name;

	jsFile << data << std::flush;
	jsFile.close();
}


void write_to_JSON(vector<string> time, vector<double> T1, vector<double> T2, vector<double> DAQData, vector<string> channelUnits, int lowChan) {

	// Initializing overarching JSON object
	Json::Value data;

	// Initializing JSON vectors
	Json::Value tc1(Json::arrayValue);
	Json::Value tc2(Json::arrayValue);
	Json::Value tc3(Json::arrayValue);
	Json::Value tc4(Json::arrayValue);

	Json::Value DAQ0(Json::arrayValue);
	Json::Value DAQ1(Json::arrayValue);
	Json::Value DAQ2(Json::arrayValue);
	Json::Value DAQ3(Json::arrayValue);
	Json::Value DAQ4(Json::arrayValue);
	Json::Value DAQ5(Json::arrayValue);
	Json::Value DAQ6(Json::arrayValue);
	Json::Value DAQ7(Json::arrayValue);

	// Appending temperature values to vectors
	tc1.append(Json::Value(T1.at(1)));
	tc1.append(Json::Value(T1.at(2)));
	tc1.append(Json::Value(T1.at(3)));
	tc1.append(Json::Value(T1.at(4)));
	tc1.append(Json::Value(T1.at(5)));
	tc1.append(Json::Value(T1.at(6)));
	
	tc2.append(Json::Value(T2.at(1)));
	tc2.append(Json::Value(T2.at(2)));
	tc2.append(Json::Value(T2.at(3)));
	tc2.append(Json::Value(T2.at(4)));
	tc2.append(Json::Value(T2.at(5)));
	tc2.append(Json::Value(T2.at(6)));
	
	tc3.append(Json::Value(48));
	tc3.append(Json::Value(49));
	tc3.append(Json::Value(50));
	tc3.append(Json::Value(50));
	tc3.append(Json::Value(49));
	tc3.append(Json::Value(49));

	tc4.append(Json::Value(60));
	tc4.append(Json::Value(60));
	tc4.append(Json::Value(61));
	tc4.append(Json::Value(60));
	tc4.append(Json::Value(64));
	tc4.append(Json::Value(64));

	if (DAQData.size() >= 6) {
		DAQ0.append(Json::Value(DAQData.at(0)));
		DAQ0.append(Json::Value(DAQData.at(1)));
		DAQ0.append(Json::Value(DAQData.at(2)));
		DAQ0.append(Json::Value(DAQData.at(3)));
		DAQ0.append(Json::Value(DAQData.at(4)));
		DAQ0.append(Json::Value(DAQData.at(5)));
		data["DAQ"]["Port " + to_string(lowChan) + ": " + channelUnits.at(lowChan)] = DAQ0;
	}

	if (DAQData.size() >= 12) {
		DAQ1.append(Json::Value(DAQData.at(6)));
		DAQ1.append(Json::Value(DAQData.at(7)));
		DAQ1.append(Json::Value(DAQData.at(8)));
		DAQ1.append(Json::Value(DAQData.at(9)));
		DAQ1.append(Json::Value(DAQData.at(10)));
		DAQ1.append(Json::Value(DAQData.at(11)));
		data["DAQ"]["Port " + to_string(lowChan + 1) + ": " + channelUnits.at(lowChan + 1)] = DAQ1;
	}
	
	if (DAQData.size() >= 18) {
		DAQ2.append(Json::Value(DAQData.at(12)));
		DAQ2.append(Json::Value(DAQData.at(13)));
		DAQ2.append(Json::Value(DAQData.at(14)));
		DAQ2.append(Json::Value(DAQData.at(15)));
		DAQ2.append(Json::Value(DAQData.at(16)));
		DAQ2.append(Json::Value(DAQData.at(17)));
		data["DAQ"]["Port " + to_string(lowChan + 2) + ": " + channelUnits.at(lowChan + 2)] = DAQ2;
	}
	
	if (DAQData.size() >= 24) {
		DAQ3.append(Json::Value(DAQData.at(18)));
		DAQ3.append(Json::Value(DAQData.at(19)));
		DAQ3.append(Json::Value(DAQData.at(20)));
		DAQ3.append(Json::Value(DAQData.at(21)));
		DAQ3.append(Json::Value(DAQData.at(22)));
		DAQ3.append(Json::Value(DAQData.at(23)));
		data["DAQ"]["Port " + to_string(lowChan + 3) + ": " + channelUnits.at(lowChan + 3)] = DAQ3;
	}

	if (DAQData.size() >= 30) {
		DAQ4.append(Json::Value(DAQData.at(24)));
		DAQ4.append(Json::Value(DAQData.at(25)));
		DAQ4.append(Json::Value(DAQData.at(26)));
		DAQ4.append(Json::Value(DAQData.at(27)));
		DAQ4.append(Json::Value(DAQData.at(28)));
		DAQ4.append(Json::Value(DAQData.at(29)));
		data["DAQ"]["Port " + to_string(lowChan + 4) + ": " + channelUnits.at(lowChan + 4)] = DAQ4;
	}

	if (DAQData.size() >= 36) {
		DAQ5.append(Json::Value(DAQData.at(30)));
		DAQ5.append(Json::Value(DAQData.at(31)));
		DAQ5.append(Json::Value(DAQData.at(32)));
		DAQ5.append(Json::Value(DAQData.at(33)));
		DAQ5.append(Json::Value(DAQData.at(34)));
		DAQ5.append(Json::Value(DAQData.at(35)));
		data["DAQ"]["Port " + to_string(lowChan + 5) + ": " + channelUnits.at(lowChan + 5)] = DAQ5;
	}

	if (DAQData.size() >= 42) {
		DAQ6.append(Json::Value(DAQData.at(36)));
		DAQ6.append(Json::Value(DAQData.at(37)));
		DAQ6.append(Json::Value(DAQData.at(38)));
		DAQ6.append(Json::Value(DAQData.at(39)));
		DAQ6.append(Json::Value(DAQData.at(40)));
		DAQ6.append(Json::Value(DAQData.at(41)));
		data["DAQ"]["Port " + to_string(lowChan + 6) + ": " + channelUnits.at(lowChan + 6)] = DAQ6;
	}

	if (DAQData.size() >= 48) {
		DAQ7.append(Json::Value(DAQData.at(42)));
		DAQ7.append(Json::Value(DAQData.at(43)));
		DAQ7.append(Json::Value(DAQData.at(44)));
		DAQ7.append(Json::Value(DAQData.at(45)));
		DAQ7.append(Json::Value(DAQData.at(46)));
		DAQ7.append(Json::Value(DAQData.at(47)));
		data["DAQ"]["Port " + to_string(lowChan + 7) + ": " +  channelUnits.at(lowChan + 7)] = DAQ7;
	}

	// JSON will have two branches underneath data, one for the DAQ, and one for the Arduino

	data["DAQ"]["Load Cell"] = "test";
	data["Arduino"]["Thermocouple1"] = tc1;
	data["Arduino"]["Thermocouple2"] = tc2;
	data["Arduino"]["Thermocouple3"] = tc3;
	data["Arduino"]["Thermocouple4"] = tc4;
	data["Arduino"]["Load Cell"] = "test";

	std::ofstream ofs("Output/JSON/" + time.back() + "ms.json", std::ofstream::app);
	ofs << data << std::flush;
	ofs.close();
}

void write_to_csv(vector<string> time, vector<double> T1, vector<double> T2, vector<double> DAQData, vector<string> channelUnits, int lowChan) {
	std::ofstream ofs("Output/CSV/" + time.back() + "ms.csv", std::ofstream::app);
	ofs << "Arduino" << endl;
	ofs << "Thermocouple,Data 1,Data 2,Data 3,Data 4,Data 5,Data 6" << endl;
	ofs << "1," << to_string(T1.at(1)) << "," << to_string(T1.at(2)) << "," << to_string(T1.at(3)) << "," << to_string(T1.at(4)) << "," << to_string(T1.at(5)) << "," << to_string(T1.at(6)) << endl;
	ofs << "2," << to_string(T2.at(1)) << "," << to_string(T2.at(2)) << "," << to_string(T2.at(3)) << "," << to_string(T2.at(4)) << "," << to_string(T2.at(5)) << "," << to_string(T2.at(6)) << endl;

	ofs << "DAQ\n";
	ofs << "Port,Unit,Data 1,Data 2,Data 3,Data 4,Data 5,Data 6\n";

	if (DAQData.size() >= 6) {
		ofs << to_string(lowChan) << "," << channelUnits.at(lowChan) << "," << DAQData.at(0) << "," << DAQData.at(1) << "," << DAQData.at(2) << "," << DAQData.at(3) << "," << DAQData.at(4) << "," << DAQData.at(5) << endl;
	}

	if (DAQData.size() >= 12) {
		ofs << to_string(lowChan + 1) << "," << channelUnits.at(lowChan + 1) << "," << DAQData.at(6) << "," << DAQData.at(7) << "," << DAQData.at(8) << "," << DAQData.at(9) << "," << DAQData.at(10) << "," << DAQData.at(11) << endl;
	}

	if (DAQData.size() >= 18) {
		ofs << to_string(lowChan + 2) << "," << channelUnits.at(lowChan + 2) << "," << DAQData.at(12) << "," << DAQData.at(13) << "," << DAQData.at(14) << "," << DAQData.at(15) << "," << DAQData.at(16) << "," << DAQData.at(17) << endl;
	}

	if (DAQData.size() >= 24) {
		ofs << to_string(lowChan + 3) << "," << channelUnits.at(lowChan + 3) << "," << DAQData.at(18) << "," << DAQData.at(19) << "," << DAQData.at(20) << "," << DAQData.at(21) << "," << DAQData.at(22) << "," << DAQData.at(23) << endl;
	}

	if (DAQData.size() >= 30) {
		ofs << to_string(lowChan + 4) << "," << channelUnits.at(lowChan + 4) << "," << DAQData.at(24) << "," << DAQData.at(25) << "," << DAQData.at(26) << "," << DAQData.at(27) << "," << DAQData.at(28) << "," << DAQData.at(29) << endl;
	}

	if (DAQData.size() >= 36) {
		ofs << to_string(lowChan + 5) << "," << channelUnits.at(lowChan + 5) << "," << DAQData.at(30) << "," << DAQData.at(31) << "," << DAQData.at(32) << "," << DAQData.at(33) << "," << DAQData.at(34) << "," << DAQData.at(35) << endl;
	}

	if (DAQData.size() >= 42) {
		ofs << to_string(lowChan + 6) << "," << channelUnits.at(lowChan + 6) << "," << DAQData.at(36) << "," << DAQData.at(37) << "," << DAQData.at(38) << "," << DAQData.at(39) << "," << DAQData.at(40) << "," << DAQData.at(41) << endl;
	}

	if (DAQData.size() >= 48) {
		ofs << to_string(lowChan + 7) << "," << channelUnits.at(lowChan + 7) << "," << DAQData.at(42) << "," << DAQData.at(43) << "," << DAQData.at(44) << "," << DAQData.at(45) << "," << DAQData.at(46) << "," << DAQData.at(47) << endl;
	}

	ofs.close();

}

int set_arduino_port_num() {
	string response;
	int COMPortNum;
	bool validPort = false;

	do {
		try {
			cout << "Enter an integer for the COM Port connected to the Arduino: ";
			cin >> response;
			COMPortNum = stoi(response);
			if (COMPortNum < 0) {
				cout << "Port number should be positive." << endl;
			}
			else {
				validPort = true;
			}
		}
		catch (invalid_argument e) {
			cout << "Invalid input." << endl;
		}
	} while (!validPort);
	return  COMPortNum;
}

void set_daq_units(int lowChan, int highChan, vector<string> *units) {
	string response;
	bool unitSet = false;
	
	cout << "\nTo set all the channels to the same unit, enter one of the units below. To set each channel individually, enter y." << endl;
	cout << "KP for Pressure (kilopsi)" << endl;
	cout << "C for Temperature (Celsius)" << endl;
	cout << "N for Force (Newtons)" << endl;
	cout << "L/s for Flow Rate (Litres/second)" << endl;
	cout << "Chosen unit: ";

	do {
		cin >> response;

		if (response == "KP") {
			fill(units->begin(), units->end(), "KP");
			cout << "Channels " << lowChan << " to " << highChan << " set to Pressure." << endl;
			return;
		}
		else if (response == "C") {
			fill(units->begin(), units->end(), "C");
			cout << "Channels " << lowChan << " to " << highChan << " set to Temperature." << endl;
			return;
		}
		else if (response == "N") {
			fill(units->begin(), units->end(), "N");
			cout << "Channels " << lowChan << " to " << highChan << " set to Force." << endl;
			return;
		}
		else if (response == "L/s") {
			fill(units->begin(), units->end(), "L/s");
			cout << "Channels " << lowChan << " to " << highChan << " set to Flow Rate." << endl;
			return;
		}
		else if (response == "y") {
			cout << endl << "Setting each channel individually..." << endl;
			cout << "For each channel, enter:" << endl;
			cout << "KP for Pressure (kilopsi)" << endl;
			cout << "C for Temperature (Celsius)" << endl;
			cout << "N for Force (Newtons)" << endl;
			cout << "L/s for Flow Rate (Litres/second)" << endl;

			int channel = lowChan;
			do {
				cout << "Channel " << channel << ": ";
				cin >> response;
				if (response == "KP" || response == "C" || response == "N" || response == "L/s") {
					units->at(channel) = response;
					channel++;
				}
				else {
					cout << "Enter KP, C, N, or L/s." << endl;
				}
			} while (channel <= highChan);
			return;
		}
		else {
			cout << "Enter KP, C, N, L/s, or y: ";
		}
	}while (response != "KP" && response != "C" && response != "N" && response != "L/s" && response != "y");
}


void calibrate_daq(int lowChan, int highChan, vector<string> units, vector<vector<float>> *linearCalibration) {
	string response;
	float calibratedVoltage;
	float calibratedUnit;
	bool validChannel = false;
	bool validUnit = false;
	bool calibrated = false;

	int channelNum = lowChan;
	cout << "An inputted unit will be calibrated with an inputted voltage (ex. 14.696 KP at -10 V)." << endl;

	do {
		do {
			try {
				cout << "Calibrating channel " << channelNum << "..." << endl;
				if (units.at(channelNum) == "KP") {
					cout << "Enter a value for pressure: ";
				}
				if (units.at(channelNum) == "C") {
					cout << "Enter a value for temperature: ";
				}
				if (units.at(channelNum) == "N") {
					cout << "Enter a value for force: ";
				}
				if (units.at(channelNum) == "L/s") {
					cout << "Enter a value for flow rate: ";
				}
				cin >> response;
				calibratedUnit = stof(response);
				validUnit = true;
			}
			catch (invalid_argument e) {
				cout << "Invalid input." << endl;
			}
		} while (!validUnit);

		string unitType;

		do {
			try {
				cout << "Enter the corresponding voltage value: ";
				cin >> response;
				calibratedVoltage = stof(response);

				if (units.at(channelNum) == "KP") {
					unitType = "KP";
				}
				else if (units.at(channelNum) == "C") {
					unitType = "C";
				}

				else if (units.at(channelNum) == "N") {
					unitType = "N";
				}

				else if (units.at(channelNum) == "L/s") {
					unitType = "L/s";
				}

				linearCalibration->at(channelNum).at(0) = (1000 - calibratedUnit) / (10 - calibratedVoltage);
				linearCalibration->at(channelNum).at(1) = 1000 - (linearCalibration->at(channelNum).at(0) * 10);

				cout << "Channel " << channelNum << " calibrated with " << calibratedUnit << " " << unitType << " and " << calibratedVoltage << " V." << endl << endl;
				calibrated = true;
			}
			catch (invalid_argument e) {
				cout << "Invalid input." << endl;
			}
		} while (!calibrated);
		channelNum++;
	} while (channelNum <= highChan);
}

int main()
{
	// MCC board setup
	int Gain = BIP10VOLTS;
	float Data = 0;
	float EngUnits = 0;
	double finalUnit = 0;
	short BoardStatus;
	int lowChan = 0;
	int highChan = 0;

	// MCC sampling
	long Count = 6; // Total number of samples to be collected (6 samples * # of channels)
	long Rate = 100000; // Rate that samples are collected per channel
	HANDLE MemHandle = cbWinBufAlloc(Count);
	WORD *ADData = (WORD*)MemHandle;

	vector<string> channelUnits(8, "");
	vector<vector<float>> linearCalibration(8, vector<float>(2));

	for (size_t i = 0; i < linearCalibration.size(); i++) {
		linearCalibration[i][0] = 50;
		linearCalibration[i][1] = 500;
	}

	vector<double> T1;
	vector<double> T2;
	vector<double> DAQData;
	vector<string> fileNames;

	// Arduino portname
	string port_string = "\\\\.\\COM" + to_string(set_arduino_port_num());
	const char *port_name = port_string.c_str();

	//String for incoming data from Arduino
	char incomingData[MAX_DATA_LENGTH];

	SerialPort arduino(port_name);

	if (!arduino.isConnected()) {
		cout << "Arduino is not connected." << endl;
	}
	else {
		cout << "Connection established with Arduino." << endl;
		Sleep(3000); // Give time to initialize Arduino
	}

	// Get a sample value on port 0 to check if DAQ is connected
	BoardStatus = cbVIn(BOARD_NUM, lowChan, Gain, &Data, 0);

	if (BoardStatus == 343) {
		cout << "MCC DAQ is not connected (Code " << BoardStatus << ")." << endl;
	}
	else if (BoardStatus != 0) {
		cout << "Error with MCC DAQ. Code: " << BoardStatus << endl;
	}
	else {
		bool validRange = false;
		cout << "Connection established with MCC DAQ." << endl;
		cout << endl << "Setting the lower and higher number of DAQ channels used (max. range of 7 channels)" << endl;
		do {
			try {
				cout << "Enter the lower channel: ";
				string lowChanStr;
				cin >> lowChanStr;
				lowChan = stoi(lowChanStr);

				cout << "Enter the higher channel: ";
				string highChanStr;
				cin >> highChanStr;
				highChan = stoi(highChanStr);

				if (highChan > 7 || lowChan < 0 || highChan - lowChan < 0 || highChan - lowChan > 7) {
					cout << "Range of channels must be between 1 and 7, and higher channel must be greater than (or equal to for a single channel) lower channel." << endl;
				}
				else {
					validRange = true;
				}
			}
			catch (invalid_argument e) {
				cout << "Invalid channel input." << endl;
			}
		} while (!validRange);

		// MCC sampling
		Count = 6 * (highChan - lowChan + 1); // Total number of samples to be collected (6 samples * # of channels)
		Rate = 100000/(highChan - lowChan + 1); // Rate that samples are collected per channel
		MemHandle = cbWinBufAlloc(Count);
		ADData = (WORD*)MemHandle;

		BoardStatus = cbAInScan(BOARD_NUM, lowChan, highChan, Count, &Rate, Gain, MemHandle, CONVERTDATA);

		set_daq_units(lowChan, highChan, &channelUnits);

		cout << "\nCalibrate DAQ voltage (y for yes)? (By default, -10 V is 0 units): ";
		string response;
		cin >> response;
		if (response == "y") {
			calibrate_daq(lowChan, highChan, channelUnits, &linearCalibration);
		}
	}

	if (arduino.isConnected() || BoardStatus == 0) {
		cout << "Press the ESC key at any time to end data collection." << endl;
		Sleep(1500);
	}
	

	clock_t time = clock();
	while (!(GetAsyncKeyState(VK_ESCAPE) & 1) && (arduino.isConnected() || BoardStatus == 0)) {
		cout << "Press the ESC key to end data collection." << endl;

		if (arduino.isConnected()) {
			//Check if data has been read or not
			int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);

			istringstream raw(incomingData);
			string thermocouple;
		
			// Temperature value of -999 is an error/invalid value
			while (getline(raw, thermocouple, '-')) {
				// Find all valid numbers in received string and push them to temperature vector
				if (thermocouple.find("T1") != string::npos && thermocouple.length() > thermocouple.find("T1") + 7)
				{
					try {
						T1.push_back(stod(thermocouple.substr(thermocouple.find("T1") + 3, 5)));
					}
					catch (invalid_argument e) {
						T1.push_back(-999);
					}
					
				}
				else
				{
					T1.push_back(-999);
				}

				if (thermocouple.find("T2") != string::npos && thermocouple.length() > thermocouple.find("T2") + 7)
				{
					try {
						T2.push_back(stod(thermocouple.substr(thermocouple.find("T2") + 3, 5)));
					}
					catch (invalid_argument e) {
						T2.push_back(-999);
					}
					
				}
				else
				{
					T2.push_back(-999);
				}
			}
		}

		// Force vector to have size of 6
		while (T1.size() <= 6) {
			T1.push_back(-999);
		}

		while (T2.size() <= 6) {
			T2.push_back(-999);
		}

		if (BoardStatus == 0) {
			printf("MCC: \n");
			for (int i = 0; (i < Count); i++)
			{
				cbToEngUnits(BOARD_NUM, Gain, ADData[i], &EngUnits);
				finalUnit = linearCalibration[i/6 + lowChan][0] *EngUnits + linearCalibration[i/6 + lowChan][1]; // -10V to +10V range

				cout << ADData[i] << ", " << EngUnits << "V, " << finalUnit << channelUnits.at(i/6 + lowChan) << endl;
				DAQData.push_back(finalUnit);
			}
		}
		else {
			for (int i = 0; i < Count; i++) {
				DAQData.push_back(-999);
			}
		}

		if (arduino.isConnected()) {
			printf("\nArduino: \n");
			printf("%s", incomingData);
		}

		fileNames.push_back(to_string(clock() - time));
		write_to_JSON(fileNames, T1, T2, DAQData, channelUnits, lowChan);
		write_to_csv(fileNames, T1, T2, DAQData, channelUnits, lowChan);
		update_filename(fileNames);

		DAQData.clear();
		T1.clear();
		T2.clear();

		// Wait 0.5 seconds (time between each file write operation)
		Sleep(100);
	}
	string response;
	if (arduino.isConnected() || BoardStatus == 0) {
		do {
			cout << "Save collected data? Enter y or n: ";
			cin >> response;
			if (response == "n") {
				// Remove files in Output folder
				for (size_t i = 0; i < fileNames.size(); ++i) {
					remove(("Output/JSON/" + fileNames.at(i) + "ms.json").c_str());
					remove(("Output/CSV/" + fileNames.at(i) + "ms.csv").c_str());
				}
			}
			else if (response == "y") {
				cout << endl << "Files saved in:" << endl;
				cout << "Output/JSON/" << endl;
				cout << "Output/CSV/" << endl;
				cout << "Please move or delete the json and csv files before running the program again." << endl;
			}
		} while (response != "y" && response != "n");
	}
	
	return 0;
}
