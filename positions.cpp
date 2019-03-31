#include "positions.h"
#include "ui_positions.h"

Positions::Positions(QWidget *parent) : QWidget(parent, Qt::Tool), ui(new Ui::Positions) {
    ui->setupUi(this);

    Constants::setReturnScaledValues(false);

    ui->cardW->setValue(Constants::cardSize().width());
    ui->cardH->setValue(Constants::cardSize().height());

    ui->actionPointsX->setValue(Constants::actionPointsRect().x());
    ui->actionPointsY->setValue(Constants::actionPointsRect().y());
    ui->actionPointsW->setValue(Constants::actionPointsRect().width());
    ui->actionPointsH->setValue(Constants::actionPointsRect().height());

    ui->manaX->setValue(Constants::manaRect().x());
    ui->manaY->setValue(Constants::manaRect().y());
    ui->manaW->setValue(Constants::manaRect().width());
    ui->manaH->setValue(Constants::manaRect().height());

    ui->nameX->setValue(Constants::nameRect().x());
    ui->nameY->setValue(Constants::nameRect().y());
    ui->nameW->setValue(Constants::nameRect().width());
    ui->nameH->setValue(Constants::nameRect().height());

    ui->pictureX->setValue(Constants::pictureRect().x());
    ui->pictureY->setValue(Constants::pictureRect().y());
    ui->pictureW->setValue(Constants::pictureRect().width());
    ui->pictureH->setValue(Constants::pictureRect().height());

    ui->scrollX->setValue(Constants::scrollRect().x());
    ui->scrollY->setValue(Constants::scrollRect().y());
    ui->scrollW->setValue(Constants::scrollRect().width());
    ui->scrollH->setValue(Constants::scrollRect().height());

    ui->typeX->setValue(Constants::typeRect().x());
    ui->typeY->setValue(Constants::typeRect().y());
    ui->typeW->setValue(Constants::typeRect().width());
    ui->typeH->setValue(Constants::typeRect().height());

    ui->flavorTextX->setValue(Constants::flavorTextRect().x());
    ui->flavorTextY->setValue(Constants::flavorTextRect().y());
    ui->flavorTextW->setValue(Constants::flavorTextRect().width());
    ui->flavorTextH->setValue(Constants::flavorTextRect().height());

    ui->rarityAndSetSymbolX->setValue(Constants::raritySetSymbolRect().x());
    ui->rarityAndSetSymbolY->setValue(Constants::raritySetSymbolRect().y());
    ui->rarityAndSetSymbolW->setValue(Constants::raritySetSymbolRect().width());
    ui->rarityAndSetSymbolH->setValue(Constants::raritySetSymbolRect().height());

    ui->illustratorNameX->setValue(Constants::illustratorRect().x());
    ui->illustratorNameY->setValue(Constants::illustratorRect().y());
    ui->illustratorNameW->setValue(Constants::illustratorRect().width());
    ui->illustratorNameH->setValue(Constants::illustratorRect().height());

    ui->setNumberX->setValue(Constants::setNumberRect().x());
    ui->setNumberY->setValue(Constants::setNumberRect().y());
    ui->setNumberW->setValue(Constants::setNumberRect().width());
    ui->setNumberH->setValue(Constants::setNumberRect().height());

    ui->goldCostX->setValue(Constants::goldCostRect().x());
    ui->goldCostY->setValue(Constants::goldCostRect().y());
    ui->goldCostW->setValue(Constants::goldCostRect().width());
    ui->goldCostH->setValue(Constants::goldCostRect().height());

    ui->manaSymbolW->setValue(Constants::manaSymbolSize().width());
    ui->manaSymbolH->setValue(Constants::manaSymbolSize().height());

    ui->spaceBetweenManaSymbols->setValue(Constants::spaceBetweenManaSymbols());

    ui->scrollSymbolW->setValue(Constants::scrollSymbolSize().width());
    ui->scrollSymbolH->setValue(Constants::scrollSymbolSize().height());

    Constants::setReturnScaledValues(true);
}

Positions::~Positions() {
    delete ui;
}

void Positions::on_validate_clicked() {
    QJsonObject obj;
    QJsonObject tmp;

    tmp["w"] = ui->cardW->value();
    tmp["h"] = ui->cardH->value();
    obj["card"] = tmp;

    tmp["x"] = ui->actionPointsX->value();
    tmp["y"] = ui->actionPointsY->value();
    tmp["w"] = ui->actionPointsW->value();
    tmp["h"] = ui->actionPointsH->value();
    obj["actionPoints"] = tmp;

    tmp["x"] = ui->manaX->value();
    tmp["y"] = ui->manaY->value();
    tmp["w"] = ui->manaW->value();
    tmp["h"] = ui->manaH->value();
    obj["mana"] = tmp;

    tmp["x"] = ui->nameX->value();
    tmp["y"] = ui->nameY->value();
    tmp["w"] = ui->nameW->value();
    tmp["h"] = ui->nameH->value();
    obj["name"] = tmp;

    tmp["x"] = ui->pictureX->value();
    tmp["y"] = ui->pictureY->value();
    tmp["w"] = ui->pictureW->value();
    tmp["h"] = ui->pictureH->value();
    obj["picture"] = tmp;

    tmp["x"] = ui->scrollX->value();
    tmp["y"] = ui->scrollY->value();
    tmp["w"] = ui->scrollW->value();
    tmp["h"] = ui->scrollH->value();
    obj["scroll"] = tmp;

    tmp["x"] = ui->typeX->value();
    tmp["y"] = ui->typeY->value();
    tmp["w"] = ui->typeW->value();
    tmp["h"] = ui->typeH->value();
    obj["type"] = tmp;

    tmp["x"] = ui->flavorTextX->value();
    tmp["y"] = ui->flavorTextY->value();
    tmp["w"] = ui->flavorTextW->value();
    tmp["h"] = ui->flavorTextH->value();
    obj["flavorText"] = tmp;

    tmp["x"] = ui->rarityAndSetSymbolX->value();
    tmp["y"] = ui->rarityAndSetSymbolY->value();
    tmp["w"] = ui->rarityAndSetSymbolW->value();
    tmp["h"] = ui->rarityAndSetSymbolH->value();
    obj["rarityAndSetSymbol"] = tmp;

    tmp["x"] = ui->illustratorNameX->value();
    tmp["y"] = ui->illustratorNameY->value();
    tmp["w"] = ui->illustratorNameW->value();
    tmp["h"] = ui->illustratorNameH->value();
    obj["illustratorName"] = tmp;

    tmp["x"] = ui->setNumberX->value();
    tmp["y"] = ui->setNumberY->value();
    tmp["w"] = ui->setNumberW->value();
    tmp["h"] = ui->setNumberH->value();
    obj["setNumber"] = tmp;

    tmp["x"] = ui->goldCostX->value();
    tmp["y"] = ui->goldCostY->value();
    tmp["w"] = ui->goldCostW->value();
    tmp["h"] = ui->goldCostH->value();
    obj["goldCost"] = tmp;

    tmp = QJsonObject();
    tmp["w"] = ui->manaSymbolW->value();
    tmp["h"] = ui->manaSymbolH->value();
    obj["manaSymbol"] = tmp;

    obj["spaceBetweenManaSymbols"] = ui->spaceBetweenManaSymbols->value();

    tmp["w"] = ui->scrollSymbolW->value();
    tmp["h"] = ui->scrollSymbolH->value();
    obj["scrollSymbol"] = tmp;

    Constants::update(obj);
    Constants::saveToJson();

    close();
}
