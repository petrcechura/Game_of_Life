#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QObject>

class Controls : public QWidget
{
Q_OBJECT

public:
    Controls::Controls(QWidget* parent);
    Controls::~Controls();

    void Start();
    void Pause();
    void Restart();

private:
    // layout
    QVBoxLayout* layout;



    // start/resume the game
    QPushButton* btn_start;
    // pause the game
    QPushButton* btn_pause;
    // restart the game with same population
    QPushButton* btn_restart;
    // apply selected rules (&& check their validity)
    QPushButton* btn_apply;

    // label to show curent rules
    QLabel* rules_label;
    // entry point for user to type custom rules
    QLineEdit* rules_entry;

    // TODO list to show avaiable pops



};