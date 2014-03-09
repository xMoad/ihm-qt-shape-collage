#ifndef DIALOGPOLYGON_H
#define DIALOGPOLYGON_H

/*!
 * \file dialogpolygon.h
 * \brief Boîte de dialogue permettant à l'utilisateur de créer un polygone
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QDialog>

namespace Ui {
class DialogPolygon;
}

/*! \class DialogPolygon
* \brief Classe représentant une boîte de dialogue permettant de créer un polygone
*/
class DialogPolygon : public QDialog
{
    Q_OBJECT
    
public:
    QPolygon mPolygon; /*!< Polygone en cours de création*/

    explicit DialogPolygon(QWidget *parent = 0);
    ~DialogPolygon();
    
private slots:
    void on_pushButtonReinitPolygon_clicked();

private:
    Ui::DialogPolygon *ui;

    QPixmap *mPixmap; /*!< Pixmap sur laquelle est dessinée le polygone*/

    /*!
     *  \brief Dessine le polygone sur la pixmap
     */
    void drawPolygon();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    /*!
     *  \brief Ré-initialise la pixmap
     */
    void reinitPixmap();
};

#endif // DIALOGPOLYGON_H
