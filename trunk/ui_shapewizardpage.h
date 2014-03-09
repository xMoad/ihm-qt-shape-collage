/********************************************************************************
** Form generated from reading UI file 'shapewizardpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPEWIZARDPAGE_H
#define UI_SHAPEWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <shape.h>

QT_BEGIN_NAMESPACE

class Ui_ShapeWizardPage
{
public:
    Shape *widgetShape;
    QLabel *label;

    void setupUi(QWidget *ShapeWizardPage)
    {
        if (ShapeWizardPage->objectName().isEmpty())
            ShapeWizardPage->setObjectName(QStringLiteral("ShapeWizardPage"));
        ShapeWizardPage->resize(700, 450);
        widgetShape = new Shape(ShapeWizardPage);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));
        widgetShape->setGeometry(QRect(30, 150, 326, 128));
        label = new QLabel(ShapeWizardPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 621, 101));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setWordWrap(true);

        retranslateUi(ShapeWizardPage);

        QMetaObject::connectSlotsByName(ShapeWizardPage);
    } // setupUi

    void retranslateUi(QWidget *ShapeWizardPage)
    {
        ShapeWizardPage->setWindowTitle(QApplication::translate("ShapeWizardPage", "Form", 0));
        label->setText(QApplication::translate("ShapeWizardPage", "Ici, vous devez choisir la forme du collage. Vous avez le choix entre choisir une forme pr\303\251d\303\251finie (rectangle, cercle) ou choisir une forme personnalis\303\251e (polygone).", 0));
    } // retranslateUi

};

namespace Ui {
    class ShapeWizardPage: public Ui_ShapeWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPEWIZARDPAGE_H
