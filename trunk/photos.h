#ifndef PHOTOS_H
#define PHOTOS_H

#include <QWidget>

#include "tools.h"

namespace Ui {
class Photos;
}

class Photos : public QWidget
{
    Q_OBJECT
    
public:

    Photos(QWidget *parent = 0);
    ~Photos();

    inline QList<QImage> * getListPhotos() { return &mListPhotos; }
    inline int countListPhotos() { return mListPhotos.count(); }

    Photos &operator =(const Photos &);

    void addPhotos();
    void clearListPhotos();
    void setWizardLayout();
    void reinitUI();

signals:
    void nbPhotosChanged();
    
private slots:

    void majNbPhotos();

    void on_pushButton_clicked();

    void on_pushButtonMoins_clicked();

    void on_listWidgetImages_itemSelectionChanged();

    void on_pushButtonClearImagesList_clicked();

    void on_pushButtonAddFromFolder_clicked();


private:
    Ui::Photos *ui;    
    QList<QImage> mListPhotos;
};

#endif // PHOTOS_H
