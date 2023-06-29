//
// Created by petr on 19.6.23.
//

#ifndef GAME_OF_LIFE_MAINWINDOW_H
#define GAME_OF_LIFE_MAINWINDOW_H

#include <QMainWindow>
#include "Backend.h"
#include <QTimer>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, const int &rows = 100, const int &columns = 100);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    // widgets
    QWidget *central_widget;
    CellMatrix *matrix_widget;
    statistics *stats_widget;

    // Backend for calculation
    Backend *backend;

    // layout
    QGridLayout *layout;

    // timer
    QTimer timer;

    // delay before next population
    int delay_ms;

private slots:
    void timerTick();
};


#endif //GAME_OF_LIFE_MAINWINDOW_H
