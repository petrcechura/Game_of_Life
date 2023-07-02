#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGridLayout>
#include <array>
#include <vector>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QRect>
#include <memory>

#ifndef GAME_OF_LIFE_POPCREATOR_H
#define GAME_OF_LIFE_POPCREATOR_H

#define P_ROWS 50
#define P_COLUMNS 50

#define t_pop std::vector<std::pair<int, int>>

QT_BEGIN_NAMESPACE
namespace Ui { class QMainWindow; }
QT_END_NAMESPACE

class PopCreator : public QMainWindow {
Q_OBJECT

public:
    explicit PopCreator(QWidget *parent);

    // Get positions of buttons that have been clicked on (-> are black)
    t_pop GetPositions();

    ~PopCreator() override;

private:
    // graphics widget
    QWidget *central_widget;
    QGridLayout *layout;

    // Matrix of rectangles (buttons)
    std::array<std::array<QPushButton*, P_COLUMNS>, P_ROWS> *btn_matrix;;

private slots:
    // on click fuction; recolours button from white to black and viceversa
    void onClick(int row, int col);



};


#endif //GAME_OF_LIFE_POP_CREATOR_H