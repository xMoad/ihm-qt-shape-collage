#include "photos.h"
#include "ui_photos.h"

#include <QFileDialog>
#include <QDirIterator>
#include <QMessageBox>

Photos::Photos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Photos)
{
    ui->setupUi(this);
}

Photos::~Photos()
{
    delete ui;
}

Photos& Photos::operator =(const Photos &photos)
{
    return *this;
}

void Photos::setWizardLayout()
{
    ui->listWidgetImages->setFixedHeight(230);
    ui->groupBox->setFixedHeight(320);

    ui->labelNbPhotos->move(ui->labelNbPhotos->x(), 259);
    ui->pushButton->move(ui->pushButton->x(), 259);
    ui->pushButtonMoins->move(ui->pushButtonMoins->x(), 259);
    ui->pushButtonClearImagesList->move(ui->pushButtonClearImagesList->x(), 259);
    ui->pushButtonAddFromFolder->move(ui->pushButtonAddFromFolder->x(), 289);
}

void Photos::reinitUI()
{
    ui->listWidgetImages->clear();
    ui->pushButtonClearImagesList->setEnabled(false);
    mListPhotos.clear();
    majNbPhotos();
}

void Photos::majNbPhotos()
{
    int nbImages = ui->listWidgetImages->count();

    setProperty("NbPhotos", nbImages);

    nbPhotosChanged();

    if (nbImages == 0)
        ui->labelNbPhotos->setText("Aucune photo");
    else
        if (nbImages == 1)
            ui->labelNbPhotos->setText("1 photo");
        else
            ui->labelNbPhotos->setText(QString::number(nbImages) + " photos");
}

void Photos::on_pushButton_clicked()
{
    addPhotos();
}

void Photos::addPhotos()
{
    QStringList paths = QFileDialog::getOpenFileNames(this, QString(),QString(),tr("Fichiers Images (*.png *.jpg *.bmp *.jpeg)") );

    QListWidgetItem * item;

    foreach (QString path, paths)
    {
        item = new QListWidgetItem(QIcon(path), Tools::getFileNameFromPath(path).left(20));
        item->setData(Qt::UserRole, path);
        ui->listWidgetImages->addItem(item);
        mListPhotos.append(QImage());
        mListPhotos[mListPhotos.count() - 1].load(path);
    }

    if (ui->listWidgetImages->count() > 0)
        ui->pushButtonClearImagesList->setEnabled(true);

    majNbPhotos();
}

void Photos::on_pushButtonMoins_clicked()
{
    QString path;
    QImage photo;
    QList<QListWidgetItem*> selectedItems = ui->listWidgetImages->selectedItems();

    for(int i = 0; i < selectedItems.count(); i++) {
        path = selectedItems[i]->data(Qt::UserRole).toString();
        photo.load(path);
        mListPhotos.removeOne(photo);
    }

    qDeleteAll(ui->listWidgetImages->selectedItems());

    if (ui->listWidgetImages->count() == 0)
        ui->pushButtonClearImagesList->setEnabled(false);

    majNbPhotos();
}

void Photos::on_listWidgetImages_itemSelectionChanged()
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

void Photos::on_pushButtonClearImagesList_clicked()
{
    int ret = QMessageBox::warning(this, "Effacer",
                                   "Etes-vous sûr(e) de vouloir tout effacer ?",
                                    QMessageBox::Yes,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes)
    {
        reinitUI();
    }
}

void Photos::on_pushButtonAddFromFolder_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this);

    if (directoryPath.isNull())
        return;

    QDirIterator directoryWalker(directoryPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    QListWidgetItem * item;
    QString fileExtension;

    while(directoryWalker.hasNext())
    {
        directoryWalker.next();

        fileExtension = (directoryWalker.fileInfo().completeSuffix()).toLower();

        if ((fileExtension == "jpg") || (fileExtension == "png") || (fileExtension == "bmp") || (fileExtension == "jpeg"))
        {
            item = new QListWidgetItem(QIcon(directoryWalker.filePath()), directoryWalker.fileName().left(20));
            item->setData(Qt::UserRole, directoryWalker.filePath());
            ui->listWidgetImages->addItem(item);
            mListPhotos.append(QImage());
            mListPhotos[mListPhotos.count() - 1].load(directoryWalker.filePath());
        }
    }

    if (ui->listWidgetImages->count() > 0)
        ui->pushButtonClearImagesList->setEnabled(true);

    majNbPhotos();
}

void Photos::clearListPhotos() {
    mListPhotos.clear();
    majNbPhotos();
    ui->pushButtonClearImagesList->setEnabled(false);
}
