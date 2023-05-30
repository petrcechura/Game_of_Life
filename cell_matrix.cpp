//
// Created by petr on 30.5.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Cell_matrix.h" resolved

#include "cell_matrix.h"
#include "ui_Cell_matrix.h"


Cell_matrix::Cell_matrix(QWidget *parent) :
        QWidget(parent), ui(new Ui::Cell_matrix) {
    ui->setupUi(this);
}

Cell_matrix::~Cell_matrix() {
    delete ui;
}
