#ifndef POSITIONS_H
#define POSITIONS_H

#include <QWidget>

namespace Ui {
class Positions;
}

class Positions : public QWidget {

    Q_OBJECT

public:
    explicit Positions(QWidget *parent = nullptr);
    ~Positions();

private:
    Ui::Positions *ui;
};

#endif // POSITIONS_H
