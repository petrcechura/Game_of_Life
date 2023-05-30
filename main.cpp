#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "statistics.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow window;
    window.setGeometry(0, 0, 1200, 800);
    statistics *widget = new statistics(&window);
    window.setCentralWidget(widget);
    window.show();
    return QApplication::exec();
}
