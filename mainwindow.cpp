//
// Created by petr on 19.6.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);


    // widgets
    central_widget = new QWidget(this);
    matrix_widget = new CellMatrix(this, 100, 100);
    stats_widget = new statistics(this);

    // layout set
    layout = new QGridLayout(central_widget);
    central_widget->setLayout(layout);
    layout->addWidget(matrix_widget, 0, 0);
    layout->addWidget(stats_widget, 0, 1);
    this->setCentralWidget(central_widget);

    // timer set
    timer.setInterval(1000);
    timer.start();
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timerTick()));
}

void MainWindow::timerTick() {
    std::vector<int*> pos = {{0, 0}};
    //matrix_widget->Set_cells(pos);
    qDebug() << "Tick...";

}

MainWindow::~MainWindow() {

    delete stats_widget;
    delete matrix_widget;
    delete central_widget;
    delete layout;
    delete ui;
}
