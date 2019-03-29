#include "widget.h"
#include "ui_widget.h"

#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    scrollSymbolPixmaps.insert("attack_power", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/attack_power.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("health", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/health.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("movement", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/movement.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("ranged_attack", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/ranged_attack.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("magic_attack", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/magic_attack.png").scaled(Constants::scrollSymbolSize())));
    scrollSymbolPixmaps.insert("defense", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/defense.png").scaled(Constants::scrollSymbolSize())));

    manaSymbolPixmaps.insert("wood", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/wood.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("mystic_node", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/mystic_node.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("weapon_forge", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/weapon_forge.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("inferno", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/inferno.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("darkness", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/darkness.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("stone_quarry", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/stone_quarry.png").scaled(Constants::manaSymbolSize())));
    manaSymbolPixmaps.insert("colorless", QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/colorless.png").scaled(Constants::manaSymbolSize())));

    scene = new QGraphicsScene(this);
    picture = scene->addPixmap(QPixmap());
    rarityAndSetSymbol = scene->addPixmap(QPixmap());
    background = scene->addPixmap(QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/background.png").scaled(Constants::cardSize())));
    actionPoints = scene->addText("");
    name = scene->addText("");
    type = scene->addText("");
    flavor = scene->addText("");
    illustratorName = scene->addText("");
    setNumber = scene->addText("");
    goldCost = scene->addText("");

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    updateTextItems();

    connect(ui->actionPoints, SIGNAL(valueChanged(int)), this, SLOT(updateTextItems()));

    connect(ui->wood, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->mysticNode, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->weaponForge, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->inferno, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->darkness, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->stoneQuarry, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));
    connect(ui->colorless, SIGNAL(valueChanged(int)), this, SLOT(updateMana()));

    connect(ui->name, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));

    connect(ui->picture, SIGNAL(clicked()), this, SLOT(openArt()));

    connect(ui->attackPower, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->health, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->movement, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->rangedAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->magicAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->defense, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));

    connect(ui->superType, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));
    connect(ui->subType, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));

    connect(ui->flavorText, SIGNAL(textChanged()), this, SLOT(updateTextItems()));

    connect(ui->rarityAndSetSymbol, SIGNAL(clicked()), this, SLOT(openRarityAndSetSymbol()));
    connect(ui->illustratorName, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));
    connect(ui->setNumber, SIGNAL(valueChanged(int)), this, SLOT(updateTextItems()));
    connect(ui->setNumberTotal, SIGNAL(valueChanged(int)), this, SLOT(updateTextItems()));
    connect(ui->goldCost, SIGNAL(valueChanged(int)), this, SLOT(updateTextItems()));

    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateMana() {
    while(!manaSymbols.isEmpty()) {
        scene->removeItem(manaSymbols.back());
        manaSymbols.pop_back();
    }

    for(int i = 0 ; i < ui->wood->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["wood"]));
    for(int i = 0 ; i < ui->mysticNode->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["mystic_node"]));
    for(int i = 0 ; i < ui->weaponForge->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["weapon_forge"]));
    for(int i = 0 ; i < ui->inferno->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["inferno"]));
    for(int i = 0 ; i < ui->darkness->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["darkness"]));
    for(int i = 0 ; i < ui->stoneQuarry->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["stone_quarry"]));
    for(int i = 0 ; i < ui->colorless->value() ; i++) manaSymbols.append(scene->addPixmap(manaSymbolPixmaps["colorless"]));

    int firstSymbolLeft = Constants::manaRect().right() - manaSymbols.count()*(Constants::manaSymbolSize().width()+5); ////////////////////////////////////////////////////////////////// 5

    for(int i = 0 ; i < manaSymbols.count() ; i++) {
        int symbolX = firstSymbolLeft + i*Constants::manaSymbolSize().width() + i*5;////////////////////////////////////////////////////////////////////////////////////////////////// 5
        int symbolY = Constants::manaRect().y() + (Constants::manaRect().height()-Constants::manaSymbolSize().height())/2;
        manaSymbols[i]->setPos(symbolX,symbolY);
    }

}

