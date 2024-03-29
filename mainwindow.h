//
// Created by petr on 19.6.23.
//

#ifndef GAME_OF_LIFE_MAINWINDOW_H
#define GAME_OF_LIFE_MAINWINDOW_H

#include "Controls.h"
#include <QTimer>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    // widgets
    QWidget *central_widget;
    CellMatrix *matrix_widget;
    Statistics *stats_widget;
    Controls *controls_widget;

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
    void start();
    void pause();
    void apply();
    void restart();
};


#endif //GAME_OF_LIFE_MAINWINDOW_H
