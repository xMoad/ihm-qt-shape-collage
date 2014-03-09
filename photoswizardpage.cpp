#include "photoswizardpage.h"
#include "ui_photoswizardpage.h"

#include <QLayout>
#include <QMessageBox>

#include "wizard.h"
#include "collage.h"

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

Photos * PhotosWizardPage::getWidgetPhotos()
{
    return ui->widgetPhotos;
}
