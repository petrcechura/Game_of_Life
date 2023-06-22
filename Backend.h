//
// Created by petr on 20.6.23.
//

#ifndef GAME_OF_LIFE_BACKEND_H
#define GAME_OF_LIFE_BACKEND_H

#include <vector>


// "static" class
class Backend {

public:
    // default rule = S23/B3
    Backend(const int &rows, const int &columns, const int to_survive = 23, const int to_be_born = 3);
    ~Backend();

    // get current calculated positions to print
    std::vector<int*> GetPositions();
    // create next population (calculate positions)
    void NextPop();


private:

    std::vector<int*> positions;
    int rows;
    int columns;
    int to_survive;
    int to_be_born;

    // analyze cell and return amount of living around
    int get_l_cells_around(const int &row, const int &column);
    // find out whether this cell is living (in positions) or not
    bool is_living(const int row, const int column);

    // predefined populations TODO
    static std::vector<int*> oscillator_pop;
    static std::vector<int*> still_life_pop;
    static std::vector<int*> gun_pop;
    static std::vector<int*> glider_pop;


};


#endif //GAME_OF_LIFE_BACKEND_H
