//
// Created by petr on 30.5.23.
//

#include "cellmatrix.h"

std::array<std::array<QGraphicsRectItem*, COLUMNS>, ROWS> CellMatrix::create_cell_matrix() {
    // rectangle size TODO automatic size calculation
    int height = 7;
    int width = 7;

    //dynamic matrix declaration
    std::array<std::array<QGraphicsRectItem*, COLUMNS>, ROWS> matrix;

    //matrix filling
    for (int i = 0; i < ROWS; i++)  {
        for (int j = 0; j < COLUMNS; j++)  {
            QRect rect(i * width,
                       j * height,
                       width,
                       height);
            QGraphicsRectItem *qRect = new QGraphicsRectItem(rect);
            matrix[i][j] = qRect;
        }
    }

    return matrix;
}

void CellMatrix::Update_matrix(const std::array<std::array<int, COLUMNS>, ROWS> matrix) {

    // check if matrix is of valid size
    if (matrix.size() != cellmatrix.size() || matrix[0].size() != cellmatrix[0].size())  {
        qDebug() << "QDEBUG: Matrices don't have same size!";
        qDebug() << "arg matrix: " << matrix.size() << "X" << matrix[0].size() << "\ncellmatrix: " << cellmatrix.size() << "X" << cellmatrix[0].size();
        qTerminate();
    }


    for (int i = 0; i < matrix.size(); i++)  {
        for (int j = 0; j < matrix[0].size(); j++)  {
            if (matrix[i][j] == 1)  {
                cellmatrix[i][j]->setBrush(Qt::black);
            }
            else  {
                cellmatrix[i][j]->setBrush(Qt::white);
            }
        }
    }
}

void CellMatrix::clearCells() {
    for (auto row : cellmatrix)  {
        for (auto rectangle : row)  {
            rectangle->setBrush(Qt::white);
        }
    }
}


CellMatrix::CellMatrix(QWidget *parent) :
        QGraphicsView(parent)  {

    this->setGeometry( QRect(0, 0, 700, 700));
    // scene
    scene = new QGraphicsScene(this);
    this->setScene(scene);

    // layout
    layout = new QGridLayout(this);
    layout->setGeometry( QRect(0, 0, 700, 700));
    this->setLayout(layout);

    // cells creation
    if (ROWS < 0 ||
        ROWS > 200 ||
        COLUMNS < 0 ||
        COLUMNS > 200
        ) {
        qDebug() << "QDEBUG: Matrix to be created is too large! (max 200x200) Terminating...";
        qTerminate();
    }

    cellmatrix = this->create_cell_matrix();
    for (auto row : cellmatrix)  {
        for (auto rectangle : row)  {
            scene->addItem(rectangle);
        }
    }

    this->show();
    return;
}

CellMatrix::~CellMatrix() {
    for (auto item : scene->items()) {
        delete item;
    }
    delete scene;
}

