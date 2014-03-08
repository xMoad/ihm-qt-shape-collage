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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <photos.h>

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
    QGroupBox *groupBox_2;
    QRadioButton *radioButtonRectangle;
    QRadioButton *radioButtonCercle;
    QRadioButton *radioButtonPolygone;
    QPushButton *pushButtonApercu;
    QPushButton *pushButtonCreate;
    QGroupBox *groupBox_3;
    QLabel *label;
    QPushButton *pushButtonAutoManuelTailleCollage;
    QPushButton *pushButtonAutoManuelTaillePhoto;
    QPushButton *pushButtonAutoManuelNbPhoto;
    QPushButton *pushButtonAutoManuelDistancePhoto;
    QLabel *label_2;
    QLineEdit *lineEditLargeurCollage;
    QLabel *labelLargeur;
    QLabel *labelX;
    QLineEdit *lineEditHauteurCollage;
    QLabel *labelHauteur;
    QLineEdit *lineEditTaillePhoto;
    QLabel *label_6;
    QLineEdit *lineEditNbPhotos;
    QLabel *labelPhotos;
    QRadioButton *radioButtonToutesPhotos;
    QRadioButton *radioButtonNbPhotos;
    QLabel *label_8;
    QSlider *horizontalSliderDistancePhotos;
    QSpinBox *spinBoxDistancePhotos;
    QLabel *labelPourcent;
    QLabel *labelPixelsPhoto;
    QLabel *labelPixelsCollage;
    QProgressBar *progressBarApercu;
    QPushButton *pushButtonReinitFormeTaille;
    QGroupBox *gb_state;
    QLabel *labelApercu;
    QGroupBox *groupBox_4;
    QSlider *sliderAngle;
    QLabel *labelAngle;
    Photos *widgetPhotos;
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(740, 10, 321, 121));
        radioButtonRectangle = new QRadioButton(groupBox_2);
        radioButtonRectangle->setObjectName(QStringLiteral("radioButtonRectangle"));
        radioButtonRectangle->setGeometry(QRect(30, 30, 82, 17));
        radioButtonRectangle->setChecked(true);
        radioButtonCercle = new QRadioButton(groupBox_2);
        radioButtonCercle->setObjectName(QStringLiteral("radioButtonCercle"));
        radioButtonCercle->setGeometry(QRect(30, 60, 82, 17));
        radioButtonPolygone = new QRadioButton(groupBox_2);
        radioButtonPolygone->setObjectName(QStringLiteral("radioButtonPolygone"));
        radioButtonPolygone->setGeometry(QRect(30, 90, 82, 17));
        pushButtonApercu = new QPushButton(centralWidget);
        pushButtonApercu->setObjectName(QStringLiteral("pushButtonApercu"));
        pushButtonApercu->setGeometry(QRect(420, 450, 75, 23));
        pushButtonCreate = new QPushButton(centralWidget);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));
        pushButtonCreate->setGeometry(QRect(550, 450, 75, 23));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(740, 140, 321, 341));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 81, 16));
        pushButtonAutoManuelTailleCollage = new QPushButton(groupBox_3);
        pushButtonAutoManuelTailleCollage->setObjectName(QStringLiteral("pushButtonAutoManuelTailleCollage"));
        pushButtonAutoManuelTailleCollage->setGeometry(QRect(20, 60, 51, 23));
        pushButtonAutoManuelTailleCollage->setCheckable(true);
        pushButtonAutoManuelTailleCollage->setChecked(true);
        pushButtonAutoManuelTailleCollage->setAutoExclusive(true);
        pushButtonAutoManuelTaillePhoto = new QPushButton(groupBox_3);
        pushButtonAutoManuelTaillePhoto->setObjectName(QStringLiteral("pushButtonAutoManuelTaillePhoto"));
        pushButtonAutoManuelTaillePhoto->setGeometry(QRect(20, 140, 51, 23));
        pushButtonAutoManuelTaillePhoto->setCheckable(true);
        pushButtonAutoManuelTaillePhoto->setAutoExclusive(true);
        pushButtonAutoManuelNbPhoto = new QPushButton(groupBox_3);
        pushButtonAutoManuelNbPhoto->setObjectName(QStringLiteral("pushButtonAutoManuelNbPhoto"));
        pushButtonAutoManuelNbPhoto->setGeometry(QRect(20, 210, 51, 23));
        pushButtonAutoManuelNbPhoto->setCheckable(true);
        pushButtonAutoManuelNbPhoto->setAutoExclusive(true);
        pushButtonAutoManuelDistancePhoto = new QPushButton(groupBox_3);
        pushButtonAutoManuelDistancePhoto->setObjectName(QStringLiteral("pushButtonAutoManuelDistancePhoto"));
        pushButtonAutoManuelDistancePhoto->setGeometry(QRect(20, 290, 51, 23));
        pushButtonAutoManuelDistancePhoto->setCheckable(true);
        pushButtonAutoManuelDistancePhoto->setAutoExclusive(true);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 91, 16));
        lineEditLargeurCollage = new QLineEdit(groupBox_3);
        lineEditLargeurCollage->setObjectName(QStringLiteral("lineEditLargeurCollage"));
        lineEditLargeurCollage->setEnabled(false);
        lineEditLargeurCollage->setGeometry(QRect(120, 60, 51, 20));
        labelLargeur = new QLabel(groupBox_3);
        labelLargeur->setObjectName(QStringLiteral("labelLargeur"));
        labelLargeur->setEnabled(false);
        labelLargeur->setGeometry(QRect(120, 40, 46, 13));
        labelX = new QLabel(groupBox_3);
        labelX->setObjectName(QStringLiteral("labelX"));
        labelX->setEnabled(false);
        labelX->setGeometry(QRect(180, 60, 16, 16));
        lineEditHauteurCollage = new QLineEdit(groupBox_3);
        lineEditHauteurCollage->setObjectName(QStringLiteral("lineEditHauteurCollage"));
        lineEditHauteurCollage->setEnabled(false);
        lineEditHauteurCollage->setGeometry(QRect(200, 60, 41, 21));
        labelHauteur = new QLabel(groupBox_3);
        labelHauteur->setObjectName(QStringLiteral("labelHauteur"));
        labelHauteur->setEnabled(false);
        labelHauteur->setGeometry(QRect(200, 40, 46, 13));
        lineEditTaillePhoto = new QLineEdit(groupBox_3);
        lineEditTaillePhoto->setObjectName(QStringLiteral("lineEditTaillePhoto"));
        lineEditTaillePhoto->setGeometry(QRect(90, 140, 41, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 180, 111, 16));
        lineEditNbPhotos = new QLineEdit(groupBox_3);
        lineEditNbPhotos->setObjectName(QStringLiteral("lineEditNbPhotos"));
        lineEditNbPhotos->setGeometry(QRect(110, 240, 31, 20));
        labelPhotos = new QLabel(groupBox_3);
        labelPhotos->setObjectName(QStringLiteral("labelPhotos"));
        labelPhotos->setGeometry(QRect(150, 240, 46, 21));
        radioButtonToutesPhotos = new QRadioButton(groupBox_3);
        radioButtonToutesPhotos->setObjectName(QStringLiteral("radioButtonToutesPhotos"));
        radioButtonToutesPhotos->setGeometry(QRect(90, 210, 51, 17));
        radioButtonToutesPhotos->setChecked(false);
        radioButtonToutesPhotos->setAutoExclusive(false);
        radioButtonNbPhotos = new QRadioButton(groupBox_3);
        radioButtonNbPhotos->setObjectName(QStringLiteral("radioButtonNbPhotos"));
        radioButtonNbPhotos->setGeometry(QRect(90, 240, 16, 17));
        radioButtonNbPhotos->setAutoExclusive(false);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 260, 141, 16));
        horizontalSliderDistancePhotos = new QSlider(groupBox_3);
        horizontalSliderDistancePhotos->setObjectName(QStringLiteral("horizontalSliderDistancePhotos"));
        horizontalSliderDistancePhotos->setGeometry(QRect(90, 290, 121, 19));
        horizontalSliderDistancePhotos->setMinimum(25);
        horizontalSliderDistancePhotos->setMaximum(200);
        horizontalSliderDistancePhotos->setValue(90);
        horizontalSliderDistancePhotos->setOrientation(Qt::Horizontal);
        spinBoxDistancePhotos = new QSpinBox(groupBox_3);
        spinBoxDistancePhotos->setObjectName(QStringLiteral("spinBoxDistancePhotos"));
        spinBoxDistancePhotos->setGeometry(QRect(220, 290, 42, 22));
        spinBoxDistancePhotos->setMinimum(25);
        spinBoxDistancePhotos->setMaximum(200);
        spinBoxDistancePhotos->setValue(100);
        labelPourcent = new QLabel(groupBox_3);
        labelPourcent->setObjectName(QStringLiteral("labelPourcent"));
        labelPourcent->setGeometry(QRect(270, 290, 16, 16));
        labelPixelsPhoto = new QLabel(groupBox_3);
        labelPixelsPhoto->setObjectName(QStringLiteral("labelPixelsPhoto"));
        labelPixelsPhoto->setGeometry(QRect(140, 140, 46, 13));
        labelPixelsCollage = new QLabel(groupBox_3);
        labelPixelsCollage->setObjectName(QStringLiteral("labelPixelsCollage"));
        labelPixelsCollage->setEnabled(false);
        labelPixelsCollage->setGeometry(QRect(250, 60, 46, 13));
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
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(740, 490, 321, 51));
        sliderAngle = new QSlider(groupBox_4);
        sliderAngle->setObjectName(QStringLiteral("sliderAngle"));
        sliderAngle->setGeometry(QRect(10, 20, 251, 22));
        sliderAngle->setMaximum(180);
        sliderAngle->setValue(60);
        sliderAngle->setOrientation(Qt::Horizontal);
        labelAngle = new QLabel(groupBox_4);
        labelAngle->setObjectName(QStringLiteral("labelAngle"));
        labelAngle->setGeometry(QRect(270, 20, 46, 13));
        widgetPhotos = new Photos(centralWidget);
        widgetPhotos->setObjectName(QStringLiteral("widgetPhotos"));
        widgetPhotos->setGeometry(QRect(0, 0, 332, 577));
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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Forme", 0));
        radioButtonRectangle->setText(QApplication::translate("MainWindow", "Rectangle", 0));
        radioButtonCercle->setText(QApplication::translate("MainWindow", "Cercle", 0));
        radioButtonPolygone->setText(QApplication::translate("MainWindow", "Polygone", 0));
        pushButtonApercu->setText(QApplication::translate("MainWindow", "Aper\303\247u", 0));
        pushButtonCreate->setText(QApplication::translate("MainWindow", "Cr\303\251er", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Taille", 0));
        label->setText(QApplication::translate("MainWindow", "Taille du collage :", 0));
        pushButtonAutoManuelTailleCollage->setText(QApplication::translate("MainWindow", "Auto", 0));
        pushButtonAutoManuelTaillePhoto->setText(QApplication::translate("MainWindow", "Manuel", 0));
        pushButtonAutoManuelNbPhoto->setText(QApplication::translate("MainWindow", "Manuel", 0));
        pushButtonAutoManuelDistancePhoto->setText(QApplication::translate("MainWindow", "Manuel", 0));
        label_2->setText(QApplication::translate("MainWindow", "Taille de la photo :", 0));
        lineEditLargeurCollage->setText(QApplication::translate("MainWindow", "1680", 0));
        labelLargeur->setText(QApplication::translate("MainWindow", "Largeur", 0));
        labelX->setText(QApplication::translate("MainWindow", "x", 0));
        lineEditHauteurCollage->setText(QApplication::translate("MainWindow", "1050", 0));
        labelHauteur->setText(QApplication::translate("MainWindow", "Hauteur", 0));
        lineEditTaillePhoto->setText(QApplication::translate("MainWindow", "200", 0));
        label_6->setText(QApplication::translate("MainWindow", "Nombres de photos :", 0));
        lineEditNbPhotos->setText(QApplication::translate("MainWindow", "150", 0));
        labelPhotos->setText(QApplication::translate("MainWindow", "photos", 0));
        radioButtonToutesPhotos->setText(QApplication::translate("MainWindow", "Tout", 0));
        radioButtonNbPhotos->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Distance entre les photos :", 0));
        labelPourcent->setText(QApplication::translate("MainWindow", "%", 0));
        labelPixelsPhoto->setText(QApplication::translate("MainWindow", "pixels", 0));
        labelPixelsCollage->setText(QApplication::translate("MainWindow", "pixels", 0));
        pushButtonReinitFormeTaille->setText(QApplication::translate("MainWindow", "Restaurer les valeurs par d\303\251faut", 0));
        gb_state->setTitle(QApplication::translate("MainWindow", "\303\211tat", 0));
        labelApercu->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Rotation", 0));
        labelAngle->setText(QApplication::translate("MainWindow", "60\302\260", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
