/********************************************************************************
** Form generated from reading UI file 'photos.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOS_H
#define UI_PHOTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Photos
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QListWidget *listWidgetImages;
    QPushButton *pushButtonMoins;
    QPushButton *pushButtonClearImagesList;
    QLabel *labelNbPhotos;
    QPushButton *pushButtonAddFromFolder;

    void setupUi(QWidget *Photos)
    {
        if (Photos->objectName().isEmpty())
            Photos->setObjectName(QStringLiteral("Photos"));
        Photos->resize(332, 577);
        Photos->setProperty("NbPhotos", QVariant(0));
        groupBox = new QGroupBox(Photos);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 551));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 490, 31, 23));
        listWidgetImages = new QListWidget(groupBox);
        listWidgetImages->setObjectName(QStringLiteral("listWidgetImages"));
        listWidgetImages->setGeometry(QRect(15, 20, 281, 461));
        listWidgetImages->setDragEnabled(false);
        listWidgetImages->setSelectionMode(QAbstractItemView::MultiSelection);
        listWidgetImages->setIconSize(QSize(120, 120));
        listWidgetImages->setFlow(QListView::LeftToRight);
        listWidgetImages->setResizeMode(QListView::Fixed);
        listWidgetImages->setViewMode(QListView::IconMode);
        listWidgetImages->setModelColumn(0);
        listWidgetImages->setBatchSize(100);
        listWidgetImages->setWordWrap(true);
        pushButtonMoins = new QPushButton(groupBox);
        pushButtonMoins->setObjectName(QStringLiteral("pushButtonMoins"));
        pushButtonMoins->setEnabled(false);
        pushButtonMoins->setGeometry(QRect(50, 490, 31, 23));
        pushButtonClearImagesList = new QPushButton(groupBox);
        pushButtonClearImagesList->setObjectName(QStringLiteral("pushButtonClearImagesList"));
        pushButtonClearImagesList->setEnabled(false);
        pushButtonClearImagesList->setGeometry(QRect(100, 490, 91, 23));
        labelNbPhotos = new QLabel(groupBox);
        labelNbPhotos->setObjectName(QStringLiteral("labelNbPhotos"));
        labelNbPhotos->setGeometry(QRect(220, 490, 71, 21));
        labelNbPhotos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonAddFromFolder = new QPushButton(groupBox);
        pushButtonAddFromFolder->setObjectName(QStringLiteral("pushButtonAddFromFolder"));
        pushButtonAddFromFolder->setGeometry(QRect(20, 520, 131, 23));

        retranslateUi(Photos);

        QMetaObject::connectSlotsByName(Photos);
    } // setupUi

    void retranslateUi(QWidget *Photos)
    {
        Photos->setWindowTitle(QApplication::translate("Photos", "Form", 0));
        groupBox->setTitle(QApplication::translate("Photos", "Photos", 0));
        pushButton->setText(QApplication::translate("Photos", "+", 0));
        pushButtonMoins->setText(QApplication::translate("Photos", "-", 0));
        pushButtonClearImagesList->setText(QApplication::translate("Photos", "Effacer la liste", 0));
        labelNbPhotos->setText(QApplication::translate("Photos", "Aucune photo", 0));
        pushButtonAddFromFolder->setText(QApplication::translate("Photos", "Ajouter depuis un dossier", 0));
    } // retranslateUi

};

namespace Ui {
    class Photos: public Ui_Photos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOS_H
