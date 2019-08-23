#include "GS_ColdflowTelemetryGUI.h"

GS_ColdflowTelemetryGUI::GS_ColdflowTelemetryGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	MCCDAQ daq();
	
	validChannel = new QIntValidator(0, 7, this);

	ui.lowerChannelInput->setValidator(validChannel);
	ui.higherChannelInput->setValidator(validChannel);

	this->calibrationDataSet.assign(8, std::vector<std::vector<double>>(2, std::vector<double>(10, 0)));
	this->channelCalibrated.assign(8, false);

	connect(ui.validateDAQButton, SIGNAL(clicked()), this, SLOT(checkDaqStatus()));
	connect(ui.confirmChannelsButton, SIGNAL(clicked()), this, SLOT(validateChannels()));
	connect(ui.confirmUnitsButton, SIGNAL(clicked()), this, SLOT(validateUnits()));

	connect(ui.channel0CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(0);});
	connect(ui.channel1CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(1); });
	connect(ui.channel2CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(2); });
	connect(ui.channel3CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(3); });
	connect(ui.channel4CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(4); });
	connect(ui.channel5CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(5); });
	connect(ui.channel6CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(6); });
	connect(ui.channel7CalibrateButton, &QPushButton::clicked, [this]() {calibrateChannel(7); });
		
	
	//connect(ui.lowerChannelInput, SIGNAL(editingFinished()), ui.lowerChannelInput, SLOT(test = ui.lowerChannelInput->text()));
}

void GS_ColdflowTelemetryGUI::enableChannelNumInput(bool shouldEnable) {
	ui.lowerChannelLabel->setEnabled(shouldEnable);
	ui.higherChannelLabel->setEnabled(shouldEnable);

	ui.lowerChannelInput->setEnabled(shouldEnable);
	ui.higherChannelInput->setEnabled(shouldEnable);

	ui.channelsStatusLabelDynamic->setEnabled(shouldEnable);
	ui.confirmChannelsButton->setEnabled(shouldEnable);
}

void GS_ColdflowTelemetryGUI::enableSelectedUnitInput(int lowChan, int highChan, bool shouldEnable) {
	for (int currentChannel = lowChan; currentChannel <= highChan; currentChannel++) {
		if (currentChannel == 0) {
			ui.channel0Label->setEnabled(shouldEnable);
			ui.channel0UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 1) {
			ui.channel1Label->setEnabled(shouldEnable);
			ui.channel1UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 2) {
			ui.channel2Label->setEnabled(shouldEnable);
			ui.channel2UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 3) {
			ui.channel3Label->setEnabled(shouldEnable);
			ui.channel3UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 4) {
			ui.channel4Label->setEnabled(shouldEnable);
			ui.channel4UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 5) {
			ui.channel5Label->setEnabled(shouldEnable);
			ui.channel5UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 6) {
			ui.channel6Label->setEnabled(shouldEnable);
			ui.channel6UnitInput->setEnabled(shouldEnable);
		}
		if (currentChannel == 7) {
			ui.channel7Label->setEnabled(shouldEnable);
			ui.channel7UnitInput->setEnabled(shouldEnable);
		}
	}
}

void GS_ColdflowTelemetryGUI::enableSelectedChannelCalibration(int lowChan, int highChan, bool shouldEnable) {
	for (int currentChannel = lowChan; currentChannel <= highChan; currentChannel++) {
		if (currentChannel == 0) {
			ui.channel0CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 1) {
			ui.channel1CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 2) {
			ui.channel2CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 3) {
			ui.channel3CalibrateButton ->setEnabled(shouldEnable);
		}
		if (currentChannel == 4) {
			ui.channel4CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 5) {
			ui.channel5CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 6) {
			ui.channel6CalibrateButton->setEnabled(shouldEnable);
		}
		if (currentChannel == 7) {
			ui.channel7CalibrateButton->setEnabled(shouldEnable);
		}
	}
}

void GS_ColdflowTelemetryGUI::checkDaqStatus() {
	bool boardNumOk;
	
	int boardNum = ui.boardNumInput->text().toInt(&boardNumOk, 10);
	if (boardNumOk) {
		daq.set_board_num(boardNum);
		//ui.boardNumInput->setText(ui.boardNumInput->text());
	}

	int BoardStatus = daq.get_board_status_single_port();
	std::string text;

	//BoardStatus = 0; // TEMP
	
	updateUnitInputFrame(false, 0, 7);
	enableChannelNumInput(false);

	if (boardNumOk && BoardStatus == 343) {
		ui.currentStateLabelDynamic->setText(("MCC DAQ is not connected (Code " + std::to_string(BoardStatus) + ")").c_str());
	}
	else if (boardNumOk && BoardStatus == 1) {
		ui.currentStateLabelDynamic->setText(("Error: Check board number (Code " + std::to_string(BoardStatus) + ")").c_str());
	}
	else if (boardNumOk && BoardStatus != 0) {
		ui.currentStateLabelDynamic->setText(("Error with MCC DAQ. Code: " + std::to_string(BoardStatus)).c_str());
	}
	else if (boardNumOk && BoardStatus == 0) {
		ui.currentStateLabelDynamic->setText("Connection established with MCC DAQ");
		enableChannelNumInput(true);
	}
	else {
		ui.currentStateLabelDynamic->setText("Error: Check board number");
	}
}

