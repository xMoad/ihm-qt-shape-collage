#include "collage.h"

Collage::Collage(QPolygon *polygone, QStringList * imgPaths, QSize &taille, int taillePhoto, int nbPhotos, int distancePhotos)
{
    this->polygone = polygone;
    this->imgPaths = imgPaths;
    this->taille = taille;
    this->taillePhoto = taillePhoto;
    this->nbPhotos = nbPhotos;
    this->distancePhotos = distancePhotos;
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

QPolygon * Collage::getPolygone()
{
    return polygone;
}

void Collage::drawApercu(QPainter *painter)
{
    painter->drawPolygon(*polygone);
}

void Collage::getImage(QString path)
{
    QImage img(taille.width(),taille.height(), QImage::Format_ARGB32);
    img.fill(Qt::white);

    QPainter painter;

    painter.begin(&img);

    painter.rotate(30);

    painter.drawImage(100,100,QImage(imgPaths->first()).scaled(150,150,Qt::KeepAspectRatio));

    painter.end();

    img.save(path);

}



