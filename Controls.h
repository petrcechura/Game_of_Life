


#ifndef GAME_OF_LIFE_CONTROLS_H
#define GAME_OF_LIFE_CONTROLS_H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QObject>
#include "Backend.h"


class Controls : public QWidget
{
Q_OBJECT

public:
    Controls(QWidget* parent);
    ~Controls();

    std::string GetRules();

private:

    // layout
    QVBoxLayout* layout;

    // start/resume the game
    QPushButton* btn_start;
    // pause the game
    QPushButton* btn_pause;
    // restart the game with same population
    QPushButton* btn_restart;
    // apply selected rules (&& check their validity)
    QPushButton* btn_apply;
    void apply_func();

    // label to show curent rules
    QLabel* rules_label;
    // entry point for user to type custom rules
    QLineEdit* rules_entry;

    // TODO list to show avaiable pops

signals:
    void start();
    void pause();
    void restart();
    void apply();

};

#endif 