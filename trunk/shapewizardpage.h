#ifndef SHAPEWIZARDPAGE_H
#define SHAPEWIZARDPAGE_H

#include <QWizardPage>

namespace Ui {
class ShapeWizardPage;
}

class ShapeWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit ShapeWizardPage(QWidget *parent = 0);
    ~ShapeWizardPage();
    
private:
    Ui::ShapeWizardPage *ui;
};

#endif // SHAPEWIZARDPAGE_H
