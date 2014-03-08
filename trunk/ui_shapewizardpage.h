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
#include <QtWidgets/QWidget>
#include <shape.h>

QT_BEGIN_NAMESPACE

class Ui_ShapeWizardPage
{
public:
    Shape *widgetShape;

    void setupUi(QWidget *ShapeWizardPage)
    {
        if (ShapeWizardPage->objectName().isEmpty())
            ShapeWizardPage->setObjectName(QStringLiteral("ShapeWizardPage"));
        ShapeWizardPage->resize(700, 450);
        widgetShape = new Shape(ShapeWizardPage);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));
        widgetShape->setGeometry(QRect(30, 180, 326, 128));

        retranslateUi(ShapeWizardPage);

        QMetaObject::connectSlotsByName(ShapeWizardPage);
    } // setupUi

    void retranslateUi(QWidget *ShapeWizardPage)
    {
        ShapeWizardPage->setWindowTitle(QApplication::translate("ShapeWizardPage", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ShapeWizardPage: public Ui_ShapeWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPEWIZARDPAGE_H
