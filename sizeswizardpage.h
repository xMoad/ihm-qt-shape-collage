#ifndef SIZESWIZARDPAGE_H
#define SIZESWIZARDPAGE_H

#include <QWizardPage>

#include "sizes.h"
#include "rotationmax.h"

namespace Ui {
class SizesWizardPage;
}

class SizesWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit SizesWizardPage(QWidget *parent = 0);
    ~SizesWizardPage();

    Sizes * getWidgetSizes();
    RotationMax * getWidgetRotationMax();
    
private:
    Ui::SizesWizardPage *ui;
};

#endif // SIZESWIZARDPAGE_H
