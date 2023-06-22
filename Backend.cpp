//
// Created by petr on 20.6.23.
//

#include "Backend.h"

Backend::Backend(const int &rows, const int &columns, const int to_survive, const int to_be_born) {

    this->rows = rows;
    this->columns = columns;
    this->to_survive = to_survive;
    this->to_be_born = to_be_born;

}

bool Backend::is_living(const int row, const int column) {
    for (auto pos : positions) {
        if (row == pos[0] && column == pos[1]) {
            return true;
        }
    }
    return false;
}

int Backend::get_l_cells_around(const int &row, const int &column) {
    int pos_row = row, pos_col = column;
    int cells_count = 0;

    pos_row = row;
    pos_col = column + 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row;
    pos_col = column - 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row + 1;
    pos_col = column;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row - 1;
    pos_col = column;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;

    pos_row = row + 1;
    pos_col = column + 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row + 1;
    pos_col = column - 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row - 1;
    pos_col = column + 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;
    pos_row = row - 1;
    pos_col = column - 1;
    cells_count = cells_count + 1 ? is_living(pos_row, pos_col) : cells_count;

    return cells_count;
}

void Backend::NextPop() {
    //loop through matrix
}




Backend::~Backend() {
    delete this;
}
