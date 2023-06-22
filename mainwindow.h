//
// Created by petr on 19.6.23.
//

#ifndef GAME_OF_LIFE_MAINWINDOW_H
#define GAME_OF_LIFE_MAINWINDOW_H

#include <QMainWindow>
#include "cellmatrix.h"
#include "statistics.h"
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
    statistics *stats_widget;

    // layout
    QGridLayout *layout;

    // timer
    QTimer timer;

private slots:
    void timerTick();
};


#endif //GAME_OF_LIFE_MAINWINDOW_H
