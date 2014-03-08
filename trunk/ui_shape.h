/********************************************************************************
** Form generated from reading UI file 'shape.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPE_H
#define UI_SHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shape
{
public:
    QGroupBox *groupBox_2;
    QRadioButton *radioButtonRectangle;
    QRadioButton *radioButtonCercle;
    QRadioButton *radioButtonPolygone;

    void setupUi(QWidget *Shape)
    {
        if (Shape->objectName().isEmpty())
            Shape->setObjectName(QStringLiteral("Shape"));
        Shape->resize(326, 128);
        groupBox_2 = new QGroupBox(Shape);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 321, 121));
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

        retranslateUi(Shape);

        QMetaObject::connectSlotsByName(Shape);
    } // setupUi

    void retranslateUi(QWidget *Shape)
    {
        Shape->setWindowTitle(QApplication::translate("Shape", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("Shape", "Forme", 0));
        radioButtonRectangle->setText(QApplication::translate("Shape", "Rectangle", 0));
        radioButtonCercle->setText(QApplication::translate("Shape", "Cercle", 0));
        radioButtonPolygone->setText(QApplication::translate("Shape", "Polygone", 0));
    } // retranslateUi

};

namespace Ui {
    class Shape: public Ui_Shape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPE_H
