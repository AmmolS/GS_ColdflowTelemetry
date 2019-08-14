/********************************************************************************
** Form generated from reading UI file 'GS_ColdflowTelemetryGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_COLDFLOWTELEMETRYGUI_H
#define UI_GS_COLDFLOWTELEMETRYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GS_ColdflowTelemetryGUIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *DAQStatusBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *currentStateLabel;
    QLabel *currentStateLabelDynamic;
    QHBoxLayout *horizontalLayout_7;
    QLabel *channelsSetLabel;
    QLabel *channelsSetLabelDynamic;
    QHBoxLayout *horizontalLayout_8;
    QLabel *unitsSetLabel;
    QLabel *unitsSetLabelDynamic;
    QHBoxLayout *horizontalLayout_17;
    QLabel *calibrationDoneLabel;
    QLabel *calibrationDoneLabelDynamic;
    QHBoxLayout *horizontalLayout_9;
    QLabel *collectingDataLabel;
    QLabel *collectingDataLabelDynamic;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *boardNumLabel;
    QLineEdit *boardNumInput;
    QPushButton *validateDAQButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lowerChannelLabel;
    QLineEdit *lowerChannelInput;
    QHBoxLayout *horizontalLayout_3;
    QLabel *higherChannelLabel;
    QLineEdit *higherChannelInput;
    QHBoxLayout *horizontalLayout_4;
    QLabel *channelsStatusLabelDynamic;
    QPushButton *confirmChannelsButton;
    QFrame *channelUnitsFrame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *channel6CalibrateButton;
    QPushButton *channel5CalibrateButton;
    QLabel *channel6Label;
    QLineEdit *channel3UnitInput;
    QPushButton *channel2CalibrateButton;
    QPushButton *channel0CalibrateButton;
    QLabel *channelUnitLabel;
    QLineEdit *channel2UnitInput;
    QLineEdit *channel5UnitInput;
    QLineEdit *channel4UnitInput;
    QLabel *channel5Label;
    QLabel *channel7Label;
    QLineEdit *channel6UnitInput;
    QLabel *channel0Label;
    QLineEdit *channel7UnitInput;
    QPushButton *channel3CalibrateButton;
    QLineEdit *channel0UnitInput;
    QPushButton *channel4CalibrateButton;
    QLabel *channel3Label;
    QLabel *channel2Label;
    QLabel *channel1Label;
    QLabel *channel4Label;
    QPushButton *channel7CalibrateButton;
    QLineEdit *channel1UnitInput;
    QPushButton *channel1CalibrateButton;
    QLabel *channel0SelectedUnitLabelDynamic;
    QLabel *channelSelectedUnitLabel;
    QLabel *channel1SelectedUnitLabelDynamic;
    QLabel *channel2SelectedUnitLabelDynamic;
    QLabel *channel3SelectedUnitLabelDynamic;
    QLabel *channel4SelectedUnitLabelDynamic;
    QLabel *channel5SelectedUnitLabelDynamic;
    QLabel *channel6SelectedUnitLabelDynamic;
    QLabel *channel7SelectedUnitLabelDynamic;
    QHBoxLayout *horizontalLayout_5;
    QLabel *channelsUnitLabelDynamic;
    QPushButton *confirmUnitsButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GS_ColdflowTelemetryGUIClass)
    {
        if (GS_ColdflowTelemetryGUIClass->objectName().isEmpty())
            GS_ColdflowTelemetryGUIClass->setObjectName(QString::fromUtf8("GS_ColdflowTelemetryGUIClass"));
        GS_ColdflowTelemetryGUIClass->setEnabled(true);
        GS_ColdflowTelemetryGUIClass->resize(503, 273);
        centralWidget = new QWidget(GS_ColdflowTelemetryGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DAQStatusBox = new QGroupBox(centralWidget);
        DAQStatusBox->setObjectName(QString::fromUtf8("DAQStatusBox"));
        verticalLayout_3 = new QVBoxLayout(DAQStatusBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        currentStateLabel = new QLabel(DAQStatusBox);
        currentStateLabel->setObjectName(QString::fromUtf8("currentStateLabel"));

        horizontalLayout_6->addWidget(currentStateLabel);

        currentStateLabelDynamic = new QLabel(DAQStatusBox);
        currentStateLabelDynamic->setObjectName(QString::fromUtf8("currentStateLabelDynamic"));

        horizontalLayout_6->addWidget(currentStateLabelDynamic);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        channelsSetLabel = new QLabel(DAQStatusBox);
        channelsSetLabel->setObjectName(QString::fromUtf8("channelsSetLabel"));

        horizontalLayout_7->addWidget(channelsSetLabel);

        channelsSetLabelDynamic = new QLabel(DAQStatusBox);
        channelsSetLabelDynamic->setObjectName(QString::fromUtf8("channelsSetLabelDynamic"));

        horizontalLayout_7->addWidget(channelsSetLabelDynamic);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        unitsSetLabel = new QLabel(DAQStatusBox);
        unitsSetLabel->setObjectName(QString::fromUtf8("unitsSetLabel"));

        horizontalLayout_8->addWidget(unitsSetLabel);

        unitsSetLabelDynamic = new QLabel(DAQStatusBox);
        unitsSetLabelDynamic->setObjectName(QString::fromUtf8("unitsSetLabelDynamic"));

        horizontalLayout_8->addWidget(unitsSetLabelDynamic);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        calibrationDoneLabel = new QLabel(DAQStatusBox);
        calibrationDoneLabel->setObjectName(QString::fromUtf8("calibrationDoneLabel"));

        horizontalLayout_17->addWidget(calibrationDoneLabel);

        calibrationDoneLabelDynamic = new QLabel(DAQStatusBox);
        calibrationDoneLabelDynamic->setObjectName(QString::fromUtf8("calibrationDoneLabelDynamic"));

        horizontalLayout_17->addWidget(calibrationDoneLabelDynamic);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        collectingDataLabel = new QLabel(DAQStatusBox);
        collectingDataLabel->setObjectName(QString::fromUtf8("collectingDataLabel"));

        horizontalLayout_9->addWidget(collectingDataLabel);

        collectingDataLabelDynamic = new QLabel(DAQStatusBox);
        collectingDataLabelDynamic->setObjectName(QString::fromUtf8("collectingDataLabelDynamic"));

        horizontalLayout_9->addWidget(collectingDataLabelDynamic);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_2->addWidget(DAQStatusBox);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        boardNumLabel = new QLabel(frame);
        boardNumLabel->setObjectName(QString::fromUtf8("boardNumLabel"));

        horizontalLayout->addWidget(boardNumLabel);

        boardNumInput = new QLineEdit(frame);
        boardNumInput->setObjectName(QString::fromUtf8("boardNumInput"));

        horizontalLayout->addWidget(boardNumInput);

        validateDAQButton = new QPushButton(frame);
        validateDAQButton->setObjectName(QString::fromUtf8("validateDAQButton"));

        horizontalLayout->addWidget(validateDAQButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lowerChannelLabel = new QLabel(frame);
        lowerChannelLabel->setObjectName(QString::fromUtf8("lowerChannelLabel"));
        lowerChannelLabel->setEnabled(false);

        horizontalLayout_2->addWidget(lowerChannelLabel);

        lowerChannelInput = new QLineEdit(frame);
        lowerChannelInput->setObjectName(QString::fromUtf8("lowerChannelInput"));
        lowerChannelInput->setEnabled(false);

        horizontalLayout_2->addWidget(lowerChannelInput);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        higherChannelLabel = new QLabel(frame);
        higherChannelLabel->setObjectName(QString::fromUtf8("higherChannelLabel"));
        higherChannelLabel->setEnabled(false);

        horizontalLayout_3->addWidget(higherChannelLabel);

        higherChannelInput = new QLineEdit(frame);
        higherChannelInput->setObjectName(QString::fromUtf8("higherChannelInput"));
        higherChannelInput->setEnabled(false);

        horizontalLayout_3->addWidget(higherChannelInput);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        channelsStatusLabelDynamic = new QLabel(frame);
        channelsStatusLabelDynamic->setObjectName(QString::fromUtf8("channelsStatusLabelDynamic"));
        channelsStatusLabelDynamic->setEnabled(false);

        horizontalLayout_4->addWidget(channelsStatusLabelDynamic);

        confirmChannelsButton = new QPushButton(frame);
        confirmChannelsButton->setObjectName(QString::fromUtf8("confirmChannelsButton"));
        confirmChannelsButton->setEnabled(false);

        horizontalLayout_4->addWidget(confirmChannelsButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(frame);


        horizontalLayout_10->addLayout(verticalLayout_2);

        channelUnitsFrame = new QFrame(centralWidget);
        channelUnitsFrame->setObjectName(QString::fromUtf8("channelUnitsFrame"));
        channelUnitsFrame->setEnabled(false);
        channelUnitsFrame->setFrameShape(QFrame::StyledPanel);
        channelUnitsFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(channelUnitsFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        channel6CalibrateButton = new QPushButton(channelUnitsFrame);
        channel6CalibrateButton->setObjectName(QString::fromUtf8("channel6CalibrateButton"));
        channel6CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel6CalibrateButton, 7, 3, 1, 1);

        channel5CalibrateButton = new QPushButton(channelUnitsFrame);
        channel5CalibrateButton->setObjectName(QString::fromUtf8("channel5CalibrateButton"));
        channel5CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel5CalibrateButton, 6, 3, 1, 1);

        channel6Label = new QLabel(channelUnitsFrame);
        channel6Label->setObjectName(QString::fromUtf8("channel6Label"));

        gridLayout->addWidget(channel6Label, 7, 0, 1, 1);

        channel3UnitInput = new QLineEdit(channelUnitsFrame);
        channel3UnitInput->setObjectName(QString::fromUtf8("channel3UnitInput"));

        gridLayout->addWidget(channel3UnitInput, 4, 1, 1, 1);

        channel2CalibrateButton = new QPushButton(channelUnitsFrame);
        channel2CalibrateButton->setObjectName(QString::fromUtf8("channel2CalibrateButton"));
        channel2CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel2CalibrateButton, 3, 3, 1, 1);

        channel0CalibrateButton = new QPushButton(channelUnitsFrame);
        channel0CalibrateButton->setObjectName(QString::fromUtf8("channel0CalibrateButton"));
        channel0CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel0CalibrateButton, 1, 3, 1, 1);

        channelUnitLabel = new QLabel(channelUnitsFrame);
        channelUnitLabel->setObjectName(QString::fromUtf8("channelUnitLabel"));

        gridLayout->addWidget(channelUnitLabel, 0, 1, 1, 1);

        channel2UnitInput = new QLineEdit(channelUnitsFrame);
        channel2UnitInput->setObjectName(QString::fromUtf8("channel2UnitInput"));

        gridLayout->addWidget(channel2UnitInput, 3, 1, 1, 1);

        channel5UnitInput = new QLineEdit(channelUnitsFrame);
        channel5UnitInput->setObjectName(QString::fromUtf8("channel5UnitInput"));

        gridLayout->addWidget(channel5UnitInput, 6, 1, 1, 1);

        channel4UnitInput = new QLineEdit(channelUnitsFrame);
        channel4UnitInput->setObjectName(QString::fromUtf8("channel4UnitInput"));

        gridLayout->addWidget(channel4UnitInput, 5, 1, 1, 1);

        channel5Label = new QLabel(channelUnitsFrame);
        channel5Label->setObjectName(QString::fromUtf8("channel5Label"));

        gridLayout->addWidget(channel5Label, 6, 0, 1, 1);

        channel7Label = new QLabel(channelUnitsFrame);
        channel7Label->setObjectName(QString::fromUtf8("channel7Label"));

        gridLayout->addWidget(channel7Label, 8, 0, 1, 1);

        channel6UnitInput = new QLineEdit(channelUnitsFrame);
        channel6UnitInput->setObjectName(QString::fromUtf8("channel6UnitInput"));

        gridLayout->addWidget(channel6UnitInput, 7, 1, 1, 1);

        channel0Label = new QLabel(channelUnitsFrame);
        channel0Label->setObjectName(QString::fromUtf8("channel0Label"));

        gridLayout->addWidget(channel0Label, 1, 0, 1, 1);

        channel7UnitInput = new QLineEdit(channelUnitsFrame);
        channel7UnitInput->setObjectName(QString::fromUtf8("channel7UnitInput"));

        gridLayout->addWidget(channel7UnitInput, 8, 1, 1, 1);

        channel3CalibrateButton = new QPushButton(channelUnitsFrame);
        channel3CalibrateButton->setObjectName(QString::fromUtf8("channel3CalibrateButton"));
        channel3CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel3CalibrateButton, 4, 3, 1, 1);

        channel0UnitInput = new QLineEdit(channelUnitsFrame);
        channel0UnitInput->setObjectName(QString::fromUtf8("channel0UnitInput"));

        gridLayout->addWidget(channel0UnitInput, 1, 1, 1, 1);

        channel4CalibrateButton = new QPushButton(channelUnitsFrame);
        channel4CalibrateButton->setObjectName(QString::fromUtf8("channel4CalibrateButton"));
        channel4CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel4CalibrateButton, 5, 3, 1, 1);

        channel3Label = new QLabel(channelUnitsFrame);
        channel3Label->setObjectName(QString::fromUtf8("channel3Label"));

        gridLayout->addWidget(channel3Label, 4, 0, 1, 1);

        channel2Label = new QLabel(channelUnitsFrame);
        channel2Label->setObjectName(QString::fromUtf8("channel2Label"));

        gridLayout->addWidget(channel2Label, 3, 0, 1, 1);

        channel1Label = new QLabel(channelUnitsFrame);
        channel1Label->setObjectName(QString::fromUtf8("channel1Label"));

        gridLayout->addWidget(channel1Label, 2, 0, 1, 1);

        channel4Label = new QLabel(channelUnitsFrame);
        channel4Label->setObjectName(QString::fromUtf8("channel4Label"));

        gridLayout->addWidget(channel4Label, 5, 0, 1, 1);

        channel7CalibrateButton = new QPushButton(channelUnitsFrame);
        channel7CalibrateButton->setObjectName(QString::fromUtf8("channel7CalibrateButton"));
        channel7CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel7CalibrateButton, 8, 3, 1, 1);

        channel1UnitInput = new QLineEdit(channelUnitsFrame);
        channel1UnitInput->setObjectName(QString::fromUtf8("channel1UnitInput"));

        gridLayout->addWidget(channel1UnitInput, 2, 1, 1, 1);

        channel1CalibrateButton = new QPushButton(channelUnitsFrame);
        channel1CalibrateButton->setObjectName(QString::fromUtf8("channel1CalibrateButton"));
        channel1CalibrateButton->setEnabled(false);

        gridLayout->addWidget(channel1CalibrateButton, 2, 3, 1, 1);

        channel0SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel0SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel0SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel0SelectedUnitLabelDynamic, 1, 2, 1, 1);

        channelSelectedUnitLabel = new QLabel(channelUnitsFrame);
        channelSelectedUnitLabel->setObjectName(QString::fromUtf8("channelSelectedUnitLabel"));

        gridLayout->addWidget(channelSelectedUnitLabel, 0, 2, 1, 1);

        channel1SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel1SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel1SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel1SelectedUnitLabelDynamic, 2, 2, 1, 1);

        channel2SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel2SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel2SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel2SelectedUnitLabelDynamic, 3, 2, 1, 1);

        channel3SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel3SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel3SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel3SelectedUnitLabelDynamic, 4, 2, 1, 1);

        channel4SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel4SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel4SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel4SelectedUnitLabelDynamic, 5, 2, 1, 1);

        channel5SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel5SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel5SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel5SelectedUnitLabelDynamic, 6, 2, 1, 1);

        channel6SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel6SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel6SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel6SelectedUnitLabelDynamic, 7, 2, 1, 1);

        channel7SelectedUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channel7SelectedUnitLabelDynamic->setObjectName(QString::fromUtf8("channel7SelectedUnitLabelDynamic"));

        gridLayout->addWidget(channel7SelectedUnitLabelDynamic, 8, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        channelsUnitLabelDynamic = new QLabel(channelUnitsFrame);
        channelsUnitLabelDynamic->setObjectName(QString::fromUtf8("channelsUnitLabelDynamic"));

        horizontalLayout_5->addWidget(channelsUnitLabelDynamic);

        confirmUnitsButton = new QPushButton(channelUnitsFrame);
        confirmUnitsButton->setObjectName(QString::fromUtf8("confirmUnitsButton"));

        horizontalLayout_5->addWidget(confirmUnitsButton);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        horizontalLayout_10->addWidget(channelUnitsFrame);

        GS_ColdflowTelemetryGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GS_ColdflowTelemetryGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 503, 18));
        GS_ColdflowTelemetryGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GS_ColdflowTelemetryGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GS_ColdflowTelemetryGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GS_ColdflowTelemetryGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GS_ColdflowTelemetryGUIClass->setStatusBar(statusBar);
        QWidget::setTabOrder(validateDAQButton, lowerChannelInput);
        QWidget::setTabOrder(lowerChannelInput, higherChannelInput);

        retranslateUi(GS_ColdflowTelemetryGUIClass);

        QMetaObject::connectSlotsByName(GS_ColdflowTelemetryGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GS_ColdflowTelemetryGUIClass)
    {
        GS_ColdflowTelemetryGUIClass->setWindowTitle(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "GS_ColdflowTelemetryGUI", nullptr));
        DAQStatusBox->setTitle(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "DAQ Status", nullptr));
        currentStateLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Current state:", nullptr));
        currentStateLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "DAQ disconnected", nullptr));
        channelsSetLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channels set:", nullptr));
        channelsSetLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "False", nullptr));
        unitsSetLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Units set: ", nullptr));
        unitsSetLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "False", nullptr));
        calibrationDoneLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Calibrated: ", nullptr));
        calibrationDoneLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "False", nullptr));
        collectingDataLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Collecting data:", nullptr));
        collectingDataLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "False", nullptr));
        boardNumLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Board Number", nullptr));
        boardNumInput->setInputMask(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "9", nullptr));
        validateDAQButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Validate DAQ", nullptr));
        lowerChannelLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Lower Channel", nullptr));
        higherChannelLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Higher Channel", nullptr));
        channelsStatusLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Enter a range of channels above", nullptr));
        confirmChannelsButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Confirm Channels", nullptr));
        channel6CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel5CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel6Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 6", nullptr));
        channel2CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel0CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channelUnitLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Entered unit", nullptr));
        channel5Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 5", nullptr));
        channel7Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 7", nullptr));
        channel0Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 0", nullptr));
        channel3CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel4CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel3Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 3", nullptr));
        channel2Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 2", nullptr));
        channel1Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 1", nullptr));
        channel4Label->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Channel 4", nullptr));
        channel7CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel1CalibrateButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not Calibrated", nullptr));
        channel0SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channelSelectedUnitLabel->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Selected unit", nullptr));
        channel1SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel2SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel3SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel4SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel5SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel6SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channel7SelectedUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Not set", nullptr));
        channelsUnitLabelDynamic->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Enter the units that will be measured above", nullptr));
        confirmUnitsButton->setText(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "Confirm Units", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GS_ColdflowTelemetryGUIClass: public Ui_GS_ColdflowTelemetryGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_COLDFLOWTELEMETRYGUI_H
