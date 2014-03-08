#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>

#include "photoswizardpage.h"

namespace Ui {
class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

    void accept();
    
private:
    Ui::Wizard *ui;
};

#endif // WIZARD_H
