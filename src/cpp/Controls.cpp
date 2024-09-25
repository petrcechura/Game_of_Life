#include "Controls.h"


Controls::Controls(QWidget* parent) :
    QWidget(parent)  {
    
    // btns definitons
    btn_start = new QPushButton("START", this);
    btn_pause = new QPushButton("PAUSE", this);
    btn_restart = new QPushButton("RESTART", this);
    btn_apply = new QPushButton("APPLY", this);

    // rules label and entry definiton
    rules_label = new QLabel("S23/B3", this);
    rules_label->setAlignment(Qt::AlignCenter);
    rules_entry = new QLineEdit(this);

    //layout definiton
    layout = new QVBoxLayout(this);
    layout->addWidget(btn_start);
    layout->addWidget(btn_pause);
    layout->addWidget(btn_restart);
    layout->addWidget(rules_label);
    layout->addWidget(rules_entry);
    layout->addWidget(btn_apply);

    // btn connections to proper functions
    QObject::connect(btn_start, &QPushButton::clicked, this, &Controls::start);
    QObject::connect(btn_pause, &QPushButton::clicked, this, &Controls::pause);
    QObject::connect(btn_restart, &QPushButton::clicked, this, &Controls::restart);
    QObject::connect(btn_apply, &QPushButton::clicked, this, &Controls::apply_func);

}

void Controls::apply_func()  {

    auto txt = rules_entry->text();

    if (txt.length() < 21 && txt.contains('/'))  {

        rules_label->setText(rules_entry->text());
        emit apply();
    }

}

std::string Controls::GetRules()  {
    return rules_label->text().toStdString();
}


Controls::~Controls()  {
    
}