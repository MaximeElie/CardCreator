#include "constants.h"

QSizeF Constants::_cardSize;
QRectF Constants::_nameRect;
QRectF Constants::_pictureRect;
QRectF Constants::_scrollRect;
QRectF Constants::_typeRect;
QRectF Constants::_flavorTextRect;

QSizeF Constants::_scrollSymbolSize;
QSizeF Constants::_scrollSymbolAndNumberSize;

QSizeF Constants::_cardSizeScaled;

void Constants::init() {
    _cardSize = QSizeF(850,1100);
    _nameRect = QRectF(125,83,600,55);
    _pictureRect = QRectF(72,145,707,392);
    _scrollRect = QRectF(155,545,540,45);
    _typeRect = QRectF(125,623,600,57);
    _flavorTextRect = QRectF(79,691,696,287);

    _scrollSymbolSize = QSizeF(35,35);
    _scrollSymbolAndNumberSize = QSizeF(90,45);

    _cardSizeScaled = QSizeF(680,880);
}

double Constants::scaleFactorX() { return _cardSizeScaled.width()/_cardSize.width(); }
double Constants::scaleFactorY() { return _cardSizeScaled.height()/_cardSize.height(); }

QRect Constants::scaleRect(const QRectF r) { return QRectF(r.x()*scaleFactorX(), r.y()*scaleFactorY(), r.width()*scaleFactorX(), r.height()*scaleFactorY()).toAlignedRect(); }
QSize Constants::scaleSize(const QSizeF s) { return QSizeF(s.width()*scaleFactorX(), s.height()*scaleFactorY()).toSize(); }

QRect Constants::nameRect() { return scaleRect(_nameRect); }
QRect Constants::pictureRect() { return scaleRect(_pictureRect); }
QRect Constants::scrollRect() {return scaleRect(_scrollRect); }
QRect Constants::typeRect() { return scaleRect(_typeRect); }
QRect Constants::flavorTextRect() { return scaleRect(_flavorTextRect); }

QSize Constants::scrollSymbolSize() { return scaleSize(_scrollSymbolSize); }
QSize Constants::scrollSymbolAndNumberSize() { return scaleSize(_scrollSymbolAndNumberSize); }

QSize Constants::cardSize() { return _cardSizeScaled.toSize();; }
