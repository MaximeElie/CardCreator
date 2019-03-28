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

    scene = new QGraphicsScene(this);
    art = scene->addPixmap(QPixmap());
    background = scene->addPixmap(QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/img/background.png").scaled(Constants::cardSize())));
    name = scene->addText("");
    type = scene->addText("");
    flavor = scene->addText("");

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    connect(ui->name, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));
    connect(ui->superType, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));
    connect(ui->subType, SIGNAL(textChanged(QString)), this, SLOT(updateTextItems()));
    connect(ui->flavorText, SIGNAL(textChanged()), this, SLOT(updateTextItems()));

    connect(ui->attackPower, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->health, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->movement, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->rangedAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->magicAttack, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));
    connect(ui->defense, SIGNAL(valueChanged(int)), this, SLOT(updateScroll()));

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(openArt()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTextItems() {
    QRectF boundingRect;

    name->setPlainText(ui->name->text());
    name->setFont(QFont("Arial", 30));
    boundingRect = name->boundingRect();
    while(boundingRect.width()>Constants::nameRect().width()) {
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
    while(boundingRect.width()>Constants::typeRect().width()) {
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

    int symbolsTotalWidth = scrollSymbols.count()*Constants::scrollSymbolAndNumberSize().width();
    int symbolCaseX = Constants::scrollRect().x() + (Constants::scrollRect().width()-symbolsTotalWidth)/2;

    for(int i = 0 ; i < scrollSymbols.count() ; i++) {
        int symbolX = symbolCaseX+i*Constants::scrollSymbolAndNumberSize().width();
        int symbolY = Constants::scrollRect().y() + (Constants::scrollRect().height()-Constants::scrollSymbolSize().height())/2;
        scrollSymbols[i]->setPos(symbolX,symbolY);
        scrollValues[i]->setFont(QFont("Arial", 20));
        scrollValues[i]->setPos(symbolX+Constants::scrollSymbolSize().width(),symbolY-5); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}

void Widget::openArt() {

    QString artFileName = QFileDialog::getOpenFileName(this, "Open Art", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!artFileName.isEmpty()) {
        art->setPixmap(QPixmap::fromImage(QImage(artFileName).scaled(Constants::pictureRect().size())));
        art->setPos(Constants::pictureRect().topLeft());
    }
}
