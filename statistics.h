//
// Created by petr on 29.5.23.
//

#ifndef GAME_OF_LIFE_STATISTICS_H
#define GAME_OF_LIFE_STATISTICS_H

#include <QLabel>
#include <QVBoxLayout>
#include <string>
#include "cellmatrix.h"


QT_BEGIN_NAMESPACE
namespace Ui { class statistics; }
QT_END_NAMESPACE

class statistics : public QWidget {
Q_OBJECT

public:
    explicit statistics(QWidget *parent = nullptr);

    ~statistics() override;

    //setters
    void LCellsSet(int amount);
    void TbbCellsSet(int amount);
    void PopulationInc();

private:
    Ui::statistics *ui;

    // labels
    QLabel *l_cells_am_l;
    QLabel *tbb_cells_l;
    QLabel *population_l;

    //layout
    QVBoxLayout *layout;

    long int pop_no;

};


#endif //GAME_OF_LIFE_STATISTICS_H
