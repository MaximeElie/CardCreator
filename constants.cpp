#include "constants.h"

QSizeF Constants::_cardSize;
QRectF Constants::_actionPointsRect;
QRectF Constants::_manaRect;
QRectF Constants::_nameRect;
QRectF Constants::_pictureRect;
QRectF Constants::_scrollRect;
QRectF Constants::_typeRect;
QRectF Constants::_flavorTextRect;
QRectF Constants::_raritySetSymbolRect;
QRectF Constants::_illustratorRect;
QRectF Constants::_setNumberRect;
QRectF Constants::_goldCostRect;

QSizeF Constants::_manaSymbolSize;
QSizeF Constants::_scrollSymbolSize;
QSizeF Constants::_scrollSymbolAndNumberSize;

QSizeF Constants::_cardSizeScaled;

void Constants::init() {
    _cardSize = QSizeF(850,1100);
    _actionPointsRect = QRectF(115, 32, 70, 56);
    _manaRect = QRectF(210, 20, 620, 60);
    _nameRect = QRectF(200, 83, 450, 55);
    _pictureRect = QRectF(72, 145, 707, 392);
    _scrollRect = QRectF(155, 545, 540, 45);
    _typeRect = QRectF(125, 623, 600, 57);
    _flavorTextRect = QRectF(79, 691, 696, 287);
    _raritySetSymbolRect = QRectF(28, 986, 127, 88);
    _illustratorRect = QRectF(165, 1015, 400, 50);
    _setNumberRect = QRectF(570, 1015, 150, 50);
    _goldCostRect = QRectF(735, 1010, 90, 50);

    _manaSymbolSize = QSizeF(50,50);
    _scrollSymbolSize = QSizeF(35,35);
    _scrollSymbolAndNumberSize = QSizeF(90,45);

    _cardSizeScaled = QSizeF(680,880);
}

double Constants::scaleFactorX() { return _cardSizeScaled.width()/_cardSize.width(); }
double Constants::scaleFactorY() { return _cardSizeScaled.height()/_cardSize.height(); }

QRect Constants::scaleRect(const QRectF r) { return QRectF(r.x()*scaleFactorX(), r.y()*scaleFactorY(), r.width()*scaleFactorX(), r.height()*scaleFactorY()).toAlignedRect(); }
QSize Constants::scaleSize(const QSizeF s) { return QSizeF(s.width()*scaleFactorX(), s.height()*scaleFactorY()).toSize(); }

QRect Constants::actionPointsRect() { return scaleRect(_actionPointsRect); }
QRect Constants::manaRect() { return scaleRect(_manaRect); }
QRect Constants::nameRect() { return scaleRect(_nameRect); }
QRect Constants::pictureRect() { return scaleRect(_pictureRect); }
QRect Constants::scrollRect() {return scaleRect(_scrollRect); }
QRect Constants::typeRect() { return scaleRect(_typeRect); }
QRect Constants::flavorTextRect() { return scaleRect(_flavorTextRect); }
QRect Constants::raritySetSymbolRect() { return scaleRect(_raritySetSymbolRect); }
QRect Constants::illustratorRect() { return scaleRect(_illustratorRect); }
QRect Constants::setNumberRect() { return scaleRect(_setNumberRect); }
QRect Constants::goldCostRect() { return scaleRect(_goldCostRect); }

QSize Constants::manaSymbolSize() { return scaleSize(_manaSymbolSize); }
QSize Constants::scrollSymbolSize() { return scaleSize(_scrollSymbolSize); }
QSize Constants::scrollSymbolAndNumberSize() { return scaleSize(_scrollSymbolAndNumberSize); }

QSize Constants::cardSize() { return _cardSizeScaled.toSize();; }
