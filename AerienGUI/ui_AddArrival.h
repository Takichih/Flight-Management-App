/********************************************************************************
** Form generated from reading UI file 'AddArrival.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDARRIVAL_H
#define UI_ADDARRIVAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddArrival
{
public:
    QLineEdit *lineEditNumber;
    QPushButton *pushButton;
    QLabel *Number;
    QLabel *Company;
    QLineEdit *lineEditCompany;
    QLabel *Hour;
    QLineEdit *lineEditHour;
    QLabel *Status;
    QLineEdit *lineEditStatus;
    QLabel *City;
    QLineEdit *lineEditCity;

    void setupUi(QDialog *AddArrival)
    {
        if (AddArrival->objectName().isEmpty())
            AddArrival->setObjectName(QString::fromUtf8("AddArrival"));
        AddArrival->resize(378, 415);
        lineEditNumber = new QLineEdit(AddArrival);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumber"));
        lineEditNumber->setGeometry(QRect(190, 40, 113, 31));
        pushButton = new QPushButton(AddArrival);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 320, 101, 31));
        Number = new QLabel(AddArrival);
        Number->setObjectName(QString::fromUtf8("Number"));
        Number->setGeometry(QRect(40, 39, 151, 31));
        Company = new QLabel(AddArrival);
        Company->setObjectName(QString::fromUtf8("Company"));
        Company->setGeometry(QRect(40, 89, 151, 31));
        lineEditCompany = new QLineEdit(AddArrival);
        lineEditCompany->setObjectName(QString::fromUtf8("lineEditCompany"));
        lineEditCompany->setGeometry(QRect(190, 90, 111, 31));
        Hour = new QLabel(AddArrival);
        Hour->setObjectName(QString::fromUtf8("Hour"));
        Hour->setGeometry(QRect(40, 139, 151, 31));
        lineEditHour = new QLineEdit(AddArrival);
        lineEditHour->setObjectName(QString::fromUtf8("lineEditHour"));
        lineEditHour->setGeometry(QRect(190, 140, 113, 31));
        Status = new QLabel(AddArrival);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setGeometry(QRect(40, 239, 151, 31));
        lineEditStatus = new QLineEdit(AddArrival);
        lineEditStatus->setObjectName(QString::fromUtf8("lineEditStatus"));
        lineEditStatus->setGeometry(QRect(190, 240, 113, 31));
        City = new QLabel(AddArrival);
        City->setObjectName(QString::fromUtf8("City"));
        City->setGeometry(QRect(40, 189, 151, 31));
        lineEditCity = new QLineEdit(AddArrival);
        lineEditCity->setObjectName(QString::fromUtf8("lineEditCity"));
        lineEditCity->setGeometry(QRect(190, 190, 113, 31));

        retranslateUi(AddArrival);
        QObject::connect(pushButton, SIGNAL(clicked()), AddArrival, SLOT(slotConfirmeArrival()));

        QMetaObject::connectSlotsByName(AddArrival);
    } // setupUi

    void retranslateUi(QDialog *AddArrival)
    {
        AddArrival->setWindowTitle(QCoreApplication::translate("AddArrival", "AddArrival", nullptr));
        lineEditNumber->setText(QCoreApplication::translate("AddArrival", "LH0472", nullptr));
        pushButton->setText(QCoreApplication::translate("AddArrival", "Confirmer", nullptr));
        Number->setText(QCoreApplication::translate("AddArrival", "Flight Number :", nullptr));
        Company->setText(QCoreApplication::translate("AddArrival", "Company :", nullptr));
        lineEditCompany->setText(QCoreApplication::translate("AddArrival", "LUFTHANSA", nullptr));
        Hour->setText(QCoreApplication::translate("AddArrival", "Hour :", nullptr));
        lineEditHour->setText(QCoreApplication::translate("AddArrival", "22:05", nullptr));
        Status->setText(QCoreApplication::translate("AddArrival", "Status :", nullptr));
        lineEditStatus->setText(QCoreApplication::translate("AddArrival", " Retard\303\251 ", nullptr));
        City->setText(QCoreApplication::translate("AddArrival", "City :", nullptr));
        lineEditCity->setText(QCoreApplication::translate("AddArrival", "MUNICH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddArrival: public Ui_AddArrival {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDARRIVAL_H
