/********************************************************************************
** Form generated from reading UI file 'dialogpolygon.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOLYGON_H
#define UI_DIALOGPOLYGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPolygon
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelImage;
    QPushButton *pushButtonReinitPolygon;

    void setupUi(QDialog *DialogPolygon)
    {
        if (DialogPolygon->objectName().isEmpty())
            DialogPolygon->setObjectName(QStringLiteral("DialogPolygon"));
        DialogPolygon->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogPolygon);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 250, 341, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelImage = new QLabel(DialogPolygon);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(0, 0, 400, 240));
        pushButtonReinitPolygon = new QPushButton(DialogPolygon);
        pushButtonReinitPolygon->setObjectName(QStringLiteral("pushButtonReinitPolygon"));
        pushButtonReinitPolygon->setGeometry(QRect(60, 260, 75, 23));

        retranslateUi(DialogPolygon);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPolygon, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPolygon, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPolygon);
    } // setupUi

    void retranslateUi(QDialog *DialogPolygon)
    {
        DialogPolygon->setWindowTitle(QApplication::translate("DialogPolygon", "Forme personalis\303\251e", 0));
        labelImage->setText(QString());
        pushButtonReinitPolygon->setText(QApplication::translate("DialogPolygon", "R\303\251initialiser", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogPolygon: public Ui_DialogPolygon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOLYGON_H
