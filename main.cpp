#include <QApplication>
#include "MainWidget.h"

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWidget mainWidget;
    mainWidget.show();
    return QApplication::exec();
}
