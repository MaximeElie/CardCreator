#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QFontDatabase>
#include <QFont>
#include <QSize>
#include <QPoint>
#include <QRect>

class Constants {

private:

    static bool _returnScaledValues;

    static int _textFontComboBoxIndex;
    static QString _textFontFamily;
    static int _numberFontComboBoxIndex;
    static QString _numberFontFamily;
    static bool _numberFontEnabled;

    static QSizeF _cardSize;

    static QRectF _actionPointsRect;
    static QRectF _manaRect;
    static QRectF _nameRect;
    static QRectF _pictureRect;
    static QRectF _scrollRect;
    static QRectF _typeRect;
    static QRectF _flavorTextRect;
    static QRectF _raritySetSymbolRect;
    static QRectF _illustratorRect;
    static QRectF _setNumberRect;
    static QRectF _goldCostRect;

    static QSizeF _manaSymbolSize;
    static int _spaceBetweenManaSymbols;
    static QSizeF _scrollSymbolSize;

    static QSizeF _cardSizeScaled;


    static double scaleFactorX();
    static double scaleFactorY();

    static QRect scaleRect(const QRectF r);
    static QSize scaleSize(const QSizeF r);

public:

    static void setReturnScaledValues(bool);

    static void init();
    static void update(QJsonObject);
    static void saveToJson();

    static void setTextFontComboBoxIndex(int);
    static int textFontComboBoxIndex();
    static void setTextFontFamily(QString);
    static QString textFontFamily();
    static void setNumberFontComboBoxIndex(int);
    static int numberFontComboBoxIndex();
    static void setNumberFontFamily(QString);
    static QString numberFontFamily();
    static void setNumberFontEnabled(bool);
    static bool isNumberFontEnabled();

    static QRect actionPointsRect();
    static QRect manaRect();
    static QRect nameRect();
    static QRect pictureRect();
    static QRect scrollRect();
    static QRect typeRect();
    static QRect flavorTextRect();
    static QRect raritySetSymbolRect();
    static QRect illustratorRect();
    static QRect setNumberRect();
    static QRect goldCostRect();

    static QSize manaSymbolSize();
    static int spaceBetweenManaSymbols();
    static QSize scrollSymbolSize();

    static QSize cardSize();

};

#endif // CONSTANTS_H
