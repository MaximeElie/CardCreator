#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void updateTextItems();
    void openArt();

private:
    Ui::Widget *ui;
    QImage backgroundImage;
    QImage artImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *artPixMap;
    QGraphicsPixmapItem *backgroundPixmap;
    QGraphicsTextItem *name;
    QGraphicsTextItem *flavor;
};

#endif // WIDGET_H
