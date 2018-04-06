#include "plat.h"

plat::plat(QWidget *parent, QString n, QString p, int pr, QString i) : QFrame(parent)
{
    name=n;
    imgpath=p;
    price=pr;
    ingred = i;

    img=new QLabel(this);
    img->setGeometry(70,5,250,150);
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Maximum);
    this->setMinimumHeight(minh);
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Plain);

    img->setPixmap(QPixmap(imgpath));
    img->setScaledContents(true);

    label=new QLabel(this);
    label->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Maximum);
    label->setGeometry(10,145,350,50);
    label->setText(name+"  "+QString::number(price)+QString::fromUtf8("€"));
    QFont f=label->font();
    f.setBold(false);
    f.setFamily("Cambria");
    f.setPointSize(12);
    label->setFont(f);
    label->setAlignment(Qt::AlignCenter);
    button=new QPushButton("Commander",this);
    f.setPointSize(9);
    button->setFont(f);
    button->setGeometry(140,185,93,28);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(orderedslot()) );

}

void plat::orderedslot()
{
    emit ordered(this);
}
