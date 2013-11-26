#ifndef COLLAGE_H
#define COLLAGE_H

#include <QStringList>
#include <QPainter>

class Collage
{
public:
    Collage(QPolygon *polygone, QStringList * imgPaths, QSize &taille, int taillePhoto, int nbPhotos, int distancePhotos);

    QPolygon* getPolygone();

    void calculTaille();
    void calculTaillePhoto();
    void calculNbPhotos();
    void calculDistancePhotos();

    void drawApercu(QPainter *painter);
    //QPicture * getImage();

private:
    QPolygon *polygone;
    QStringList * imgPaths;
    QSize taille;
    int taillePhoto;
    int nbPhotos;
    int distancePhotos;
};

#endif // COLLAGE_H
