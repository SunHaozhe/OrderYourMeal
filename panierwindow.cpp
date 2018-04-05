#include "panierwindow.h"
#include "ui_panierwindow.h"
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>

PanierWindow::PanierWindow(QWidget *parent,vector<plat*> _listPlat, int _numClient, int _somme, int _numTable) :
    QDialog(parent), panier(_listPlat,_numClient,_somme,_numTable),
    ui(new Ui::PanierWindow)
{

    isStatic = false;
    ui->setupUi(this);
    numPlat=_listPlat.size();
    clist.push_back("not specified");
    for(int i=0; i<4; i++){
        QString name = ClientInput::Instance().getClient(i);
        if(!name.isEmpty()){
            clist.push_back(name);
        }
    }
    for(int i=0; i<_listPlat.size(); i++){
//        platIntro* tmp = new platIntro(_listPlat[i]);
        QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
        plats.push_back(tmp);
        ui->gridLayout->addWidget(tmp,i,0);
        QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
        prix.push_back(tmpPrix);
        ui->gridLayout->addWidget(tmpPrix,i,1);
        QComboBox* tmpClt = new QComboBox;
        tmpClt->addItems(clist);
        clients.push_back(tmpClt);
        ui->gridLayout->addWidget(tmpClt,i,2);
        QPushButton* deleteBtn = new QPushButton("Delete");
        ui->gridLayout->addWidget(deleteBtn,i,3);
        btnGroup.addButton(deleteBtn,i);
        somme+=_listPlat[i]->getPrix();
    }
    connect(&btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(deletePlat(int)));
    connect(ui->addBtn,SIGNAL(clicked(bool)),this,SLOT(addClient()));
    connect(ui->retourBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->confirmBtn,SIGNAL(clicked(bool)),this,SLOT(confirmOrder()));
    ui->prixLabel->setText("Somme: "+QString::number(somme)+" EUR");
}

PanierWindow::~PanierWindow()
{
    delete ui;
    delete cltInput;
}

void PanierWindow::addPlat(plat *p){
    int idx = ui->gridLayout->rowCount();
//    platIntro* tmp = new platIntro(p);
    listPlat.push_back(p);
    QLabel* tmp = new QLabel(QString::fromStdString(p->getNom()));
    plats.push_back(tmp);
    ui->gridLayout->addWidget(tmp,idx,0);
    QLabel* tmpPrix = new QLabel(QString::number(p->getPrix()));
    prix.push_back(tmpPrix);
    ui->gridLayout->addWidget(tmpPrix,idx,1);
    if(!isStatic){
    QComboBox* clt = new QComboBox;
    clt->addItems(clist);
    clients.push_back(clt);
    ui->gridLayout->addWidget(clients.back(),idx,2);
    QPushButton* deleteBtn = new QPushButton("Delete");
    ui->gridLayout->addWidget(deleteBtn,idx,3);
    btnGroup.addButton(deleteBtn,plats.size()-1);
    }
    somme+=p->getPrix();
    ui->prixLabel->setText("Somme: "+QString::number(somme)+" EUR");
    numPlat++;
    emit panierUpdated();
}

void PanierWindow::deletePlat(int idx){
    plats[idx]->close();
    clients[idx]->close();
    prix[idx]->close();
    btnGroup.button(idx)->close();
    somme-=listPlat[idx]->getPrix();
    ui->prixLabel->setText("Somme: "+QString::number(somme)+" EUR");
    numPlat--;
    emit panierUpdated();
}

void PanierWindow::addClient(){
    cltInput->show();
}

void PanierWindow::updateClient(bool update){
    if(update){
        clist.clear();
        clist.push_back("---");
        for(int i=0; i<4; i++){
            QString name = ClientInput::Instance().getClient(i);
            if(!name.isEmpty()){
                clist.push_back(name);
            }
        }

        for(int i=0; i<clients.size(); i++){
            clients[i]->clear();
            clients[i]->addItems(clist);
        }

    }
}

void PanierWindow::confirmOrder(){
    std::cout << "Confirm" << std::endl;
    QMessageBox::StandardButton msg = QMessageBox::information(NULL,"Order","Confirm to submit the order?",QMessageBox::No|QMessageBox::Yes, QMessageBox::Yes);
    if(msg== QMessageBox::Yes){
        QMessageBox::information(NULL,"Order","Order submitted successfully! :)",QMessageBox::Ok);
        emit orderComfirmed();
        this->close();
    }
}

void PanierWindow::payBill(){
    QMessageBox::StandardButton msg = QMessageBox::information(NULL,"Bill","Confirm to pay the bill?",QMessageBox::No|QMessageBox::Yes, QMessageBox::Yes);
    if(msg==QMessageBox::Yes){
        QMessageBox::information(NULL,"Bill","The waiter is comming. Please wait a minute. :)",QMessageBox::Ok);
        this->close();
    }
}

void PanierWindow::setStatic(){
    ui->confirmBtn->setText(tr("Pay the bill"));
    disconnect(ui->confirmBtn,SIGNAL(clicked()),this,SLOT(confirmOrder()));
    connect(ui->confirmBtn,SIGNAL(clicked()),this,SLOT(payBill()));
    ui->addBtn->hide();
    QList<QAbstractButton*> buttons = btnGroup.buttons();
    for(int i=0; i<buttons.size();i++){
        buttons[i]->hide();
    }
    clients.clear();
    isStatic=true;
}
