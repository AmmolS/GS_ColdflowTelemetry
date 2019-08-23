#include "ChannelCalibrationWindow.h"

ChannelCalibrationWindow::ChannelCalibrationWindow(int channel, MCCDAQ daq, std::vector<std::vector<double>> *calibrationDataSet, bool previouslyCalibrated, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->m_channel = channel;
	this->m_daq = daq;
	this->m_calibrationDataSet.assign(2, std::vector<double>(10, 0));

	//this->m_dataSet = *dataSet;

	ui.currentChannelLabelDynamic->setText(QString::number(channel, 10));
	ui.yValuesLabel->setText(("y-values (" + daq.get_channel_units().at(channel) + ")").c_str());

	if (previouslyCalibrated) {
		reloadPreviousData(calibrationDataSet);
	}

	ui.buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);

	connect(ui.dataPointsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [this](int i) {this->m_numOfPoints = i; validatePoints(i); });
	connect(ui.calibrateButton, &QPushButton::clicked, this, &ChannelCalibrationWindow::on_calibrateButton_clicked);
	connect(ui.buttonBox, &QDialogButtonBox::accepted, [calibrationDataSet, this]() {on_saveButton_clicked(calibrationDataSet); });
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &ChannelCalibrationWindow::on_cancelButton_clicked);

	connect(ui.point1ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(1); });
	connect(ui.point2ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(2); });
	connect(ui.point3ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(3); });
	connect(ui.point4ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(4); });
	connect(ui.point5ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(5); });
	connect(ui.point6ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(6); });
	connect(ui.point7ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(7); });
	connect(ui.point8ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(8); });
	connect(ui.point9ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(9); });
	connect(ui.point10ReadChannelButton, &QPushButton::clicked, [this]() {on_readChannelButton_clicked(10); });
}

ChannelCalibrationWindow::~ChannelCalibrationWindow()
{
}

void ChannelCalibrationWindow::validatePoints(int numOfPoints) {
	enableSelectedPoints(10, false);
	enableSelectedPoints(numOfPoints, true);
}

void ChannelCalibrationWindow::enableSelectedPoints(int numOfPoints, bool shouldEnable) {
	for (int currentPoint = 3; currentPoint <= numOfPoints;	currentPoint++) {
		if (currentPoint == 3) {
			ui.point3Label->setEnabled(shouldEnable);
			ui.point3xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point3yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point3ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point3ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 4) {
			ui.point4Label->setEnabled(shouldEnable);
			ui.point4xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point4yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point4ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point4ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 5) {
			ui.point5Label->setEnabled(shouldEnable);
			ui.point5xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point5yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point5ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point5ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 6) {
			ui.point6Label->setEnabled(shouldEnable);
			ui.point6xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point6yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point6ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point6ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 7) {
			ui.point7Label->setEnabled(shouldEnable);
			ui.point7xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point7yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point7ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point7ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 8) {
			ui.point8Label->setEnabled(shouldEnable);
			ui.point8xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point8yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point8ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point8ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 9) {
			ui.point9Label->setEnabled(shouldEnable);
			ui.point9xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point9yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point9ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point9ReadChannelButton->setEnabled(shouldEnable);
		}
		if (currentPoint == 10) {
			ui.point10Label->setEnabled(shouldEnable);
			ui.point10xValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point10yValuesDoubleSpinBox->setEnabled(shouldEnable);
			ui.point10ReadChannelSpinBox->setEnabled(shouldEnable);
			ui.point10ReadChannelButton->setEnabled(shouldEnable);
		}
	}
}

