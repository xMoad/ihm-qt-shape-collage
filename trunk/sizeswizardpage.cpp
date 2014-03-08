#include "sizeswizardpage.h"
#include "ui_sizeswizardpage.h"

SizesWizardPage::SizesWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SizesWizardPage)
{
    ui->setupUi(this);
}

SizesWizardPage::~SizesWizardPage()
{
    delete ui;
}
