#include "clientinput.h"
#include "ui_clientinput.h"


ClientInput::ClientInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientInput)
{
    ui->setupUi(this);
    names.push_back(ui->lineEdit);
    names.push_back(ui->lineEdit_2);
    names.push_back(ui->lineEdit_3);
    names.push_back(ui->lineEdit_4);
    prefixs.push_back(ui->comboBox);
    prefixs.push_back(ui->comboBox_2);
    prefixs.push_back(ui->comboBox_3);
    prefixs.push_back(ui->comboBox_4);
    setMinimumSize(150,150);
}

ClientInput::~ClientInput()
{
    delete ui;
}
