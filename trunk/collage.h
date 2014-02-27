#ifndef COLLAGE_H
#define COLLAGE_H

#include <QStringList>
#include <QPainter>
#include <math.h>

#define PI 3.14159265

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

    QPoint getAprecuCoords(QPoint p);
    QSize getAprecuSize(QSize s);
    QPoint getCoordsFromAprecuCoords(QPoint p);

    QPoint rotatePoint(QPoint center, QPoint point, int angle);
    bool isRectInPolygon(QRect * rect, QPolygon * polygon, int angleRotation);
    bool isPolygonEquals(QPolygon * polygon1, QPolygon * polygon2);
};

#endif // COLLAGE_H
