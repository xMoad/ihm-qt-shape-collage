#include "sizes.h"
#include "ui_sizes.h"

Sizes::Sizes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sizes)
{
    ui->setupUi(this);

    ui->radioButtonToutesPhotos->setChecked(true);

    mUIntValidator = new QIntValidator(0, std::numeric_limits<int>::max(), ui->lineEditLargeurCollage->parent());
    ui->lineEditLargeurCollage->setValidator(mUIntValidator);
    ui->lineEditHauteurCollage->setValidator(mUIntValidator);
    ui->lineEditTaillePhoto->setValidator(mUIntValidator);
    ui->lineEditNbPhotos->setValidator(mUIntValidator);
}

Sizes::~Sizes()
{
    delete ui;
    delete mUIntValidator;
}

int Sizes::getCollageWidth()
{
    return ui->lineEditLargeurCollage->text().toInt();
}

int Sizes::getCollageHeight()
{
    return ui->lineEditHauteurCollage->text().toInt();
}

int Sizes::getNbPhotos(int maxPhotos)
{
    int nbPhotos;
    ui->radioButtonToutesPhotos->isChecked() ? nbPhotos = maxPhotos : nbPhotos = ui->lineEditNbPhotos->text().toInt();
    return nbPhotos;
}

int Sizes::getPhotoSize()
{
    return ui->lineEditTaillePhoto->text().toInt();
}

int Sizes::getDistancePhotos()
{
    return ui->spinBoxDistancePhotos->value();
}

bool Sizes::getAutoSize()
{
    return ui->pushButtonAutoManuelTailleCollage->isChecked();
}

bool Sizes::getAutoPhotoSize()
{
    return ui->pushButtonAutoManuelTaillePhoto->isChecked();
}

bool Sizes::getAutoNbPhotos()
{
    return ui->pushButtonAutoManuelNbPhoto->isChecked();
}

bool Sizes::getAutoDistancePhotos()
{
    return ui->pushButtonAutoManuelDistancePhoto->isChecked();
}

void Sizes::on_pushButtonAutoManuelTailleCollage_clicked()
{
    majTaille();
}

void Sizes::on_pushButtonAutoManuelTaillePhoto_clicked()
{
    majTaille();
}

void Sizes::on_pushButtonAutoManuelNbPhoto_clicked()
{
    majTaille();
}

void Sizes::on_pushButtonAutoManuelDistancePhoto_clicked()
{
    majTaille();
}

void Sizes::on_radioButtonToutesPhotos_clicked()
{
    ui->radioButtonToutesPhotos->setChecked(true);
    ui->radioButtonNbPhotos->setChecked(false);
}

void Sizes::on_radioButtonNbPhotos_clicked()
{
    ui->radioButtonToutesPhotos->setChecked(false);
    ui->radioButtonNbPhotos->setChecked(true);
}

void Sizes::on_horizontalSliderDistancePhotos_valueChanged(int value)
{
    ui->spinBoxDistancePhotos->setValue(value);
}

void Sizes::on_spinBoxDistancePhotos_valueChanged(int arg1)
{
    ui->horizontalSliderDistancePhotos->setValue(arg1);
}

void Sizes::majTaille()
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

void Sizes::reinitUI()
{
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
}
