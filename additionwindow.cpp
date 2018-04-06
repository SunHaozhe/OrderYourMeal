#include "additionwindow.h"
#include "ui_additionwindow.h"

using namespace std;

AdditionWindow::AdditionWindow(QWidget *parent, int c1) :
    QWidget(parent),
    ui(new Ui::AdditionWindow)
{
    ui->setupUi(this);
    std::vector<int> clientPrice;

    int max_clientN = 4; //max_clientN <= 8

    clientPrice.clear();
    clientPrice.push_back(c1);
    clientPrice.push_back(20);
    clientPrice.push_back(24);
    clientPrice.push_back(46);
    clientPrice.push_back(39);
    clientPrice.push_back(11);
    clientPrice.push_back(23);
    clientPrice.push_back(98);
    clientPrice.push_back(21);
    clientPrice.push_back(67);
    clientPrice.push_back(9);
    clientPrice.push_back(124);

    QButtonGroup * radioGroup = new QButtonGroup(this);
    QObject::connect(radioGroup, SIGNAL(buttonClicked(int)), this, SLOT(payModeChanged(int)));
    radioGroup->addButton(ui->payForYourselfRadio, 0);
    radioGroup->addButton(ui->payForYourDeskRadio, 1);
    ui->payForYourselfRadio->setChecked(true);

    QButtonGroup * noteGroup = new QButtonGroup(this);
    QObject::connect(noteGroup, SIGNAL(buttonClicked(int)), this, SLOT(eval()));
    noteGroup->addButton(ui->note1, 1);
    noteGroup->addButton(ui->note2, 2);
    noteGroup->addButton(ui->note3, 3);
    noteGroup->addButton(ui->note4, 4);
    noteGroup->addButton(ui->note5, 5);
    ui->note3->setChecked(true);

    for(int i = 0; i < max_clientN; i++){
        ui->deskClientList->insertItem(i, QString("Client %1").arg(i + 1));
    }

    for(int i = 0; i < max_clientN; i++){
        ui->clientPriceList->insertItem(i, QString("%1 euros").arg(clientPrice[i]));
    }

    dutchPrice = clientPrice[0];
    ui->yourselfPrice->setText(QString("%1 euros").arg(clientPrice[0]));
    deskPrice = 0;
    for(int i = 0; i < max_clientN; i++){
        deskPrice += clientPrice[i];
    }
    ui->yourDeskPrice->setText(QString("%1 euros").arg(deskPrice));

    QObject::connect(ui->payButton, SIGNAL(clicked(bool)), this, SLOT(payAction()));
}

AdditionWindow::~AdditionWindow()
{
    delete ui;
}

void AdditionWindow::payModeChanged(int sender){
    if(sender == 0){
        goDutch = true;
    }else{
        goDutch = false;
    }
}

void AdditionWindow::eval(){
    //
}

void AdditionWindow::payAction(){
    QMessageBox messageBox;
    messageBox.setWindowTitle("Paiement");
    if(goDutch) messageBox.setText(QString("Vous devez payer %1 euros.").arg(dutchPrice));
    else messageBox.setText(QString("Vous devez payer %1 euros.").arg(deskPrice));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::Yes);
    int chosenButton = messageBox.exec();
    if (chosenButton == QMessageBox::Yes){
        QApplication::quit();
    }
}