void GS_ColdflowTelemetryGUI::validateChannels() {
	bool lowChanOk;
	bool highChanOk;

	int lowChan = ui.lowerChannelInput->text().toInt(&lowChanOk, 10);
	int highChan = ui.higherChannelInput->text().toInt(&highChanOk, 10);

	if (lowChanOk && highChanOk && highChan <= 7 && lowChan >= 0 && highChan >= lowChan) {
		ui.channelsStatusLabelDynamic->setText("Valid channel range");
		daq.set_daq_channels(lowChan, highChan);
		ui.channelsSetLabelDynamic->setText("True");
		updateUnitInputFrame(true, lowChan, highChan);
	}
	else {
		ui.channelsStatusLabelDynamic->setText("Invalid channel range");
		ui.channelsSetLabelDynamic->setText("False");
		updateUnitInputFrame(false, 0, 7);
	}
}

void GS_ColdflowTelemetryGUI::validateUnits() {
	for (int currentChannel = daq.get_low_chan(); currentChannel <= daq.get_high_chan(); currentChannel++) {
		if (currentChannel == 0) {
			daq.set_daq_units(ui.channel0UnitInput->text().toStdString(), 0);
			ui.channel0SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(0)));
		}
		if (currentChannel == 1) {
			daq.set_daq_units(ui.channel1UnitInput->text().toStdString(), 1);
			ui.channel1SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(1)));
		}
		if (currentChannel == 2) {
			daq.set_daq_units(ui.channel2UnitInput->text().toStdString(), 2);
			ui.channel2SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(2)));
		}
		if (currentChannel == 3) {
			daq.set_daq_units(ui.channel3UnitInput->text().toStdString(), 3);
			ui.channel3SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(3)));
		}
		if (currentChannel == 4) {
			daq.set_daq_units(ui.channel4UnitInput->text().toStdString(), 4);
			ui.channel4SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(4)));
		}
		if (currentChannel == 5) {
			daq.set_daq_units(ui.channel5UnitInput->text().toStdString(), 5);
			ui.channel5SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(5)));
		}
		if (currentChannel == 6) {
			daq.set_daq_units(ui.channel6UnitInput->text().toStdString(), 6);
			ui.channel6SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(6)));
		}
		if (currentChannel == 7) {
			daq.set_daq_units(ui.channel7UnitInput->text().toStdString(), 7);
			ui.channel7SelectedUnitLabelDynamic->setText(QString::fromStdString(daq.get_channel_units().at(7)));
		}
	}
	ui.unitsSetLabelDynamic->setText("True");
	updateChannelCalibrationButtons(true, daq.get_low_chan(), daq.get_high_chan());
}

void GS_ColdflowTelemetryGUI::updateUnitInputFrame(bool shouldEnable, int lowChan, int highChan) {
	ui.unitsSetLabelDynamic->setText("False");
	updateChannelCalibrationButtons(false, 0, 7);
	if (shouldEnable) {
		ui.channelUnitsFrame->setEnabled(true);
		enableSelectedUnitInput(0, 7, false);
		enableSelectedUnitInput(lowChan, highChan, true);
	}
	else {
		ui.channelUnitsFrame->setEnabled(false);
		enableSelectedUnitInput(0, 7, false);
	}
}

void GS_ColdflowTelemetryGUI::updateChannelCalibrationButtons(bool shouldEnable, int lowChan, int highChan) {
	ui.calibrationDoneLabelDynamic->setText("False");
	if (shouldEnable) {
		enableSelectedChannelCalibration(0, 7, false);
		enableSelectedChannelCalibration(lowChan, highChan, true);
	}
	else {
		enableSelectedChannelCalibration(0, 7, false);
	}
}

void GS_ColdflowTelemetryGUI::calibrateChannel(int channel) {
	ChannelCalibrationWindow calibrateChannelWindow(channel, this->daq, &calibrationDataSet.at(channel), channelCalibrated.at(channel));
	//calibrateChannelWindow.setModal(true);

	//connect(&calibrateChannelWindow, SIGNAL(rejected()), this, SLOT(lower()));

	//connect(&calibrateChannelWindow, &QDialog::accepted, [this]() {ui.channel0CalibrateButton->setText("Calibrated"); });
	//connect(&calibrateChannelWindow, &QDialog::rejected, [this]() {ui.channel0CalibrateButton->setText("Not calibrated"); });

	int status = calibrateChannelWindow.exec();


	if (status == QDialog::Accepted && channel == 0) {
		ui.channel0CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 1) {
		ui.channel1CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 2) {
		ui.channel2CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 3) {
		ui.channel3CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 4) {
		ui.channel4CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 5) {
		ui.channel5CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 6) {
		ui.channel6CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
	else if (status == QDialog::Accepted && channel == 7) {
		ui.channel7CalibrateButton->setText("Calibrated");
		channelCalibrated.at(channel) = true;
	}
}