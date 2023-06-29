//
// Created by petr on 30.5.23.
//

#ifndef GAME_OF_LIFE_CELLMATRIX_H
#define GAME_OF_LIFE_CELLMATRIX_H

#include "PopCreator.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CellMatrix; }
QT_END_NAMESPACE

class CellMatrix : public QGraphicsView {
Q_OBJECT

public:
    explicit CellMatrix(QWidget *parent = nullptr, const int &rows = 0, const int &columns = 0);
    ~CellMatrix() override;

    // method to set living and dead cells
    void Update_matrix(const std::vector<std::vector<int>> matrix);


private:
    Ui::CellMatrix *ui;

    // scene
    QGraphicsScene *scene;

    // layout
    QGridLayout *layout;

    // matrix of cells
    std::vector<std::vector<QGraphicsRectItem*>>* create_cell_matrix(unsigned int rows, unsigned int columns);
    std::vector<std::vector<QGraphicsRectItem*>> *cellmatrix;

    // clear whole matrix (make all cells dead)
    void clearCells();

};


#endif //GAME_OF_LIFE_CELL_MATRIX_H
