#ifndef SIZESWIZARDPAGE_H
#define SIZESWIZARDPAGE_H

#include <QWizardPage>

namespace Ui {
class SizesWizardPage;
}

class SizesWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit SizesWizardPage(QWidget *parent = 0);
    ~SizesWizardPage();
    
private:
    Ui::SizesWizardPage *ui;
};

#endif // SIZESWIZARDPAGE_H
