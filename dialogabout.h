#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

/*!
 * \file dialogabout.h
 * \brief Boîte de dialogue "A propos"
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QDialog>

namespace Ui {
class DialogAbout;
}

/*! \class DialogAbout
* \brief Classe représentant une boîte de dialogue "A propos"
*/
class DialogAbout : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAbout(QWidget *parent = 0);
    ~DialogAbout();
    
private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::DialogAbout *ui;
};

#endif // DIALOGABOUT_H
