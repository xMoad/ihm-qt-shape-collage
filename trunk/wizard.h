#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>

#include "collage.h"

namespace Ui {
class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

    void reinitUI();
    void accept();
    
private:
    Ui::Wizard *ui;
    Collage mCollage;
};

#endif // WIZARD_H
