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
    void updateMana();
    void updateTextItems();
    void openArt();
    void updateScroll();
    void openRarityAndSetSymbol();
    void save();

private:
    Ui::Widget* ui;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* background;
    QMap<QString, QPixmap> manaSymbolPixmaps;
    QList<QGraphicsPixmapItem*> manaSymbols;
    QGraphicsPixmapItem* picture;
    QMap<QString, QPixmap> scrollSymbolPixmaps;
    QList<QGraphicsPixmapItem*> scrollSymbols;
    QGraphicsPixmapItem* rarityAndSetSymbol;
    QGraphicsTextItem* actionPoints;
    QGraphicsTextItem* name;
    QList<QGraphicsTextItem*> scrollValues;
    QGraphicsTextItem* type;
    QGraphicsTextItem* flavor;
    QGraphicsTextItem* illustratorName;
    QGraphicsTextItem* setNumber;
    QGraphicsTextItem* goldCost;
};

#endif // WIDGET_H
