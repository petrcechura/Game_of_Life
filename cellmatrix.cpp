//
// Created by petr on 30.5.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Cell_matrix.h" resolved

#include "cellmatrix.h"
#include "ui_cellmatrix.h"

std::vector<std::vector<QGraphicsRectItem*>>* CellMatrix::create_cell_matrix(unsigned int rows, unsigned int columns) {
    // rectangle size TODO automatic size calculation
    int height = 7;
    int width = 7;

    //dynamic matrix declaration
    std::vector<std::vector<QGraphicsRectItem*>> *matrix = new std::vector<std::vector<QGraphicsRectItem*>>();

    //matrix filling
    for (int i = 0; i < rows; i++)  {
        matrix->push_back(std::vector<QGraphicsRectItem*>());
        for (int j = 0; j < columns; j++)  {
            QRect rect(i * width,
                       j * height,
                       width,
                       height);
            QGraphicsRectItem *qRect = new QGraphicsRectItem(rect);
            (*matrix)[i].push_back(qRect);
        }
    }

    qDebug() << "Matrix: " << matrix->size() << "x" << matrix[0].size();

    return matrix;
}

void CellMatrix::Update_matrix(const std::vector<std::vector<int>> matrix) {

    // check if matrix is of valid size
    if (matrix.size() != cellmatrix->size() || matrix[0].size() != cellmatrix[0].size())  {
        qDebug() << "QDEBUG: Matrices don't have same size!";
        qDebug() << "arg matrix: " << matrix.size() << "X" << matrix[0].size() << "\ncellmatrix: " << cellmatrix->size() << "X" << cellmatrix[0].size();
        qTerminate();
    }


    for (int i = 0; i < matrix.size(); i++)  {
        for (int j = 0; j < matrix[0].size(); j++)  {
            if (matrix[i][j] == 1)  {
                cellmatrix[0][i][j]->setBrush(Qt::black);
            }
            else  {
                cellmatrix[0][i][j]->setBrush(Qt::white);
            }
        }
    }
}

void CellMatrix::clearCells() {
    for (auto row : (*cellmatrix))  {
        for (auto rectangle : row)  {
            rectangle->setBrush(Qt::white);
        }
    }
}


CellMatrix::CellMatrix(QWidget *parent, const int &rows, const int &columns) :
        QGraphicsView(parent), ui(new Ui::CellMatrix) {
    ui->setupUi(this);

    this->setGeometry( QRect(0, 0, 800, 800));
    // scene
    scene = new QGraphicsScene(this);
    this->setScene(scene);

    // layout
    layout = new QGridLayout(this);
    layout->setGeometry( QRect(0, 0, 700, 700));
    this->setLayout(layout);

    // cells creation
    if (rows < 0 ||
        rows > 200 ||
        columns < 0 ||
        columns > 200
        ) {
        qDebug() << "QDEBUG: Matrix to be created is too large! (max 200x200) Terminating...";
        qTerminate();
    }

    cellmatrix = this->create_cell_matrix(rows, columns);
    for (auto row : (*cellmatrix))  {
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
    for (auto arr : *cellmatrix)  {
        for (auto item : arr) {
            delete item;
        }
    }
    delete cellmatrix;
    delete scene;
    delete layout;
    delete ui;
}

