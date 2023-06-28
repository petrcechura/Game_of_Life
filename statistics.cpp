//
// Created by petr on 29.5.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_statistics.h" resolved

#include "statistics.h"
#include "ui_statistics.h"


statistics::statistics(QWidget *parent) :
        QWidget(parent), ui(new Ui::statistics) {
    ui->setupUi(this);

    //labels init
    l_cells_am_l = new QLabel(QString("Living cells: 0"));
    population_l = new QLabel(QString("Population no. "));

    // default pop no
    pop_no = 0;

    // layout definition
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(l_cells_am_l);
    layout->addWidget(population_l);

    setLayout(layout);
}

void statistics::LCellsSet(int amount) {
        l_cells_am_l->setText("Living cells: " + QString::number(amount));
}



void statistics::PopulationInc() {
    population_l->setText("Population no. " + QString::number(pop_no));
    pop_no++;
}





statistics::~statistics() {
    delete ui;
}
