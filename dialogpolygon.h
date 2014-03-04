#ifndef DIALOGPOLYGON_H
#define DIALOGPOLYGON_H

#include <QDialog>

namespace Ui {
class DialogPolygon;
}

class DialogPolygon : public QDialog
{
    Q_OBJECT
    
public:
    QPolygon mPolygon;

    explicit DialogPolygon(QWidget *parent = 0);
    ~DialogPolygon();
    
private slots:
    void on_pushButtonReinitPolygon_clicked();

private:
    Ui::DialogPolygon *ui;

    QPixmap *mPixmap;

    void drawPolygon();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void reinitPixmap();
};

#endif // DIALOGPOLYGON_H
