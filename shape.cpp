#include "shape.h"
#include "ui_shape.h"

Shape::Shape(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shape)
{
    ui->setupUi(this);
}

Shape::~Shape()
{
    delete ui;
}

void Shape::on_radioButtonPolygone_clicked()
{
    dialogPolygon.show();
}

QPolygon Shape::getPolygon(int w, int h)
{
    QPolygon polygon;

    if (ui->radioButtonPolygone->isChecked())
        polygon = dialogPolygon.mPolygon;
    else
    {
        if (ui->radioButtonRectangle->isChecked())
        {
            polygon.push_back(QPoint(0,0));
            polygon.push_back(QPoint(0,20));
            polygon.push_back(QPoint(30, 20));
            polygon.push_back(QPoint(30,0));
        }
        else
        {
            int nbPoints = 36;
            double slice = 2 * (atan(1.0)*4) /nbPoints;
            double rad, px, py;
            int rayon;

            if(h > w)
                rayon = w / 2;
            else
                rayon = h / 2;

            for (int i = 0; i < nbPoints; i++)
            {
                rad = slice * i;
                px = 200 + rayon * cos(rad);
                py = 120 + rayon * sin(rad);
                polygon.push_back(QPoint(px,py));
            }
        }
    }

    return polygon;
}

void Shape::reinitUI()
{
    ui->radioButtonRectangle->setChecked(true);
}
