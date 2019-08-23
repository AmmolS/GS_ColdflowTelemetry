/********************************************************************************
** Form generated from reading UI file 'ChannelCalibrationWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELCALIBRATIONWINDOW_H
#define UI_CHANNELCALIBRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelCalibrationWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *currentChannelLabel;
    QLabel *currentChannelLabelDynamic;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dataPointsLabel;
    QSpinBox *dataPointsSpinBox;
    QGridLayout *gridLayout;
    QSpinBox *point6ReadChannelSpinBox;
    QDoubleSpinBox *point6yValuesDoubleSpinBox;
    QDoubleSpinBox *point5xValuesDoubleSpinBox;
    QDoubleSpinBox *point9yValuesDoubleSpinBox;
    QLabel *point1Label;
    QPushButton *point4ReadChannelButton;
    QLabel *point8Label;
    QDoubleSpinBox *point10xValuesDoubleSpinBox;
    QPushButton *point5ReadChannelButton;
    QDoubleSpinBox *point7yValuesDoubleSpinBox;
    QLabel *yValuesLabel;
    QDoubleSpinBox *point4yValuesDoubleSpinBox;
    QSpinBox *point5ReadChannelSpinBox;
    QDoubleSpinBox *point7xValuesDoubleSpinBox;
    QDoubleSpinBox *point5yValuesDoubleSpinBox;
    QLabel *point10Label;
    QLabel *point6Label;
    QSpinBox *point3ReadChannelSpinBox;
    QPushButton *point9ReadChannelButton;
    QPushButton *point8ReadChannelButton;
    QDoubleSpinBox *point3xValuesDoubleSpinBox;
    QPushButton *point1ReadChannelButton;
    QDoubleSpinBox *point8yValuesDoubleSpinBox;
    QPushButton *point3ReadChannelButton;
    QLabel *xValuesLabel;
    QLabel *point5Label;
    QSpinBox *point10ReadChannelSpinBox;
    QLabel *readChanneLabel;
    QDoubleSpinBox *point1yValuesDoubleSpinBox;
    QDoubleSpinBox *point6xValuesDoubleSpinBox;
    QDoubleSpinBox *point2yValuesDoubleSpinBox;
    QPushButton *point6ReadChannelButton;
    QDoubleSpinBox *point4xValuesDoubleSpinBox;
    QDoubleSpinBox *point1xValuesDoubleSpinBox;
    QPushButton *point7ReadChannelButton;
    QDoubleSpinBox *point10yValuesDoubleSpinBox;
    QSpinBox *point1ReadChannelSpinBox;
    QDoubleSpinBox *point8xValuesDoubleSpinBox;
    QSpinBox *point4ReadChannelSpinBox;
    QLabel *point9Label;
    QSpinBox *point8ReadChannelSpinBox;
    QPushButton *point2ReadChannelButton;
    QLabel *point3Label;
    QDoubleSpinBox *point3yValuesDoubleSpinBox;
    QDoubleSpinBox *point2xValuesDoubleSpinBox;
    QSpinBox *point7ReadChannelSpinBox;
    QLabel *point4Label;
    QPushButton *point10ReadChannelButton;
    QLabel *point7Label;
    QLabel *point2Label;
    QDoubleSpinBox *point9xValuesDoubleSpinBox;
    QSpinBox *point2ReadChannelSpinBox;
    QSpinBox *point9ReadChannelSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *slopeLabel;
    QLabel *slopeLabelDynamic;
    QHBoxLayout *horizontalLayout_4;
    QLabel *yinterceptLabel;
    QLabel *yinterceptLabelDynamic;
    QPushButton *calibrateButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *ChannelCalibrationWindow)
    {
        if (ChannelCalibrationWindow->objectName().isEmpty())
            ChannelCalibrationWindow->setObjectName(QString::fromUtf8("ChannelCalibrationWindow"));
        ChannelCalibrationWindow->resize(470, 349);
        verticalLayout_2 = new QVBoxLayout(ChannelCalibrationWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        currentChannelLabel = new QLabel(ChannelCalibrationWindow);
        currentChannelLabel->setObjectName(QString::fromUtf8("currentChannelLabel"));

        horizontalLayout->addWidget(currentChannelLabel);

        currentChannelLabelDynamic = new QLabel(ChannelCalibrationWindow);
        currentChannelLabelDynamic->setObjectName(QString::fromUtf8("currentChannelLabelDynamic"));

        horizontalLayout->addWidget(currentChannelLabelDynamic);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dataPointsLabel = new QLabel(ChannelCalibrationWindow);
        dataPointsLabel->setObjectName(QString::fromUtf8("dataPointsLabel"));

        horizontalLayout_2->addWidget(dataPointsLabel);

        dataPointsSpinBox = new QSpinBox(ChannelCalibrationWindow);
        dataPointsSpinBox->setObjectName(QString::fromUtf8("dataPointsSpinBox"));
        dataPointsSpinBox->setMinimum(2);
        dataPointsSpinBox->setMaximum(10);

        horizontalLayout_2->addWidget(dataPointsSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        point6ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point6ReadChannelSpinBox->setObjectName(QString::fromUtf8("point6ReadChannelSpinBox"));
        point6ReadChannelSpinBox->setEnabled(false);
        point6ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point6ReadChannelSpinBox, 6, 4, 1, 1);

        point6yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point6yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point6yValuesDoubleSpinBox"));
        point6yValuesDoubleSpinBox->setEnabled(false);
        point6yValuesDoubleSpinBox->setDecimals(7);
        point6yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point6yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point6yValuesDoubleSpinBox, 6, 2, 1, 1);

        point5xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point5xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point5xValuesDoubleSpinBox"));
        point5xValuesDoubleSpinBox->setEnabled(false);
        point5xValuesDoubleSpinBox->setDecimals(7);
        point5xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point5xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point5xValuesDoubleSpinBox, 5, 1, 1, 1);

        point9yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point9yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point9yValuesDoubleSpinBox"));
        point9yValuesDoubleSpinBox->setEnabled(false);
        point9yValuesDoubleSpinBox->setDecimals(7);
        point9yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point9yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point9yValuesDoubleSpinBox, 9, 2, 1, 1);

        point1Label = new QLabel(ChannelCalibrationWindow);
        point1Label->setObjectName(QString::fromUtf8("point1Label"));

        gridLayout->addWidget(point1Label, 1, 0, 1, 1);

        point4ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point4ReadChannelButton->setObjectName(QString::fromUtf8("point4ReadChannelButton"));
        point4ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point4ReadChannelButton, 4, 5, 1, 1);

        point8Label = new QLabel(ChannelCalibrationWindow);
        point8Label->setObjectName(QString::fromUtf8("point8Label"));
        point8Label->setEnabled(false);

        gridLayout->addWidget(point8Label, 8, 0, 1, 1);

        point10xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point10xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point10xValuesDoubleSpinBox"));
        point10xValuesDoubleSpinBox->setEnabled(false);
        point10xValuesDoubleSpinBox->setDecimals(7);
        point10xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point10xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point10xValuesDoubleSpinBox, 10, 1, 1, 1);

        point5ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point5ReadChannelButton->setObjectName(QString::fromUtf8("point5ReadChannelButton"));
        point5ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point5ReadChannelButton, 5, 5, 1, 1);

        point7yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point7yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point7yValuesDoubleSpinBox"));
        point7yValuesDoubleSpinBox->setEnabled(false);
        point7yValuesDoubleSpinBox->setDecimals(7);
        point7yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point7yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point7yValuesDoubleSpinBox, 7, 2, 1, 1);

        yValuesLabel = new QLabel(ChannelCalibrationWindow);
        yValuesLabel->setObjectName(QString::fromUtf8("yValuesLabel"));

        gridLayout->addWidget(yValuesLabel, 0, 2, 1, 1);

        point4yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point4yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point4yValuesDoubleSpinBox"));
        point4yValuesDoubleSpinBox->setEnabled(false);
        point4yValuesDoubleSpinBox->setDecimals(7);
        point4yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point4yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point4yValuesDoubleSpinBox, 4, 2, 1, 1);

        point5ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point5ReadChannelSpinBox->setObjectName(QString::fromUtf8("point5ReadChannelSpinBox"));
        point5ReadChannelSpinBox->setEnabled(false);
        point5ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point5ReadChannelSpinBox, 5, 4, 1, 1);

        point7xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point7xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point7xValuesDoubleSpinBox"));
        point7xValuesDoubleSpinBox->setEnabled(false);
        point7xValuesDoubleSpinBox->setDecimals(7);
        point7xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point7xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point7xValuesDoubleSpinBox, 7, 1, 1, 1);

        point5yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point5yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point5yValuesDoubleSpinBox"));
        point5yValuesDoubleSpinBox->setEnabled(false);
        point5yValuesDoubleSpinBox->setDecimals(7);
        point5yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point5yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point5yValuesDoubleSpinBox, 5, 2, 1, 1);

        point10Label = new QLabel(ChannelCalibrationWindow);
        point10Label->setObjectName(QString::fromUtf8("point10Label"));
        point10Label->setEnabled(false);

        gridLayout->addWidget(point10Label, 10, 0, 1, 1);

        point6Label = new QLabel(ChannelCalibrationWindow);
        point6Label->setObjectName(QString::fromUtf8("point6Label"));
        point6Label->setEnabled(false);

        gridLayout->addWidget(point6Label, 6, 0, 1, 1);

        point3ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point3ReadChannelSpinBox->setObjectName(QString::fromUtf8("point3ReadChannelSpinBox"));
        point3ReadChannelSpinBox->setEnabled(false);
        point3ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point3ReadChannelSpinBox, 3, 4, 1, 1);

        point9ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point9ReadChannelButton->setObjectName(QString::fromUtf8("point9ReadChannelButton"));
        point9ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point9ReadChannelButton, 9, 5, 1, 1);

        point8ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point8ReadChannelButton->setObjectName(QString::fromUtf8("point8ReadChannelButton"));
        point8ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point8ReadChannelButton, 8, 5, 1, 1);

        point3xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point3xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point3xValuesDoubleSpinBox"));
        point3xValuesDoubleSpinBox->setEnabled(false);
        point3xValuesDoubleSpinBox->setDecimals(7);
        point3xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point3xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point3xValuesDoubleSpinBox, 3, 1, 1, 1);

        point1ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point1ReadChannelButton->setObjectName(QString::fromUtf8("point1ReadChannelButton"));

        gridLayout->addWidget(point1ReadChannelButton, 1, 5, 1, 1);

        point8yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point8yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point8yValuesDoubleSpinBox"));
        point8yValuesDoubleSpinBox->setEnabled(false);
        point8yValuesDoubleSpinBox->setDecimals(7);
        point8yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point8yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point8yValuesDoubleSpinBox, 8, 2, 1, 1);

        point3ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point3ReadChannelButton->setObjectName(QString::fromUtf8("point3ReadChannelButton"));
        point3ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point3ReadChannelButton, 3, 5, 1, 1);

        xValuesLabel = new QLabel(ChannelCalibrationWindow);
        xValuesLabel->setObjectName(QString::fromUtf8("xValuesLabel"));

        gridLayout->addWidget(xValuesLabel, 0, 1, 1, 1);

        point5Label = new QLabel(ChannelCalibrationWindow);
        point5Label->setObjectName(QString::fromUtf8("point5Label"));
        point5Label->setEnabled(false);

        gridLayout->addWidget(point5Label, 5, 0, 1, 1);

        point10ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point10ReadChannelSpinBox->setObjectName(QString::fromUtf8("point10ReadChannelSpinBox"));
        point10ReadChannelSpinBox->setEnabled(false);
        point10ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point10ReadChannelSpinBox, 10, 4, 1, 1);

        readChanneLabel = new QLabel(ChannelCalibrationWindow);
        readChanneLabel->setObjectName(QString::fromUtf8("readChanneLabel"));

        gridLayout->addWidget(readChanneLabel, 0, 4, 1, 2);

        point1yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point1yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point1yValuesDoubleSpinBox"));
        point1yValuesDoubleSpinBox->setDecimals(7);
        point1yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point1yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point1yValuesDoubleSpinBox, 1, 2, 1, 1);

        point6xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point6xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point6xValuesDoubleSpinBox"));
        point6xValuesDoubleSpinBox->setEnabled(false);
        point6xValuesDoubleSpinBox->setDecimals(7);
        point6xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point6xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point6xValuesDoubleSpinBox, 6, 1, 1, 1);

        point2yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point2yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point2yValuesDoubleSpinBox"));
        point2yValuesDoubleSpinBox->setDecimals(7);
        point2yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point2yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point2yValuesDoubleSpinBox, 2, 2, 1, 1);

        point6ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point6ReadChannelButton->setObjectName(QString::fromUtf8("point6ReadChannelButton"));
        point6ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point6ReadChannelButton, 6, 5, 1, 1);

        point4xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point4xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point4xValuesDoubleSpinBox"));
        point4xValuesDoubleSpinBox->setEnabled(false);
        point4xValuesDoubleSpinBox->setDecimals(7);
        point4xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point4xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point4xValuesDoubleSpinBox, 4, 1, 1, 1);

        point1xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point1xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point1xValuesDoubleSpinBox"));
        point1xValuesDoubleSpinBox->setDecimals(7);
        point1xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point1xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point1xValuesDoubleSpinBox, 1, 1, 1, 1);

        point7ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point7ReadChannelButton->setObjectName(QString::fromUtf8("point7ReadChannelButton"));
        point7ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point7ReadChannelButton, 7, 5, 1, 1);

        point10yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point10yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point10yValuesDoubleSpinBox"));
        point10yValuesDoubleSpinBox->setEnabled(false);
        point10yValuesDoubleSpinBox->setDecimals(7);
        point10yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point10yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point10yValuesDoubleSpinBox, 10, 2, 1, 1);

        point1ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point1ReadChannelSpinBox->setObjectName(QString::fromUtf8("point1ReadChannelSpinBox"));
        point1ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point1ReadChannelSpinBox, 1, 4, 1, 1);

        point8xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point8xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point8xValuesDoubleSpinBox"));
        point8xValuesDoubleSpinBox->setEnabled(false);
        point8xValuesDoubleSpinBox->setDecimals(7);
        point8xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point8xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point8xValuesDoubleSpinBox, 8, 1, 1, 1);

        point4ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point4ReadChannelSpinBox->setObjectName(QString::fromUtf8("point4ReadChannelSpinBox"));
        point4ReadChannelSpinBox->setEnabled(false);
        point4ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point4ReadChannelSpinBox, 4, 4, 1, 1);

        point9Label = new QLabel(ChannelCalibrationWindow);
        point9Label->setObjectName(QString::fromUtf8("point9Label"));
        point9Label->setEnabled(false);

        gridLayout->addWidget(point9Label, 9, 0, 1, 1);

        point8ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point8ReadChannelSpinBox->setObjectName(QString::fromUtf8("point8ReadChannelSpinBox"));
        point8ReadChannelSpinBox->setEnabled(false);
        point8ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point8ReadChannelSpinBox, 8, 4, 1, 1);

        point2ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point2ReadChannelButton->setObjectName(QString::fromUtf8("point2ReadChannelButton"));

        gridLayout->addWidget(point2ReadChannelButton, 2, 5, 1, 1);

        point3Label = new QLabel(ChannelCalibrationWindow);
        point3Label->setObjectName(QString::fromUtf8("point3Label"));
        point3Label->setEnabled(false);

        gridLayout->addWidget(point3Label, 3, 0, 1, 1);

        point3yValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point3yValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point3yValuesDoubleSpinBox"));
        point3yValuesDoubleSpinBox->setEnabled(false);
        point3yValuesDoubleSpinBox->setDecimals(7);
        point3yValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point3yValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point3yValuesDoubleSpinBox, 3, 2, 1, 1);

        point2xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point2xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point2xValuesDoubleSpinBox"));
        point2xValuesDoubleSpinBox->setDecimals(7);
        point2xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point2xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point2xValuesDoubleSpinBox, 2, 1, 1, 1);

        point7ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point7ReadChannelSpinBox->setObjectName(QString::fromUtf8("point7ReadChannelSpinBox"));
        point7ReadChannelSpinBox->setEnabled(false);
        point7ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point7ReadChannelSpinBox, 7, 4, 1, 1);

        point4Label = new QLabel(ChannelCalibrationWindow);
        point4Label->setObjectName(QString::fromUtf8("point4Label"));
        point4Label->setEnabled(false);

        gridLayout->addWidget(point4Label, 4, 0, 1, 1);

        point10ReadChannelButton = new QPushButton(ChannelCalibrationWindow);
        point10ReadChannelButton->setObjectName(QString::fromUtf8("point10ReadChannelButton"));
        point10ReadChannelButton->setEnabled(false);

        gridLayout->addWidget(point10ReadChannelButton, 10, 5, 1, 1);

        point7Label = new QLabel(ChannelCalibrationWindow);
        point7Label->setObjectName(QString::fromUtf8("point7Label"));
        point7Label->setEnabled(false);

        gridLayout->addWidget(point7Label, 7, 0, 1, 1);

        point2Label = new QLabel(ChannelCalibrationWindow);
        point2Label->setObjectName(QString::fromUtf8("point2Label"));

        gridLayout->addWidget(point2Label, 2, 0, 1, 1);

        point9xValuesDoubleSpinBox = new QDoubleSpinBox(ChannelCalibrationWindow);
        point9xValuesDoubleSpinBox->setObjectName(QString::fromUtf8("point9xValuesDoubleSpinBox"));
        point9xValuesDoubleSpinBox->setEnabled(false);
        point9xValuesDoubleSpinBox->setDecimals(7);
        point9xValuesDoubleSpinBox->setMinimum(-99999.999999000006937);
        point9xValuesDoubleSpinBox->setMaximum(99999.999999000006937);

        gridLayout->addWidget(point9xValuesDoubleSpinBox, 9, 1, 1, 1);

        point2ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point2ReadChannelSpinBox->setObjectName(QString::fromUtf8("point2ReadChannelSpinBox"));
        point2ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point2ReadChannelSpinBox, 2, 4, 1, 1);

        point9ReadChannelSpinBox = new QSpinBox(ChannelCalibrationWindow);
        point9ReadChannelSpinBox->setObjectName(QString::fromUtf8("point9ReadChannelSpinBox"));
        point9ReadChannelSpinBox->setEnabled(false);
        point9ReadChannelSpinBox->setMaximum(7);

        gridLayout->addWidget(point9ReadChannelSpinBox, 9, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        slopeLabel = new QLabel(ChannelCalibrationWindow);
        slopeLabel->setObjectName(QString::fromUtf8("slopeLabel"));

        horizontalLayout_3->addWidget(slopeLabel);

        slopeLabelDynamic = new QLabel(ChannelCalibrationWindow);
        slopeLabelDynamic->setObjectName(QString::fromUtf8("slopeLabelDynamic"));

        horizontalLayout_3->addWidget(slopeLabelDynamic);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        yinterceptLabel = new QLabel(ChannelCalibrationWindow);
        yinterceptLabel->setObjectName(QString::fromUtf8("yinterceptLabel"));

        horizontalLayout_4->addWidget(yinterceptLabel);

        yinterceptLabelDynamic = new QLabel(ChannelCalibrationWindow);
        yinterceptLabelDynamic->setObjectName(QString::fromUtf8("yinterceptLabelDynamic"));

        horizontalLayout_4->addWidget(yinterceptLabelDynamic);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        calibrateButton = new QPushButton(ChannelCalibrationWindow);
        calibrateButton->setObjectName(QString::fromUtf8("calibrateButton"));

        horizontalLayout_5->addWidget(calibrateButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(ChannelCalibrationWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(ChannelCalibrationWindow);

        QMetaObject::connectSlotsByName(ChannelCalibrationWindow);
    } // setupUi

    void retranslateUi(QWidget *ChannelCalibrationWindow)
    {
        ChannelCalibrationWindow->setWindowTitle(QCoreApplication::translate("ChannelCalibrationWindow", "ChannelCalibrationWindow", nullptr));
        currentChannelLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Channel:", nullptr));
        currentChannelLabelDynamic->setText(QCoreApplication::translate("ChannelCalibrationWindow", "<channelNum>", nullptr));
        dataPointsLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Number of data points to be used:", nullptr));
        point1Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 1:", nullptr));
        point4ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point8Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 8:", nullptr));
        point5ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        yValuesLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "y-values (<unit>)", nullptr));
        point10Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 10:", nullptr));
        point6Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 6:", nullptr));
        point9ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point8ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point1ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point3ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        xValuesLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "x-values (V)", nullptr));
        point5Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 5:", nullptr));
        readChanneLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Channel to read from (optional)", nullptr));
        point6ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point7ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point9Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 9:", nullptr));
        point2ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point3Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 3:", nullptr));
        point4Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 4:", nullptr));
        point10ReadChannelButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Read V from DAQ", nullptr));
        point7Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 7:", nullptr));
        point2Label->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Point 2:", nullptr));
        slopeLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Slope:", nullptr));
        slopeLabelDynamic->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Not calculated", nullptr));
        yinterceptLabel->setText(QCoreApplication::translate("ChannelCalibrationWindow", "y-intercept:", nullptr));
        yinterceptLabelDynamic->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Not calculated", nullptr));
        calibrateButton->setText(QCoreApplication::translate("ChannelCalibrationWindow", "Calibrate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChannelCalibrationWindow: public Ui_ChannelCalibrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELCALIBRATIONWINDOW_H
