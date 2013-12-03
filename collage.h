#ifndef COLLAGE_H
#define COLLAGE_H

#include <QStringList>
#include <QPainter>
#include <math.h>
class Collage
{
public:
    Collage(QPolygon *polygone, QStringList * imgPaths, QSize &taille, int taillePhoto, int nbPhotos, int distancePhotos);

    QPolygon* getPolygoneApercu();

    void calculTaille();
    void calculTaillePhoto();
    void calculNbPhotos();
    void calculDistancePhotos();

    void drawApercu(QPainter *painter);
    void getImage(QString path);

private:
    QPolygon *polygone, *polygoneApercu;
    QStringList * imgPaths;
    QSize taille;
    int taillePhoto;
    int nbPhotos;
    int distancePhotos;

    QPoint rotatePoint(QPoint p, qreal r);
    bool isImageInCollage(int x, int y, int w, int h, qreal r);
};

#endif // COLLAGE_H
