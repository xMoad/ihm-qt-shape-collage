#include "creationwizardpage.h"
#include "ui_creationwizardpage.h"

#include <QFileDialog>

CreationWizardPage::CreationWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::CreationWizardPage)
{
    ui->setupUi(this);

    registerField("imagePath*", ui->lineEditImagePath);
}

CreationWizardPage::~CreationWizardPage()
{
    delete ui;
}

void CreationWizardPage::on_pushButtonImagePath_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "", tr("PNG file (*.png)"));

    if (!path.isEmpty())
    {
        ui->lineEditImagePath->setText(path);

       /*majCollage();
       QFile file(path);
       file.open(QIODevice::WriteOnly);
       QPixmap *rendering = mCollage.render(mCollage.getWidth(), mCollage.getHeight());
       rendering->save(&file, "PNG");
       delete rendering;*/
    }
}
