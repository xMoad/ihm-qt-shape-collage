#ifndef CREATIONWIZARDPAGE_H
#define CREATIONWIZARDPAGE_H

#include <QWizardPage>

namespace Ui {
class CreationWizardPage;
}

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
