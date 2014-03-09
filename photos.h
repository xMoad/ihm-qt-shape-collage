#ifndef PHOTOS_H
#define PHOTOS_H

/*!
 * \file photos.h
 * \brief Widget permettant la gestion des photos
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWidget>

#include "tools.h"

namespace Ui {
class Photos;
}

/*! \class Photos
* \brief Classe représentant un widget permettant la gestion des photos
*/
class Photos : public QWidget
{
    Q_OBJECT
    
public:

    Photos(QWidget *parent = 0);
    ~Photos();

    // getters
    inline QList<QImage> * getListPhotos() { return &mListPhotos; }
    inline int countListPhotos() { return mListPhotos.count(); }

    /*!
    *  \brief Ouvre une boîte de dialogue permettant à l'utilisateur d'ajouter une ou plusieurs photos
    */
    void addPhotos();

    /*!
    *  \brief Ré-initialise la liste des photos chargé par l'utilisateur
    */
    void clearListPhotos();

    /*!
    *  \brief Ajuste le widget pour que celui-ci prenne moins de place et puisse être intégré dans l'assistant de création
    */
    void setWizardLayout();

    /*!
    *  \brief Ré-initialise l'interface
    */
    void reinitUI();

signals:
    void nbPhotosChanged();
    
private slots:

    /*!
    *  \brief Met à jour l'affichage du nombre de photos ainsi que la propriété "NbPhotos"
    */
    void majNbPhotos();

    void on_pushButton_clicked();

    void on_pushButtonMoins_clicked();

    void on_listWidgetImages_itemSelectionChanged();

    void on_pushButtonClearImagesList_clicked();

    void on_pushButtonAddFromFolder_clicked();


private:
    Ui::Photos *ui;    
    QList<QImage> mListPhotos; /*!< Liste des photos chargées par l'utilisateur*/
};

#endif // PHOTOS_H
