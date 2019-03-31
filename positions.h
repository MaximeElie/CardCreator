#ifndef POSITIONS_H
#define POSITIONS_H

#include <QWidget>

#include "constants.h"

namespace Ui {
    class Positions;
}

class Positions : public QWidget {

    Q_OBJECT

public:
    explicit Positions(QWidget *parent = nullptr);
    ~Positions();

private slots:
    void on_validate_clicked();

private:
    Ui::Positions *ui;
};

#endif // POSITIONS_H
