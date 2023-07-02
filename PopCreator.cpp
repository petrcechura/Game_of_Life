#include "PopCreator.h"


PopCreator::PopCreator(QWidget *parent) : 
        QMainWindow(parent) {
        
        const int BTN_SIZE = 10;

        // set widget and its layout
        central_widget = new QWidget(this);
        central_widget->setFixedSize(QSize(P_ROWS * BTN_SIZE, P_COLUMNS * BTN_SIZE));
        layout = new QGridLayout();
        layout->setGeometry(QRect(0, 0, P_ROWS * BTN_SIZE, P_COLUMNS * BTN_SIZE));      // size of widget depends on amount of btns
        layout->setSpacing(0);
        central_widget->setLayout(layout);
        this->setCentralWidget(central_widget);


        // create rectangles
        btn_matrix = new std::array<std::array<QPushButton*, P_COLUMNS>, P_ROWS>();
        for (int i = 0; i < P_ROWS; i++)  {
            for (int j = 0; j < P_COLUMNS; j++)  {          
                QPushButton *btn = new QPushButton(this);
                btn->setFixedSize(QSize(BTN_SIZE, BTN_SIZE));
                layout->addWidget(btn, i, j);
                (*btn_matrix)[i][j] = btn;
                QObject::connect((*btn_matrix)[i][j], &QPushButton::clicked, this, [this, i, j]() { onClick(i, j); });

            }
        }

        this->show();
}

void PopCreator::onClick(int row, int col)  {
    
    if ((*btn_matrix)[row][col]->styleSheet() == "background-color: black")  {
        (*btn_matrix)[row][col]->setStyleSheet("background-color: white");
    }
    else  {
        (*btn_matrix)[row][col]->setStyleSheet("background-color: black");
    }

}

std::vector<std::pair<int, int>> PopCreator::GetPositions()  {
    t_pop vec = {};
    for (int i = 0; i < btn_matrix->size(); i++)  {
        for (int j = 0; j < btn_matrix[0].size(); j++)  {
            if (btn_matrix[0][i][j]->styleSheet() == "background-color: black")  {
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