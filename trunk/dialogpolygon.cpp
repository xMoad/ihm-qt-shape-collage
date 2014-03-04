#include "dialogpolygon.h"
#include "ui_dialogpolygon.h"

#include <QPainter>
#include <QMouseEvent>

DialogPolygon::DialogPolygon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPolygon)
{
    ui->setupUi(this);

    ui->labelImage->setStyleSheet("QLabel {background-color : white;}");

    mPixmap = new QPixmap(ui->labelImage->width(), ui->labelImage->height());
    mPixmap->fill(QColor("transparent"));
}

DialogPolygon::~DialogPolygon()
{
    delete ui;
    delete mPixmap;
}

void DialogPolygon::drawPolygon()
{
    reinitPixmap();

    QPainter painter(mPixmap);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawPolygon(mPolygon);
    ui->labelImage->setPixmap(*mPixmap);
}

void DialogPolygon::mousePressEvent(QMouseEvent *e)
{
    mPolygon.push_back(QPoint(e->localPos().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y()));
}

void DialogPolygon::mouseMoveEvent(QMouseEvent *e)
{
    mPolygon.setPoint(mPolygon.size() - 1, e->localPos().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y());
    drawPolygon();
}

void DialogPolygon::mouseReleaseEvent(QMouseEvent *e)
{
    // si le point est dans la QPixmap
    if ((ui->labelImage->size().width() > e->localPos().x()) && (ui->labelImage->size().height() > e->localPos().y()) &&
            (e->localPos().x() > 0) && (e->localPos().y() > 0))
        mPolygon.setPoint(mPolygon.size() - 1, e->localPos ().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y());
    else
        mPolygon.pop_back();

    drawPolygon();
}

void DialogPolygon::reinitPixmap()
{
    QPainter painter(mPixmap);
    QPen pen(Qt::white);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(ui->labelImage->rect());
    ui->labelImage->setPixmap(*mPixmap);
}

void DialogPolygon::on_pushButtonReinitPolygon_clicked()
{
    reinitPixmap();

    mPolygon.clear();
}
