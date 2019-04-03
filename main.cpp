#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QCoreApplication::addLibraryPath("./");

    QApplication a(argc, argv);

    Constants::init();

    Widget w;
    w.show();

    return a.exec();
}
