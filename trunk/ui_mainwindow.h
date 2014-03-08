/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <photos.h>
#include <rotationmax.h>
#include <shape.h>
#include <sizes.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionNouveau_projet;
    QAction *actionAjouter_des_photos;
    QAction *actionCr_er_un_collage;
    QAction *action_propos;
    QAction *actionAide_la_cr_ation;
    QWidget *centralWidget;
    QPushButton *pushButtonApercu;
    QPushButton *pushButtonCreate;
    QProgressBar *progressBarApercu;
    QPushButton *pushButtonReinitFormeTaille;
    QGroupBox *gb_state;
    QLabel *labelApercu;
    Photos *widgetPhotos;
    Shape *widgetShape;
    Sizes *widgetSizes;
    RotationMax *widgetRotationMax;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1070, 637);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionNouveau_projet = new QAction(MainWindow);
        actionNouveau_projet->setObjectName(QStringLiteral("actionNouveau_projet"));
        actionNouveau_projet->setEnabled(true);
        actionAjouter_des_photos = new QAction(MainWindow);
        actionAjouter_des_photos->setObjectName(QStringLiteral("actionAjouter_des_photos"));
        actionCr_er_un_collage = new QAction(MainWindow);
        actionCr_er_un_collage->setObjectName(QStringLiteral("actionCr_er_un_collage"));
        action_propos = new QAction(MainWindow);
        action_propos->setObjectName(QStringLiteral("action_propos"));
        actionAide_la_cr_ation = new QAction(MainWindow);
        actionAide_la_cr_ation->setObjectName(QStringLiteral("actionAide_la_cr_ation"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonApercu = new QPushButton(centralWidget);
        pushButtonApercu->setObjectName(QStringLiteral("pushButtonApercu"));
        pushButtonApercu->setGeometry(QRect(420, 450, 75, 23));
        pushButtonCreate = new QPushButton(centralWidget);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));
        pushButtonCreate->setGeometry(QRect(550, 450, 75, 23));
        progressBarApercu = new QProgressBar(centralWidget);
        progressBarApercu->setObjectName(QStringLiteral("progressBarApercu"));
        progressBarApercu->setGeometry(QRect(390, 400, 301, 23));
        progressBarApercu->setValue(0);
        pushButtonReinitFormeTaille = new QPushButton(centralWidget);
        pushButtonReinitFormeTaille->setObjectName(QStringLiteral("pushButtonReinitFormeTaille"));
        pushButtonReinitFormeTaille->setGeometry(QRect(790, 560, 211, 23));
        gb_state = new QGroupBox(centralWidget);
        gb_state->setObjectName(QStringLiteral("gb_state"));
        gb_state->setGeometry(QRect(340, 10, 381, 371));
        labelApercu = new QLabel(gb_state);
        labelApercu->setObjectName(QStringLiteral("labelApercu"));
        labelApercu->setGeometry(QRect(20, 20, 341, 341));
        labelApercu->setAutoFillBackground(false);
        widgetPhotos = new Photos(centralWidget);
        widgetPhotos->setObjectName(QStringLiteral("widgetPhotos"));
        widgetPhotos->setGeometry(QRect(0, 0, 332, 577));
        widgetShape = new Shape(centralWidget);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));
        widgetShape->setGeometry(QRect(740, 10, 326, 128));
        widgetSizes = new Sizes(centralWidget);
        widgetSizes->setObjectName(QStringLiteral("widgetSizes"));
        widgetSizes->setGeometry(QRect(740, 140, 327, 345));
        widgetRotationMax = new RotationMax(centralWidget);
        widgetRotationMax->setObjectName(QStringLiteral("widgetRotationMax"));
        widgetRotationMax->setGeometry(QRect(740, 490, 325, 57));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1070, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouveau_projet);
        menuFichier->addAction(actionAjouter_des_photos);
        menuFichier->addAction(actionCr_er_un_collage);
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(action_propos);
        menuAide->addAction(actionAide_la_cr_ation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shape Copiage", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionNouveau_projet->setText(QApplication::translate("MainWindow", "Nouveau projet", 0));
        actionAjouter_des_photos->setText(QApplication::translate("MainWindow", "Ajouter des photos", 0));
        actionCr_er_un_collage->setText(QApplication::translate("MainWindow", "Cr\303\251er un collage", 0));
        action_propos->setText(QApplication::translate("MainWindow", "\303\200 propos", 0));
        actionAide_la_cr_ation->setText(QApplication::translate("MainWindow", "Aide \303\240 la cr\303\251ation", 0));
        pushButtonApercu->setText(QApplication::translate("MainWindow", "Aper\303\247u", 0));
        pushButtonCreate->setText(QApplication::translate("MainWindow", "Cr\303\251er", 0));
        pushButtonReinitFormeTaille->setText(QApplication::translate("MainWindow", "Restaurer les valeurs par d\303\251faut", 0));
        gb_state->setTitle(QApplication::translate("MainWindow", "\303\211tat", 0));
        labelApercu->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
