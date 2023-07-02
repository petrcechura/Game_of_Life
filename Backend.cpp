//
// Created by petr on 20.6.23.
//

#include "Backend.h"

t_pop Backend::blank_pop() {
    t_pop positions;
    return positions;
}

t_pop Backend::random_pop() {
    t_pop positions;
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)  {
            if (rand() % 2 == 1)  {
                positions.push_back(std::pair<int, int>(i, j));
            }
        }
    }
    return positions;
}

t_pop Backend::glider_pop() {
    t_pop positions;

    int center_row = ROWS/2;
    int center_column = COLUMNS/2;


    //  010
    //  001
    //  111
        positions.push_back(std::pair<int, int>(center_row - 1, center_column));
        positions.push_back(std::pair<int, int>(center_row, center_column + 1));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column - 1));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column + 1));
    
    return positions;
}




Backend::Backend(std::string rules) {

    SetRules(rules);
    NewPop();
}

void Backend::SetRules(std::string rules)  {
    
    int middle = rules.find('/');
    to_survive = "";
    to_be_born = "";

    // loop through rules from character S to get whole "to survive" string 
    for (int i = 0; i < middle; i++)  {
        if (rules[i] < 58 && rules[i] > 47)
            to_survive += rules[i];
    }
    // same but with "to be born"
    for (int i = middle + 1; i < rules.size(); i++)  {
        if (rules[i] < 58 && rules[i] > 47)
            to_be_born += rules[i];
    }

}

std::array<std::array<int, COLUMNS>, ROWS> Backend::create_matrix(const t_pop def_positions)  {

    // create blank matrix
    std::array<std::array<int, COLUMNS>, ROWS> matrix;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)  {
            matrix[i][j] = 0;
        }
    }

    // fill the matrix with default positions
    for (auto pos : def_positions) {
        matrix[pos.first][pos.second] = 1;
    }

    return matrix;
}


int Backend::get_living_cells_around(const int &row, const int &column) {
    int pos_row = row, pos_col = column;
    int cells_count = 0;

    if (pos_row + 1 < ROWS)
        cells_count = matrix[pos_row + 1][pos_col] == 1 ? cells_count + 1 : cells_count;
    if (pos_row - 1 >= 0)  
        cells_count = matrix[pos_row - 1][pos_col] == 1? cells_count + 1 : cells_count;

    if (pos_col + 1 < COLUMNS)
        cells_count = matrix[pos_row][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_col - 1 >= 0)
        cells_count = matrix[pos_row][pos_col - 1] == 1 ? cells_count + 1 : cells_count;

    if (pos_row + 1 < ROWS && pos_col + 1 < COLUMNS)
        cells_count = matrix[pos_row + 1][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_row + 1 < ROWS && pos_col - 1 >= 0)
        cells_count = matrix[pos_row + 1][pos_col - 1] == 1 ? cells_count + 1 : cells_count;

    if (pos_row - 1 >= 0 && pos_col + 1 < COLUMNS)
        cells_count = matrix[pos_row - 1][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_row - 1 >= 0 && pos_col - 1>= 0)
        cells_count = matrix[pos_row - 1][pos_col - 1] == 1 ? cells_count + 1 : cells_count;
    
    return cells_count;
}

void Backend::NextPop() {
    std::array<std::array<int, COLUMNS>, ROWS> new_matrix;
    int new_living_cells = 0;

    for (int row = 0; row < ROWS; row++)  {
        for (int col = 0; col < COLUMNS; col++)  {
            int cells_amount = get_living_cells_around(row, col);
            // if cell is alive, check survival, otherwise check if to_be_born is possible
            if (matrix[row][col] == 1)  {
                if (contains_num(to_survive, cells_amount)) {
                    new_matrix[row][col] = 1;
                    new_living_cells++;
                }
                else {
                    new_matrix[row][col] = 0;
                }
            }
            else {
                if (contains_num(to_be_born, cells_amount)) {
                    new_matrix[row][col] = 1;
                    new_living_cells++;
                }
                else {
                    new_matrix[row][col] = 0;
                }
            }
        }
    }

    matrix = new_matrix;
    living_cells = new_living_cells;

}

bool Backend::contains_num(std::string str, int num)  {
    for (char c : str)
        if (c - 48 == num)
            return true;
    return false;
}


Backend::~Backend() {
    delete this;
}
