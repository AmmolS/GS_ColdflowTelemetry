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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GS_ColdflowTelemetryGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GS_ColdflowTelemetryGUIClass)
    {
        if (GS_ColdflowTelemetryGUIClass->objectName().isEmpty())
            GS_ColdflowTelemetryGUIClass->setObjectName(QString::fromUtf8("GS_ColdflowTelemetryGUIClass"));
        GS_ColdflowTelemetryGUIClass->resize(600, 400);
        menuBar = new QMenuBar(GS_ColdflowTelemetryGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GS_ColdflowTelemetryGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GS_ColdflowTelemetryGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GS_ColdflowTelemetryGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GS_ColdflowTelemetryGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GS_ColdflowTelemetryGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GS_ColdflowTelemetryGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GS_ColdflowTelemetryGUIClass->setStatusBar(statusBar);

        retranslateUi(GS_ColdflowTelemetryGUIClass);

        QMetaObject::connectSlotsByName(GS_ColdflowTelemetryGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GS_ColdflowTelemetryGUIClass)
    {
        GS_ColdflowTelemetryGUIClass->setWindowTitle(QCoreApplication::translate("GS_ColdflowTelemetryGUIClass", "GS_ColdflowTelemetryGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GS_ColdflowTelemetryGUIClass: public Ui_GS_ColdflowTelemetryGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_COLDFLOWTELEMETRYGUI_H
