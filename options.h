#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QCloseEvent>

#include "positions.h"

namespace Ui {
    class Options;
}

class Options : public QWidget {

    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

signals:
    void optionsClosed();

private slots:
    void on_background_clicked();
    void on_font_clicked();
    void on_positions_clicked();
    void on_wood_clicked();
    void on_mysticNode_clicked();
    void on_weaponForge_clicked();
    void on_inferno_clicked();
    void on_darkness_clicked();
    void on_stoneQuarry_clicked();
    void on_colorless_clicked();
    void on_attackPower_clicked();
    void on_health_clicked();
    void on_movement_clicked();
    void on_rangedAttack_clicked();
    void on_magicAttack_clicked();
    void on_defense_clicked();
    void on_ok_clicked();

private:
    void addImage(QString name);

    Ui::Options *ui;
    Positions* positionsWindow;

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // OPTIONS_H
