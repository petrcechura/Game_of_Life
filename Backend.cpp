//
// Created by petr on 20.6.23.
//

#include "Backend.h"

std::vector<std::pair<int, int>> Backend::blank_pop() {
    std::vector<std::pair<int, int>> positions;
    return positions;
}

std::vector<std::pair<int, int>> Backend::random_pop() {
    std::vector<std::pair<int, int>> positions;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)  {
            if (rand() % 2 == 1)  {
                
                positions.push_back(std::pair<int, int>(i, j));
            }
        }
    }
    return positions;
}

std::vector<std::pair<int, int>> Backend::glider_pop() {
    std::vector<std::pair<int, int>> positions;

    int center_row = rows/2;
    int center_column = columns/2;


    //  010
    //  001
    //  111
    try
    {
        positions.push_back(std::pair<int, int>(center_row - 1, center_column));
        positions.push_back(std::pair<int, int>(center_row, center_column + 1));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column - 1));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column));
        positions.push_back(std::pair<int, int>(center_row + 1, center_column + 1));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return positions;
}



Backend::Backend(const int &rows, const int &columns, std::string rules)
    : rows(rows), columns(columns) {

    int to_sur = rules.find('S');
    int to_bb = rules.find('B');
    to_survive = "";
    to_be_born = "";

    // loop through rules from character S to get whole "to survive" string 
    for (int i = to_sur+1; i < to_bb-1; i++)  {
        to_survive += rules[i];
    }
    // same but with "to be born"
    for (int i = to_bb+1; i < rules.size(); i++)  {
        to_be_born += rules[i];
    }

    matrix = create_matrix(rows, columns, random_pop());
}

std::vector<std::vector<int>> Backend::create_matrix(const int &rows, const int &columns, const std::vector<std::pair<int, int>> def_positions)  {

    // create blank matrix
    std::vector<std::vector<int>> matrix = {};
    for (int i = 0; i < rows; i++) {
        std::vector<int> *vec = new std::vector<int>();
        for (int j = 0; j < columns; j++)  {
            vec->push_back(0);
        }
        matrix.push_back(*vec);
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

    if (pos_row + 1 < rows)
        cells_count = matrix[pos_row + 1][pos_col] == 1 ? cells_count + 1 : cells_count;
    if (pos_row - 1 >= 0)  
        cells_count = matrix[pos_row - 1][pos_col] == 1? cells_count + 1 : cells_count;

    if (pos_col + 1 < columns)
        cells_count = matrix[pos_row][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_col - 1 >= 0)
        cells_count = matrix[pos_row][pos_col - 1] == 1 ? cells_count + 1 : cells_count;

    if (pos_row + 1 < rows && pos_col + 1 < columns)
        cells_count = matrix[pos_row + 1][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_row + 1 < rows && pos_col - 1 >= 0)
        cells_count = matrix[pos_row + 1][pos_col - 1] == 1 ? cells_count + 1 : cells_count;

    if (pos_row - 1 >= 0 && pos_col + 1 < columns)
        cells_count = matrix[pos_row - 1][pos_col + 1] == 1 ? cells_count + 1 : cells_count;
    if (pos_row - 1 >= 0 && pos_col - 1>= 0)
        cells_count = matrix[pos_row - 1][pos_col - 1] == 1 ? cells_count + 1 : cells_count;
    
    return cells_count;
}

void Backend::NextPop() {
    std::vector<std::vector<int>> new_matrix;
    int new_living_cells = 0;

    for (int row = 0; row < this->rows; row++)  {
        std::vector<int> vec;
        for (int col = 0; col < this->columns; col++)  {
            int cells_amount = get_living_cells_around(row, col);
            // if cell is alive, check survival, otherwise check if to_be_born is possible
            if (matrix[row][col] == 1)  {
                if (contains_num(to_survive, cells_amount)) {
                    vec.push_back(1);
                    new_living_cells++;
                }
                else {
                    vec.push_back(0);
                }
            }
            else {
                if (contains_num(to_be_born, cells_amount)) {
                    vec.push_back(1);
                    new_living_cells++;
                }
                else {
                    vec.push_back(0);
                }
            }

        }
        new_matrix.push_back(vec);
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
