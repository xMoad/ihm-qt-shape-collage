#ifndef SIZESWIZARDPAGE_H
#define SIZESWIZARDPAGE_H

/*!
 * \file sizeswizardpage.h
 * \brief Page de l'assistant de création, permettant la gestion des tailles et de la rotation maximale 
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWizardPage>

#include "sizes.h"
#include "rotationmax.h"

namespace Ui {
class SizesWizardPage;
}

/*! \class SizesWizardPage
* \brief Classe représentant la page de gestion des tailles et de la rotation maximale de l'assitant de création
*/
class SizesWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit SizesWizardPage(QWidget *parent = 0);
    ~SizesWizardPage();

    /*!
    *  \brief Retourne le widget permettant la gestion des tailles
    *  \return Retourne le widget permettant la gestion des tailles
    */
    Sizes * getWidgetSizes();

    /*!
    *  \brief Retourne le widget permettant la gestion de la rotation maximale
    *  \return Retourne le widget permettant la gestion de la rotation maximale
    */
    RotationMax * getWidgetRotationMax();
    
private:
    Ui::SizesWizardPage *ui;
};

#endif // SIZESWIZARDPAGE_H
