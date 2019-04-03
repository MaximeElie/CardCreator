#ifndef FLAVORTEXT_H
#define FLAVORTEXT_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QList>

#include "constants.h"

class FlavorText
{
public:
    FlavorText(QGraphicsScene* scene);
    void update(QString text, bool centered);

private:
    QGraphicsScene* _scene;
    QList<QGraphicsTextItem*> _lines;

    bool addLines(QString line, QFontMetrics fm);

};

#endif // FLAVORTEXT_H
