#ifndef ROTATIONMAX_H
#define ROTATIONMAX_H

#include <QWidget>

namespace Ui {
class RotationMax;
}

class RotationMax : public QWidget
{
    Q_OBJECT
    
public:
    explicit RotationMax(QWidget *parent = 0);
    ~RotationMax();

    int getValue();

    void reinitUI();

private slots:
    void on_sliderAngle_valueChanged(int value);
    
private:
    Ui::RotationMax *ui;
};

#endif // ROTATIONMAX_H
