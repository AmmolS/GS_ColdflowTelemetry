#define AMBIENT_PRESSURE 14.696
#define BOARD_NUM 0

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SerialPort.h"
#include "cbw.h"

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

// Arduino portname
const char *port_name = "\\\\.\\COM4";

//String for incoming data from Arduino
char incomingData[MAX_DATA_LENGTH];

void update_filename(vector<string> fileNames) {
	// Create new JSON file (or truncate existing contents)
	std::ofstream jsFile("Output/JSFileName/FileList.json", std::ofstream::trunc);

	Json::Value data;
	Json::Value name(Json::arrayValue);

	// Add file names to JSON file
	for (size_t i = 0; i < fileNames.size(); i++) {
		name.append(fileNames.at(i));
	}
	
	data["File Name"] = name;

	jsFile << data << std::flush;
	jsFile.close();
}


void write_to_JSON(vector<string> time, vector<double> T1, vector<double> T2, vector<double> pressure) {

	// Initializing overarching JSON object
	Json::Value data;

	// Initializing JSON vectors
	Json::Value tc1(Json::arrayValue);
	Json::Value tc2(Json::arrayValue);
	Json::Value tc3(Json::arrayValue);
	Json::Value tc4(Json::arrayValue);

	Json::Value pt1(Json::arrayValue);
	Json::Value pt2(Json::arrayValue);
	Json::Value pt3(Json::arrayValue);

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

	pt1.append(Json::Value(pressure.at(0)));
	pt1.append(Json::Value(pressure.at(1)));
	pt1.append(Json::Value(pressure.at(2)));
	pt1.append(Json::Value(pressure.at(3)));
	pt1.append(Json::Value(pressure.at(4)));
	pt1.append(Json::Value(pressure.at(5)));

	pt2.append(Json::Value(pressure.at(6)));
	pt2.append(Json::Value(pressure.at(7)));
	pt2.append(Json::Value(pressure.at(8)));
	pt2.append(Json::Value(pressure.at(9)));
	pt2.append(Json::Value(pressure.at(10)));
	pt2.append(Json::Value(pressure.at(11)));

	pt3.append(Json::Value(pressure.at(12)));
	pt3.append(Json::Value(pressure.at(13)));
	pt3.append(Json::Value(pressure.at(14)));
	pt3.append(Json::Value(pressure.at(15)));
	pt3.append(Json::Value(pressure.at(16)));
	pt3.append(Json::Value(pressure.at(17)));

	// JSON will have two branches underneath data, one for the DAQ, and one for the Arduino
	data["DAQ"]["PT1"] = pt1;
	data["DAQ"]["PT2"] = pt2;
	data["DAQ"]["PT3"] = pt3;
	data["DAQ"]["Load Cell"] = "test";
	data["Arduino"]["Thermocouple1"] = tc1;
	data["Arduino"]["Thermocouple2"] = tc2;
	data["Arduino"]["Thermocouple3"] = tc3;
	data["Arduino"]["Thermocouple4"] = tc4;
	data["Arduino"]["Load Cell"] = "test";

	std::ofstream ofs("Output/" + time.back(), std::ofstream::app);
	ofs << data << std::flush;
	ofs.close();
}

void calibrate_daq(float *slope, float *constant, int lowChan, int highChan) {
	string response;
	float ambientVoltage;
	bool validChannel = false;
	bool calibrated = false;

	do {
		try {
			cout << "Enter a voltage value to set as ambient voltage or y to use current received voltage on a specific channel: ";
			cin >> response;
			if (response == "y") {
				string channel;
				do {
					try {
						do {
							cout << "Pick a channel between 0 and 7: ";
							cin >> channel;
						} while (stoi(channel) > 7 || stoi(channel) < 0);
						validChannel = true;
					}
					catch (invalid_argument e) {
						cout << "Invalid input." << endl;
					}
				} while (!validChannel);

				cbVIn(BOARD_NUM, stof(channel), BIP10VOLTS, &ambientVoltage, 0);
				*slope = (1000 - AMBIENT_PRESSURE) / (10 - ambientVoltage);
				*constant = 1000 - (*slope) * 10;
				cout << "DAQ calibrated with " << ambientVoltage << " V as ambient pressure voltage." << endl;
				calibrated = true;
			}
			else {
				*slope = (1000 - AMBIENT_PRESSURE) / (10 - stof(response));
				*constant = 1000 - (*slope) * 10;
				cout << "DAQ calibrated with " << response << " V as ambient pressure voltage." << endl;
				calibrated = true;
			}
		}
		catch (invalid_argument e) {
			cout << "Invalid input." << endl;
		}
	} while (!calibrated);
	
}

