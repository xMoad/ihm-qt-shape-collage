/********************************************************************************
** Form generated from reading UI file 'sizes.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZES_H
#define UI_SIZES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sizes
{
public:
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

    void setupUi(QWidget *Sizes)
    {
        if (Sizes->objectName().isEmpty())
            Sizes->setObjectName(QStringLiteral("Sizes"));
        Sizes->resize(327, 345);
        groupBox_3 = new QGroupBox(Sizes);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 321, 341));
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

        retranslateUi(Sizes);

        QMetaObject::connectSlotsByName(Sizes);
    } // setupUi

    void retranslateUi(QWidget *Sizes)
    {
        Sizes->setWindowTitle(QApplication::translate("Sizes", "Form", 0));
        groupBox_3->setTitle(QApplication::translate("Sizes", "Taille", 0));
        label->setText(QApplication::translate("Sizes", "Taille du collage :", 0));
        pushButtonAutoManuelTailleCollage->setText(QApplication::translate("Sizes", "Auto", 0));
        pushButtonAutoManuelTaillePhoto->setText(QApplication::translate("Sizes", "Manuel", 0));
        pushButtonAutoManuelNbPhoto->setText(QApplication::translate("Sizes", "Manuel", 0));
        pushButtonAutoManuelDistancePhoto->setText(QApplication::translate("Sizes", "Manuel", 0));
        label_2->setText(QApplication::translate("Sizes", "Taille de la photo :", 0));
        lineEditLargeurCollage->setText(QApplication::translate("Sizes", "1680", 0));
        labelLargeur->setText(QApplication::translate("Sizes", "Largeur", 0));
        labelX->setText(QApplication::translate("Sizes", "x", 0));
        lineEditHauteurCollage->setText(QApplication::translate("Sizes", "1050", 0));
        labelHauteur->setText(QApplication::translate("Sizes", "Hauteur", 0));
        lineEditTaillePhoto->setText(QApplication::translate("Sizes", "200", 0));
        label_6->setText(QApplication::translate("Sizes", "Nombres de photos :", 0));
        lineEditNbPhotos->setText(QApplication::translate("Sizes", "150", 0));
        labelPhotos->setText(QApplication::translate("Sizes", "photos", 0));
        radioButtonToutesPhotos->setText(QApplication::translate("Sizes", "Tout", 0));
        radioButtonNbPhotos->setText(QString());
        label_8->setText(QApplication::translate("Sizes", "Distance entre les photos :", 0));
        labelPourcent->setText(QApplication::translate("Sizes", "%", 0));
        labelPixelsPhoto->setText(QApplication::translate("Sizes", "pixels", 0));
        labelPixelsCollage->setText(QApplication::translate("Sizes", "pixels", 0));
    } // retranslateUi

};

namespace Ui {
    class Sizes: public Ui_Sizes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZES_H
