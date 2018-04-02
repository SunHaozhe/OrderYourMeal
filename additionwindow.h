#ifndef ADDITIONWINDOW_H
#define ADDITIONWINDOW_H

#include <QWidget>

namespace Ui {
class AdditionWindow;
}

class AdditionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdditionWindow(QWidget *parent = 0);
    ~AdditionWindow();

private:
    Ui::AdditionWindow *ui;
};

#endif // ADDITIONWINDOW_H
