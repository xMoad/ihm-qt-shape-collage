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

    foreach (QPoint p, points)
    {
        this->polygone->push_back(getCoordsFromAprecuCoords(p));
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

QPoint Collage::getAprecuCoords(QPoint p)
{
    int x, y;

    if (p.x() == 0)
        x = 0;
    else
        x = (int) (p.x() * 400 / taille.width());

    if (p.y() == 0)
        y = 0;
    else
        y = (int) (p.y() * 240 / taille.height());

    return QPoint(x, y);
}

QSize Collage::getAprecuSize(QSize s)
{
    int h, w;

    if (s.width() == 0)
        w = 0;
    else
        w = (int) (s.width() * 400 / taille.width());

    if (s.height() == 0)
        h = 0;
    else
        h = (int) (s.height() * 240 / taille.height());

    return QSize(w, h);
}

QPoint Collage::getCoordsFromAprecuCoords(QPoint p)
{
    int x, y;

    if (p.x() == 0)
        x = 0;
    else
        x = (int) (p.x() * taille.width() / 400);

    if (p.y() == 0)
        y = 0;
    else
        y = (int) (p.y() * taille.height() / 240);

    return QPoint(x, y);
}

QList<QPixmap> Collage::getResizedPixmaps()
{
    QList<QPixmap> images = QList<QPixmap>();
    QPixmap pixmap;
    QSize pixmapSize;
    QList<QString>::iterator path;

    for (path = imgPaths->begin(); path != imgPaths->end(); ++path)
    {
        pixmap= QPixmap(*path);
        pixmapSize = getAprecuSize(pixmap.size());
        pixmap = pixmap.scaled(QSize(pixmapSize.width(), pixmapSize.height()),  Qt::KeepAspectRatio);
        images.push_back(pixmap);
    }

    return images;
}

// return a pixmap from pixmaps placed in the polygon at the position [x,y] with the rotation(angle), or null
QPixmap Collage::placeImageAt(QList<QPixmap> pixmaps, QPolygon * polygon, int x, int y, int angle)
{
    QRect * rect;

    for(int i=0; i<pixmaps.size();i++)
    {
        rect = new QRect(x,y,pixmaps.at(i).width(),pixmaps.at(i).height());

        if (isRectInPolygon(rect, polygon, angle))
        {
            pixmaps.removeAt(i);

            return pixmaps.at(i);
        }
    }

    return NULL;
}

void Collage::drawApercu(QPainter *painter)
{
    painter->drawPolygon(*polygoneApercu);

    if (imgPaths->isEmpty())
        return;

    QTransform * trans;
    int angle, i = 0, j = 0, maxHeight;
    QRect * rect;

    QList<QPixmap> pixmaps = getResizedPixmaps();
    QPixmap pixmap = pixmaps.first();
    pixmap = pixmap.scaled(getAprecuSize(pixmap.size()),  Qt::KeepAspectRatio);

    for (j = 0; j < 240; j += 5)
    {
        maxHeight = 0;

        for (i = 0; i < 400; i += 5)
        {
            angle = (qrand() % (90 + 1)) - 45; // random angle between -45° and +45°

            rect = new QRect(i,j,pixmap.width(),pixmap.height());

            if (isRectInPolygon(rect, polygoneApercu, angle))
            {
                if (pixmap.height() > maxHeight)
                    maxHeight = pixmap.height();

                trans = new QTransform();

                // Move to the center of the rect
                trans->translate((i + pixmap.width()/2), (j + pixmap.height()/2));

                // Do the rotation
                trans->rotate(angle);

                painter->setTransform(*trans);

                painter->drawPixmap(-pixmap.width()/2,-pixmap.height()/2,pixmap.width(),pixmap.height(), pixmap);

                painter->resetTransform();

                // get next qpixmap or exit

                pixmaps.removeFirst();

                if (pixmaps.isEmpty())
                    return;

                pixmap = pixmaps.first();
                pixmap = pixmap.scaled(getAprecuSize(pixmap.size()),  Qt::KeepAspectRatio);

                i += pixmap.width() * distancePhotos / 100 - 5;
            }
        }

        if (maxHeight > 0)
            j += pixmap.height() * distancePhotos / 100 - 5;
    }

    /*while ((j < 240) && (!pixmaps.isEmpty()))
    {
        angle = (qrand() % (360 + 1));

        pixmap = &placeImageAt(pixmaps, polygoneApercu, i, j, angle);

        if (pixmap != NULL)
        {
            trans = new QTransform();

            // Move to the center of the rect
            trans->translate((i + pixmap->width()/2), (j + pixmap->height()/2));

            // Do the rotation
            trans->rotate(angle);

            painter->setTransform(*trans);

            painter->drawPixmap(-pixmap->width()/2,-pixmap->height()/2,pixmap->width(),pixmap->height(), *pixmap);

            painter->resetTransform();

            i += pixmap->width() * distancePhotos / 100;

            if (i >= 400) {
                i = 0;
                j += pixmap->height() * distancePhotos / 100;
            }
        } else {
            i += 10;
            if (i >= 400) {
                i = 0;
                j += 10;
            }
        }
    }*/
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



