#pragma once

#include <QWidget>
#include <QDialog>
#include "ui_ChannelCalibrationWindow.h"
#include "MCCDAQ.h"
#include <algorithm>

class ChannelCalibrationWindow : public QDialog
{
	Q_OBJECT

public:
	ChannelCalibrationWindow(int channel, MCCDAQ daq, std::vector<std::vector<double>> *calibrationDataSet, bool previouslyCalibrated, QWidget *parent = Q_NULLPTR);
	~ChannelCalibrationWindow();

	void validatePoints(int numOfPoints);
	void enableSelectedPoints(int numOfPoints, bool shouldEnable);
	void on_readChannelButton_clicked(int point);
	void on_calibrateButton_clicked();
	void on_saveButton_clicked(std::vector<std::vector<double>> *calibrationDataSet);
	void on_cancelButton_clicked();
	void reloadPreviousData(std::vector<std::vector<double>> *calibrationDataSet);

private:
	Ui::ChannelCalibrationWindow ui;

	int m_channel;
	int m_numOfPoints;
	double m_slope;
	double m_yintercept;
	MCCDAQ m_daq;
	std::vector<std::vector<double>> m_calibrationDataSet;
	std::vector<std::vector<double>> test;
	
};
