#pragma once

#include <QtWidgets/QMainWindow>
#include <QIntValidator>
#include "ui_GS_ColdflowTelemetryGUI.h"
#include "MCCDAQ.h"
#include "ChannelCalibrationWindow.h"
#include <string>

class GS_ColdflowTelemetryGUI : public QMainWindow
{
	Q_OBJECT

public:
	GS_ColdflowTelemetryGUI(QWidget *parent = Q_NULLPTR);
	void enableChannelNumInput(bool shouldEnable);
	void enableSelectedUnitInput(int lowChan, int highChan, bool shouldEnable);
	void enableSelectedChannelCalibration(int lowChan, int highChan, bool shouldEnable);
	void updateUnitInputFrame(bool shouldEnable, int lowChan, int highChan);
	void updateChannelCalibrationButtons(bool shouldEnable, int lowChan, int highChan);

public slots:
	void checkDaqStatus();
	void validateChannels();
	void validateUnits();
	void calibrateChannel(int channel);

private:
	Ui::GS_ColdflowTelemetryGUIClass ui;

	QIntValidator *validChannel;
	MCCDAQ daq;
};
