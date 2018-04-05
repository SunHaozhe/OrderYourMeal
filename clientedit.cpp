#include "clientedit.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>
#include <QHBoxLayout>
#include <QDebug>

clientEdit::clientEdit(QWidget *parent) :
    QDialog(parent)
{
//    client->setParent(this);
//    qDebug()<< client->getClient(0);
    client = &ClientInput::Instance();
    client->show();
    QPushButton* cancelBtn = new QPushButton("Cancel");
    QPushButton* confirmBtn = new QPushButton("Confirm");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(confirmBtn);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(client);
    mainLayout->addLayout(buttonLayout);

    this->setLayout(mainLayout);

    setModal(true);
//    this->setAutoDefault(true);
    connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancelButtonClicked()));
    connect(confirmBtn,SIGNAL(clicked(bool)),this,SLOT(confirmButtonClicked()));

    setMinimumSize(300,300);

}

clientEdit::~clientEdit()
{
}

void clientEdit::cancelButtonClicked(){
    this->hide();
    emit cancel(false);
}

void clientEdit::confirmButtonClicked(){
    this->hide();
    emit cancel(true);
}
