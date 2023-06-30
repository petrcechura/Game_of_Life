//
// Created by petr on 20.6.23.
//

#ifndef GAME_OF_LIFE_BACKEND_H
#define GAME_OF_LIFE_BACKEND_H

#include <tuple>
#include <iostream>
#include <QDebug>
#include <random>
#include <time.h>
#include "statistics.h"


// "static" class
class Backend {

public:
    // default rule = S23/B3
    Backend(const int &rows, const int &columns, std::string rules);
    ~Backend();

    // get current calculated positions to print
    std::vector<std::vector<int>> GetMatrix() { return matrix;};
    // create next population (calculate positions)
    void NextPop();
    // get amount of current living cells
    int GetCells() {return living_cells;};

private:

    std::vector<std::vector<int>> matrix;
    int rows;
    int columns;
    std::string to_survive;
    std::string to_be_born;
    int living_cells;

    // analyze cell and return amount of living around
    int get_living_cells_around(const int &row, const int &column);
    // create matrix
    std::vector<std::vector<int>> create_matrix(const int &rows, const int &columns, const std::vector<std::pair<int, int>> def_positions);

    // check if given string contains given number
    inline bool contains_num(std::string str, int num);

    // predefined populations TODO
    std::vector<std::pair<int, int>> blank_pop();
    std::vector<std::pair<int, int>> oscillator_pop();
    std::vector<std::pair<int, int>> still_life_pop();
    std::vector<std::pair<int, int>> gun_pop();
    std::vector<std::pair<int, int>> glider_pop();
    std::vector<std::pair<int, int>> random_pop();


};


#endif //GAME_OF_LIFE_BACKEND_H
