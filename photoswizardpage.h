#ifndef PHOTOSWIZARDPAGE_H
#define PHOTOSWIZARDPAGE_H

/*!
 * \file photoswizardpage.h
 * \brief Page de l'assistant de création, permettant la gestion des photos
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWizardPage>

#include "photos.h"

namespace Ui {
class PhotosWizardPage;
}

/*! \class PhotosWizardPage
* \brief Classe représentant la page de gestion des photos de l'assitant de création
*/
class PhotosWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit PhotosWizardPage(QWidget *parent = 0);
    ~PhotosWizardPage();

    /*!
    *  \brief Retourne le widget permettant la gestion des photos
    *  \return Retourne le widget permettant la gestion des photos
    */
    Photos * getWidgetPhotos();
    
private:
    Ui::PhotosWizardPage *ui;
};

#endif // PHOTOSWIZARDPAGE_H
