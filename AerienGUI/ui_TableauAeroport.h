/********************************************************************************
** Form generated from reading UI file 'TableauAeroport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEAUAEROPORT_H
#define UI_TABLEAUAEROPORT_H

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

class Ui_TableauAeroport
{
public:
    QAction *actionSupprimer_un_Vol;
    QAction *actionQuitter;
    QAction *actionDepart;
    QAction *actionArrive;
    QWidget *centralwidget;
    QTextEdit *textEditAero;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_un_Vol;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TableauAeroport)
    {
        if (TableauAeroport->objectName().isEmpty())
            TableauAeroport->setObjectName(QString::fromUtf8("TableauAeroport"));
        TableauAeroport->resize(800, 600);
        actionSupprimer_un_Vol = new QAction(TableauAeroport);
        actionSupprimer_un_Vol->setObjectName(QString::fromUtf8("actionSupprimer_un_Vol"));
        actionQuitter = new QAction(TableauAeroport);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionDepart = new QAction(TableauAeroport);
        actionDepart->setObjectName(QString::fromUtf8("actionDepart"));
        actionArrive = new QAction(TableauAeroport);
        actionArrive->setObjectName(QString::fromUtf8("actionArrive"));
        centralwidget = new QWidget(TableauAeroport);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditAero = new QTextEdit(centralwidget);
        textEditAero->setObjectName(QString::fromUtf8("textEditAero"));
        textEditAero->setGeometry(QRect(10, 0, 681, 451));
        textEditAero->setStyleSheet(QString::fromUtf8("font: oblique 10pt \"Monospace\";"));
        TableauAeroport->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TableauAeroport);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_un_Vol = new QMenu(menuMenu);
        menuAjouter_un_Vol->setObjectName(QString::fromUtf8("menuAjouter_un_Vol"));
        TableauAeroport->setMenuBar(menubar);
        statusbar = new QStatusBar(TableauAeroport);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TableauAeroport->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_un_Vol->menuAction());
        menuMenu->addAction(actionSupprimer_un_Vol);
        menuMenu->addAction(actionQuitter);
        menuAjouter_un_Vol->addAction(actionDepart);
        menuAjouter_un_Vol->addAction(actionArrive);

        retranslateUi(TableauAeroport);
        QObject::connect(actionQuitter, SIGNAL(triggered()), TableauAeroport, SLOT(close()));
        QObject::connect(actionDepart, SIGNAL(triggered()), TableauAeroport, SLOT(slotDepart()));
        QObject::connect(actionArrive, SIGNAL(triggered()), TableauAeroport, SLOT(slotArrivee()));
        QObject::connect(actionSupprimer_un_Vol, SIGNAL(triggered()), TableauAeroport, SLOT(slotSupprimerVol()));

        QMetaObject::connectSlotsByName(TableauAeroport);
    } // setupUi

    void retranslateUi(QMainWindow *TableauAeroport)
    {
        TableauAeroport->setWindowTitle(QCoreApplication::translate("TableauAeroport", "TableauAeroport", nullptr));
        actionSupprimer_un_Vol->setText(QCoreApplication::translate("TableauAeroport", "Supprimer un Vol", nullptr));
        actionQuitter->setText(QCoreApplication::translate("TableauAeroport", "Quitter", nullptr));
        actionDepart->setText(QCoreApplication::translate("TableauAeroport", "D\303\251part", nullptr));
        actionArrive->setText(QCoreApplication::translate("TableauAeroport", "Arriv\303\251e", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("TableauAeroport", "Menu", nullptr));
        menuAjouter_un_Vol->setTitle(QCoreApplication::translate("TableauAeroport", "Ajouter un Vol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableauAeroport: public Ui_TableauAeroport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEAUAEROPORT_H
