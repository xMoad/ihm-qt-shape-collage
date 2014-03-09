#include "wizard.h"
#include "ui_wizard.h"

#include <QFile>

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);

}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::reinitUI()
{
    ui->photosWizardPage->getWidgetPhotos()->reinitUI();
    ui->sizesWizardPage->getWidgetSizes()->reinitUI();
    ui->sizesWizardPage->getWidgetRotationMax()->reinitUI();
    ui->shapeWizardPage->getWidgetShape()->reinitUI();
}

void Wizard::accept()
{
    mCollage.setListPhoto(ui->photosWizardPage->getWidgetPhotos()->getListPhotos());

    int w = ui->sizesWizardPage->getWidgetSizes()->getCollageWidth();
    int h = ui->sizesWizardPage->getWidgetSizes()->getCollageHeight();

    mCollage.setPolygon(ui->shapeWizardPage->getWidgetShape()->getPolygon(w, h));
    mCollage.setWidth(w);
    mCollage.setHeight(h);
    mCollage.setPhotoSize(ui->sizesWizardPage->getWidgetSizes()->getPhotoSize());
    mCollage.setDistancePhotos(ui->sizesWizardPage->getWidgetSizes()->getDistancePhotos());
    mCollage.setNbPhotos(ui->sizesWizardPage->getWidgetSizes()->getNbPhotos(ui->photosWizardPage->getWidgetPhotos()->countListPhotos()));
    mCollage.setAngleMax(ui->sizesWizardPage->getWidgetRotationMax()->getValue());
    mCollage.setAutoSize(ui->sizesWizardPage->getWidgetSizes()->getAutoSize());
    mCollage.setAutoPhotoSize(ui->sizesWizardPage->getWidgetSizes()->getAutoPhotoSize());
    mCollage.setAutoNbPhotos(ui->sizesWizardPage->getWidgetSizes()->getAutoNbPhotos());
    mCollage.setAutoDistancePhotos(ui->sizesWizardPage->getWidgetSizes()->getDistancePhotos());

    QFile file(field("imagePath").toString());
    file.open(QIODevice::WriteOnly);
    QPixmap *rendering = mCollage.render(mCollage.getWidth(), mCollage.getHeight());
    rendering->save(&file, "PNG");
    delete rendering;

    QDialog::accept();
}
