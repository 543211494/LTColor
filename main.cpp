#include <QApplication>
#include "MainWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWidget mainWidget;
    mainWidget.show();
    return QApplication::exec();
}
