#include "ChannelCalibrationWindow.h"

ChannelCalibrationWindow::ChannelCalibrationWindow(int channel, MCCDAQ daq, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->m_channel = channel;
	this->m_daq = daq;

	ui.currentChannelLabelDynamic->setText(QString::number(channel, 10));
	ui.yValuesLabel->setText(("y-values (" + daq.get_channel_units().at(channel) + ")").c_str());

	connect(ui.dataPointsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [this](int i) {validatePoints(i); });
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
