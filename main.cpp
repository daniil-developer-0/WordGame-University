#include "wordgame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WordGame w;
    w.show();
    return a.exec();
}
