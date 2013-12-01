#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter.h>
#include <QMouseEvent>
#include <QFileDialog>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogPolygon = new DialogPolygon();

    ui->radioButtonToutesPhotos->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::majNbPhotos()
{
    int nbImages = ui->listWidgetImages->count();

    if (nbImages == 0)
        ui->labelNbPhotos->setText("Aucune photo");
    else
        if (nbImages == 1)
            ui->labelNbPhotos->setText("1 photo");
        else
            ui->labelNbPhotos->setText(QString::number(nbImages) + " photos");
}

void MainWindow::on_pushButton_clicked()
{
    QStringList paths = QFileDialog::getOpenFileNames(this, QString(),QString(),tr("Fichiers Images (*.png *.jpg *.bmp *.jpeg)") );

    QListWidgetItem * item;

    foreach (QString path, paths)
    {
        item = new QListWidgetItem(QIcon(path), Tools::getFileNameFromPath(path).left(20));
        item->setData(Qt::UserRole, path);
        ui->listWidgetImages->addItem(item);
    }

    if (ui->listWidgetImages->count() > 0)
        ui->pushButtonClearImagesList->setEnabled(true);

    majNbPhotos();
}

void MainWindow::on_pushButtonMoins_clicked()
{
    qDeleteAll(ui->listWidgetImages->selectedItems());

    if (ui->listWidgetImages->count() == 0)
        ui->pushButtonClearImagesList->setEnabled(false);

    majNbPhotos();
}

void MainWindow::on_listWidgetImages_itemSelectionChanged()
{
    if (ui->listWidgetImages->selectedItems().count() > 0)
    {
        ui->pushButtonMoins->setEnabled(true);
    }
    else
    {
        ui->pushButtonMoins->setEnabled(false);
    }
}

void MainWindow::on_pushButtonClearImagesList_clicked()
{
    int ret = QMessageBox::warning(this, "Effacer",
                                   "Etes-vous sûr(e) de vouloir tout effacer ?",
                                    QMessageBox::Yes,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes)
    {
        ui->listWidgetImages->clear();
        ui->pushButtonClearImagesList->setEnabled(false);
        majNbPhotos();
    }
}

void MainWindow::on_pushButtonAddFromFolder_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this);

    QDirIterator directoryWalker(directoryPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    QListWidgetItem * item;
    QString fileExtension;

    while(directoryWalker.hasNext())
    {
        directoryWalker.next();

        fileExtension = directoryWalker.fileInfo().completeSuffix();

        if ((fileExtension == "jpg") || (fileExtension == "png") || (fileExtension == "bmp") ||
                (fileExtension == "jpeg"))
        {
            item = new QListWidgetItem(QIcon(directoryWalker.filePath()), directoryWalker.fileName().left(20));
            item->setData(Qt::UserRole, directoryWalker.filePath());
            ui->listWidgetImages->addItem(item);
        }
    }

    if (ui->listWidgetImages->count() > 0)
        ui->pushButtonClearImagesList->setEnabled(true);

    majNbPhotos();
}

void MainWindow::on_pushButton_2_clicked()
{
    dialogPolygon->show();
}

void MainWindow::on_pushButtonApercu_clicked()
{
    if (ui->listWidgetImages->count() > 0)
    {
        renderApercu();
    }
    else
    {
        int ret = QMessageBox::critical(this, "Erreur",
                                        "Il n'y a aucune photos chargée.\nVeuillez charger des photos puis ré-essayer.");
    }
}

