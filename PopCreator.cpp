#include "PopCreator.h"


PopCreator::PopCreator(QWidget *parent, const int &rows, const int &columns) : 
        QMainWindow(parent) {
        
        const int btn_size = 15;

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
                btn->setGeometry(i * 10,
                                 j * 10,
                                 10,
                                 10);
                btn->setFixedSize(QSize(btn_size, btn_size));
                layout->addWidget(btn, i, j);
                (*rectangles)[i].push_back(btn);
                QObject::connect((*rectangles)[i][j], SIGNAL(clicked()), this, SLOT([&] { rectangles[0][i][j]->setText("X");}));
            }
        }

        this->show();
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