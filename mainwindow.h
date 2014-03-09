#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "math.h"

#include "tools.h"
#include "collage.h"
#include "photos.h"
#include "wizard.h"
#include "dialogabout.h"

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

    void on_pushButtonReinitFormeTaille_clicked();

    void on_pushButtonCreate_clicked();

    void on_actionNouveau_projet_triggered();

    void on_actionAjouter_des_photos_triggered();

    void on_actionCr_er_un_collage_triggered();

    void on_action_propos_triggered();

    void on_actionAide_la_cr_ation_triggered();

private:
    Ui::MainWindow *ui;
    Collage mCollage;
    Wizard wizard;
    DialogAbout dialogAbout;

    void reinitUI();
    void clearApercu();
    void createCollage();
};

#endif // MAINWINDOW_H
