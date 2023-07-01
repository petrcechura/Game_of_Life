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

class Statistics : public QWidget {
Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);

    ~Statistics() override;

    //setters
    void LCellsSet(int amount);
    void PopulationInc();

private:
    Ui::statistics *ui;

    // labels
    QLabel *l_cells_am_l;
    QLabel *population_l;
    // TODO labels for stability check, derivation of population...

    //layout
    QVBoxLayout *layout;

    long int pop_no;

};


#endif //GAME_OF_LIFE_STATISTICS_H
