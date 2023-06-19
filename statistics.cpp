//
// Created by petr on 29.5.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_statistics.h" resolved

#include "statistics.h"
#include "ui_statistics.h"
#include "string"
#include "QVBoxLayout"

statistics::statistics(QWidget *parent) :
        QWidget(parent), ui(new Ui::statistics) {
    ui->setupUi(this);

    //labels init
    l_cells_am_l = new QLabel(QString("Living cells: 0"));
    tbb_cells_l = new QLabel(QString("Cells to be born: 0"));
    population_l = new QLabel(QString("Population no. 0"));

    // layout definition
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(l_cells_am_l);
    layout->addWidget(tbb_cells_l);
    layout->addWidget(population_l);

    setLayout(layout);
}

void statistics::l_cells_set(int amount) {
        l_cells_am_l->setText("Living cells: " + QString::number(amount));
}


void statistics::tbb_cells_set(int amount) {
    tbb_cells_l->setText("Cells to be born: " + QString::number(amount));
}


void statistics::population_set(int amount) {
    population_l->setText("Population no. 0" + QString::number(amount));
}





statistics::~statistics() {
    delete ui;
}
