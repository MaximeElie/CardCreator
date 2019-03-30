#include "positions.h"
#include "ui_positions.h"

Positions::Positions(QWidget *parent) : QWidget(parent, Qt::Tool), ui(new Ui::Positions) {
    ui->setupUi(this);
}

Positions::~Positions() {
    delete ui;
}
