#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr, 100, 100);
    window.setGeometry(0, 0, 1200, 800);
    window.show();
    return QApplication::exec();
}

