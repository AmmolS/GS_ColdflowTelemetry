#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GS_ColdflowTelemetryGUI.h"

class GS_ColdflowTelemetryGUI : public QMainWindow
{
	Q_OBJECT

public:
	GS_ColdflowTelemetryGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::GS_ColdflowTelemetryGUIClass ui;
};
