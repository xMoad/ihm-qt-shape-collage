#ifndef WIZARD_H
#define WIZARD_H

/*!
 * \file wizard.h
 * \brief Assistant de création de collage de photos
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWizard>

#include "collage.h"

namespace Ui {
class Wizard;
}

/*! \class Wizard
* \brief Classe représentant l'assistant de création de collage de photos
*/
class Wizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

    /*!
    *  \brief Ré-initialise l'interface
    */
    void reinitUI();

    /*!
    *  \brief Créé le collage et ferme l'assistant de création
    */
    void accept();
    
private:
    Ui::Wizard *ui;
    Collage mCollage; /*!< Collage de photos*/
};

#endif // WIZARD_H
