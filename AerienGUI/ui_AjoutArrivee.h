/********************************************************************************
** Form generated from reading UI file 'AjoutArrivee.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTARRIVEE_H
#define UI_AJOUTARRIVEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutArrivee
{
public:
    QLineEdit *lineEditNumber;
    QPushButton *pushButton;
    QLabel *Numero;
    QLabel *Compagnie;
    QLineEdit *lineEditCompany;
    QLabel *Heure;
    QLineEdit *lineEdithour;
    QLabel *Statut;
    QLineEdit *lineEditStatus;
    QLabel *Ville;
    QLineEdit *lineEditCity;

    void setupUi(QDialog *AjoutArrivee)
    {
        if (AjoutArrivee->objectName().isEmpty())
            AjoutArrivee->setObjectName(QString::fromUtf8("AjoutArrivee"));
        AjoutArrivee->resize(378, 415);
        lineEditNumber = new QLineEdit(AjoutArrivee);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumero"));
        lineEditNumber->setGeometry(QRect(190, 40, 113, 31));
        pushButton = new QPushButton(AjoutArrivee);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 320, 101, 31));
        Numero = new QLabel(AjoutArrivee);
        Numero->setObjectName(QString::fromUtf8("Numero"));
        Numero->setGeometry(QRect(40, 39, 151, 31));
        Compagnie = new QLabel(AjoutArrivee);
        Compagnie->setObjectName(QString::fromUtf8("Compagnie"));
        Compagnie->setGeometry(QRect(40, 89, 151, 31));
        lineEditCompany = new QLineEdit(AjoutArrivee);
        lineEditCompany->setObjectName(QString::fromUtf8("lineEditCompagnie"));
        lineEditCompany->setGeometry(QRect(190, 90, 111, 31));
        Heure = new QLabel(AjoutArrivee);
        Heure->setObjectName(QString::fromUtf8("Heure"));
        Heure->setGeometry(QRect(40, 139, 151, 31));
        lineEdithour = new QLineEdit(AjoutArrivee);
        lineEdithour->setObjectName(QString::fromUtf8("lineEditHeure"));
        lineEdithour->setGeometry(QRect(190, 140, 113, 31));
        Statut = new QLabel(AjoutArrivee);
        Statut->setObjectName(QString::fromUtf8("Statut"));
        Statut->setGeometry(QRect(40, 239, 151, 31));
        lineEditStatus = new QLineEdit(AjoutArrivee);
        lineEditStatus->setObjectName(QString::fromUtf8("lineEditStatut"));
        lineEditStatus->setGeometry(QRect(190, 240, 113, 31));
        Ville = new QLabel(AjoutArrivee);
        Ville->setObjectName(QString::fromUtf8("Ville"));
        Ville->setGeometry(QRect(40, 189, 151, 31));
        lineEditCity = new QLineEdit(AjoutArrivee);
        lineEditCity->setObjectName(QString::fromUtf8("lineEditVille"));
        lineEditCity->setGeometry(QRect(190, 190, 113, 31));

        retranslateUi(AjoutArrivee);
        QObject::connect(pushButton, SIGNAL(clicked()), AjoutArrivee, SLOT(slotConfirmerArrivee()));

        QMetaObject::connectSlotsByName(AjoutArrivee);
    } // setupUi

    void retranslateUi(QDialog *AjoutArrivee)
    {
        AjoutArrivee->setWindowTitle(QCoreApplication::translate("AjoutArrivee", "AjoutArrivee", nullptr));
        lineEditNumber->setText(QCoreApplication::translate("AjoutArrivee", "LH0472", nullptr));
        pushButton->setText(QCoreApplication::translate("AjoutArrivee", "Confirmer", nullptr));
        Numero->setText(QCoreApplication::translate("AjoutArrivee", "Num\303\251ro de vol :", nullptr));
        Compagnie->setText(QCoreApplication::translate("AjoutArrivee", "Compagnie :", nullptr));
        lineEditCompany->setText(QCoreApplication::translate("AjoutArrivee", "LUFTHANSA", nullptr));
        Heure->setText(QCoreApplication::translate("AjoutArrivee", "Heure :", nullptr));
        lineEdithour->setText(QCoreApplication::translate("AjoutArrivee", "22:05", nullptr));
        Statut->setText(QCoreApplication::translate("AjoutArrivee", "Statut :", nullptr));
        lineEditStatus->setText(QCoreApplication::translate("AjoutArrivee", " Retard\303\251 ", nullptr));
        Ville->setText(QCoreApplication::translate("AjoutArrivee", "Ville :", nullptr));
        lineEditCity->setText(QCoreApplication::translate("AjoutArrivee", "MUNICH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddArrival: public Ui_AjoutArrivee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTARRIVEE_H