void ChannelCalibrationWindow::on_readChannelButton_clicked(int point) {
	float readVoltage;

	if (point == 1) {
		cbVIn(this->m_daq.get_board_num(), ui.point1ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point1xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 2) {
		cbVIn(this->m_daq.get_board_num(), ui.point2ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point2xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 3) {
		cbVIn(this->m_daq.get_board_num(), ui.point3ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point3xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 4) {
		cbVIn(this->m_daq.get_board_num(), ui.point4ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point4xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 5) {
		cbVIn(this->m_daq.get_board_num(), ui.point5ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point5xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 6) {
		cbVIn(this->m_daq.get_board_num(), ui.point6ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point6xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 7) {
		cbVIn(this->m_daq.get_board_num(), ui.point7ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point7xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 8) {
		cbVIn(this->m_daq.get_board_num(), ui.point8ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point8xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 9) {
		cbVIn(this->m_daq.get_board_num(), ui.point9ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point9xValuesDoubleSpinBox->setValue(readVoltage);
	}
	if (point == 10) {
		cbVIn(this->m_daq.get_board_num(), ui.point10ReadChannelSpinBox->value(), this->m_daq.get_gain(), &readVoltage, 0);
		ui.point10xValuesDoubleSpinBox->setValue(readVoltage);
	}
}

void ChannelCalibrationWindow::on_calibrateButton_clicked() {
	int numOfPoints = ui.dataPointsSpinBox->value();
	std::vector<double> x_voltages;
	std::vector<double> y_units;
	bool calibrated = false;

	this->m_calibrationDataSet.at(0).clear();
	this->m_calibrationDataSet.at(1).clear();

	for (int currentPoint = 1; currentPoint <= numOfPoints; currentPoint++) {
		if (currentPoint == 1) {
			this->m_calibrationDataSet.at(0).push_back(ui.point1xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point1yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 2) {
			this->m_calibrationDataSet.at(0).push_back(ui.point2xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point2yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 3) {
			this->m_calibrationDataSet.at(0).push_back(ui.point3xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point3yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 4) {
			this->m_calibrationDataSet.at(0).push_back(ui.point4xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point4yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 5) {
			this->m_calibrationDataSet.at(0).push_back(ui.point5xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point5yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 6) {
			this->m_calibrationDataSet.at(0).push_back(ui.point6xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point6yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 7) {
			this->m_calibrationDataSet.at(0).push_back(ui.point7xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point7yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 8) {
			this->m_calibrationDataSet.at(0).push_back(ui.point8xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point8yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 9) {
			this->m_calibrationDataSet.at(0).push_back(ui.point9xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point9yValuesDoubleSpinBox->value());
		}
		if (currentPoint == 10) {
			this->m_calibrationDataSet.at(0).push_back(ui.point10xValuesDoubleSpinBox->value());
			this->m_calibrationDataSet.at(1).push_back(ui.point10yValuesDoubleSpinBox->value());
		}
	}
	calibrated = this->m_daq.linear_regression(numOfPoints, this->m_calibrationDataSet.at(0), this->m_calibrationDataSet.at(1), &this->m_slope, &this->m_yintercept);

	if (calibrated) {
		ui.slopeLabelDynamic->setText(QString::number(this->m_slope, 'g', 7));
		ui.yinterceptLabelDynamic->setText(QString::number(this->m_yintercept, 'g', 7));
		ui.buttonBox->button(QDialogButtonBox::Save)->setEnabled(true);
	}
	else {
		ui.slopeLabelDynamic->setText("Error: check inputted values");
		ui.yinterceptLabelDynamic->setText("Error: check inputted values");
		ui.buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
	}
}

void ChannelCalibrationWindow::on_saveButton_clicked(std::vector<std::vector<double>> *calibrationDataSet) {
	this->m_daq.calibrate_daq_channel(this->m_channel, this->m_slope, this->m_yintercept);
	calibrationDataSet->at(0).clear();
	calibrationDataSet->at(1).clear();
	for (int count = 0; count < this->m_calibrationDataSet.at(0).size(); count++) {
		calibrationDataSet->at(0).push_back(this->m_calibrationDataSet.at(0).at(count));
		calibrationDataSet->at(1).push_back(this->m_calibrationDataSet.at(1).at(count));
	}

	this->accept();
}

void ChannelCalibrationWindow::on_cancelButton_clicked() {
	this->reject();
}

void ChannelCalibrationWindow::reloadPreviousData(std::vector<std::vector<double>> *calibrationDataSet) {
	if (calibrationDataSet->at(0).size() > 0 && calibrationDataSet->at(1).size() > 0) {
		ui.dataPointsSpinBox->setValue(calibrationDataSet->at(0).size());
		enableSelectedPoints(calibrationDataSet->at(0).size(), true);

		for (int point = 1; point <= calibrationDataSet->at(0).size(); point++) {
			if (point == 1) {
				ui.point1xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(0));
				ui.point1yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(0));
			}
			if (point == 2) {
				ui.point2xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(1));
				ui.point2yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(1));
			}
			if (point == 3) {
				ui.point3xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(2));
				ui.point3yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(2));
			}
			if (point == 4) {
				ui.point4xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(3));
				ui.point4yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(3));
			}
			if (point == 5) {
				ui.point5xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(4));
				ui.point5yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(4));
			}
			if (point == 6) {
				ui.point6xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(5));
				ui.point6yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(5));
			}
			if (point == 7) {
				ui.point7xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(6));
				ui.point7yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(6));
			}
			if (point == 8) {
				ui.point8xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(7));
				ui.point8yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(7));
			}
			if (point == 9) {
				ui.point9xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(8));
				ui.point9yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(8));
			}
			if (point == 10) {
				ui.point10xValuesDoubleSpinBox->setValue(calibrationDataSet->at(0).at(9));
				ui.point10yValuesDoubleSpinBox->setValue(calibrationDataSet->at(1).at(9));
			}
		}
		this->m_daq.linear_regression(calibrationDataSet->at(0).size(), calibrationDataSet->at(0), calibrationDataSet->at(1), &this->m_slope, &this->m_yintercept);
		ui.slopeLabelDynamic->setText(QString::number(this->m_slope, 'g', 7));
		ui.yinterceptLabelDynamic->setText(QString::number(this->m_yintercept, 'g', 7));
	}
}
