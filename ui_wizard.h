/********************************************************************************
** Form generated from reading UI file 'wizard.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_H
#define UI_WIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>
#include <creationwizardpage.h>
#include <photoswizardpage.h>
#include <shapewizardpage.h>
#include <sizeswizardpage.h>

QT_BEGIN_NAMESPACE

class Ui_Wizard
{
public:
    PhotosWizardPage *photosWizardPage;
    ShapeWizardPage *shapeWizardPage;
    SizesWizardPage *sizesWizardPage;
    CreationWizardPage *creationWizardPage;

    void setupUi(QWizard *Wizard)
    {
        if (Wizard->objectName().isEmpty())
            Wizard->setObjectName(QStringLiteral("Wizard"));
        Wizard->resize(700, 500);
        photosWizardPage = new PhotosWizardPage();
        photosWizardPage->setObjectName(QStringLiteral("photosWizardPage"));
        Wizard->addPage(photosWizardPage);
        shapeWizardPage = new ShapeWizardPage();
        shapeWizardPage->setObjectName(QStringLiteral("shapeWizardPage"));
        Wizard->addPage(shapeWizardPage);
        sizesWizardPage = new SizesWizardPage();
        sizesWizardPage->setObjectName(QStringLiteral("sizesWizardPage"));
        Wizard->addPage(sizesWizardPage);
        creationWizardPage = new CreationWizardPage();
        creationWizardPage->setObjectName(QStringLiteral("creationWizardPage"));
        Wizard->addPage(creationWizardPage);

        retranslateUi(Wizard);

        QMetaObject::connectSlotsByName(Wizard);
    } // setupUi

    void retranslateUi(QWizard *Wizard)
    {
        Wizard->setWindowTitle(QApplication::translate("Wizard", "Aide \303\240 la cr\303\251ation", 0));
    } // retranslateUi

};

namespace Ui {
    class Wizard: public Ui_Wizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_H
