#include "options.h"
#include "ui_options.h"

#include <QFileDialog>

Options::Options(QWidget *parent) : QWidget(parent, Qt::Tool), ui(new Ui::Options) {
    ui->setupUi(this);
}

Options::~Options() {
    delete ui;
}

void Options::addImage(QString name) {
    QString source = QFileDialog::getOpenFileName(this, "Open image", QDir::homePath(), "Images (*.png)");
    if(source.isEmpty()) return;

    QString destination = qApp->applicationDirPath()+"/img/"+name+".png";
    if(QFile::exists(destination)) QFile::remove(destination);
    QFile::copy(source, destination);
}

void Options::on_background_clicked() { addImage("background"); }

void Options::on_font_clicked() {
    QString source = QFileDialog::getOpenFileName(this, "Open font", QDir::homePath(), "Fonts (*.ttf)");
    if(source.isEmpty()) return;

    QString destination = qApp->applicationDirPath()+"/font.ttf";
    if(QFile::exists(destination)) QFile::remove(destination);
    QFile::copy(source, destination);
}

void Options::on_positions_clicked() {
    positionsWindow = new Positions(this);
    positionsWindow->show();
    positionsWindow->activateWindow();
}

void Options::on_wood_clicked() { addImage("wood"); }
void Options::on_mysticNode_clicked() { addImage("mystic_node"); }
void Options::on_weaponForge_clicked() { addImage("weapon_forge"); }
void Options::on_inferno_clicked() { addImage("inferno"); }
void Options::on_darkness_clicked() { addImage("darkness"); }
void Options::on_stoneQuarry_clicked() { addImage("stone_quarry"); }
void Options::on_colorless_clicked() { addImage("colorless"); }
void Options::on_attackPower_clicked() { addImage("attack_power"); }
void Options::on_health_clicked() { addImage("health"); }
void Options::on_movement_clicked() { addImage("movement"); }
void Options::on_rangedAttack_clicked() { addImage("ranged_attack"); }
void Options::on_magicAttack_clicked() { addImage("magic_attack"); }
void Options::on_defense_clicked() { addImage("defense"); }

void Options::on_ok_clicked() { close(); }

void Options::closeEvent(QCloseEvent* event) {
      emit emit optionsClosed();
      event->accept();
}
