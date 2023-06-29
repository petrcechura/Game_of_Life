//
// Created by petr on 19.6.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, const int &rows, const int &columns) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);


    // widgets
    central_widget = new QWidget(this);
    matrix_widget = new CellMatrix(this, rows, columns);
    stats_widget = new statistics(this);

    // layout set
    layout = new QGridLayout(central_widget);
    central_widget->setLayout(layout);
    layout->addWidget(matrix_widget, 0, 0);
    layout->addWidget(stats_widget, 0, 1);
    this->setCentralWidget(central_widget);

    // backend init
    backend = new Backend(rows, columns, "S23/B3");
    
    // timer delay (default)
    delay_ms = 100; 

    // timer set
    timer.setInterval(delay_ms);
    timer.start();
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timerTick()));
}

void MainWindow::timerTick() {
    
    matrix_widget->Update_matrix(backend->GetMatrix());
    backend->NextPop();
    stats_widget->PopulationInc();
    stats_widget->LCellsSet(backend->GetCells());
}

MainWindow::~MainWindow() {

    delete stats_widget;
    delete matrix_widget;
    delete central_widget;
    delete layout;
    delete ui;
}
