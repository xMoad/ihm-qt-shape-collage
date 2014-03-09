#ifndef SIZES_H
#define SIZES_H

/*!
 * \file sizes.h
 * \brief Widget permettant la gestion des tailles
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWidget>
#include <QIntValidator>

namespace Ui {
class Sizes;
}

/*! \class Sizes
* \brief Classe représentant un widget permettant la gestion des tailles
*/
class Sizes : public QWidget
{
    Q_OBJECT
    
public:
    explicit Sizes(QWidget *parent = 0);
    ~Sizes();

    // getters
    int getCollageWidth();
    int getCollageHeight();
    int getNbPhotos(int maxPhotos);
    int getPhotoSize();
    int getDistancePhotos();
    bool getAutoSize();
    bool getAutoPhotoSize();
    bool getAutoNbPhotos();
    bool getAutoDistancePhotos();

    /*!
    *  \brief Ré-initialise l'interface
    */
    void reinitUI();

private slots:
    void on_pushButtonAutoManuelTailleCollage_clicked();
    void on_pushButtonAutoManuelTaillePhoto_clicked();
    void on_pushButtonAutoManuelNbPhoto_clicked();
    void on_pushButtonAutoManuelDistancePhoto_clicked();
    void on_radioButtonToutesPhotos_clicked();
    void on_radioButtonNbPhotos_clicked();
    void on_horizontalSliderDistancePhotos_valueChanged(int value);
    void on_spinBoxDistancePhotos_valueChanged(int arg1);

    
private:
    Ui::Sizes *ui;
    QIntValidator *mUIntValidator; /*!< Validateur pour entier non signé*/

    /*!
    *  \brief Met à jour l'interface en fonction des choix auto/manuel de l'utilisateur
    */
    void majTaille();
};

#endif // SIZES_H
