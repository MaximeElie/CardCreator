#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {

    updateBorderPixmaps();
    updateManaSymbolPixmaps();
    updatescrollSymbolPixmaps();

    scene = new QGraphicsScene(this);
    picture = scene->addPixmap(QPixmap());
    rarityAndSetSymbol = scene->addPixmap(QPixmap());
    background = scene->addPixmap(QPixmap());
    updateBackground();
    border = scene->addPixmap(QPixmap());
    actionPoints = scene->addText("");
    name = scene->addText("");
    type = scene->addText("");
    flavor = scene->addText("");
    illustratorName = scene->addText("");
    setNumber = scene->addText("");
    goldCost = scene->addText("");

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    updateCard();

    connect(ui->actionPoints, SIGNAL(valueChanged(int)), this, SLOT(updateActionPoints()));

    connect(ui->wood, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->mysticNode, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->weaponForge, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->inferno, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->darkness, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->stoneQuarry, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->colorless, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));

    connect(ui->name, SIGNAL(textChanged(QString)), this, SLOT(updateName()));

    connect(ui->picture, SIGNAL(clicked()), this, SLOT(openPicture()));

    connect(ui->attackPower, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->health, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->movement, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->rangedAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->magicAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->defense, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));

    connect(ui->superType, SIGNAL(textChanged(QString)), this, SLOT(updateType()));
    connect(ui->subType, SIGNAL(textChanged(QString)), this, SLOT(updateType()));

    connect(ui->flavorText, SIGNAL(textChanged()), this, SLOT(updateFlavorText()));

    connect(ui->borderColor, SIGNAL(activated(QString)), this, SLOT(updateBorderColor()));

    connect(ui->rarityAndSetSymbol, SIGNAL(clicked()), this, SLOT(openRarityAndSetSymbol()));
    connect(ui->illustratorName, SIGNAL(textChanged(QString)), this, SLOT(updateIllustratorName()));
    connect(ui->setNumber, SIGNAL(valueChanged(int)), this, SLOT(updateSetNumber()));
    connect(ui->setNumberTotal, SIGNAL(valueChanged(int)), this, SLOT(updateSetNumber()));
    connect(ui->goldCost, SIGNAL(valueChanged(int)), this, SLOT(updateGoldCost()));

    connect(ui->options, SIGNAL(clicked()), this, SLOT(options()));
    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::updateAll() {

    updateBackground();
    updateBorderPixmaps();
    updateManaSymbolPixmaps();
    updatescrollSymbolPixmaps();
    updateFont();
    updateCard();
}