void MainWindow::majCollage()
{
    QStringList *imgPaths = new QStringList();

    for(int i = 0; i < ui->listWidgetImages->count(); ++i)
    {
        imgPaths->append(ui->listWidgetImages->item(i)->data(Qt::UserRole).toString());
    }

    QPolygon *polygone;

    if (ui->radioButtonPolygone->isChecked())
        polygone = dialogPolygon->polygon;
    else
    {
        polygone = new QPolygon();

        if (ui->radioButtonRectangle->isChecked())
        {
            polygone->push_back(QPoint(0,0));
            polygone->push_back(QPoint(0,240));
            polygone->push_back(QPoint(400,240));
            polygone->push_back(QPoint(400,0));
        }
        else
        {
            int nbPoints = 36;
            double slice = 2 * (atan(1.0)*4) /nbPoints;
            double rad, px, py;
            int rayon = 120;


            for (int i = 0; i < nbPoints; i++)
            {
                rad = slice * i;
                px = 200 + rayon * cos(rad);
                py = 120 + rayon * sin(rad);
                polygone->push_back(QPoint(px,py));
            }
        }
    }

    int h = ui->lineEditLargeurCollage->text().toInt(); /* TODO : verif > 0 */
    int w = ui->lineEditHauteurCollage->text().toInt(); /* TODO : verif > 0 */

    QSize * taille = new QSize(h,w); /* TODO : unite */

    int taillePhoto = ui->lineEditTaillePhoto->text().toInt(); /* TODO : verif > 0 + unités ! */
    int nbPhotos = ui->lineEditNbPhotos->text().toInt();  /* TODO : verif > 0 + radiobox + < à nbphotos */
    int distancePhotos = ui->spinBoxDistancePhotos->text().toInt(); /* TODO : verif > 0*/

    collage = new Collage(polygone, imgPaths, *taille, taillePhoto, nbPhotos, distancePhotos);

    if (ui->pushButtonAutoManuelTailleCollage->isChecked())
        collage->calculTaille();
    else
        if (ui->pushButtonAutoManuelTaillePhoto->isChecked())
            collage->calculTaillePhoto();
        else
            if (ui->pushButtonAutoManuelNbPhoto->isChecked())
                collage->calculNbPhotos();
            else
                collage->calculDistancePhotos();
}

void MainWindow::renderApercu()
{
    QPixmap *imageApercu = new QPixmap(ui->labelApercu->width(), ui->labelApercu->height());
    QPainter painter(imageApercu);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);

    painter.drawPolygon(*collage->getPolygone());

    ui->labelApercu->setPixmap(*imageApercu);
}

void MainWindow::clearApercu()
{
    QPixmap *imageApercu = new QPixmap(ui->labelApercu->width(), ui->labelApercu->height());
    QPainter painter(imageApercu);
    QPen pen(Qt::white);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(ui->labelApercu->rect());
    ui->labelApercu->setPixmap(*imageApercu);
}

void MainWindow::on_radioButtonPolygone_clicked()
{
    dialogPolygon->show();
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
    ui->comboBoxUniteTailleCollage->setEnabled(enabled);
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
    ui->comboBoxUniteTaillePhoto->setEnabled(enabled);

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
    ui->radioButtonRectangle->setChecked(true);

    ui->pushButtonAutoManuelTailleCollage->setChecked(true);
    majTaille();

    ui->lineEditLargeurCollage->setText("1680");
    ui->lineEditHauteurCollage->setText("1050");
    ui->comboBoxUniteTailleCollage->setCurrentIndex(0);

    ui->lineEditTaillePhoto->setText("200");
    ui->comboBoxUniteTaillePhoto->setCurrentIndex(0);

    ui->radioButtonToutesPhotos->setChecked(true);
    ui->radioButtonNbPhotos->setChecked(false);
    ui->lineEditNbPhotos->setText("150");

    ui->spinBoxDistancePhotos->setValue(90);
    ui->horizontalSliderDistancePhotos->setValue(90);
}

void MainWindow::on_pushButtonCreate_clicked()
{
    if (ui->listWidgetImages->count() > 0)
    {
        QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "", tr("PNG file (*.png)"));

        if (!path.isEmpty())
        {
           majCollage();
           collage->getImage(path);
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                                        "Il n'y a aucune photos chargée.\nVeuillez charger des photos puis ré-essayer.");
    }
}
