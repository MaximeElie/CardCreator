#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) : QWidget(parent, Qt::Tool), ui(new Ui::Options) {
    ui->setupUi(this);

    ui->chooseTextFont->setCurrentIndex(Constants::textFontComboBoxIndex());
    ui->chooseNumberFont->setCurrentIndex(Constants::numberFontComboBoxIndex());

    ui->numberFontEnabled->setChecked(Constants::isNumberFontEnabled());
    ui->chooseNumberFont->setEnabled(Constants::isNumberFontEnabled());

    ui->label_1->hide();
    ui->numberFontEnabled->hide();
    ui->label_2->hide();
    ui->chooseNumberFont->hide();
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
void Options::on_greenWhiteGreyBorder_clicked() { addImage("green_white_grey"); }
void Options::on_blackBorder_clicked() { addImage("black"); }
void Options::on_redBorder_clicked() { addImage("red"); }
void Options::on_purpleBorder_clicked() { addImage("purple"); }
void Options::on_blueGoldBorder_clicked() { addImage("blue_gold"); }

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

void Options::on_numberFontEnabled_stateChanged(int) { ui->chooseNumberFont->setEnabled(ui->numberFontEnabled->isChecked()); }

void Options::on_addCustomFont_clicked() {
    QString source = QFileDialog::getOpenFileName(this, "Open font", QDir::homePath(), "Fonts (*.ttf *.ttc *.otf)");
    if(source.isEmpty()) return;


    QString destination = qApp->applicationDirPath()+"/fonts/"+source.split("/").last();

    if(QFile::exists(destination)) QFile::remove(destination);
    QFile::copy(source, destination);

    int id = QFontDatabase::addApplicationFont(source);
    if(id == -1) return;
    QStringList families = QFontDatabase::applicationFontFamilies(id);
    if(families.isEmpty()) return;
    int index = ui->chooseTextFont->findText(families.first());
    if(index == -1) return;
    ui->chooseTextFont->setCurrentIndex(index);
}

void Options::on_positions_clicked() {
    positionsWindow = new Positions(this);
    positionsWindow->show();
    positionsWindow->activateWindow();
}

void Options::on_ok_clicked() { close(); }

void Options::closeEvent(QCloseEvent* event) {
    Constants::setTextFontComboBoxIndex(ui->chooseTextFont->currentIndex());
    Constants::setTextFontFamily(ui->chooseTextFont->currentText());
    Constants::setNumberFontComboBoxIndex(ui->chooseNumberFont->currentIndex());
    Constants::setNumberFontFamily(ui->chooseNumberFont->currentText());
    Constants::setNumberFontEnabled(ui->numberFontEnabled->isChecked());
    Constants::saveToJson();
    emit optionsClosed();
    event->accept();
}
