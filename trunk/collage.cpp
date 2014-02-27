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

    QTransform * trans;
    int angle;
    QRect * rect;

    for (int i = 0; i < 400; i += 5)
    {
        for (int j = 0; j < 240; j += 5)
        {
            angle = (qrand() % (360 + 1));

            rect = new QRect(i,j,50,50);

            if (isRectInPolygon(rect, polygoneApercu, angle))
            {
                trans = new QTransform();

                // Move to the center of the rect
                trans->translate((i + 50/2), (j + 50/2));

                // Do the rotation
                trans->rotate(angle);

                painter->setTransform(*trans);

                painter->drawRect(-25,-25,50,50);

                painter->resetTransform();
            }
        }
    }
}

QPoint Collage::rotatePoint(QPoint center, QPoint point, int angleRotation)
{
    float angle = angleRotation * PI / 180.0;

    qreal radius = sqrt(abs(pow((float)(point.x() - center.x()),2) + pow((float)(point.y() - center.y()), 2)));

    return QPoint((int) (center.x() + radius * cos(angle)),
                  (int) (center.y() + radius * sin(angle)));
}

bool Collage::isPolygonEquals(QPolygon * polygon1, QPolygon * polygon2)
{
    QList<QPoint> pointsP1 = polygon1->toList();
    QList<QPoint> pointsP2 = polygon2->toList();

    bool isEqual;

    foreach (QPoint p1, pointsP1)
    {
        isEqual = false;

        foreach (QPoint p2, pointsP2)
        {
            if ((p1.x() == p2.x()) && (p1.y() == p2.y()))
                isEqual = true;
        }

        if (!isEqual)
            return false;
    }

    return true;
}

bool Collage::isRectInPolygon(QRect * rect, QPolygon * polygon, int angleRotation)
{
    QPolygon * rectPolygon = new QPolygon(4);
    rectPolygon->setPoint(0, rotatePoint(rect->center(), rect->bottomRight(), (angleRotation+45)%360));
    rectPolygon->setPoint(1, rotatePoint(rect->center(), rect->bottomLeft(), (angleRotation+135)%360));
    rectPolygon->setPoint(2, rotatePoint(rect->center(), rect->topLeft(), (angleRotation+225)%360));
    rectPolygon->setPoint(3, rotatePoint(rect->center(), rect->topRight(), (angleRotation+315)%360));

    QList<QPoint> points = rectPolygon->toList();

    foreach (QPoint p, points)
    {
        if (!polygon->containsPoint(p, Qt::OddEvenFill))
            return false;
    }

    return isPolygonEquals(&polygon->united(*rectPolygon), polygon);
}

void Collage::getImage(QString path)
{
    QImage img(taille.width(),taille.height(), QImage::Format_ARGB32);
    img.fill(Qt::white);

    QPainter painter;

    painter.begin(&img);

    painter.rotate(30);

    if (isRectInPolygon(new QRect(100,100,150,150), polygone, 30))
        painter.drawImage(100,100,QImage(imgPaths->first()).scaled(150,150,Qt::KeepAspectRatio));

    painter.rotate(-30);

    painter.rotate(30);

    if (isRectInPolygon(new QRect(500,500,150,150), polygone, 30))
        painter.drawImage(500,500,QImage(imgPaths->first()).scaled(150,150,Qt::KeepAspectRatio));

    painter.end();

    img.save(path);

}



