#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QSize>
#include <QPoint>
#include <QRect>

class Constants {

private:
    static QSizeF _cardSize;

    static QRectF _nameRect;
    static QRectF _pictureRect;
    static QRectF _scrollRect;
    static QRectF _typeRect;
    static QRectF _flavorTextRect;

    static QSizeF _scrollSymbolSize;
    static QSizeF _scrollSymbolAndNumberSize;

    static QSizeF _cardSizeScaled;


    static double scaleFactorX();
    static double scaleFactorY();

    static QRect scaleRect(const QRectF r);
    static QSize scaleSize(const QSizeF r);

public:

    static void init();

    static QRect nameRect();
    static QRect pictureRect();
    static QRect scrollRect();
    static QRect typeRect();
    static QRect flavorTextRect();

    static QSize scrollSymbolSize();
    static QSize scrollSymbolAndNumberSize();

    static QSize cardSize();

};

#endif // CONSTANTS_H
