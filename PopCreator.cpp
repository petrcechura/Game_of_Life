#include "PopCreator.h"


PopCreator::PopCreator(QWidget *parent, const int &rows, const int &columns) : 
        QMainWindow(parent) {
        
        const int btn_size = 10;

        // set widget
        central_widget = new QWidget(this);
        central_widget->setFixedSize(QSize(rows * btn_size, columns * btn_size));
        layout = new QGridLayout();
        layout->setGeometry(QRect(0, 0, rows * btn_size, columns * btn_size));
        layout->setSpacing(0);
        central_widget->setLayout(layout);
        this->setCentralWidget(central_widget);


        // create rectangles
        rectangles = new std::vector<std::vector<QPushButton*>>();
        for (int i = 0; i < rows; i++)  {
            rectangles->push_back(std::vector<QPushButton*>());
            for (int j = 0; j < columns; j++)  {          
                QPushButton *btn = new QPushButton(this);
                btn->setFixedSize(QSize(btn_size, btn_size));
                layout->addWidget(btn, i, j);
                (*rectangles)[i].push_back(btn);
                QObject::connect((*rectangles)[i][j], &QPushButton::clicked, this, [this, i, j]() { onClick(i, j); });

            }
        }

        this->show();
}

void PopCreator::onClick(int row, int col)  {
    
    if ((*rectangles)[row][col]->styleSheet() == "background-color: black")  {
        (*rectangles)[row][col]->setStyleSheet("background-color: white");
    }
    else  {
        (*rectangles)[row][col]->setStyleSheet("background-color: black");
    }

}

std::vector<std::pair<int, int>> PopCreator::GetPositions()  {
    std::vector<std::pair<int, int>> vec = {};
    for (int i = 0; i < rectangles->size(); i++)  {
        for (int j = 0; j < rectangles[0].size(); j++)  {
            if (rectangles[0][i][j]->styleSheet() == "background-color: black")  {
                vec.push_back(std::pair(i, j));
            }
        }
    }
    return vec;
}

PopCreator::~PopCreator()  {

    delete layout;
    delete central_widget;
}