int main()
{
	// MCC board setup
	int Gain = BIP10VOLTS;
	float Data = 0;
	float EngUnits = 0;
	double pressureKP = 0;
	short BoardStatus;
	int lowChan = 0;
	int highChan = 0;

	// MCC sampling
	long Count = 18; // Total number of samples to be collected (6 samples * 3 channels)
	long Rate = 5000; // Rate that samples are collected per channel
	HANDLE MemHandle = cbWinBufAlloc(Count);
	WORD *ADData = (WORD*)MemHandle;

	vector<double> T1;
	vector<double> T2;
	vector<double> pressure;
	vector<string> fileNames;

	SerialPort arduino(port_name);

	float slope = 50;
	float constant = 500;
	

	if (!arduino.isConnected()) {
		cout << "Arduino is not connected." << endl;
	}
	else {
		cout << "Connection established with Arduino." << endl;
		Sleep(3000); // Give time to initialize Arduino
	}

	// Scan channels 0 to 2 on DAQ
	BoardStatus = cbVIn(BOARD_NUM, lowChan, Gain, &Data, 0);

	//BoardStatus = cbAInScan(BOARD_NUM, lowChan, highChan, Count, &Rate, Gain, MemHandle, CONVERTDATA);
	
	if (BoardStatus == 343) {
		cout << "MCC DAQ is not connected (Code " << BoardStatus << ")." << endl;
	}
	else if (BoardStatus != 0) {
		cout << "Error with MCC DAQ. Code: " << BoardStatus << endl;
	}
	else {
		bool validRange = false;
		cout << "Connection established with MCC DAQ." << endl;
		cout << "Setting the lower and higher number of channels used (max. range of 3 channels)" << endl;
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
			}
			catch (invalid_argument e) {
				cout << "Invalid channel input." << endl;
			}
			if (highChan - lowChan != 2) {
				cout << "Range of channels must be 3 and higher channel must be greater than lower channel." << endl;
			}
			else {
				validRange = true;
			}
		} while (!validRange);

		BoardStatus = cbAInScan(BOARD_NUM, lowChan, highChan, Count, &Rate, Gain, MemHandle, CONVERTDATA);
		cout << "Calibrate DAQ voltage (y for yes)? (By default, -10 V is 0 KP): ";
		string response;
		cin >> response;
		if (response == "y") {
			calibrate_daq(&slope, &constant, lowChan, highChan);
		}

	}

	clock_t time = clock();
	while (!_kbhit() && (arduino.isConnected() || BoardStatus == 0)) {

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
					T1.push_back(stod(thermocouple.substr(thermocouple.find("T1") + 3, 5)));
				}
				else
				{
					T1.push_back(-999);
				}


				if (thermocouple.find("T2") != string::npos && thermocouple.length() > thermocouple.find("T2") + 7)
				{
					T2.push_back(stod(thermocouple.substr(thermocouple.find("T2") + 3, 5)));
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
			for (int i = 0; (i < 18); i++)
			{
				cbToEngUnits(BOARD_NUM, Gain, ADData[i], &EngUnits);
				pressureKP = slope * EngUnits + constant; // -10V to +10V range
				printf("%4u, %fV, %lfP\n", ADData[i], EngUnits, pressureKP);
				pressure.push_back(pressureKP);
			}
		}
		else {
			for (int i = 0; i < 18; i++) {
				pressure.push_back(-999);
			}
		}

		if (arduino.isConnected()) {
			printf("\nArduino: \n");
			printf("%s", incomingData);
		}

		fileNames.push_back(to_string(clock() - time) + "ms.json");
		write_to_JSON(fileNames, T1, T2, pressure);
		update_filename(fileNames);

		pressure.clear();
		T1.clear();
		T2.clear();

		// Wait 0.5 seconds (time between each file write operation)
		Sleep(500);
	}
	// Remove files in Output folder
	for (size_t i = 0; i < fileNames.size(); ++i) {
		remove(("Output/" + fileNames.at(i)).c_str());
	}
	
	free(ADData); 
	return 0;
}
