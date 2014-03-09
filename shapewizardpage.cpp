#include "shapewizardpage.h"
#include "ui_shapewizardpage.h"

ShapeWizardPage::ShapeWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ShapeWizardPage)
{
    ui->setupUi(this);
}

ShapeWizardPage::~ShapeWizardPage()
{
    delete ui;
}

Shape * ShapeWizardPage::getWidgetShape()
{
    return ui->widgetShape;
}
