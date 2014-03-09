#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter.h>
#include <QMouseEvent>
#include <QtCore/qmath.h>
#include <QLayout>
#include <QFileDialog>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mCollage.setListPhoto(ui->widgetPhotos->getListPhotos());

    QPixmap imageApercu(ui->labelApercu->width(), ui->labelApercu->height());
    ui->labelApercu->setPixmap(imageApercu);

    connect(&mCollage, SIGNAL(valueChanged(int)), ui->progressBarApercu, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_pushButtonApercu_clicked()
{
    if (ui->widgetPhotos->countListPhotos() > 0)
    {
        majCollage();
        renderApercu();
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                                        "Il n'y a aucune photos chargée.\nVeuillez charger des photos puis ré-essayer.");
    }
}

void MainWindow::majCollage()
{
    int w = ui->widgetSizes->getCollageWidth();
    int h = ui->widgetSizes->getCollageHeight();

    mCollage.setPolygon(ui->widgetShape->getPolygon(w, h));
    mCollage.setWidth(w);
    mCollage.setHeight(h);
    mCollage.setPhotoSize(ui->widgetSizes->getPhotoSize());
    mCollage.setDistancePhotos(ui->widgetSizes->getDistancePhotos());
    mCollage.setNbPhotos(ui->widgetSizes->getNbPhotos(ui->widgetPhotos->countListPhotos()));
    mCollage.setAngleMax(ui->widgetRotationMax->getValue());
    mCollage.setAutoSize(ui->widgetSizes->getAutoSize());
    mCollage.setAutoPhotoSize(ui->widgetSizes->getAutoPhotoSize());
    mCollage.setAutoNbPhotos(ui->widgetSizes->getAutoNbPhotos());
    mCollage.setAutoDistancePhotos(ui->widgetSizes->getAutoDistancePhotos());
}

void MainWindow::renderApercu()
{
    QPixmap *imageApercu = mCollage.render(ui->labelApercu->width(), ui->labelApercu->height());
    ui->labelApercu->setPixmap(*imageApercu);
    delete imageApercu;
}

void MainWindow::clearApercu()
{
    QPixmap imageApercu(ui->labelApercu->width(), ui->labelApercu->height());
    ui->labelApercu->setPixmap(imageApercu);
}

void MainWindow::on_pushButtonReinitFormeTaille_clicked()
{
    reinitUI();
}

void MainWindow::reinitUI()
{
    ui->widgetShape->reinitUI();

    ui->widgetSizes->reinitUI();

    ui->widgetRotationMax->reinitUI();

    ui->progressBarApercu->setValue(0);
}

void MainWindow::on_pushButtonCreate_clicked()
{
    createCollage();
}

void MainWindow::createCollage()
{
    if (ui->widgetPhotos->countListPhotos() > 0)
    {
        QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "", tr("PNG file (*.png)"));

        if (!path.isEmpty())
        {
           majCollage();
           QFile file(path);
           file.open(QIODevice::WriteOnly);
           QPixmap *rendering = mCollage.render(mCollage.getWidth(), mCollage.getHeight());
           rendering->save(&file, "PNG");
           delete rendering;
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                                        "Il n'y a aucune photos chargée.\nVeuillez charger des photos puis ré-essayer.");
    }
}

void MainWindow::on_actionNouveau_projet_triggered()
{
    int ret = QMessageBox::warning(this, "Effacer",
                                   "Etes-vous sûr(e) de vouloir tout effacer ?",
                                    QMessageBox::Yes,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes)
    {
        ui->widgetPhotos->clearListPhotos();
        reinitUI();
        clearApercu();
    }
}

void MainWindow::on_actionAjouter_des_photos_triggered()
{
    ui->widgetPhotos->addPhotos();
}

void MainWindow::on_actionCr_er_un_collage_triggered()
{
    createCollage();
}

void MainWindow::on_action_propos_triggered()
{
    dialogAbout.show();
}

void MainWindow::on_actionAide_la_cr_ation_triggered()
{
    wizard.reinitUI();
    wizard.restart();
    wizard.show();
}
