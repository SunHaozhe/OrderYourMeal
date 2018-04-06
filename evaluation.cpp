#include "evaluation.h"
#include "ui_evaluation.h"

Evaluation::Evaluation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Evaluation)
{
    ui->setupUi(this);

    QButtonGroup * radioGroup = new QButtonGroup(this);
    radioGroup->addButton(ui->note1, 1);
    radioGroup->addButton(ui->note2, 2);
    radioGroup->addButton(ui->note3, 3);
    radioGroup->addButton(ui->note4, 4);
    radioGroup->addButton(ui->note5, 5);
    ui->note3->setChecked(true);
}

Evaluation::~Evaluation()
{
    delete ui;
}
