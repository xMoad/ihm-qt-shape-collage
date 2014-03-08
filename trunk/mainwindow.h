#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include "math.h"

#include "tools.h"
#include "dialogpolygon.h"
#include "collage.h"
#include "photos.h"
#include "wizard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void majCollage();

    void renderApercu();

    void on_actionQuitter_triggered();

    void on_pushButtonApercu_clicked();

    void on_radioButtonPolygone_clicked();

    void on_pushButtonAutoManuelTailleCollage_clicked();

    void on_pushButtonAutoManuelTaillePhoto_clicked();

    void on_pushButtonAutoManuelNbPhoto_clicked();

    void on_pushButtonAutoManuelDistancePhoto_clicked();

    void on_radioButtonToutesPhotos_clicked();

    void on_radioButtonNbPhotos_clicked();

    void on_horizontalSliderDistancePhotos_valueChanged(int value);

    void on_spinBoxDistancePhotos_valueChanged(int arg1);

    void on_pushButtonReinitFormeTaille_clicked();

    void on_pushButtonCreate_clicked();

    void on_sliderAngle_valueChanged(int value);

    void on_actionNouveau_projet_triggered();

    void on_actionAjouter_des_photos_triggered();

    void on_actionCr_er_un_collage_triggered();

    void on_action_propos_triggered();

    void on_actionAide_la_cr_ation_triggered();

private:
    Ui::MainWindow *ui;
    DialogPolygon dialogPolygon;
    Collage mCollage;
    QIntValidator *mUIntValidator;    
    Wizard wizard;

    void majTaille();
    void reinitUI();
    void clearApercu();
    void createCollage();
};

#endif // MAINWINDOW_H
