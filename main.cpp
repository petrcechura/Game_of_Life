#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "statistics.h"
#include "cellmatrix.h"
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow window;
    window.setGeometry(0, 0, 1200, 800);

    // create central widget with lesser widgets
    std::unique_ptr<QWidget> central_widget = std::make_unique<QWidget>(&window);
    std::unique_ptr<statistics> stat_widget = std::make_unique<statistics>(central_widget.get());
    std::unique_ptr<CellMatrix> matr_widget = std::make_unique<CellMatrix>(central_widget.get(), 80, 80);

    QGridLayout *layout = new QGridLayout(central_widget.get());
    layout->addWidget(matr_widget.get(), 0, 0);
    layout->addWidget(stat_widget.get(), 0, 1);
    central_widget->setLayout(layout);
    window.setCentralWidget(central_widget.get());

    // TEST CODE
    int pos1[2] = {1, 2};
    int pos2[2] = {5, 10};
    int pos3[2] = {7, 22};
    std::vector<int*> positions;
    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos3);
    matr_widget->Positions = positions;
    matr_widget->Start();
    // END


    window.show();
    return QApplication::exec();
}

