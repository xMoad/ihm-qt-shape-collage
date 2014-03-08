#include "rotationmax.h"
#include "ui_rotationmax.h"

RotationMax::RotationMax(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RotationMax)
{
    ui->setupUi(this);
}

RotationMax::~RotationMax()
{
    delete ui;
}

void RotationMax::on_sliderAngle_valueChanged(int value)
{
    ui->labelAngle->setText(QString::number(value) + "°");
}

int RotationMax::getValue()
{
    return ui->sliderAngle->value();
}

void RotationMax::reinitUI()
{
    ui->sliderAngle->setValue(60);
}
