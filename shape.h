#ifndef SHAPE_H
#define SHAPE_H

/*!
 * \file shape.h
 * \brief Widget permettant la gestion des formes
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWidget>

#include "dialogpolygon.h"

namespace Ui {
class Shape;
}

/*! \class Shape
* \brief Classe représentant un widget permettant la gestion des formes
*/
class Shape : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shape(QWidget *parent = 0);
    ~Shape();

    /*!
     *  \brief Retourne le polygone choisit par l'utilisateur en fonction d'une taille définie
     *  \param w : largeur du conteneur du polygone
     *  \param h : hauteur du conteneur du polygone
     *  \return Retourne la forme choisit par l'utilisateur sous forme d'un polygone
     */
    QPolygon getPolygon(int w, int h);

    /*!
    *  \brief Ré-initialise l'interface
    */
    void reinitUI();

private slots:
    void on_radioButtonPolygone_clicked();
    
private:
    Ui::Shape *ui;
    DialogPolygon dialogPolygon; /*!< Boîte de dialogue permettant la création de polygone*/
};

#endif // SHAPE_H
