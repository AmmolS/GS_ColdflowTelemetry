#ifndef MCCDAQ_H
#define MCCDAQ_H

#include "cbw.h"

#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <math.h>
#include <fstream>


class MCCDAQ 
{
private:
	int m_BoardNum;
	int m_Gain;
	float m_Data;
	float m_EngUnits;
	double m_finalUnit;
	short m_BoardStatus;
	int m_lowChan;
	int m_highChan;

	// MCC sampling
	long m_Count;// Total number of samples to be collected (6 samples * # of channels)
	long m_Rate; // Rate that samples are collected per channel
	HANDLE m_MemHandle;
	WORD *m_ADData;

	std::vector<std::string> m_channelUnits;
	std::vector<std::vector<double>> m_linearCalibration;
	std::vector<double> m_DAQVoltages;
	std::vector<double> m_DAQData;

	void calibrate_daq_manually();
	void calibrate_daq_automatically();

public:
	MCCDAQ();
	MCCDAQ(int boardNum, int Gain, int lowChan, int highChan, long Count, long Rate);

	bool linear_regression(int numOfPoints, std::vector<double> x_voltages, std::vector<double> y_units, double* slope, double* y_intercept);

	void set_board_num(int boardNum);
	void set_low_chan(int lowChan);
	void set_high_chan(int highChan);
	void set_daq_channels(int lowChan, int highChan);
	void set_daq_units(std::string unit, int index);
	void calibrate_daq_channel(int channelNum, double slope, double y_intercept);

	int get_board_status_single_port();
	int get_board_status_multiple_ports();
	void collect_data(std::vector<std::string>);
	void write_csv_heading_daq();
	void write_to_csv_daq(std::vector<std::string> filenames);

	std::vector<double> get_daq_voltages();
	std::vector<double> get_daq_data();
	std::vector<std::string> get_channel_units();
	std::vector<std::vector<double>> get_linear_calibration();
	int get_board_num();
	int get_gain();
	int get_low_chan();
	int get_high_chan();

	void clear_daq_voltages();
	void clear_daq_data();
};
#endif
