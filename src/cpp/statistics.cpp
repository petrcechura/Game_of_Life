//
// Created by petr on 29.5.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_statistics.h" resolved

#include "statistics.h"


Statistics::Statistics(QWidget *parent) :
        QWidget(parent) {

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

void Statistics::LCellsSet(int amount) {
        l_cells_am_l->setText("Living cells: " + QString::number(amount));
}



void Statistics::PopulationInc() {
    population_l->setText("Population no. " + QString::number(pop_no));
    pop_no++;
}





Statistics::~Statistics() {
    delete l_cells_am_l;
    delete population_l;
    delete layout;
}
