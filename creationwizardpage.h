#ifndef CREATIONWIZARDPAGE_H
#define CREATIONWIZARDPAGE_H

/*!
 * \file creationwizardpage.h
 * \brief Page de l'assistant de création, permettant la création du collage
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QWizardPage>

namespace Ui {
class CreationWizardPage;
}

/*! \class CreationWizardPage
* \brief Classe représentant la page de création de l'assitant de création
*/
class CreationWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit CreationWizardPage(QWidget *parent = 0);
    ~CreationWizardPage();
    
private slots:
    void on_pushButtonImagePath_clicked();

private:
    Ui::CreationWizardPage *ui;
};

#endif // CREATIONWIZARDPAGE_H
