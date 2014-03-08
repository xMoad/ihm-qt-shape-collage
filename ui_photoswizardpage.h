/********************************************************************************
** Form generated from reading UI file 'photoswizardpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOSWIZARDPAGE_H
#define UI_PHOTOSWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizardPage>
#include <photos.h>

QT_BEGIN_NAMESPACE

class Ui_PhotosWizardPage
{
public:
    Photos *widgetPhotos;

    void setupUi(QWizardPage *PhotosWizardPage)
    {
        if (PhotosWizardPage->objectName().isEmpty())
            PhotosWizardPage->setObjectName(QStringLiteral("PhotosWizardPage"));
        PhotosWizardPage->resize(700, 450);
        widgetPhotos = new Photos(PhotosWizardPage);
        widgetPhotos->setObjectName(QStringLiteral("widgetPhotos"));
        widgetPhotos->setGeometry(QRect(0, 0, 332, 400));

        retranslateUi(PhotosWizardPage);

        QMetaObject::connectSlotsByName(PhotosWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *PhotosWizardPage)
    {
        PhotosWizardPage->setWindowTitle(QApplication::translate("PhotosWizardPage", "WizardPage", 0));
    } // retranslateUi

};

namespace Ui {
    class PhotosWizardPage: public Ui_PhotosWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOSWIZARDPAGE_H
