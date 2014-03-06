#include "collage.h"
#include <QtCore/qmath.h>

Collage::Collage()
{
    mPolygon = new QPolygon();
    mWidth = 0;
    mHeight = 0;
    mPhotoSize = 0;
    mNbPhotos = 0;
    mDistancePhotos = 0;
    mDistancePhotosPx = 0;
    mAngleMax = 0;
    mAutoSize = true;
    mAutoPhotoSize = false;
    mAutoNbPhotos = false;
    mAutoDistancePhotos = false;
}

Collage::~Collage()
{
    delete mPolygon;
}

// Fait le rendu du collage dans un QPixmap de largeur renderW et de hauteur renderH.
// Les paramètres renderW et renderH sont ignorés si mAutoSize est à true car ils seront calculés.
QPixmap* Collage::render(uint renderW, uint renderH)
{
    QPixmap *rendering = new QPixmap(renderW, renderH);
    QPainter painter(rendering);
    QPen pen;
    qreal scaleX, scaleY, scale;
    QRect rect;
    QPoint point;
    QImage photo;
    QImage photoR;
    qreal angle;
    QMatrix matrix;
    QList<QImage> listScaledPhotos;
    int w, h;
    int i;

    valueChanged(0); // On met à jour la barre de progression en lui envoyant un signal.

    if(!CalculateParameters())
        return rendering;

    scaleX = (qreal)(renderW) / mWidth;
    scaleY = (qreal)(renderH) / mHeight;
    (scaleX < scaleY) ? scale = scaleX : scale = scaleY;

    // On centre le rendu du polygone dans le collage.
    painter.translate(((qreal)(renderW) - scale * mWidth) / 2, ((qreal)(renderH) - scale * mHeight) / 2);

    // On adapte la taille du rendu à la taille de la pixmap cible.
    painter.scale(scale, scale);

    // On redimensionne les photos.
    for(i = 0; i < mListPhotos->count(); i++)
        listScaledPhotos.append((*mListPhotos)[i].scaled((*mListPhotos)[i].width() * scale, (*mListPhotos)[i].height() * scale));

    painter.setPen(pen);
    painter.fillRect(QRect(0, 0, mWidth, mHeight), Qt::white);

    for(i = 0; i < mScatterPlot.count(); i++) {
        point = mScatterPlot[i];
        photo = listScaledPhotos[i % listScaledPhotos.count()];

        // On effectue une rotation sur la photo d'un angle aléatoire compris entre -mAngleMax et mAngleMax.
        angle = (qrand() % (2*mAngleMax+1)) - mAngleMax;
        matrix.translate(photo.width() / 2, photo.height() / 2);
        matrix.rotate(angle);
        photoR = photo.transformed(matrix, Qt::FastTransformation);

        if(photoR.width() > photoR.height()) {
            w = mPhotoSize;
            h = mPhotoSize / ((float)(photoR.width()) / photoR.height());
        }
        else {
            w = mPhotoSize / ((float)(photoR.height()) / photoR.width());
            h = mPhotoSize;
        }

        rect.setLeft(point.x() - w / 2);
        rect.setRight(point.x() +  w / 2);
        rect.setTop(point.y() - h / 2);
        rect.setBottom(point.y() + h / 2);

        painter.drawImage(rect, photoR);
        valueChanged(((float)(i+1) / (mScatterPlot.count())) * 100); // On met à jour la barre de progression en lui envoyant un signal.
    }

    return rendering;
}

// Calcule les paramètres du collage.
bool Collage::CalculateParameters()
{
    CalculateSize();
    CalculatePhotoSize();
    CalculateNbPhotos();

    if(mNbPhotos == 0) {
        valueChanged(100);
        return false;
    }
    else {
        CalculateDistancePhotosPx();
        fitPolygon();
        CalculateTightScatterPlot();
    }

    return true;
}

// On adapate la taille du polygone à la taille du collage et on le centre dans le collage.
void Collage::fitPolygon()
{
    qreal photoDiagonal = qSqrt(2*mPhotoSize*mPhotoSize);
    int fitWidth = mWidth - photoDiagonal;
    int fitHeight = mHeight - photoDiagonal;

    if(fitWidth < 0)
        fitWidth = 0;

    if(fitHeight < 0)
        fitHeight = 0;

    QRect boundingRect = mPolygon->boundingRect();
    qreal scaleX = (qreal)fitWidth / boundingRect.width();
    qreal scaleY = (qreal)fitHeight / boundingRect.height();
    qreal scale;
    (scaleX < scaleY) ? scale = scaleX : scale = scaleY;
    scalePolygon(scale, scale);
    boundingRect = mPolygon->boundingRect();
    mPolygon->translate(((mWidth - boundingRect.width()) / 2) - boundingRect.left(), ((mHeight - boundingRect.height()) / 2) - boundingRect.top());
}

// Met à l'échelle le polygone en multipliant les coordonnées (x, y) de chaque point par (sx, sy).
void Collage::scalePolygon(qreal sx, qreal sy)
{
    int x, y;

    for(int i=0; i<mPolygon->count(); i++) {
        mPolygon->point(i, &x, &y);
        mPolygon->setPoint(i, x*sx, y*sy);
    }
}

