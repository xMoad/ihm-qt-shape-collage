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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWizardPage>
#include <photos.h>

QT_BEGIN_NAMESPACE

class Ui_PhotosWizardPage
{
public:
    Photos *widgetPhotos;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWizardPage *PhotosWizardPage)
    {
        if (PhotosWizardPage->objectName().isEmpty())
            PhotosWizardPage->setObjectName(QStringLiteral("PhotosWizardPage"));
        PhotosWizardPage->resize(700, 450);
        widgetPhotos = new Photos(PhotosWizardPage);
        widgetPhotos->setObjectName(QStringLiteral("widgetPhotos"));
        widgetPhotos->setGeometry(QRect(0, 0, 332, 400));
        label = new QLabel(PhotosWizardPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 30, 321, 61));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(PhotosWizardPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 100, 291, 51));
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);
        label_2->setWordWrap(true);
        label_3 = new QLabel(PhotosWizardPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 150, 301, 81));
        label_3->setFont(font1);
        label_3->setWordWrap(true);

        retranslateUi(PhotosWizardPage);

        QMetaObject::connectSlotsByName(PhotosWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *PhotosWizardPage)
    {
        PhotosWizardPage->setWindowTitle(QApplication::translate("PhotosWizardPage", "WizardPage", 0));
        label->setText(QApplication::translate("PhotosWizardPage", "Bienvenue dans l'assistant de cr\303\251ation de collages !", 0));
        label_2->setText(QApplication::translate("PhotosWizardPage", "Pour commencer, veuillez charger des images \303\240 l'aide des boutons \"+\" et/ou \"Ajouter depuis un dossier\".", 0));
        label_3->setText(QApplication::translate("PhotosWizardPage", "Si vous voulez supprimer une  image, vous pouver en s\303\251lectionner une et cliquer sur le bouton \"-\". Pour supprimer toutes les images, cliquez sur le bouton \"Effacer la liste\".", 0));
    } // retranslateUi

};

namespace Ui {
    class PhotosWizardPage: public Ui_PhotosWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOSWIZARDPAGE_H
