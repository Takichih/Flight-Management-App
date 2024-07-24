/********************************************************************************
** Form generated from reading UI file 'DeleteFlight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEFLIGHT_H
#define UI_DELETEFLIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Delete_Flight
{
public:
    QPushButton *BoutonDelete;
    QSplitter *splitter;
    QLabel *labelDescription;
    QLineEdit *lineNumber;

    void setupUi(QDialog *Delete_Flight)
    {
        if (Delete_Flight->objectName().isEmpty())
            Delete_Flight->setObjectName(QString::fromUtf8("Delete_Flight"));
        Delete_Flight->resize(451, 130);
        BoutonDelete = new QPushButton(Delete_Flight);
        BoutonDelete->setObjectName(QString::fromUtf8("BoutonDelete"));
        BoutonDelete->setGeometry(QRect(170, 80, 90, 28));
        splitter = new QSplitter(Delete_Flight);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 20, 406, 41));
        splitter->setOrientation(Qt::Horizontal);
        labelDescription = new QLabel(splitter);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));
        splitter->addWidget(labelDescription);
        lineNumber = new QLineEdit(splitter);
        lineNumber->setObjectName(QString::fromUtf8("lineNumber"));
        splitter->addWidget(lineNumber);

        retranslateUi(Delete_Flight);
        QObject::connect(BoutonDelete, SIGNAL(clicked()), Delete_Flight, SLOT(slotDelete()));

        QMetaObject::connectSlotsByName(Delete_Flight);
    } // setupUi

    void retranslateUi(QDialog *Delete_Flight)
    {
        Delete_Flight->setWindowTitle(QCoreApplication::translate("Delete_Flight", "Delete a Flight", nullptr));
        BoutonDelete->setText(QCoreApplication::translate("Delete_Flight", "Delete", nullptr));
        labelDescription->setText(QCoreApplication::translate("Delete_Flight", "Enter the flight number to be deleted: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete_Flight: public Ui_Delete_Flight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEFLIGHT_H
