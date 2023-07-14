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


class Backend {

public:
    // default rule = S23/B3
    Backend(std::string rules);
    ~Backend();

    // get current calculated positions to print
    std::array<std::array<int, COLUMNS>, ROWS> GetMatrix() { return matrix;};
    
    // create next population (calculate positions due to rules)
    void NextPop();

    // get amount of current living cells
    int GetCells() {return living_cells;};

    // generate new population
    void NewPop() {matrix = create_matrix(random_pop()); };

    // add new population that can be used later
    void AddPop(t_pop pop);

    // set rules for calculations
    void SetRules(std::string rules);

private:

    std::array<std::array<int, COLUMNS>, ROWS> matrix;
    std::string to_survive;
    std::string to_be_born;
    int living_cells;

    // analyze cell and return amount of living cells around
    int get_living_cells_around(const int &row, const int &column);
    // create matrix
    std::array<std::array<int, COLUMNS>, ROWS> create_matrix(const t_pop def_positions);

    // check if given string contains given number
    inline bool contains_num(std::string str, int num);



    // predefined populations TODO
    t_pop blank_pop();
    t_pop oscillator_pop();
    t_pop still_life_pop();
    t_pop gun_pop();
    t_pop glider_pop();
    t_pop random_pop();


};


#endif //GAME_OF_LIFE_BACKEND_H
