#include "like.h"
#include <numeric>




Like::Like(QWidget *parent) : QMainWindow(parent)
{


//mainwidget and mainlayout
QWidget* mainWidget = new QWidget;
mainLayout = new QVBoxLayout;

//welcome
 QHBoxLayout * Layout0 = new QHBoxLayout;
 QLabel * label0 = new QLabel("Vous pouvez choisir votre préférences ici");
 Layout0 ->addWidget(label0);

 //add ingredient preference
 QHBoxLayout * Layout1 = new QHBoxLayout;
 QLabel * label1 = new QLabel("Ingrédients :");
 ing1 = new QCheckBox("Boeuf", this);
 ing2 = new QCheckBox("Canard", this);
 ing3 = new QCheckBox("Viande", this);
 ing4 = new QCheckBox("Huitre", this);
 ing5 = new QCheckBox("Thon", this);

 Layout1 ->addWidget(label1);
 Layout1 ->addWidget(ing1);
 Layout1 ->addWidget(ing2);
 Layout1 ->addWidget(ing3);
 Layout1 ->addWidget(ing4);
 Layout1 ->addWidget(ing5);

 //add saveur preference
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

 //add stars preference
 QHBoxLayout * Layout3 = new QHBoxLayout;
 QLabel * label3 = new QLabel("Etoiles: ");
 QCheckBox *star1 = new QCheckBox("\t1", this);
 QCheckBox *star2 = new QCheckBox("\t2", this);
 QCheckBox *star3 = new QCheckBox("\t3", this);
 QCheckBox *star4 = new QCheckBox("\t4", this);
 QCheckBox *star5 = new QCheckBox("\t5", this);
 Layout3->addWidget(label3);
 Layout3->addWidget(star1);
 Layout3->addWidget(star2);
 Layout3->addWidget(star3);
 Layout3->addWidget(star4);
 Layout3->addWidget(star5);

//add quit button
 QHBoxLayout * Layout4 = new QHBoxLayout;
 QPushButton *quit = new QPushButton("Confirmer");
 QWidget * empty = new QWidget;

 empty->setFixedWidth(300);
 quit->setFixedHeight(20);
 quit->setFixedWidth(100);
 Layout4->addWidget(empty);
 Layout4->addWidget(quit);
 connect(quit, SIGNAL( clicked() ), this, SLOT( confirmSLOT()) );


 choicesWidget = new QWidget;
 QVBoxLayout* choicesLayout = new QVBoxLayout;
 choicesWidget->setLayout(choicesLayout);

 choicesLayout->addLayout(Layout0);
 choicesLayout->addLayout(Layout1);
 choicesLayout->addLayout(Layout2);
 choicesLayout->addLayout(Layout3);

 //add layouts to main layout
 mainLayout->addWidget(choicesWidget);
 mainLayout->addLayout(Layout4);

 mainWidget->setLayout(mainLayout);
 mainWidget->setFixedSize(450, 200);

 setCentralWidget(mainWidget);
}

void Like::confirmSLOT()
{
    ingrediantName.clear();
   if(ing1->isChecked())
   {
    ingrediantName.push_back("Boeuf");
    emit confirm();
   }
   if(ing2->isChecked())
   {
    ingrediantName.push_back("canard");
     emit confirm();
   }
   if(ing3->isChecked())
   {
    ingrediantName.push_back("viande");
     emit confirm();
   }
   if(ing4->isChecked())
   {
    ingrediantName.push_back("huitre");
     emit confirm();
   }

   if(ing5->isChecked())
   {
    ingrediantName.push_back("thon");
    emit confirm();
   }

    cout<<"label    "<<label<<endl;
    this->close();
}
