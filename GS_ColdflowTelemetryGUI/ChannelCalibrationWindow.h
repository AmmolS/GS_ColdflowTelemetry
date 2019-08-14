#pragma once

#include <QWidget>
#include <QDialog>
#include "ui_ChannelCalibrationWindow.h"
#include "MCCDAQ.h"

class ChannelCalibrationWindow : public QDialog
{
	Q_OBJECT

public:
	ChannelCalibrationWindow(int channel, MCCDAQ daq, QWidget *parent = Q_NULLPTR);
	~ChannelCalibrationWindow();

	void validatePoints(int numOfPoints);
	void enableSelectedPoints(int numOfPoints, bool shouldEnable);

private:
	Ui::ChannelCalibrationWindow ui;

	int m_channel;
	MCCDAQ m_daq;
};
