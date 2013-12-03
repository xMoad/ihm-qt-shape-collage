#include "collage.h"

Collage::Collage(QPolygon *polygone, QStringList * imgPaths, QSize &taille, int taillePhoto, int nbPhotos, int distancePhotos)
{
    this->polygoneApercu = polygone;
    this->imgPaths = imgPaths;
    this->taille = taille;
    this->taillePhoto = taillePhoto;
    this->nbPhotos = nbPhotos;
    this->distancePhotos = distancePhotos;
    this->polygone = new QPolygon();

    QList<QPoint> points = polygone->toList();

    int x,y;

    foreach (QPoint p, points)
    {
        if (p.x() == 0)
            x = 0;
        else
            x = (int) (p.x() * taille.width() / 400);

        if (p.y() == 0)
            y = 0;
        else
            y = (int) (p.y() * taille.height() / 240);

        this->polygone->push_back(QPoint(x, y));
    }
}


void Collage::calculTaille()
{

}

void Collage::calculTaillePhoto()
{

}

void Collage::calculNbPhotos()
{

}

void Collage::calculDistancePhotos()
{

}

QPolygon * Collage::getPolygoneApercu()
{
    return polygoneApercu;
}

void Collage::drawApercu(QPainter *painter)
{
    painter->drawPolygon(*polygoneApercu);
}

QPoint Collage::rotatePoint(QPoint p, qreal r)
{
    return QPoint((int) (p.x() * cos(r) - p.y() * sin(r)), (int) (p.x() * sin(r) + p.y() * cos(r)));
}

bool Collage::isImageInCollage(int x, int y, int w, int h, qreal r)
{
    r = r * (atan(1.0)*4) / 180.0;

    return (polygone->containsPoint(rotatePoint(QPoint(x,y), r), Qt::WindingFill) && polygone->containsPoint(rotatePoint(QPoint(x+w,y), r), Qt::WindingFill) &&
            polygone->containsPoint(rotatePoint(QPoint(x,y+h), r), Qt::WindingFill) && polygone->containsPoint(rotatePoint(QPoint(x+w,y+h), r), Qt::WindingFill));
}

void Collage::getImage(QString path)
{
    QImage img(taille.width(),taille.height(), QImage::Format_ARGB32);
    img.fill(Qt::white);

    QPainter painter;

    painter.begin(&img);

    painter.rotate(30);

    if (isImageInCollage(100,100,150,150,30))
        painter.drawImage(100,100,QImage(imgPaths->first()).scaled(150,150,Qt::KeepAspectRatio));

    painter.rotate(-30);

    painter.rotate(30);

    if (isImageInCollage(500,500,150,150,30))
        painter.drawImage(500,500,QImage(imgPaths->first()).scaled(150,150,Qt::KeepAspectRatio));

    painter.end();

    img.save(path);

}



