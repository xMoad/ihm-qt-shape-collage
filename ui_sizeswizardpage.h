/********************************************************************************
** Form generated from reading UI file 'sizeswizardpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZESWIZARDPAGE_H
#define UI_SIZESWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWizardPage>
#include <rotationmax.h>
#include <sizes.h>

QT_BEGIN_NAMESPACE

class Ui_SizesWizardPage
{
public:
    Sizes *widgetSizes;
    RotationMax *widgetRotationMax;
    QLabel *label;

    void setupUi(QWizardPage *SizesWizardPage)
    {
        if (SizesWizardPage->objectName().isEmpty())
            SizesWizardPage->setObjectName(QStringLiteral("SizesWizardPage"));
        SizesWizardPage->resize(700, 450);
        widgetSizes = new Sizes(SizesWizardPage);
        widgetSizes->setObjectName(QStringLiteral("widgetSizes"));
        widgetSizes->setGeometry(QRect(0, 0, 327, 345));
        widgetRotationMax = new RotationMax(SizesWizardPage);
        widgetRotationMax->setObjectName(QStringLiteral("widgetRotationMax"));
        widgetRotationMax->setGeometry(QRect(340, 210, 325, 57));
        label = new QLabel(SizesWizardPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 50, 291, 141));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setWordWrap(true);

        retranslateUi(SizesWizardPage);

        QMetaObject::connectSlotsByName(SizesWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *SizesWizardPage)
    {
        SizesWizardPage->setWindowTitle(QApplication::translate("SizesWizardPage", "WizardPage", 0));
        label->setText(QApplication::translate("SizesWizardPage", "Ici, vous pouvez modifier les param\303\250tres de tailles des images et du collage, ainsi que la rotation maximale des images", 0));
    } // retranslateUi

};

namespace Ui {
    class SizesWizardPage: public Ui_SizesWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZESWIZARDPAGE_H
