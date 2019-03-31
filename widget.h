#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QSpinBox>
#include <QFileDialog>
#include <QDir>

#include "options.h"
#include "constants.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {

    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void updateBackground();
    void updateBorderPixmaps();
    void updateManaSymbolPixmaps();
    void updatescrollSymbolPixmaps();
    void updateFont();
    void updateCard();
    void updatePicture();
    void updateRarityAndSetSymbol();

public slots:
    void updateAll();
    void updateActionPoints();
    void updateMana();
    void updateName();
    void openPicture();
    void updateScroll();
    void updateType();
    void updateFlavorText();
    void updateBorderColor();
    void openRarityAndSetSymbol();
    void updateIllustratorName();
    void updateSetNumber();
    void updateGoldCost();
    void options();
    void save();

private:
    Ui::Widget* ui;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* background;
    QGraphicsTextItem* actionPoints;
    QMap<QString, QPixmap> manaSymbolPixmaps;
    QList<QGraphicsPixmapItem*> manaSymbols;
    QGraphicsTextItem* name;
    QGraphicsPixmapItem* picture;
    QMap<QString, QPixmap> scrollSymbolPixmaps;
    QList<QGraphicsPixmapItem*> scrollSymbols;
    QList<QGraphicsTextItem*> scrollValues;
    QGraphicsTextItem* type;
    QGraphicsTextItem* flavor;
    QMap<QString, QPixmap> borderPixmaps;
    QGraphicsPixmapItem* border;
    QGraphicsPixmapItem* rarityAndSetSymbol;
    QGraphicsTextItem* illustratorName;
    QGraphicsTextItem* setNumber;
    QGraphicsTextItem* goldCost;
    Options* optionsWindow;
};

#endif // WIDGET_H
