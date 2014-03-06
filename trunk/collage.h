#ifndef COLLAGE_H
#define COLLAGE_H

/*!
 * \file collage.h
 * \brief Collage photos
 * \author Julien JUNG
 * \version 1.0
 */
#include <QStringList>
#include <QPainter>

/*! \class Collage
   * \brief Classe représentant un collage
   */
class Collage : public QObject
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Collage
     */
    Collage();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Collage
     */
    ~Collage();

    /*!
     *  \brief Rendu d'un collage
     *
     *  Fait le rendu du collage dans un QPixmap de largeur renderW et de hauteur renderH.
     *  Les paramètres renderW et renderH sont ignorés si mAutoSize est à true car ils seront calculés.
     *
     *  \param renderW : largeur du rendu
     *  \param renderH : hauteur du rendu
     *  \return le rendu dans une QPixmap
     */
    QPixmap* render(uint renderW = 0, uint renderH = 0);

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
    QPolygon *mPolygon; /*!< Forme du collage*/
    QList<QPoint> mScatterPlot; /*!< Nuage de points pour le placement des photos*/
    QList<QImage> *mListPhotos; /*!< Liste des photos pouvant etre utilisées dans le collage*/
    qreal mWidth; /*!< Largeur du collage en pixels*/
    qreal mHeight;  /*!< Hauteur du collage en pixels*/
    qreal mPhotoSize; /*!< Longueur en pixels du coté du carré englobant une photo*/
    qreal mNbPhotos; /*!< Nombre de photos cible pour le collage*/
    qreal mDistancePhotos; /*!< Distance en pourcent entre 2 photos*/
    qreal mDistancePhotosPx; /*!< Distance en pixels entre 2 photos*/
    int mAngleMax; /*!< Angle de rotation maximum des photos*/
    bool mAutoSize; /*!< Mode de sélection automatique ou manuel de la taille du collage*/
    bool mAutoPhotoSize; /*!< Mode de sélection automatique ou manuel de la taille des images*/
    bool mAutoNbPhotos; /*!< Mode de sélection automatique ou manuel du nombre de photos à utiliser pour le collage*/
    bool mAutoDistancePhotos; /*!< Mode de sélection automatique ou manuel de la distance entre 2 photos*/

    /*!
     *  \brief Calcule les paramètres du collage.
     *
     *  \return Faux si le nombre de photos à utiliser pour le collage égal 0
     */
    bool CalculateParameters();

    /*!
     *  \brief Adapate la taille du polygone à la taille du collage et le centre dans le collage.
     */
    void fitPolygon();

    /*!
     *  \brief Met à l'échelle le polygone en multipliant les coordonnées (x, y) de chaque point par (sx, sy).
     *
     *  \param sx : facteur de mise à l'échelle sur l'axe des x
     *  \param sy : facteur de mise à l'échelle sur l'axe des y
     */
    void scalePolygon(qreal sx, qreal sy);

    /*!
     *  \brief Calcule un nuage de points à l'intérieur du polygone dont le nombre de points se rapproche au mieux du nombre de photos souhaité.
     */
    void CalculateTightScatterPlot();

    /*!
     *  \brief Calcule un nuage de points à l'intérieur du polygone.
     */
    void CalculateScatterPlot();

    /*!
     *  \brief Modifie la densité du nuage de points.
     *
     *  \param densityMultiplier : facteur de multiplication de la densié
     */
    void ChangeScatterPlotDensity(qreal densityMultiplier);

    /*!
     *  \brief Détermine si un polygone est valide
     *
     *  Un polygone est valide si son aire n'est pas nulle.
     *  Les paramètres renderW et renderH sont ignorés si mAutoSize est à true car ils seront calculés.
     *
     *  \return Retourne vrai si l'aire du polygone est supérieure à 0 et faux dans le cas contraire.
     */
    bool isPolygonValid();

    /*!
     *  \brief Calcule la taille minimum du collage pouvant contenir les photos souhaitées.
     */
    void CalculateSize();

    /*!
     *  \brief Calcule la taille des photos en fonction de la taille du collage et du nombre de photos.
     */
    void CalculatePhotoSize();

    /*!
     *  \brief Calcule le nombre de photos que l'on peut faire entrer dans le collage en fonction de la taille du collage et de la distance entre les photos.
     */
    void CalculateNbPhotos();

    /*!
     *  \brief Calcule la distance en pixels entre chaque photo nécessaire pour faire entrer le nombre de photos souhaité dans le collage.
     */
    void CalculateDistancePhotosPx();
};

#endif // COLLAGE_H
