#ifndef PHOTOSWIZARDPAGE_H
#define PHOTOSWIZARDPAGE_H

#include <QWizardPage>

#include "photos.h"

namespace Ui {
class PhotosWizardPage;
}

class PhotosWizardPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit PhotosWizardPage(QWidget *parent = 0);
    ~PhotosWizardPage();

    Photos * getWidgetPhotos();
    
private:
    Ui::PhotosWizardPage *ui;
};

#endif // PHOTOSWIZARDPAGE_H
