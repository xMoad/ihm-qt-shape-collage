/********************************************************************************
** Form generated from reading UI file 'rotationmax.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATIONMAX_H
#define UI_ROTATIONMAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotationMax
{
public:
    QGroupBox *groupBox_4;
    QSlider *sliderAngle;
    QLabel *labelAngle;

    void setupUi(QWidget *RotationMax)
    {
        if (RotationMax->objectName().isEmpty())
            RotationMax->setObjectName(QStringLiteral("RotationMax"));
        RotationMax->resize(325, 57);
        groupBox_4 = new QGroupBox(RotationMax);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 321, 51));
        sliderAngle = new QSlider(groupBox_4);
        sliderAngle->setObjectName(QStringLiteral("sliderAngle"));
        sliderAngle->setGeometry(QRect(10, 20, 251, 22));
        sliderAngle->setMaximum(180);
        sliderAngle->setValue(60);
        sliderAngle->setOrientation(Qt::Horizontal);
        labelAngle = new QLabel(groupBox_4);
        labelAngle->setObjectName(QStringLiteral("labelAngle"));
        labelAngle->setGeometry(QRect(270, 20, 46, 13));

        retranslateUi(RotationMax);

        QMetaObject::connectSlotsByName(RotationMax);
    } // setupUi

    void retranslateUi(QWidget *RotationMax)
    {
        RotationMax->setWindowTitle(QApplication::translate("RotationMax", "Form", 0));
        groupBox_4->setTitle(QApplication::translate("RotationMax", "Rotation maximale", 0));
        labelAngle->setText(QApplication::translate("RotationMax", "60\302\260", 0));
    } // retranslateUi

};

namespace Ui {
    class RotationMax: public Ui_RotationMax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATIONMAX_H
