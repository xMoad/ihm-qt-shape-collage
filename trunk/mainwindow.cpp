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

    ui->radioButtonToutesPhotos->setChecked(true);

    mCollage.setListPhoto(ui->widgetPhotos->getListPhotos());

    QPixmap imageApercu(ui->labelApercu->width(), ui->labelApercu->height());
    ui->labelApercu->setPixmap(imageApercu);

    connect(&mCollage, SIGNAL(valueChanged(int)), ui->progressBarApercu, SLOT(setValue(int)));

    mUIntValidator = new QIntValidator(0, std::numeric_limits<int>::max(), ui->lineEditLargeurCollage->parent());
    ui->lineEditLargeurCollage->setValidator(mUIntValidator);
    ui->lineEditHauteurCollage->setValidator(mUIntValidator);
    ui->lineEditTaillePhoto->setValidator(mUIntValidator);
    ui->lineEditNbPhotos->setValidator(mUIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mUIntValidator;
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
    int nbPhotos;
    int w = ui->lineEditLargeurCollage->text().toInt();
    int h = ui->lineEditHauteurCollage->text().toInt();

    QPolygon polygon;

    ui->radioButtonToutesPhotos->isChecked() ? nbPhotos = ui->widgetPhotos->countListPhotos() : nbPhotos = ui->lineEditNbPhotos->text().toInt();

    if (ui->radioButtonPolygone->isChecked())
        polygon = dialogPolygon.mPolygon;
    else
    {
        if (ui->radioButtonRectangle->isChecked())
        {
            polygon.push_back(QPoint(0,0));
            polygon.push_back(QPoint(0,20));
            polygon.push_back(QPoint(30, 20));
            polygon.push_back(QPoint(30,0));
        }
        else
        {
            int nbPoints = 36;
            double slice = 2 * (atan(1.0)*4) /nbPoints;
            double rad, px, py;
            int rayon;

            if(h > w)
                rayon = w / 2;
            else
                rayon = h / 2;

            for (int i = 0; i < nbPoints; i++)
            {
                rad = slice * i;
                px = 200 + rayon * cos(rad);
                py = 120 + rayon * sin(rad);
                polygon.push_back(QPoint(px,py));
            }
        }
    }

    mCollage.setPolygon(polygon);
    mCollage.setWidth(w);
    mCollage.setHeight(h);
    mCollage.setPhotoSize(ui->lineEditTaillePhoto->text().toInt());
    mCollage.setDistancePhotos(ui->spinBoxDistancePhotos->value());
    mCollage.setNbPhotos(nbPhotos);
    mCollage.setAngleMax(ui->sliderAngle->value());
    mCollage.setAutoSize(ui->pushButtonAutoManuelTailleCollage->isChecked());
    mCollage.setAutoPhotoSize(ui->pushButtonAutoManuelTaillePhoto->isChecked());
    mCollage.setAutoNbPhotos(ui->pushButtonAutoManuelNbPhoto->isChecked());
    mCollage.setAutoDistancePhotos(ui->pushButtonAutoManuelDistancePhoto->isChecked());
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

void MainWindow::on_radioButtonPolygone_clicked()
{
    dialogPolygon.show();
}

void MainWindow::majTaille()
{
    bool enabled;

    /* màj taille collage */
    if (ui->pushButtonAutoManuelTailleCollage->isChecked())
    {
        ui->pushButtonAutoManuelTailleCollage->setText("Auto");
        enabled = false;
    }
    else
    {
        ui->pushButtonAutoManuelTailleCollage->setText("Manuel");
        enabled = true;
    }

    ui->lineEditHauteurCollage->setEnabled(enabled);
    ui->lineEditLargeurCollage->setEnabled(enabled);
    ui->labelPixelsCollage->setEnabled(enabled);
    ui->labelHauteur->setEnabled(enabled);
    ui->labelLargeur->setEnabled(enabled);
    ui->labelX->setEnabled(enabled);

    /* màj taille photo */
    if (ui->pushButtonAutoManuelTaillePhoto->isChecked())
    {
        ui->pushButtonAutoManuelTaillePhoto->setText("Auto");
        enabled = false;
    }
    else
    {
        ui->pushButtonAutoManuelTaillePhoto->setText("Manuel");
        enabled = true;
    }

    ui->lineEditTaillePhoto->setEnabled(enabled);
    ui->labelPixelsPhoto->setEnabled(enabled);

    /* màj nombre photos */
    if (ui->pushButtonAutoManuelNbPhoto->isChecked())
    {
        ui->pushButtonAutoManuelNbPhoto->setText("Auto");
        enabled = false;
    }
    else
    {
        ui->pushButtonAutoManuelNbPhoto->setText("Manuel");
        enabled = true;
    }

    ui->lineEditNbPhotos->setEnabled(enabled);
    ui->labelPhotos->setEnabled(enabled);
    ui->radioButtonToutesPhotos->setEnabled(enabled);
    ui->radioButtonNbPhotos->setEnabled(true);

    /* màj distance photos */
    if (ui->pushButtonAutoManuelDistancePhoto->isChecked())
    {
        ui->pushButtonAutoManuelDistancePhoto->setText("Auto");
        enabled = false;
    }
    else
    {
        ui->pushButtonAutoManuelDistancePhoto->setText("Manuel");
        enabled = true;
    }

    ui->spinBoxDistancePhotos->setEnabled(enabled);
    ui->labelPourcent->setEnabled(enabled);
    ui->horizontalSliderDistancePhotos->setEnabled(enabled);
}

void MainWindow::on_pushButtonAutoManuelTailleCollage_clicked()
{
    majTaille();
}

void MainWindow::on_pushButtonAutoManuelTaillePhoto_clicked()
{
    majTaille();
}

void MainWindow::on_pushButtonAutoManuelNbPhoto_clicked()
{
    majTaille();
}

void MainWindow::on_pushButtonAutoManuelDistancePhoto_clicked()
{
    majTaille();
}

void MainWindow::on_radioButtonToutesPhotos_clicked()
{
    ui->radioButtonToutesPhotos->setChecked(true);
    ui->radioButtonNbPhotos->setChecked(false);
}

void MainWindow::on_radioButtonNbPhotos_clicked()
{
    ui->radioButtonToutesPhotos->setChecked(false);
    ui->radioButtonNbPhotos->setChecked(true);
}

void MainWindow::on_horizontalSliderDistancePhotos_valueChanged(int value)
{
    ui->spinBoxDistancePhotos->setValue(value);
}

void MainWindow::on_spinBoxDistancePhotos_valueChanged(int arg1)
{
    ui->horizontalSliderDistancePhotos->setValue(arg1);
}

void MainWindow::on_pushButtonReinitFormeTaille_clicked()
{
    reinitUI();
}

void MainWindow::reinitUI() {
    ui->radioButtonRectangle->setChecked(true);

    ui->pushButtonAutoManuelTailleCollage->setChecked(true);
    majTaille();

    ui->lineEditLargeurCollage->setText("1680");
    ui->lineEditHauteurCollage->setText("1050");

    ui->lineEditTaillePhoto->setText("200");

    ui->radioButtonToutesPhotos->setChecked(true);
    ui->radioButtonNbPhotos->setChecked(false);
    ui->lineEditNbPhotos->setText("150");

    ui->spinBoxDistancePhotos->setValue(100);
    ui->horizontalSliderDistancePhotos->setValue(100);

    ui->sliderAngle->setValue(60);

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

void MainWindow::on_sliderAngle_valueChanged(int value)
{
    ui->labelAngle->setText(QString::number(value) + "°");
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

}

void MainWindow::on_actionAide_la_cr_ation_triggered()
{
    wizard.show();
}