void Widget::updateBackground() {
    background->setPixmap(QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/background.png").scaled(Constants::cardSize())));
}

void Widget::updateBorderPixmaps() {
    borderPixmaps.clear();

    borderPixmaps.insert("green_white_grey", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/green_white_grey.png").scaled(Constants::cardSize())));
    borderPixmaps.insert("black", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/black.png").scaled(Constants::cardSize())));
    borderPixmaps.insert("red", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/red.png").scaled(Constants::cardSize())));
    borderPixmaps.insert("purple", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/purple.png").scaled(Constants::cardSize())));
    borderPixmaps.insert("blue_gold", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/blue_gold.png").scaled(Constants::cardSize())));
}

void Widget::updateManaSymbolPixmaps() {

    manaSymbolPixmaps.clear();

    manaSymbolPixmaps.insert("wood", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/wood.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("mystic_node", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/mystic_node.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("weapon_forge", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/weapon_forge.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("inferno", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/inferno.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("darkness", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/darkness.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("stone_quarry", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/stone_quarry.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("colorless", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/colorless.png").scaled(Constants::manaSymbolSize())));
}

void Widget::updatescrollSymbolPixmaps() {

    scrollSymbolPixmaps.clear();

    scrollSymbolPixmaps.insert("attack_power", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/attack_power.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("health", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/health.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("movement", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/movement.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("ranged_attack", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/ranged_attack.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("magic_attack", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/magic_attack.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("defense", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/defense.png").scaled(Constants::scrollSymbolSize())));
}

void Widget::updateFont() { /////////////////////////////////////////////// faire

}

void Widget::updateCard() {
    updateActionPoints();
    updateMana();
    updateName();
    updatePicture();
    updateScroll();
    updateType();
    updateFlavorText();
    updateBorderColor();
    updateRarityAndSetSymbol();
    updateIllustratorName();
    updateSetNumber();
    updateGoldCost();
}

void updateText(QGraphicsTextItem* item, QString text, QRect rect, Qt::Alignment alignment) {

    QRectF boundingRect;

    item->setPlainText(text);
    item->setFont(QFont("Arial", 100));
    boundingRect = item->boundingRect();
    while(boundingRect.width()>rect.width() || boundingRect.height()>rect.height()) {
        item->setFont(QFont("Arial", item->font().pointSize()-1));
        boundingRect = item->boundingRect();
    }

    int posX;

    switch(alignment) {
        case Qt::AlignLeft: posX = rect.left(); break;
        case Qt::AlignCenter: posX = rect.center().x() - boundingRect.width()/2; break;
        case Qt::AlignRight: posX = rect.right() - boundingRect.width(); break;
        default: posX = rect.center().x() - boundingRect.width()/2;;
    }

    item->setPos(posX, rect.center().y() - boundingRect.height()/2);
}

void Widget::updateActionPoints() {
    updateText(actionPoints, QString::number(ui->actionPoints->value()), Constants::actionPointsRect(), Qt::AlignCenter);
}

void Widget::updateMana() {

    for(QGraphicsPixmapItem* item : manaSymbols) scene->removeItem(item);
    manaSymbols.clear();

    for(int i = 0 ; i < ui->wood->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["wood"]));
    for(int i = 0 ; i < ui->mysticNode->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["mystic_node"]));
    for(int i = 0 ; i < ui->weaponForge->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["weapon_forge"]));
    for(int i = 0 ; i < ui->inferno->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["inferno"]));
    for(int i = 0 ; i < ui->darkness->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["darkness"]));
    for(int i = 0 ; i < ui->stoneQuarry->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["stone_quarry"]));
    for(int i = 0 ; i < ui->colorless->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["colorless"]));

    int firstSymbolLeft = Constants::manaRect().right() - manaSymbols.count()*(Constants::manaSymbolSize().width()+Constants::spaceBetweenManaSymbols());

    for(int i = 0 ; i < manaSymbols.count() ; i++) {
        int symbolX = firstSymbolLeft + i*Constants::manaSymbolSize().width() + i*Constants::spaceBetweenManaSymbols();
        int symbolY = Constants::manaRect().y() + (Constants::manaRect().height()-Constants::manaSymbolSize().height())/2;
        manaSymbols[i]->setPos(symbolX,symbolY);
    }

}

void Widget::updateName() {
    updateText(name, ui->name->text(), Constants::nameRect(), Qt::AlignCenter);
}

void Widget::openPicture() {

    QString fileName = QFileDialog::getOpenFileName(this, "Open Picture", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!fileName.isEmpty()) {
        picture->setPixmap(QPixmap::fromImage(QImage(fileName).scaled(Constants::pictureRect().size())));
        updatePicture();
    }
}

void Widget::updatePicture() {
    picture->setPos(Constants::pictureRect().topLeft());
}

void Widget::updateScroll() {//////////////////////////////////////////////////

    for(QGraphicsPixmapItem* item : scrollSymbols) scene->removeItem(item);
    scrollSymbols.clear();
    for(QGraphicsTextItem* item : scrollValues) scene->removeItem(item);
    scrollValues.clear();

    if(ui->attackPower->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["attack_power"]));
        scrollValues.append(scene->addText(QString::number(ui->attackPower->value())));
    }
    if(ui->health->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["health"]));
        scrollValues.append(scene->addText(QString::number(ui->health->value())));
    }
    if(ui->movement->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["movement"]));
        scrollValues.append(scene->addText(QString::number(ui->movement->value())));
    }
    if(ui->rangedAttack->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["ranged_attack"]));
        scrollValues.append(scene->addText(QString::number(ui->rangedAttack->value())));
    }
    if(ui->magicAttack->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["magic_attack"]));
        scrollValues.append(scene->addText(QString::number(ui->magicAttack->value())));
    }
    if(ui->defense->value()>0) {
        scrollSymbols.append(scene->addPixmap(scrollSymbolPixmaps["defense"]));
        scrollValues.append(scene->addText(QString::number(ui->defense->value())));
    }

    if(scrollSymbols.isEmpty()) return;

    int symbolCaseWidth = Constants::scrollRect().width()/scrollSymbols.count();
    int firstSymbolLeft = Constants::scrollRect().left() + symbolCaseWidth/2 - Constants::scrollSymbolSize().width();

    for(int i = 0 ; i < scrollSymbols.count() ; i++) {
        int symbolX = firstSymbolLeft + i*symbolCaseWidth;
        int symbolY = Constants::scrollRect().y() + (Constants::scrollRect().height()-Constants::scrollSymbolSize().height())/2;
        scrollSymbols[i]->setPos(symbolX,symbolY);
        scrollValues[i]->setFont(QFont("Arial", 15));////////////////////////////////////////////////////////////////////////////////////////////////////////// taille police auto
        scrollValues[i]->setPos(symbolX+Constants::scrollSymbolSize().width(),symbolY); ////////////////////////////////////////////////////////////////////// position y auto
    }
}

void Widget::updateType() {
    QString superTypeStr = ui->superType->text();
    QString subTypeStr = ui->subType->text();
    QString typeStr = (superTypeStr.isEmpty() || subTypeStr.isEmpty()) ? superTypeStr+subTypeStr : superTypeStr + " - " + subTypeStr;
    updateText(type, typeStr, Constants::typeRect(), Qt::AlignCenter);
}

void Widget::updateFlavorText() {/////////////////////////////////// centrer

    QRectF boundingRect;

    flavor->setPlainText(ui->flavorText->toPlainText());
    flavor->setTextWidth(-1);
    flavor->setFont(QFont("Arial", 40));
    boundingRect = flavor->boundingRect();
    if(boundingRect.width()>Constants::flavorTextRect().width()) {
        flavor->setTextWidth(Constants::flavorTextRect().width());
        boundingRect = flavor->boundingRect();
        while(boundingRect.height()>Constants::flavorTextRect().height()) {
            flavor->setFont(QFont("Arial", flavor->font().pointSize()-1));
            boundingRect = flavor->boundingRect();
        }
    }
    flavor->setPos(Constants::flavorTextRect().center().x() - boundingRect.width()/2, Constants::flavorTextRect().center().y() - boundingRect.height()/2);
}

void Widget::updateBorderColor() {
    if(ui->borderColor->currentText() == "Green/White/Grey") border->setPixmap(borderPixmaps["green_white_grey"]);
    else if(ui->borderColor->currentText() == "Black") border->setPixmap(borderPixmaps["black"]);
    else if(ui->borderColor->currentText() == "Red") border->setPixmap(borderPixmaps["red"]);
    else if(ui->borderColor->currentText() == "Purple") border->setPixmap(borderPixmaps["purple"]);
    else if(ui->borderColor->currentText() == "Blue/Gold") border->setPixmap(borderPixmaps["blue_gold"]);
}

void Widget::openRarityAndSetSymbol() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open set", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!fileName.isEmpty()) {
        rarityAndSetSymbol->setPixmap(QPixmap::fromImage(QImage(fileName).scaled(Constants::raritySetSymbolRect().size())));
        updateRarityAndSetSymbol();
    }
}

void Widget::updateRarityAndSetSymbol() {
    rarityAndSetSymbol->setPos(Constants::raritySetSymbolRect().topLeft());
}

void Widget::updateIllustratorName() {
    updateText(illustratorName, ui->illustratorName->text(), Constants::illustratorRect(), Qt::AlignLeft);
}

void Widget::updateSetNumber() {
    ui->setNumber->setMaximum(ui->setNumberTotal->value());
    QString setNumberStr = QString::number(ui->setNumber->value()) + " / " + QString::number(ui->setNumberTotal->value());
    updateText(setNumber, setNumberStr, Constants::setNumberRect(), Qt::AlignRight);
}

void Widget::updateGoldCost() {
    updateText(goldCost, QString::number(ui->goldCost->value()), Constants::goldCostRect(), Qt::AlignCenter);
}

void Widget::options() {
    optionsWindow = new Options(this);
    connect(optionsWindow, SIGNAL(optionsClosed()), this, SLOT(updateAll()));
    optionsWindow->show();
    optionsWindow->activateWindow();
}

void Widget::save() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Scene", ui->name->text(), "Image (*.png)");
    QPixmap pixMap = ui->graphicsView->grab();;
    ui->graphicsView->grab();
    pixMap.save(fileName);
}
