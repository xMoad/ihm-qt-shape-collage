#ifndef ROTATIONMAX_H
#define ROTATIONMAX_H

/*!
 * \file rotationmax.h
 * \brief Widget permettant la gestion de la rotation maximum
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWidget>

namespace Ui {
class RotationMax;
}

/*! \class RotationMax
* \brief Classe représentant un widget permettant la gestion de la rotation maximum
*/
class RotationMax : public QWidget
{
    Q_OBJECT
    
public:
    explicit RotationMax(QWidget *parent = 0);
    ~RotationMax();

    /*!
    *  \brief Retourne la valeur de la rotation maximum
    *  \return Retourne la valeur de la rotation maximum
    */
    int getValue();

    /*!
    *  \brief Ré-initialise l'interface
    */
    void reinitUI();

private slots:
    void on_sliderAngle_valueChanged(int value);
    
private:
    Ui::RotationMax *ui;
};

#endif // ROTATIONMAX_H
