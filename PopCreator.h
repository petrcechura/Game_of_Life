#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGridLayout>
#include <vector>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QRect>

#ifndef GAME_OF_LIFE_POPCREATOR_H
#define GAME_OF_LIFE_POPCREATOR_H


QT_BEGIN_NAMESPACE
namespace Ui { class QMainWindow; }
QT_END_NAMESPACE

class PopCreator : public QMainWindow {
Q_OBJECT

public:
    explicit PopCreator(QWidget *parent = nullptr, const int &rows = 100, const int &columns = 100);

    std::vector<std::pair<int, int>> GetPositions();

    ~PopCreator() override;

private:
    // graphics widget
    QWidget *central_widget;
    QGridLayout *layout;

    // subset of rectangles;
    std::vector<std::vector<QPushButton*>> *rectangles;

private slots:
    // on click fuction (for all buttons)
    void onClick(int row, int column);



};


#endif //GAME_OF_LIFE_POP_CREATOR_H