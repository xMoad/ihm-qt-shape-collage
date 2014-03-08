#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);

    setWindowTitle(tr("Aide à la création"));
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::accept()
{
    QDialog::accept();
}
