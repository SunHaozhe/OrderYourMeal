#include "additionwindow.h"
#include "ui_additionwindow.h"

AdditionWindow::AdditionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdditionWindow)
{
    ui->setupUi(this);

    QButtonGroup * radioGroup = new QButtonGroup(this);
    QObject::connect(radioGroup, SIGNAL(buttonClicked(int)), this, SLOT(payModeChanged(int)));
    radioGroup->addButton(ui->payForYourselfRadio, 0);
    radioGroup->addButton(ui->payForYourDeskRadio, 1);
    ui->payForYourselfRadio->setChecked(true);

    //ui->deskClientList->insertItem(0, const QStringList &labels);
    //ui->clientPriceList->insertItem(0, const QStringList &labels);
    //ui->orderedList->insertItem(0, const QStringList QListWidgetItem &labels);

    ui->yourselfPrice->setText(QString("2"));
    ui->yourDeskPrice->setText(QString("13"));

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

void AdditionWindow::payAction(){
    QMessageBox messageBox;
    if(goDutch) messageBox.setText(QString("You should pay %1, are you sure to pay ?").arg(dutchPrice));
    else messageBox.setText(QString("You should pay %1, are you sure to pay ?").arg(deskPrice));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    //messageBox.setDefaultButton(QMessageBox::No);
    int chosenButton = messageBox.exec();
    if (chosenButton == QMessageBox::Yes){
        QApplication::quit();
    }
}
