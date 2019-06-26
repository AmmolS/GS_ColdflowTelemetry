#define AMBIENT_PRESSURE 14.696
#define BOARD_NUM 0

#include "MCCDAQ.h"
#include "SerialPort.h"
//#include "cbw.h"

#include <jsoncpp.cpp> // include from dist in project folder
#include <json/json.h>
#include <json/json-forwards.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
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

void write_to_JSON(vector<string> time, vector<double> T1, vector<double> T2, vector<double> DAQData, vector<string> channelUnits, int lowChan, int highChan) {

	int numOfPorts = highChan - lowChan + 1;
	int counter = numOfPorts;

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
		DAQ0.append(Json::Value(DAQData.at(numOfPorts)));
		DAQ0.append(Json::Value(DAQData.at(numOfPorts*2)));
		DAQ0.append(Json::Value(DAQData.at(numOfPorts*3)));
		DAQ0.append(Json::Value(DAQData.at(numOfPorts*4)));
		DAQ0.append(Json::Value(DAQData.at(numOfPorts*5)));
		data["DAQ"]["Port " + to_string(lowChan) + ": " + channelUnits.at(lowChan)] = DAQ0;
	}

	if (DAQData.size() >= 12) {
		DAQ1.append(Json::Value(DAQData.at(1)));
		DAQ1.append(Json::Value(DAQData.at(numOfPorts + 1)));
		DAQ1.append(Json::Value(DAQData.at(numOfPorts*2 + 1)));
		DAQ1.append(Json::Value(DAQData.at(numOfPorts*3 + 1)));
		DAQ1.append(Json::Value(DAQData.at(numOfPorts*4 + 1)));
		DAQ1.append(Json::Value(DAQData.at(numOfPorts*5 + 1)));
		data["DAQ"]["Port " + to_string(lowChan + 1) + ": " + channelUnits.at(lowChan + 1)] = DAQ1;
	}
	
	if (DAQData.size() >= 18) {
		DAQ2.append(Json::Value(DAQData.at(2)));
		DAQ2.append(Json::Value(DAQData.at(numOfPorts + 2)));
		DAQ2.append(Json::Value(DAQData.at(numOfPorts*2 + 2)));
		DAQ2.append(Json::Value(DAQData.at(numOfPorts*3 + 2)));
		DAQ2.append(Json::Value(DAQData.at(numOfPorts*4 + 2)));
		DAQ2.append(Json::Value(DAQData.at(numOfPorts*5 + 2)));
		data["DAQ"]["Port " + to_string(lowChan + 2) + ": " + channelUnits.at(lowChan + 2)] = DAQ2;
	}
	
	if (DAQData.size() >= 24) {
		DAQ3.append(Json::Value(DAQData.at(3)));
		DAQ3.append(Json::Value(DAQData.at(numOfPorts + 3)));
		DAQ3.append(Json::Value(DAQData.at(numOfPorts*2 + 3)));
		DAQ3.append(Json::Value(DAQData.at(numOfPorts*3 + 3)));
		DAQ3.append(Json::Value(DAQData.at(numOfPorts*4 + 3)));
		DAQ3.append(Json::Value(DAQData.at(numOfPorts*5 + 3)));
		data["DAQ"]["Port " + to_string(lowChan + 3) + ": " + channelUnits.at(lowChan + 3)] = DAQ3;
	}

	if (DAQData.size() >= 30) {
		DAQ4.append(Json::Value(DAQData.at(4)));
		DAQ4.append(Json::Value(DAQData.at(numOfPorts + 4)));
		DAQ4.append(Json::Value(DAQData.at(numOfPorts*2 + 4)));
		DAQ4.append(Json::Value(DAQData.at(numOfPorts*3 + 4)));
		DAQ4.append(Json::Value(DAQData.at(numOfPorts*4 + 4)));
		DAQ4.append(Json::Value(DAQData.at(numOfPorts*5 + 4)));
		data["DAQ"]["Port " + to_string(lowChan + 4) + ": " + channelUnits.at(lowChan + 4)] = DAQ4;
	}

	if (DAQData.size() >= 36) {
		DAQ5.append(Json::Value(DAQData.at(5)));
		DAQ5.append(Json::Value(DAQData.at(numOfPorts + 5)));
		DAQ5.append(Json::Value(DAQData.at(numOfPorts*2 + 5)));
		DAQ5.append(Json::Value(DAQData.at(numOfPorts*3 + 5)));
		DAQ5.append(Json::Value(DAQData.at(numOfPorts*4 + 5)));
		DAQ5.append(Json::Value(DAQData.at(numOfPorts*5 + 5)));
		data["DAQ"]["Port " + to_string(lowChan + 5) + ": " + channelUnits.at(lowChan + 5)] = DAQ5;
	}

	if (DAQData.size() >= 42) {
		DAQ6.append(Json::Value(DAQData.at(6)));
		DAQ6.append(Json::Value(DAQData.at(numOfPorts + 6)));
		DAQ6.append(Json::Value(DAQData.at(numOfPorts*2 + 6)));
		DAQ6.append(Json::Value(DAQData.at(numOfPorts*3 + 6)));
		DAQ6.append(Json::Value(DAQData.at(numOfPorts*4 + 6)));
		DAQ6.append(Json::Value(DAQData.at(numOfPorts*5 + 6)));
		data["DAQ"]["Port " + to_string(lowChan + 6) + ": " + channelUnits.at(lowChan + 6)] = DAQ6;
	}

	if (DAQData.size() >= 48) {
		DAQ7.append(Json::Value(DAQData.at(7)));
		DAQ7.append(Json::Value(DAQData.at(numOfPorts + 7)));
		DAQ7.append(Json::Value(DAQData.at(numOfPorts*2 + 7)));
		DAQ7.append(Json::Value(DAQData.at(numOfPorts*3 + 7)));
		DAQ7.append(Json::Value(DAQData.at(numOfPorts*4 + 7)));
		DAQ7.append(Json::Value(DAQData.at(numOfPorts*5 + 7)));
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

void write_to_csv(vector<string> time, vector<double> T1, vector<double> T2, vector<double> DAQData, vector<string> channelUnits, int lowChan, int highChan) {
	int numOfPorts = highChan - lowChan + 1;

	std::ofstream ofs("Output/CSV/" + time.back() + "ms.csv", std::ofstream::app);
	ofs << "Arduino" << endl;
	ofs << "Thermocouple,Data 1,Data 2,Data 3,Data 4,Data 5,Data 6" << endl;
	ofs << "1," << to_string(T1.at(1)) << "," << to_string(T1.at(2)) << "," << to_string(T1.at(3)) << "," << to_string(T1.at(4)) << "," << to_string(T1.at(5)) << "," << to_string(T1.at(6)) << endl;
	ofs << "2," << to_string(T2.at(1)) << "," << to_string(T2.at(2)) << "," << to_string(T2.at(3)) << "," << to_string(T2.at(4)) << "," << to_string(T2.at(5)) << "," << to_string(T2.at(6)) << endl;

	ofs << "DAQ\n";
	ofs << "Port,Unit,Data 1,Data 2,Data 3,Data 4,Data 5,Data 6\n";

	if (DAQData.size() >= 6) {
		ofs << to_string(lowChan) << "," << channelUnits.at(lowChan) << "," << DAQData.at(0) << "," << DAQData.at(numOfPorts) << "," << DAQData.at(numOfPorts*2) << "," << DAQData.at(numOfPorts*3) << "," << DAQData.at(numOfPorts*4) << "," << DAQData.at(numOfPorts*5) << endl;
	}

	if (DAQData.size() >= 12) {
		ofs << to_string(lowChan + 1) << "," << channelUnits.at(lowChan + 1) << "," << DAQData.at(1) << "," << DAQData.at(numOfPorts + 1) << "," << DAQData.at(numOfPorts*2 + 1) << "," << DAQData.at(numOfPorts*3 + 1) << "," << DAQData.at(numOfPorts*4 + 1) << "," << DAQData.at(numOfPorts*5 + 1) << endl;
	}

	if (DAQData.size() >= 18) {
		ofs << to_string(lowChan + 2) << "," << channelUnits.at(lowChan + 2) << "," << DAQData.at(2) << "," << DAQData.at(numOfPorts + 2) << "," << DAQData.at(numOfPorts*2 + 2) << "," << DAQData.at(numOfPorts*3 + 2) << "," << DAQData.at(numOfPorts*4 + 2) << "," << DAQData.at(numOfPorts*5 + 2) << endl;
	}

	if (DAQData.size() >= 24) {
		ofs << to_string(lowChan + 3) << "," << channelUnits.at(lowChan + 3) << "," << DAQData.at(3) << "," << DAQData.at(numOfPorts + 3) << "," << DAQData.at(numOfPorts*2 + 3) << "," << DAQData.at(numOfPorts*3 + 3) << "," << DAQData.at(numOfPorts*4 + 3) << "," << DAQData.at(numOfPorts*5 + 3) << endl;
	}

	if (DAQData.size() >= 30) {
		ofs << to_string(lowChan + 4) << "," << channelUnits.at(lowChan + 4) << "," << DAQData.at(4) << "," << DAQData.at(numOfPorts + 4) << "," << DAQData.at(numOfPorts*2 + 4) << "," << DAQData.at(numOfPorts*3 + 4) << "," << DAQData.at(numOfPorts*4 + 4) << "," << DAQData.at(numOfPorts*5 + 4) << endl;
	}

	if (DAQData.size() >= 36) {
		ofs << to_string(lowChan + 5) << "," << channelUnits.at(lowChan + 5) << "," << DAQData.at(5) << "," << DAQData.at(numOfPorts + 5) << "," << DAQData.at(numOfPorts*2 + 5) << "," << DAQData.at(numOfPorts*3 + 5) << "," << DAQData.at(numOfPorts*4 + 5) << "," << DAQData.at(numOfPorts*5 + 5) << endl;
	}

	if (DAQData.size() >= 42) {
		ofs << to_string(lowChan + 6) << "," << channelUnits.at(lowChan + 6) << "," << DAQData.at(6) << "," << DAQData.at(numOfPorts + 6) << "," << DAQData.at(numOfPorts*2 + 6) << "," << DAQData.at(numOfPorts*3 + 6) << "," << DAQData.at(numOfPorts*4 + 6) << "," << DAQData.at(numOfPorts*5 + 6) << endl;
	}

	if (DAQData.size() >= 48) {
		ofs << to_string(lowChan + 7) << "," << channelUnits.at(lowChan + 7) << "," << DAQData.at(7) << "," << DAQData.at(numOfPorts + 7) << "," << DAQData.at(numOfPorts*2 + 7) << "," << DAQData.at(numOfPorts*3 + 7) << "," << DAQData.at(numOfPorts*4 + 7) << "," << DAQData.at(numOfPorts*5 + 7) << endl;
	}

	ofs.close();

}

string set_arduino_port_num() {
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
	string port_string = "\\\\.\\COM" + to_string(COMPortNum);

	return port_string;
}

int main()
{
	// Set up DAQ
	MCCDAQ daq(BIP10VOLTS, 0, 0, 6, 100000);
	short BoardStatus;

	vector<double> T1;
	vector<double> T2;
	vector<string> fileNames;

	// Arduino portname
	string port_string = set_arduino_port_num();
	const char *port_name = port_string.c_str();

	//String for incoming data from Arduino
	char incomingData[MAX_DATA_LENGTH];

	SerialPort arduino(port_name);

	if (!arduino.isConnected()) {
		cout << "Arduino is not connected." << endl;
	}
	else {
		cout << "Connection established with Arduino." << endl;
		//Sleep(3000); // Give time to initialize Arduino
	}

	// Get a sample value on port 0 to check if DAQ is connected
	BoardStatus = daq.get_board_status_single_port();

	if (BoardStatus == 343) {
		cout << endl << "MCC DAQ is not connected (Code " << BoardStatus << ")." << endl;
		cout << "Press any key to continue." << endl;
		getch();
	}
	else if (BoardStatus != 0) {
		cout << endl << "Error with MCC DAQ. Code: " << BoardStatus << endl;
		cout << "Press any key to continue." << endl;
		getch();
	}
	else {
		bool validRange = false;
		cout << endl << "Connection established with MCC DAQ." << endl;
		cout << "Press any key to continue." << endl;
		getch();
		daq.set_daq_ports();

		BoardStatus = daq.get_board_status_multiple_ports();

		daq.set_daq_units();

		cout << "\nCalibrate DAQ voltage (y for yes)? (By default, -10 V is 0 units): ";
		string response;
		cin >> response;
		if (response == "y") {
			daq.calibrate_daq();
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

		fileNames.push_back(to_string(clock() - time));

		daq.print_data(fileNames);

		if (arduino.isConnected()) {
			printf("\nArduino: \n");
			printf("%s", incomingData);
		}

		
		write_to_JSON(fileNames, T1, T2, daq.get_daq_data(), daq.get_channel_units(), daq.get_low_chan(), daq.get_high_chan());
		write_to_csv(fileNames, T1, T2, daq.get_daq_data(), daq.get_channel_units(), daq.get_low_chan(), daq.get_high_chan());
		update_filename(fileNames);

		daq.clear_daq_data();
		T1.clear();
		T2.clear();

		// Wait 0.1 seconds (time between each file write operation)
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
