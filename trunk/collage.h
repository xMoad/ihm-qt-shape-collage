#ifndef COLLAGE_H
#define COLLAGE_H

#include <QStringList>
#include <QPainter>

class Collage : public QObject
{
    Q_OBJECT

public:
    Collage();
    ~Collage();
    QPixmap* render(int renderW = 0, int renderH = 0);

    // getters & setters
    inline int getWidth() { CalculateSize(); return mWidth; }
    inline int getHeight() { CalculateSize(); return mHeight; }
    inline int getPhotoSize() { CalculatePhotoSize(); return mPhotoSize; }
    inline int getNbPhotos() { CalculateNbPhotos(); return mNbPhotos; }
    inline int getDistancePoints() { CalculateDistancePhotosPx(); return mDistancePhotosPx; }
    inline void setPolygon(const QPolygon &polygon) { delete mPolygon; mPolygon = new QPolygon(polygon); }
    inline void setListPhoto(QList<QImage> *listPhotos) { mListPhotos = listPhotos; }
    inline void setWidth(int width) { mWidth = width; }
    inline void setHeight(int height) { mHeight = height; }
    inline void setPhotoSize(int photoSize) { mPhotoSize = photoSize; }
    inline void setNbPhotos(int nbPhotos) { mNbPhotos = nbPhotos; }
    inline void setDistancePhotos(int distancePhotos) { mDistancePhotos = distancePhotos; }
    inline void setAngleMax(int angleMax) { mAngleMax = angleMax; }
    inline void setAutoSize(bool autoSize) { mAutoSize = autoSize; }
    inline void setAutoPhotoSize(bool autoPhotoSize) { mAutoPhotoSize = autoPhotoSize; }
    inline void setAutoNbPhotos(bool autoNbPhotos) { mAutoNbPhotos = autoNbPhotos; }
    inline void setAutoDistancePhotos(bool autoDistancePhotos) { mAutoDistancePhotos = autoDistancePhotos; }

signals:
    void valueChanged(int);

private:
    QPolygon *mPolygon;
    QList<QPoint> mScatterPlot;
    QList<QImage> *mListPhotos;
    int mWidth;
    int mHeight;
    int mPhotoSize;
    int mNbPhotos;
    int mDistancePhotos;
    qreal mDistancePhotosPx;
    int mAngleMax;
    bool mAutoSize;
    bool mAutoPhotoSize;
    bool mAutoNbPhotos;
    bool mAutoDistancePhotos;

    void fitPolygon();
    void scalePolygon(qreal sx, qreal sy);
    void CalculateTightScatterPlot();
    void CalculateScatterPlot();
    void ChangeScatterPlotDensity(float densityMultiplier);
    bool isPolygonValid();
    void CalculateSize();
    void CalculatePhotoSize();
    void CalculateNbPhotos();
    void CalculateDistancePhotosPx();
};

#endif // COLLAGE_H
