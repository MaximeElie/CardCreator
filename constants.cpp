#include "constants.h"

bool Constants::_returnScaledValues = true;

int Constants::_textFontComboBoxIndex;
QString Constants::_textFontFamily;
int Constants::_numberFontComboBoxIndex;
QString Constants::_numberFontFamily;
bool Constants::_numberFontEnabled;

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
int Constants::_spaceBetweenManaSymbols;
QSizeF Constants::_scrollSymbolSize;

QSizeF Constants::_cardSizeScaled;

#include <QTextStream>

void Constants::init() {

    QDir dir(qApp->applicationDirPath()+"/fonts/");
    for(QString fontFile : dir.entryList(QStringList() << "*.ttf" << "*.ttc" << "*.otf",QDir::Files)) {
        QFontDatabase::addApplicationFont(dir.path()+"/"+fontFile);
    }

    QFile file(qApp->applicationDirPath()+"/data.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    update(doc.object());

    _cardSizeScaled = QSizeF(680,880);
}

void Constants::setReturnScaledValues(bool b) { _returnScaledValues = b; }

void Constants::update(QJsonObject obj) {

    _textFontComboBoxIndex = obj["textFontComboBoxIndex"].toInt();
    _textFontFamily = obj["textFontFamily"].toString();
    _numberFontComboBoxIndex = obj["numberFontComboBoxIndex"].toInt();
    _numberFontFamily = obj["numberFontFamily"].toString();
    _numberFontEnabled = obj["numberFontEnabled"].toBool();

    _cardSize.setWidth(obj["card"].toObject()["w"].toInt());
    _cardSize.setHeight(obj["card"].toObject()["h"].toInt());

    _actionPointsRect.setX(obj["actionPoints"].toObject()["x"].toInt());
    _actionPointsRect.setY(obj["actionPoints"].toObject()["y"].toInt());
    _actionPointsRect.setWidth(obj["actionPoints"].toObject()["w"].toInt());
    _actionPointsRect.setHeight(obj["actionPoints"].toObject()["h"].toInt());

    _manaRect.setX(obj["mana"].toObject()["x"].toInt());
    _manaRect.setY(obj["mana"].toObject()["y"].toInt());
    _manaRect.setWidth(obj["mana"].toObject()["w"].toInt());
    _manaRect.setHeight(obj["mana"].toObject()["h"].toInt());

    _nameRect.setX(obj["name"].toObject()["x"].toInt());
    _nameRect.setY(obj["name"].toObject()["y"].toInt());
    _nameRect.setWidth(obj["name"].toObject()["w"].toInt());
    _nameRect.setHeight(obj["name"].toObject()["h"].toInt());

    _pictureRect.setX(obj["picture"].toObject()["x"].toInt());
    _pictureRect.setY(obj["picture"].toObject()["y"].toInt());
    _pictureRect.setWidth(obj["picture"].toObject()["w"].toInt());
    _pictureRect.setHeight(obj["picture"].toObject()["h"].toInt());

    _scrollRect.setX(obj["scroll"].toObject()["x"].toInt());
    _scrollRect.setY(obj["scroll"].toObject()["y"].toInt());
    _scrollRect.setWidth(obj["scroll"].toObject()["w"].toInt());
    _scrollRect.setHeight(obj["scroll"].toObject()["h"].toInt());

    _typeRect.setX(obj["type"].toObject()["x"].toInt());
    _typeRect.setY(obj["type"].toObject()["y"].toInt());
    _typeRect.setWidth(obj["type"].toObject()["w"].toInt());
    _typeRect.setHeight(obj["type"].toObject()["h"].toInt());

    _flavorTextRect.setX(obj["flavorText"].toObject()["x"].toInt());
    _flavorTextRect.setY(obj["flavorText"].toObject()["y"].toInt());
    _flavorTextRect.setWidth(obj["flavorText"].toObject()["w"].toInt());
    _flavorTextRect.setHeight(obj["flavorText"].toObject()["h"].toInt());

    _raritySetSymbolRect.setX(obj["rarityAndSetSymbol"].toObject()["x"].toInt());
    _raritySetSymbolRect.setY(obj["rarityAndSetSymbol"].toObject()["y"].toInt());
    _raritySetSymbolRect.setWidth(obj["rarityAndSetSymbol"].toObject()["w"].toInt());
    _raritySetSymbolRect.setHeight(obj["rarityAndSetSymbol"].toObject()["h"].toInt());

    _illustratorRect.setX(obj["illustratorName"].toObject()["x"].toInt());
    _illustratorRect.setY(obj["illustratorName"].toObject()["y"].toInt());
    _illustratorRect.setWidth(obj["illustratorName"].toObject()["w"].toInt());
    _illustratorRect.setHeight(obj["illustratorName"].toObject()["h"].toInt());

    _setNumberRect.setX(obj["setNumber"].toObject()["x"].toInt());
    _setNumberRect.setY(obj["setNumber"].toObject()["y"].toInt());
    _setNumberRect.setWidth(obj["setNumber"].toObject()["w"].toInt());
    _setNumberRect.setHeight(obj["setNumber"].toObject()["h"].toInt());

    _goldCostRect.setX(obj["goldCost"].toObject()["x"].toInt());
    _goldCostRect.setY(obj["goldCost"].toObject()["y"].toInt());
    _goldCostRect.setWidth(obj["goldCost"].toObject()["w"].toInt());
    _goldCostRect.setHeight(obj["goldCost"].toObject()["h"].toInt());

    _manaSymbolSize.setWidth(obj["manaSymbol"].toObject()["w"].toInt());
    _manaSymbolSize.setHeight(obj["manaSymbol"].toObject()["h"].toInt());

    _spaceBetweenManaSymbols = obj["spaceBetweenManaSymbols"].toInt();

    _scrollSymbolSize.setWidth(obj["scrollSymbol"].toObject()["w"].toInt());
    _scrollSymbolSize.setHeight(obj["scrollSymbol"].toObject()["h"].toInt());
}

void Constants::saveToJson() {

    QFile file(qApp->applicationDirPath()+"/data.json");

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't save data.");
        return;
    }

    QJsonObject obj;
    QJsonObject tmp;

    obj["textFontComboBoxIndex"] = _textFontComboBoxIndex;
    obj["textFontFamily"] = _textFontFamily;
    obj["numberFontComboBoxIndex"] = _numberFontComboBoxIndex;
    obj["numberFontFamily"] = _numberFontFamily;
    obj["numberFontEnabled"] = _numberFontEnabled;

    tmp["w"] = _cardSize.width();
    tmp["h"] = _cardSize.height();
    obj["card"] = tmp;

    tmp["x"] = _actionPointsRect.x();
    tmp["y"] = _actionPointsRect.y();
    tmp["w"] = _actionPointsRect.width();
    tmp["h"] = _actionPointsRect.height();
    obj["actionPoints"] = tmp;

    tmp["x"] = _manaRect.x();
    tmp["y"] = _manaRect.y();
    tmp["w"] = _manaRect.width();
    tmp["h"] = _manaRect.height();
    obj["mana"] = tmp;

    tmp["x"] = _nameRect.x();
    tmp["y"] = _nameRect.y();
    tmp["w"] = _nameRect.width();
    tmp["h"] = _nameRect.height();
    obj["name"] = tmp;

    tmp["x"] = _pictureRect.x();
    tmp["y"] = _pictureRect.y();
    tmp["w"] = _pictureRect.width();
    tmp["h"] = _pictureRect.height();
    obj["picture"] = tmp;

    tmp["x"] = _scrollRect.x();
    tmp["y"] = _scrollRect.y();
    tmp["w"] = _scrollRect.width();
    tmp["h"] = _scrollRect.height();
    obj["scroll"] = tmp;

    tmp["x"] = _typeRect.x();
    tmp["y"] = _typeRect.y();
    tmp["w"] = _typeRect.width();
    tmp["h"] = _typeRect.height();
    obj["type"] = tmp;

    tmp["x"] = _flavorTextRect.x();
    tmp["y"] = _flavorTextRect.y();
    tmp["w"] = _flavorTextRect.width();
    tmp["h"] = _flavorTextRect.height();
    obj["flavorText"] = tmp;

    tmp["x"] = _raritySetSymbolRect.x();
    tmp["y"] = _raritySetSymbolRect.y();
    tmp["w"] = _raritySetSymbolRect.width();
    tmp["h"] = _raritySetSymbolRect.height();
    obj["rarityAndSetSymbol"] = tmp;

    tmp["x"] = _illustratorRect.x();
    tmp["y"] = _illustratorRect.y();
    tmp["w"] = _illustratorRect.width();
    tmp["h"] = _illustratorRect.height();
    obj["illustratorName"] = tmp;

    tmp["x"] = _setNumberRect.x();
    tmp["y"] = _setNumberRect.y();
    tmp["w"] = _setNumberRect.width();
    tmp["h"] = _setNumberRect.height();
    obj["setNumber"] = tmp;

    tmp["x"] = _goldCostRect.x();
    tmp["y"] = _goldCostRect.y();
    tmp["w"] = _goldCostRect.width();
    tmp["h"] = _goldCostRect.height();
    obj["goldCost"] = tmp;

    tmp = QJsonObject();

    tmp["w"] = _manaSymbolSize.width();
    tmp["h"] = _manaSymbolSize.height();
    obj["manaSymbol"] = tmp;

    obj["spaceBetweenManaSymbols"] = _spaceBetweenManaSymbols;

    tmp["w"] = _scrollSymbolSize.width();
    tmp["h"] = _scrollSymbolSize.height();
    obj["scrollSymbol"] = tmp;

    QJsonDocument doc(obj);
    file.write(doc.toJson());
}

