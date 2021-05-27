#include "winorloose.h"
#include "ui_winorloose.h"
#include "wordgame.h"
#include <QProcess>

WinOrLoose::WinOrLoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinOrLoose)
{
    ui->setupUi(this);
    connect(ui->WinNoButton, &QPushButton::released, this, &QApplication::quit);
}

WinOrLoose::~WinOrLoose()
{
    delete ui;
}
