/********************************************************************************
** Form generated from reading UI file 'creationwizardpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONWIZARDPAGE_H
#define UI_CREATIONWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_CreationWizardPage
{
public:
    QPushButton *pushButtonImagePath;
    QLineEdit *lineEditImagePath;
    QLabel *labelImagePath;

    void setupUi(QWizardPage *CreationWizardPage)
    {
        if (CreationWizardPage->objectName().isEmpty())
            CreationWizardPage->setObjectName(QStringLiteral("CreationWizardPage"));
        CreationWizardPage->resize(700, 450);
        pushButtonImagePath = new QPushButton(CreationWizardPage);
        pushButtonImagePath->setObjectName(QStringLiteral("pushButtonImagePath"));
        pushButtonImagePath->setGeometry(QRect(370, 230, 75, 23));
        lineEditImagePath = new QLineEdit(CreationWizardPage);
        lineEditImagePath->setObjectName(QStringLiteral("lineEditImagePath"));
        lineEditImagePath->setGeometry(QRect(70, 230, 291, 20));
        lineEditImagePath->setReadOnly(true);
        labelImagePath = new QLabel(CreationWizardPage);
        labelImagePath->setObjectName(QStringLiteral("labelImagePath"));
        labelImagePath->setGeometry(QRect(70, 200, 271, 16));

        retranslateUi(CreationWizardPage);

        QMetaObject::connectSlotsByName(CreationWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *CreationWizardPage)
    {
        CreationWizardPage->setWindowTitle(QApplication::translate("CreationWizardPage", "WizardPage", 0));
        pushButtonImagePath->setText(QApplication::translate("CreationWizardPage", "Parcourir", 0));
        labelImagePath->setText(QApplication::translate("CreationWizardPage", "S\303\251lectionnez le chemin de destination du collage :", 0));
    } // retranslateUi

};

namespace Ui {
    class CreationWizardPage: public Ui_CreationWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONWIZARDPAGE_H
