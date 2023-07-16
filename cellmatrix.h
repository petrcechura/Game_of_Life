//
// Created by petr on 30.5.23.
//

#ifndef GAME_OF_LIFE_CELLMATRIX_H
#define GAME_OF_LIFE_CELLMATRIX_H

#include "PopCreator.h"
#include <thread>

#define ROWS 100
#define COLUMNS 100

#define t_matr_int std::array<std::array<int, COLUMNS>, ROWS>
#define t_matr_rect std::array<std::array<QGraphicsRectItem*, COLUMNS>, ROWS>



QT_BEGIN_NAMESPACE
namespace Ui { class CellMatrix; }
QT_END_NAMESPACE

class CellMatrix : public QGraphicsView {
Q_OBJECT

public:
    explicit CellMatrix(QWidget *parent = nullptr);
    ~CellMatrix() override;

    // method to set living and dead cells
    void Update_matrix(const t_matr_int &matrix);


private:
    Ui::CellMatrix *ui;

    // scene
    QGraphicsScene *scene;

    // layout
    QGridLayout *layout;

    // matrix of cells
    t_matr_rect create_cell_matrix();
    t_matr_rect cellmatrix;

    // clear whole matrix (make all cells dead)
    void clearCells();

};


#endif //GAME_OF_LIFE_CELL_MATRIX_H
