#include "plat.h"

plat::plat(QWidget *parent, QString n, QString p, int pr) : QFrame(parent)
{
    name=n;
    imgpath=p;
    price=pr;

    img=new QLabel(this);
    img->setGeometry(10,10,281,101);
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Maximum);
    this->setMinimumHeight(minh);
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Plain);

    img->setPixmap(QPixmap(imgpath));
    img->setScaledContents(true);

    label=new QLabel(this);
    label->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Maximum);
    label->setGeometry(10,101,279,50);
    label->setText(name+"  "+QString::number(price)+QString::fromUtf8("€"));
    QFont f=label->font();
    f.setBold(true);
    f.setPointSize(12);
    label->setFont(f);
    label->setAlignment(Qt::AlignCenter);
    button=new QPushButton("Commander",this);

    button->setGeometry(100,140,93,28);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(orderedslot()) );

}

void plat::orderedslot()
{
    emit ordered(this);
}
