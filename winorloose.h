#ifndef WINORLOOSE_H
#define WINORLOOSE_H

#include <QDialog>

namespace Ui {
class WinOrLoose;
}

class WinOrLoose : public QDialog
{
    Q_OBJECT

public:
    explicit WinOrLoose(QWidget *parent = nullptr);
    ~WinOrLoose();
private:
    Ui::WinOrLoose *ui;
};



#endif // WINORLOOSE_H