void Widget::updateTextItems() {
    QRectF boundingRect;

    actionPoints->setPlainText(QString::number(ui->actionPoints->value()));
    actionPoints->setFont(QFont("Arial", 50));
    boundingRect = actionPoints->boundingRect();
    while(boundingRect.width()>Constants::actionPointsRect().width() || boundingRect.height()>Constants::actionPointsRect().height()) {
        actionPoints->setFont(QFont("Arial", actionPoints->font().pointSize()-1));
        boundingRect = actionPoints->boundingRect();
    }
    actionPoints->setPos(Constants::actionPointsRect().center().x() - boundingRect.width()/2, Constants::actionPointsRect().center().y() - boundingRect.height()/2);

    name->setPlainText(ui->name->text());
    name->setFont(QFont("Arial", 30));
    boundingRect = name->boundingRect();
    while(boundingRect.width()>Constants::nameRect().width() || boundingRect.height()>Constants::nameRect().height()) {
        name->setFont(QFont("Arial", name->font().pointSize()-1));
        boundingRect = name->boundingRect();
    }
    name->setPos(Constants::nameRect().center().x() - boundingRect.width()/2, Constants::nameRect().center().y() - boundingRect.height()/2);


    QString superType = ui->superType->text();
    QString subType = ui->subType->text();
    QString typeStr = (superType.isEmpty() || subType.isEmpty()) ? superType+subType : superType + " - " + subType;
    type->setPlainText(typeStr);
    type->setFont(QFont("Arial", 20));
    boundingRect = type->boundingRect();
    while(boundingRect.width()>Constants::typeRect().width() || boundingRect.height()>Constants::typeRect().height()) {
        type->setFont(QFont("Arial", type->font().pointSize()-1));
        boundingRect = type->boundingRect();
    }
    type->setPos(Constants::typeRect().center().x() - boundingRect.width()/2, Constants::typeRect().center().y() - boundingRect.height()/2);


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

    illustratorName->setPlainText(ui->illustratorName->text());
    illustratorName->setFont(QFont("Arial", 50));
    boundingRect = illustratorName->boundingRect();
    while(boundingRect.width()>Constants::illustratorRect().width() || boundingRect.height()>Constants::illustratorRect().height()) {
        illustratorName->setFont(QFont("Arial", illustratorName->font().pointSize()-1));
        boundingRect = illustratorName->boundingRect();
    }
    illustratorName->setPos(Constants::illustratorRect().left(), Constants::illustratorRect().center().y() - boundingRect.height()/2);

    ui->setNumber->setMaximum(ui->setNumberTotal->value());
    setNumber->setPlainText(QString::number(ui->setNumber->value()) + " / " + QString::number(ui->setNumberTotal->value()));
    setNumber->setFont(QFont("Arial", 50));
    boundingRect = setNumber->boundingRect();
    while(boundingRect.width()>Constants::setNumberRect().width() || boundingRect.height()>Constants::setNumberRect().height()) {
        setNumber->setFont(QFont("Arial", setNumber->font().pointSize()-1));
        boundingRect = setNumber->boundingRect();
    }
    setNumber->setPos(Constants::setNumberRect().right() - boundingRect.width(), Constants::setNumberRect().center().y() - boundingRect.height()/2);

    goldCost->setPlainText(QString::number(ui->goldCost->value()));
    goldCost->setFont(QFont("Arial", 50));
    boundingRect = goldCost->boundingRect();
    while(boundingRect.width()>Constants::goldCostRect().width() || boundingRect.height()>Constants::goldCostRect().height()) {
        goldCost->setFont(QFont("Arial", goldCost->font().pointSize()-1));
        boundingRect = goldCost->boundingRect();
    }
    goldCost->setPos(Constants::goldCostRect().center().x() - boundingRect.width()/2, Constants::goldCostRect().center().y() - boundingRect.height()/2);
}

void Widget::openArt() {

    QString artFileName = QFileDialog::getOpenFileName(this, "Open Art", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!artFileName.isEmpty()) {
        picture->setPixmap(QPixmap::fromImage(QImage(artFileName).scaled(Constants::pictureRect().size())));
        picture->setPos(Constants::pictureRect().topLeft());
    }
}

void Widget::updateScroll() {

    while(!scrollSymbols.isEmpty()) {
        scene->removeItem(scrollSymbols.back());
        scene->removeItem(scrollValues.back());
        scrollSymbols.pop_back();
        scrollValues.pop_back();
    }

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

    int symbolCaseWidth = Constants::scrollRect().width()/scrollSymbols.count();
    int firstSymbolLeft = Constants::scrollRect().left() + symbolCaseWidth/2 - Constants::scrollSymbolAndNumberSize().width()/2;

    for(int i = 0 ; i < scrollSymbols.count() ; i++) {
        int symbolX = firstSymbolLeft + i*symbolCaseWidth;
        int symbolY = Constants::scrollRect().y() + (Constants::scrollRect().height()-Constants::scrollSymbolSize().height())/2;
        scrollSymbols[i]->setPos(symbolX,symbolY);
        scrollValues[i]->setFont(QFont("Arial", 15));////////////////////////////////////////////////////////////////////////// taille police auto
        scrollValues[i]->setPos(symbolX+Constants::scrollSymbolSize().width(),symbolY); /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// position y auto
    }
}

void Widget::openRarityAndSetSymbol() {
    QString file = QFileDialog::getOpenFileName(this, "Open set", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!file.isEmpty()) {
        rarityAndSetSymbol->setPixmap(QPixmap::fromImage(QImage(file).scaled(Constants::raritySetSymbolRect().size())));
        rarityAndSetSymbol->setPos(Constants::raritySetSymbolRect().topLeft());
    }
}

void Widget::save() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Scene", "", "Image (*.png)");
    QPixmap pixMap = ui->graphicsView->grab();;
    ui->graphicsView->grab();
    pixMap.save(fileName);
}
