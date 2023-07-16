//
// Created by petr on 19.6.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent)  {

    // widgets
    central_widget = new QWidget(this);
    matrix_widget = new CellMatrix(this);
    stats_widget = new Statistics(this);
    controls_widget = new Controls(this);

    // layout set
    layout = new QGridLayout(central_widget);
    central_widget->setLayout(layout);
    layout->addWidget(matrix_widget, 0, 0, 2, 1);
    layout->addWidget(stats_widget, 0, 1);
    layout->addWidget(controls_widget, 1, 1);
    this->setCentralWidget(central_widget);

    // backend init
    backend = new Backend(controls_widget->GetRules());
    
    // timer delay (default)
    delay_ms = 100; 

    // timer set
    timer.setInterval(delay_ms);
    timerTick();
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer.start();

    // connections between Controls and window
    QObject::connect(controls_widget, &Controls::start, this, &MainWindow::start);
    QObject::connect(controls_widget, &Controls::pause, this, &MainWindow::pause);
    QObject::connect(controls_widget, &Controls::restart, this, &MainWindow::restart);
    QObject::connect(controls_widget, &Controls::apply, this, &MainWindow::apply);
}

void MainWindow::timerTick() {
    
    matrix_widget->Update_matrix(backend->GetMatrix());
    backend->NextPop();
    stats_widget->PopulationInc();
    stats_widget->LCellsSet(backend->GetCells());
}

void MainWindow::start()  {
    timer.start();
}

void MainWindow::pause()  {
    timer.stop();
}

void MainWindow::restart()  {
    backend->NewPop();
}

void MainWindow::apply()  {
    backend->SetRules(controls_widget->GetRules());
}

MainWindow::~MainWindow() {

    delete central_widget;
}
