#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QSpinBox>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include "constants.h"

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
    void updateScroll();
    void openArt();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *art;
    QGraphicsPixmapItem *background;
    QMap<QString, QPixmap> scrollSymbolPixmaps;
    QList<QGraphicsPixmapItem*> scrollSymbols;
    QGraphicsTextItem *name;
    QList<QGraphicsTextItem*> scrollValues;
    QGraphicsTextItem* type;
    QGraphicsTextItem* flavor;
};

#endif // WIDGET_H