void Constants::setTextFontComboBoxIndex(int index) { _textFontComboBoxIndex = index; }
int Constants::textFontComboBoxIndex() { return _textFontComboBoxIndex; }
void Constants::setTextFontFamily(QString fontFamily) { _textFontFamily = fontFamily; }
QString Constants::textFontFamily() { return _textFontFamily; }
void Constants::setNumberFontComboBoxIndex(int index) { _numberFontComboBoxIndex = index; }
int Constants::numberFontComboBoxIndex() { return _numberFontComboBoxIndex; }
void Constants::setNumberFontFamily(QString fontFamily) { _numberFontFamily = fontFamily; }
QString Constants::numberFontFamily() { return _numberFontEnabled ? _numberFontFamily : _textFontFamily; }
void Constants::setNumberFontEnabled(bool b) { _numberFontEnabled = b; }
bool Constants::isNumberFontEnabled() { return _numberFontEnabled; }

double Constants::scaleFactorX() { return _cardSizeScaled.width()/_cardSize.width(); }
double Constants::scaleFactorY() { return _cardSizeScaled.height()/_cardSize.height(); }

QRect Constants::scaleRect(const QRectF r) { return !_returnScaledValues ? r.toAlignedRect() : QRectF(r.x()*scaleFactorX(), r.y()*scaleFactorY(), r.width()*scaleFactorX(), r.height()*scaleFactorY()).toAlignedRect(); }
QSize Constants::scaleSize(const QSizeF s) { return !_returnScaledValues ? s.toSize() : QSizeF(s.width()*scaleFactorX(), s.height()*scaleFactorY()).toSize(); }

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
int Constants::spaceBetweenManaSymbols() { return _spaceBetweenManaSymbols; }
QSize Constants::scrollSymbolSize() { return scaleSize(_scrollSymbolSize); }

QSize Constants::cardSize() { return scaleSize(_cardSize); }
