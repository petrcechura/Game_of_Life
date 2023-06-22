#include <QApplication>
#include "mainwindow.h"
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window;
    window.setGeometry(0, 0, 1200, 800);
    window.show();
    return QApplication::exec();
}