// Calcule un nuage de points à l'intérieur du polygone dont le nombre de points se rapproche au mieux du nombre de photos souhaité.
void Collage::CalculateTightScatterPlot()
{
    mScatterPlot.clear();

    // Si le polygone a une aire nulle alors on ne peut pas le redimensionner pour trouver un nuage de points plus précis donc on s'arrete.
    if(isPolygonValid())
    {
        CalculateScatterPlot();

        if(mScatterPlot.count() > mNbPhotos) {
            while(mScatterPlot.count() > mNbPhotos && isPolygonValid()) // tant qu'il y a plus de points dans le polygone que de photos souhaitées
            {
                ChangeScatterPlotDensity(0.9F); // On diminue la densité du nuage de points de 10%
                CalculateScatterPlot();
            }
        }
        else {
            while(mScatterPlot.count() < mNbPhotos) // tant qu'il y a moins de points dans le polygone que de photos souhaitées
            {
                ChangeScatterPlotDensity(1.1F); // On augmente la densité du nuage de points de 10%
                CalculateScatterPlot();
            }
        }
    }
    else // On place juste une photo au centre du collage.
    {
        mScatterPlot.push_back(QPoint(mWidth / 2, mHeight / 2));
    }
}

// Calcule un nuage de points à l'intérieur du polygone.
void Collage::CalculateScatterPlot()
{
    qreal x, y;
    int top, bottom, left, right;
    QPoint point, prevPoint;

    mScatterPlot.clear();

    // Si on a réduit la taille du polygone jusqu'à ce qu'il disparaisse cela signifie que mNbPhotos est très faible alors on place juste une photo au centre.
    if(!isPolygonValid()) {
        mScatterPlot.push_back(QPoint(mWidth / 2, mHeight / 2));
    }
    else {
        top = mPolygon->boundingRect().top();
        bottom = mPolygon->boundingRect().bottom();
        left = mPolygon->boundingRect().left();
        right = mPolygon->boundingRect().right();

        for(x = left; x <= right; x += mDistancePhotosPx) {
            for(y = top; y <= bottom; y += mDistancePhotosPx) {
                point.setX((int)x);
                point.setY((int)y);

                if(point != prevPoint && mPolygon->containsPoint(point, Qt::OddEvenFill)) {
                    mScatterPlot.push_back(point);
                    prevPoint = point;
                }
            }
        }
    }
}

// Modifie la densité du nuage de points.
void Collage::ChangeScatterPlotDensity(float densityMultiplier)
{
    if(mAutoSize) { // On modifie la densité du nuage de points en modifiant la taille du collage afin d'obtenir Aire(collage) = Aire(collage) * matchRate
        mWidth *= qSqrt(densityMultiplier);
        mHeight *= qSqrt(densityMultiplier);
        fitPolygon(); // On réajuste la taille et la position du polygone.
    }
    else if(mAutoPhotoSize) { // On modifie la densité du nuage de points en modifiant la taille des photos.
        mPhotoSize /= qSqrt(densityMultiplier);
        CalculateDistancePhotosPx(); // La tailles des photos a une influence sur mDistancePhotosPx quand mAutoDistancePhotos est à false;
    }
    else if(mAutoNbPhotos) { // On modifie la densité du nuage de points en modifiant le nombre de photos.
        mNbPhotos *= qSqrt(densityMultiplier);
    }
    else { // Si la taille du collage, la taille des photos et le nombre de photos sont en manuel alors la distance entre 2 photos est forcément en auto.
        mDistancePhotosPx /= qSqrt(densityMultiplier);
    }
}

// Retourne vrai si l'aire du polygone est supérieure à 0 et faux dans le cas contraire.
bool Collage::isPolygonValid()
{
    return (mPolygon->boundingRect().left() != mPolygon->boundingRect().right() && mPolygon->boundingRect().top() != mPolygon->boundingRect().bottom());
}

// Calcule la taille minimum du collage pouvant contenir les photos souhaitées.
void Collage::CalculateSize()
{
    if(mAutoSize) {
        CalculateDistancePhotosPx();
        int size = (qSqrt(mNbPhotos) - 1) * mDistancePhotosPx + qSqrt(2 * mPhotoSize * mPhotoSize);

        if(mPolygon->boundingRect().width() > mPolygon->boundingRect().height()) {
            mWidth = size;
            mHeight = size * ((float)mPolygon->boundingRect().height() / mPolygon->boundingRect().width());
        }
        else {
            mHeight = size;
            mWidth = size * ((float)mPolygon->boundingRect().width() / mPolygon->boundingRect().height());
        }
    }
}

// On calcule la taille des photos en fonction de la taille du collage et du nombre de photos.
void Collage::CalculatePhotoSize()
{
    if(mAutoPhotoSize && mNbPhotos > 0) {
        mPhotoSize = qSqrt((mWidth * mHeight) / mNbPhotos);
    }
}

// On calcule le nombre de photos que l'on peut faire entrer dans le collage en fonction de la taille du collage et de la distance entre les photos.
void Collage::CalculateNbPhotos()
{
    if(mAutoNbPhotos) {
        CalculateDistancePhotosPx();
        mNbPhotos = (((mWidth - qSqrt(2 * mPhotoSize * mPhotoSize)) / mDistancePhotosPx) + 1) * (((mHeight - qSqrt(2 * mPhotoSize * mPhotoSize)) / mDistancePhotosPx) + 1);
    }
}

// Calcule la distance en pixels entre chaque photo nécessaire pour faire entrer le nombre de photos souhaité dans le collage.
void Collage::CalculateDistancePhotosPx()
{
    if(mAutoDistancePhotos) {
        qreal nbRow; // Nombre de lignes de photos
        qreal w = mWidth - qSqrt(2 * mPhotoSize * mPhotoSize);
        qreal h = mHeight - qSqrt(2 * mPhotoSize * mPhotoSize);

        nbRow = qSqrt((h * mNbPhotos) / w);

        if(nbRow > 1)
            mDistancePhotosPx = (qreal)h / (nbRow - 1);
        else
            mDistancePhotosPx = (qreal)w / mNbPhotos;
    }
    else {
        mDistancePhotosPx = (qreal)mPhotoSize * mDistancePhotos / 100;
    }
}
