#include <QApplication>
#include "mainwindow.h"
#include <array>


void PrintArray(std::array<int, 5> arr)  {
    for (int i = 0; i < arr.size(); i++)  {
        std::cout << arr[i];
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr, 100, 100);
    PopCreator cwindow(nullptr, 50, 50);
    window.setGeometry(0, 0, 1200, 800);
    window.show();
    cwindow.show();
    
    
    
    
    return QApplication::exec();

    
}

