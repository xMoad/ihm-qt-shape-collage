#ifndef SHAPEWIZARDPAGE_H
#define SHAPEWIZARDPAGE_H

/*!
 * \file shapewizardpage.h
 * \brief Page de l'assistant de création, permettant la gestion des formes
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWizardPage>

#include "shape.h"

namespace Ui {
class ShapeWizardPage;
}

/*! \class ShapeWizardPage
* \brief Classe représentant la page de gestion des formes de l'assitant de création
*/
class ShapeWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit ShapeWizardPage(QWidget *parent = 0);
    ~ShapeWizardPage();

    /*!
    *  \brief Retourne le widget permettant la gestion des formes
    *  \return Retourne le widget permettant la gestion des formes
    */
    Shape * getWidgetShape();
    
private:
    Ui::ShapeWizardPage *ui;
};

#endif // SHAPEWIZARDPAGE_H
