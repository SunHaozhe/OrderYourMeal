#include "filter.h"
#include "ui_filter.h"

Filter::Filter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Filter)
{

    ui->setupUi(this);
    setWindowTitle("Filter");
    QWidget * mainwidget = new QWidget;
    mainLayout = new QVBoxLayout;
    QLabel * label0 = new QLabel("Vous pouvez choisir ce que vous ne mangez pas ici");
    QLabel * label1 = new QLabel("Ingrédients:");
    ing1 = new QCheckBox("Boeuf", this);
    ing2 = new QCheckBox("legume", this);
    ing3 = new QCheckBox("fruit de mer", this);
    ing4 = new QCheckBox("pomme de terre", this);
    ing5 = new QCheckBox("pate", this);
    ing6 = new QCheckBox("poisson", this);
    ing7 = new QCheckBox("porc", this);
    ing8 = new QCheckBox("poulet", this);

    QVBoxLayout * Layout1 = new QVBoxLayout;
    QHBoxLayout * Layout2 = new QHBoxLayout;

    QVBoxLayout * Layout15 = new QVBoxLayout;
    QVBoxLayout * Layout26 = new QVBoxLayout;
    QVBoxLayout * Layout37 = new QVBoxLayout;
    QVBoxLayout * Layout48 = new QVBoxLayout;

    Layout15 ->addWidget(ing1);
    Layout15 ->addWidget(ing5);
    Layout26 ->addWidget(ing2);
    Layout26 ->addWidget(ing6);
    Layout37 ->addWidget(ing3);
    Layout37 ->addWidget(ing7);
    Layout48 ->addWidget(ing4);
    Layout48 ->addWidget(ing8);

    Layout2 -> addLayout(Layout15);
    Layout2 -> addLayout(Layout26);
    Layout2 -> addLayout(Layout37);
    Layout2 -> addLayout(Layout48);

    Layout1 ->addWidget(label0);
    Layout1 ->addWidget(label1);
    Layout1 ->addLayout(Layout2);

/*
    QHBoxLayout * Layout2 = new QHBoxLayout;
    QLabel * label2 = new QLabel("Saveurs: ");
    QCheckBox *saveur1 = new QCheckBox("Salé", this);
    QCheckBox *saveur2 = new QCheckBox("Sucré", this);
    QCheckBox *saveur3 = new QCheckBox("Epicé", this);
    QCheckBox *saveur4 = new QCheckBox("Acide", this);
    Layout2->addWidget(label2);
    Layout2->addWidget(saveur1);
    Layout2->addWidget(saveur2);
    Layout2->addWidget(saveur3);
    Layout2->addWidget(saveur4);
*/
    //add quit button
    QHBoxLayout * Layout3 = new QHBoxLayout;
    QPushButton *quit = new QPushButton("Confirmer");
    QWidget * empty2 = new QWidget;
    empty2->setFixedWidth(300);
    quit->setFixedHeight(20);
    quit->setFixedWidth(100);
    connect(quit, SIGNAL( clicked() ), this, SLOT(confirmSLOT()));
    Layout3->addWidget(empty2);
    Layout3->addWidget(quit);

   choicesWidget = new QWidget;
   QVBoxLayout* choicesLayout = new QVBoxLayout;
   choicesLayout->addLayout(Layout1);
   choicesWidget->setLayout(choicesLayout);

   //add to mainlayout
    mainLayout->addWidget(choicesWidget);
    mainLayout->addLayout(Layout3);

   this->setLayout(mainLayout);
   mainwidget->setFixedSize(350, 200);


}

Filter::~Filter()
{
    delete ui;
}


void Filter::confirmSLOT()
{
    ingrediantName.clear();
    if(ing1->isChecked())
    {
     ingrediantName.push_back( "boeuf");


    }
    if(ing2->isChecked())
    {
     ingrediantName.push_back( "legume");


    }
    if(ing3->isChecked())
    {
     ingrediantName.push_back( "fruit_de_mer");


    }
    if(ing4->isChecked())
    {
     ingrediantName.push_back("pomme_de_terre");

    }

    if(ing5->isChecked())
    {
     ingrediantName.push_back("pate");


    }
    if(ing6->isChecked())
    {
     ingrediantName.push_back("poisson");


    }
    if(ing7->isChecked())
    {
     ingrediantName.push_back("porc");


    }
    if(ing8->isChecked())
    {
     ingrediantName.push_back("poulet");


    }
      emit confirm();
     cout<<"label    "<<label<<endl;
     this->hide();

}
