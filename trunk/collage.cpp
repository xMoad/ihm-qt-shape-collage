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
    qreal angle;

    for (int i = 0; i < 400; i += 10)
    {
        for (int j = 0; j < 240; j += 10)
        {
            angle = (qreal) (qrand() % (360 + 1));

            /*if (isImageInCollage(i,j,50,50,angle))
            {*/
                trans = new QTransform();
                // Move to the center of the widget
                trans->translate(400/2, 240/2);

                // Do the rotation
                trans->rotate(angle);

                // Move to the center of the rect
                trans->translate((i + 50/2), (j + 50/2));

                painter->setTransform(*trans);

                painter->drawRect(0,0,50,50);

                painter->resetTransform();
            //}
        }
    }
}

QPoint Collage::rotatePoint(QPoint p, qreal r)
{
    return QPoint((int) (p.x() * cos(r) - p.y() * sin(r)), (int) (p.x() * sin(r) + p.y() * cos(r)));
}

bool Collage::isRectInPolygon(QRect * rect, QPolygon * polygon)
{
    QPolygon * p = new QPolygon(rect);

}

// faux :
// - vérifier que les points sont contenus (rect to polygon puis translate rotate puis vérification des points)
// - vérifier que les lignes sont contenus (polygon intersect lignes ou inverse)
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



