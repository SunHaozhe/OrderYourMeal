#ifndef ADDITIONWINDOW_H
#define ADDITIONWINDOW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AdditionWindow;
}

class AdditionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdditionWindow(QWidget *parent = 0);
    ~AdditionWindow();

public slots:
    void payModeChanged(int);
    void payAction();


private:
    Ui::AdditionWindow *ui;
    bool goDutch = true;
    float dutchPrice = 2;
    float deskPrice = 13;
};

#endif // ADDITIONWINDOW_H
