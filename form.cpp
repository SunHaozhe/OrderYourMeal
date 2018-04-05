#include "form.h"
#include "ui_form.h"

//#include <QString>
//#include <QDebug>
//#include <QMainWindow>
//#include <QMessageBox>



Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}

Form::~Form()
{
    delete ui;
}

void Form::afficheDetail(plat *selectedPlat){

    ui->pj_name->setText(QString::fromStdString(selectedPlat->getNom()));
    ui->pj_prix->setText(QString::number(selectedPlat->getPrix()));
    ui->pj_calorie->setText(QString::number(selectedPlat->getCalorie()));
    ui->pj_note->setText(QString::number(selectedPlat->getAvis()));
    std::string s;
    vector<std::string> v=selectedPlat->getIngredient();
    s = accumulate(v.begin(), v.end(), s);
    ui->pj_description->setText(QString::fromStdString(s));

    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->pj_picture->setPixmap(image2);
    this ->open();
}
