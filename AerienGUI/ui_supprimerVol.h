/********************************************************************************
** Form generated from reading UI file 'supprimerVol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERVOL_H
#define UI_SUPPRIMERVOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_supprimerVol
{
public:
    QPushButton *BoutonSupprimer;
    QSplitter *splitter;
    QLabel *labelDescription;
    QLineEdit *lineNumber;

    void setupUi(QDialog *supprimerVol)
    {
        if (supprimerVol->objectName().isEmpty())
            supprimerVol->setObjectName(QString::fromUtf8("supprimerVol"));
        supprimerVol->resize(451, 130);
        BoutonSupprimer = new QPushButton(supprimerVol);
        BoutonSupprimer->setObjectName(QString::fromUtf8("BoutonSupprimer"));
        BoutonSupprimer->setGeometry(QRect(170, 80, 90, 28));
        splitter = new QSplitter(supprimerVol);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 20, 406, 41));
        splitter->setOrientation(Qt::Horizontal);
        labelDescription = new QLabel(splitter);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));
        splitter->addWidget(labelDescription);
        lineNumber = new QLineEdit(splitter);
        lineNumber->setObjectName(QString::fromUtf8("lineNumero"));
        splitter->addWidget(lineNumber);

        retranslateUi(supprimerVol);
        QObject::connect(BoutonSupprimer, SIGNAL(clicked()), supprimerVol, SLOT(slotSupprimer()));

        QMetaObject::connectSlotsByName(supprimerVol);
    } // setupUi

    void retranslateUi(QDialog *supprimerVol)
    {
        supprimerVol->setWindowTitle(QCoreApplication::translate("supprimerVol", "supprimerVol", nullptr));
        BoutonSupprimer->setText(QCoreApplication::translate("supprimerVol", "Supprimer", nullptr));
        labelDescription->setText(QCoreApplication::translate("supprimerVol", "Veuillez entrer le num\303\251ro de vol a supprimer : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteFlight: public Ui_supprimerVol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERVOL_H
