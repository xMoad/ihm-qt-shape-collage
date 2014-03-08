#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>

#include "dialogpolygon.h"

namespace Ui {
class Shape;
}

class Shape : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shape(QWidget *parent = 0);
    ~Shape();

    QPolygon getPolygon(int w, int h);

    void reinitUI();

private slots:
    void on_radioButtonPolygone_clicked();
    
private:
    Ui::Shape *ui;
    DialogPolygon dialogPolygon;
};

#endif // SHAPE_H
