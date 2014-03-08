#include "photoswizardpage.h"
#include "ui_photoswizardpage.h"

#include <QLayout>
#include <QMessageBox>

PhotosWizardPage::PhotosWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PhotosWizardPage)
{
    ui->setupUi(this);

    ui->widgetPhotos->setWizardLayout();

    registerField("NbPhotos*", ui->widgetPhotos, "NbPhotos", SIGNAL(nbPhotosChanged()));
}

PhotosWizardPage::~PhotosWizardPage()
{
    delete ui;
}
