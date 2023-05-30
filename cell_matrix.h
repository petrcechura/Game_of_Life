//
// Created by petr on 30.5.23.
//

#ifndef GAME_OF_LIFE_CELL_MATRIX_H
#define GAME_OF_LIFE_CELL_MATRIX_H

#include <QWidget>
#include <QGraphicsView>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class Cell_matrix; }
QT_END_NAMESPACE

class Cell_matrix : public QGraphicsView {
Q_OBJECT

public:
    explicit Cell_matrix(QWidget *parent = nullptr);

    ~Cell_matrix() override;

private:
    Ui::Cell_matrix *ui;

    // scene
    QGraphicsScene *scene;

    // layout
    QGridLayout *layout;

    // matrix of cells



};


#endif //GAME_OF_LIFE_CELL_MATRIX_H
