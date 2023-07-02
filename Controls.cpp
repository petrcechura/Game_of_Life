#include "Controls.h"


Controls::Controls(QWidget* parent) :
    QWidget(parent)  {
    
    // btns definitons
    btn_start = new QPushButton("START", this);
    btn_pause = new QPushButton("PAUSE", this);
    btn_restart = new QPushButton("RESTART", this);
    btn_apply = new QPushButton("APPLY", this);

    //layout definiton
    layout = new QVBoxLayout(this);
    layout->addWidget(btn_start);
    layout->addWidget(btn_pause);
    layout->addWidget(btn_restart);
    layout->addWidget(btn_apply);

    // btn connections to proper functions
    QObject::connect(btn_start, &QPushButton::clicked, this, Start);
    QObject::connect(btn_pause, &QPushButton::clicked, this, Pause);
    QObject::connect(btn_restart, &QPushButton::clicked, this, Restart);
    QObject::connect(btn_apply, &QPushButton::clicked, this, Start);
}

void Controls::Start()  {

}

void Controls::Pause()  {

}

void Controls::Restart()  {

}


Controls::~Controls()  {
    
}