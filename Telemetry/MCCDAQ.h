#include "cbw.h"

#include <vector>
#include <string>
#include <iostream>

#define BOARD_NUM 0

class MCCDAQ 
{
private:
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
	std::vector<std::vector<float>> m_linearCalibration;
	std::vector<double> m_DAQData;

public:
	MCCDAQ(int Gain, int lowChan, int highChan, long Count, long Rate);

	void set_daq_ports();
	void set_daq_units();
	void calibrate_daq();

	int get_board_status_single_port();
	int get_board_status_multiple_ports();
	void print_data(std::vector<std::string>);

	std::vector<double> get_daq_data();
	std::vector<std::string> get_channel_units();
	int get_low_chan();
	int get_high_chan();

	void clear_daq_data();
};