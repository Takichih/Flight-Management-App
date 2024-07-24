/********************************************************************************
** Form generated from reading UI file 'Airport_Table.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRPORT_TABLE_H
#define UI_AIRPORT_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirportTable
{
public:
    QAction *actionDelete_Flight;
    QAction *actionClose;
    QAction *actionDeparture;
    QAction *actionArrival;
    QWidget *centralwidget;
    QTextEdit *textEditAir;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAdd_Flight;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AirportTable)
    {
        if (AirportTable->objectName().isEmpty())
            AirportTable->setObjectName(QString::fromUtf8("AirportTable"));
        AirportTable->resize(800, 600);
        actionDelete_Flight = new QAction(AirportTable);
        actionDelete_Flight->setObjectName(QString::fromUtf8("actionDelete_Flight"));
        actionClose = new QAction(AirportTable);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionDeparture = new QAction(AirportTable);
        actionDeparture->setObjectName(QString::fromUtf8("actionDeparture"));
        actionArrival = new QAction(AirportTable);
        actionArrival->setObjectName(QString::fromUtf8("actionArrival"));
        centralwidget = new QWidget(AirportTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditAir = new QTextEdit(centralwidget);
        textEditAir->setObjectName(QString::fromUtf8("textEditAir"));
        textEditAir->setGeometry(QRect(10, 0, 681, 451));
        textEditAir->setStyleSheet(QString::fromUtf8("font: oblique 10pt \"Monospace\";"));
        AirportTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AirportTable);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAdd_Flight = new QMenu(menuMenu);
        menuAdd_Flight->setObjectName(QString::fromUtf8("menuAdd_Flight"));
        AirportTable->setMenuBar(menubar);
        statusbar = new QStatusBar(AirportTable);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AirportTable->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAdd_Flight->menuAction());
        menuMenu->addAction(actionDelete_Flight);
        menuMenu->addAction(actionClose);
        menuAdd_Flight->addAction(actionDeparture);
        menuAdd_Flight->addAction(actionArrival);

        retranslateUi(AirportTable);
        QObject::connect(actionClose, SIGNAL(triggered()), AirportTable, SLOT(close()));
        QObject::connect(actionDeparture, SIGNAL(triggered()), AirportTable, SLOT(slotDeparture()));
        QObject::connect(actionArrival, SIGNAL(triggered()), AirportTable, SLOT(slotArrival()));
        QObject::connect(actionDelete_Flight, SIGNAL(triggered()), AirportTable, SLOT(slotDeleteFlight()));

        QMetaObject::connectSlotsByName(AirportTable);
    } // setupUi

    void retranslateUi(QMainWindow *AirportTable)
    {
        AirportTable->setWindowTitle(QCoreApplication::translate("AirportTable", "TableauAeroport", nullptr));
        actionDelete_Flight->setText(QCoreApplication::translate("AirportTable", "Delete", nullptr));
        actionClose->setText(QCoreApplication::translate("AirportTable", "Close", nullptr));
        actionDeparture->setText(QCoreApplication::translate("AirportTable", "Departure", nullptr));
        actionArrival->setText(QCoreApplication::translate("AirportTable", "Arrival", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("AirportTable", "Menu", nullptr));
        menuAdd_Flight->setTitle(QCoreApplication::translate("AirportTable", "Add ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirportTable: public Ui_AirportTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRPORT_TABLE_H
