#include "PopCreator.h"


PopCreator::PopCreator(QWidget *parent, const int &rows, const int &columns) : 
        QMainWindow(parent) {

        // set widget
        central_widget = new QWidget(this);
        layout = new QGridLayout(this);
        this->setLayout(layout);
        this->show();
        this->setCentralWidget(central_widget);


        // create rectangles
        rectangles = new std::vector<std::vector<QPushButton*>>();
        for (int i = 0; i < rows; i++)  {
            rectangles->push_back(std::vector<QPushButton*>());
            for (int j = 0; j < columns; j++)  {          
                QPushButton *btn = new QPushButton(this);
                QObject::connect(btn, SIGNAL(clicked()), this, SLOT(onClick(i, j)));
                (*rectangles)[i].push_back(btn);
            }
        }
}

void PopCreator::onClick(int row, int column)  {
    rectangles[0][row][column]->setText("X");

}

std::vector<std::pair<int, int>> PopCreator::GetPositions()  {
    std::vector<std::pair<int, int>> vec = {};
    for (int i = 0; i < rectangles->size(); i++)  {
        for (int j = 0; j < rectangles[0].size(); j++)  {
            if (rectangles[0][i][j]->text() == "X")  {
                vec.push_back(std::pair(i, j));
            }
        }
    }
    return vec;
}

PopCreator::~PopCreator()  {

    for (int i = 0; i < rectangles->size(); i++)  {
        for (int j = 0; j < rectangles[0].size(); j++)  {
            delete rectangles[0][i][j];
        }
    }
    delete rectangles;

    delete layout;
    delete central_widget;
    delete this;
}