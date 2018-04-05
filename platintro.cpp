#include "platintro.h"



platIntro::platIntro(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(200,120);
    setMaximumSize(500,100);

}
platIntro::platIntro(plat *plat){

    setMinimumSize(200,120);
    setMaximumSize(500,100);
    _plat = plat;
    layoutGlobal = new QHBoxLayout();
    setLayout(layoutGlobal);
    layoutImage= new QHBoxLayout();
    layoutDescrip= new QVBoxLayout();
    layoutGlobal->addLayout(layoutImage);
    layoutGlobal->addLayout(layoutDescrip);
    layoutPlatName= new QHBoxLayout();
    layoutPlatEtoile= new QHBoxLayout();
    layoutShowDetail= new QHBoxLayout();
    layoutDescrip->addLayout(layoutPlatName);
    layoutDescrip->addLayout(layoutPlatEtoile);
    layoutDescrip->addLayout(layoutShowDetail);

    showImage = new QLabel();
    QPixmap *image = plat->getImage();
    QPixmap image2 = image->scaled(120,80,Qt::KeepAspectRatio);
    showImage->setPixmap(image2);

    showDetail = new QPushButton("Detail");
    add = new QPushButton("Add");
    layoutImage->addWidget(showImage);
    layoutShowDetail->addWidget(showDetail);
    layoutShowDetail->addWidget(add);

    showName = new QLabel();
    showName->setText(QString::fromStdString(plat->getNom()));

    showPrice= new QLabel();
    showPrice->setText("Prix:"+QString::number(plat->getPrix())+"€");

    showAvis = new QLabel();
    showAvis->setText("Étoile:"+QString::number(plat->getAvis())+"/5");

    layoutPlatEtoile->addWidget(showAvis);
    layoutPlatName->addWidget(showName);
    layoutPlatName->addWidget(showPrice);

    connect(add,SIGNAL(clicked( )), this, SLOT(on_Add_clicked()));
    connect(showDetail,SIGNAL(clicked( )), this, SLOT(on_Detail_clicked()));
}

void platIntro::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);// comportement standard(afficher le fond, etc.)
    QPainter painter(this); // crée un Painter pour ce Canvas painter

    painter.fillRect(QRectF(QPointF(0,0),QSize(this->width(),this->height())),QColor(255, 255, 255));
}

void platIntro::on_Add_clicked()
{

    emit addToPanier(_plat);
}

void platIntro::on_Detail_clicked()
{
    emit afficherDetails(_plat);
}

