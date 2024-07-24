/********************************************************************************
** Form generated from reading UI file 'AddDeparture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEPARTURE_H
#define UI_ADDDEPARTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddDeparture
{
public:
    QPushButton *ButtonConfirmer;
    QLabel *labelNumber;
    QLineEdit *lineEditNumber;
    QLabel *labelCompany;
    QLineEdit *lineEditCompany;
    QLabel *labelHour;
    QLineEdit *lineEditHour;
    QLabel *labelCity;
    QLineEdit *lineEditCity;
    QLabel *labelBoardingGate;
    QLabel *labelBoardingHour;
    QLineEdit *lineEditBoardingHour;
    QLineEdit *lineEditBoardingGate;

    void setupUi(QDialog *AddDeparture)
    {
        if (AddDeparture->objectName().isEmpty())
            AddDeparture->setObjectName(QString::fromUtf8("AddDeparture"));
        AddDeparture->resize(400, 391);
        ButtonConfirmer = new QPushButton(AddDeparture);
        ButtonConfirmer->setObjectName(QString::fromUtf8("ButtonConfirmer"));
        ButtonConfirmer->setGeometry(QRect(140, 330, 90, 31));
        labelNumber = new QLabel(AddDeparture);
        labelNumber->setObjectName(QString::fromUtf8("labelNumber"));
        labelNumber->setGeometry(QRect(40, 30, 101, 16));
        lineEditNumber = new QLineEdit(AddDeparture);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumber"));
        lineEditNumber->setGeometry(QRect(210, 20, 113, 28));
        labelCompany = new QLabel(AddDeparture);
        labelCompany->setObjectName(QString::fromUtf8("labelCompany"));
        labelCompany->setGeometry(QRect(40, 80, 101, 16));
        lineEditCompany = new QLineEdit(AddDeparture);
        lineEditCompany->setObjectName(QString::fromUtf8("lineEditCompany"));
        lineEditCompany->setGeometry(QRect(210, 70, 113, 28));
        labelHour = new QLabel(AddDeparture);
        labelHour->setObjectName(QString::fromUtf8("labelHour"));
        labelHour->setGeometry(QRect(40, 130, 101, 16));
        lineEditHour = new QLineEdit(AddDeparture);
        lineEditHour->setObjectName(QString::fromUtf8("lineEditHour"));
        lineEditHour->setGeometry(QRect(210, 120, 113, 28));
        labelCity = new QLabel(AddDeparture);
        labelCity->setObjectName(QString::fromUtf8("labelCity"));
        labelCity->setGeometry(QRect(40, 180, 101, 16));
        lineEditCity = new QLineEdit(AddDeparture);
        lineEditCity->setObjectName(QString::fromUtf8("lineEditCity"));
        lineEditCity->setGeometry(QRect(210, 170, 113, 28));
        labelBoardingGate = new QLabel(AddDeparture);
        labelBoardingGate->setObjectName(QString::fromUtf8("labelBoardingGate"));
        labelBoardingGate->setGeometry(QRect(40, 230, 141, 16));
        labelBoardingHour = new QLabel(AddDeparture);
        labelBoardingHour->setObjectName(QString::fromUtf8("labelBoardingHour"));
        labelBoardingHour->setGeometry(QRect(40, 280, 141, 16));
        lineEditBoardingHour = new QLineEdit(AddDeparture);
        lineEditBoardingHour->setObjectName(QString::fromUtf8("lineEditBoardingHour"));
        lineEditBoardingHour->setGeometry(QRect(210, 270, 113, 28));
        lineEditBoardingGate = new QLineEdit(AddDeparture);
        lineEditBoardingGate->setObjectName(QString::fromUtf8("lineEditBoardingGate"));
        lineEditBoardingGate->setGeometry(QRect(210, 220, 113, 28));

        retranslateUi(AddDeparture);
        QObject::connect(ButtonConfirmer, SIGNAL(clicked()), AddDeparture, SLOT(slotConfirmeDeparture()));

        QMetaObject::connectSlotsByName(AddDeparture);
    } // setupUi

    void retranslateUi(QDialog *AddDeparture)
    {
        AddDeparture->setWindowTitle(QCoreApplication::translate("AddDeparture", "Add Departure", nullptr));
        ButtonConfirmer->setText(QCoreApplication::translate("AddDeparture", "Confirmer", nullptr));
        labelNumber->setText(QCoreApplication::translate("AddDeparture", "Flight Number", nullptr));
        lineEditNumber->setText(QCoreApplication::translate("AddDeparture", "AC1234", nullptr));
        labelCompany->setText(QCoreApplication::translate("AddDeparture", "Company", nullptr));
        lineEditCompany->setText(QCoreApplication::translate("AddDeparture", "AIR UL", nullptr));
        labelHour->setText(QCoreApplication::translate("AddDeparture", "Hour", nullptr));
        lineEditHour->setText(QCoreApplication::translate("AddDeparture", "18:00", nullptr));
        labelCity->setText(QCoreApplication::translate("AddDeparture", "City", nullptr));
        lineEditCity->setText(QCoreApplication::translate("AddDeparture", "TORONTO", nullptr));
        labelBoardingGate->setText(QCoreApplication::translate("AddDeparture", "Boarding Gate", nullptr));
        labelBoardingHour->setText(QCoreApplication::translate("AddDeparture", "Boarding Time", nullptr));
        lineEditBoardingHour->setText(QCoreApplication::translate("AddDeparture", "17:59", nullptr));
        lineEditBoardingGate->setText(QCoreApplication::translate("AddDeparture", "Z99", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDeparture: public Ui_AddDeparture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEPARTURE_H
