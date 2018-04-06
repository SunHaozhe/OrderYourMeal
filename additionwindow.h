#ifndef ADDITIONWINDOW_H
#define ADDITIONWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <vector>
#include <cstdlib>
#include <iostream>

namespace Ui {
class AdditionWindow;
}

class AdditionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdditionWindow(QWidget *parent = 0, int c1=10);
    ~AdditionWindow();

public slots:
    void payModeChanged(int);
    void payAction();
    void eval();


private:
    Ui::AdditionWindow *ui;
    bool goDutch = true;
    int dutchPrice = 0;
    int deskPrice = 0;
};

#endif // ADDITIONWINDOW_H
