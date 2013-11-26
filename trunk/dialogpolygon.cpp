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

    pixmap = new QPixmap(ui->labelImage->width(), ui->labelImage->height());
    pixmap->fill(QColor("transparent"));

    polygon = new QPolygon();
}

DialogPolygon::~DialogPolygon()
{
    delete ui;
}

void DialogPolygon::drawPolygon()
{
    reinitPixmap();

    QPainter painter(pixmap);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawPolygon(*polygon);
    ui->labelImage->setPixmap(*pixmap);
}

void DialogPolygon::mousePressEvent(QMouseEvent *e)
{
    polygon->push_back(QPoint(e->localPos().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y()));
}

void DialogPolygon::mouseMoveEvent(QMouseEvent *e)
{
    polygon->setPoint(polygon->size() - 1, e->localPos().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y());
    drawPolygon();
}

void DialogPolygon::mouseReleaseEvent(QMouseEvent *e)
{
    // si le point est dans la QPixmap
    if ((ui->labelImage->size().width() > e->localPos().x()) && (ui->labelImage->size().height() > e->localPos().y()) &&
            (e->localPos().x() > 0) && (e->localPos().y() > 0))
        polygon->setPoint(polygon->size() - 1, e->localPos ().x() - ui->labelImage->x(), e->localPos().y() - ui->labelImage->y());
    else
        polygon->pop_back();

    drawPolygon();
}

void DialogPolygon::reinitPixmap()
{
    QPainter painter(pixmap);
    QPen pen(Qt::white);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(ui->labelImage->rect());
    ui->labelImage->setPixmap(*pixmap);
}

void DialogPolygon::on_pushButtonReinitPolygon_clicked()
{
    reinitPixmap();

    polygon = new QPolygon();
}
