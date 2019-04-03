#include "flavortext.h"

#include <QFontMetrics>
#include <QTextStream>

FlavorText::FlavorText(QGraphicsScene* scene) {
    _scene = scene;
}

void FlavorText::update(QString text, bool centered) {

    for(QGraphicsTextItem* item : _lines) _scene->removeItem(item);
    _lines.clear();

    QStringList lines = text.split('\n');
    QFont font(Constants::textFontFamily());
    int nbLines = Constants::flavorTextAmountOfLinesAtWidestFontSize();
    font.setPixelSize(Constants::flavorTextRect().height()/nbLines);
    QFontMetrics fm(font);

    bool reduceSize;

    do {

        for(int i = 0 ; i < text.count('\n')+1 ; i++) {
            if(!addLines(lines[i], fm)) {
                for(QGraphicsTextItem* item : _lines) _scene->removeItem(item);
                _lines.clear();
                return;
            }
        }

        reduceSize = false;
        if(font.pixelSize()*_lines.count()>Constants::flavorTextRect().height()) {
            reduceSize = true;
            nbLines++;
            int newPixelSize = Constants::flavorTextRect().height()/nbLines;
            if(!(newPixelSize>0)) return;
            font.setPixelSize(newPixelSize);
            fm = QFontMetrics(font);
            _lines.clear();
        }

    } while(reduceSize);

    for(int i = 0 ; i < _lines.count(); i++) {
        _lines[i]->setFont(font);
        int posX = Constants::flavorTextRect().left();
        if(centered)
            posX = Constants::flavorTextRect().center().x() - _lines[i]->boundingRect().width()/2;
        int posY = Constants::flavorTextRect().top() + i*font.pixelSize();
        _lines[i]->setPos(posX, posY);
        _scene->addItem(_lines[i]);
    }
}

bool FlavorText::addLines(QString line, QFontMetrics fm) {

    QStringList words = line.split(' ');
    QStringList wordsRemoved;
    bool firstLetterRemoved = false;

    while(fm.boundingRect(words.join(' ')).width() >= Constants::flavorTextRect().width()) {
        if(!(words.join(' ').length() > 1)) return false;
        else if(words.count()==1) {
            if(!firstLetterRemoved) { firstLetterRemoved = true; wordsRemoved.push_front(""); }
            QString word = words.first();
            wordsRemoved.replace(0, word.at(word.count()-1)+wordsRemoved.first());
            word.chop(1);
            words.replace(0, word);
        }
        else {
            wordsRemoved.push_front(words.last());
            words.pop_back();
        }
    }

    _lines.append(new QGraphicsTextItem(words.join(' ')));

    return wordsRemoved.isEmpty() ? true : addLines(wordsRemoved.join(' '), fm);
}
