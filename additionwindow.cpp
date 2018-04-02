#include "additionwindow.h"
#include "ui_additionwindow.h"

AdditionWindow::AdditionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdditionWindow)
{
    ui->setupUi(this);
}

AdditionWindow::~AdditionWindow()
{
    delete ui;
}
