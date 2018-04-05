#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <numeric>


MainWindow::MainWindow(Like* _like, Dislike* _dislike, QWidget *parent) :
    preference(_like),ne_mange_pas(_dislike),QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scrollAreaWidget_list_entree->setLayout(&entreeLayout);
    ui->scrollAreaWidget_list_plat->setLayout(&platLayout);
    ui->scrollAreaWidget_list_boisson->setLayout(&boissonLayout);
    ui->scrollAreaWidget_list_dessert->setLayout(&dessertLayout);
    ui->scrollAreaWidget_list_platdujour->setLayout(&platdujourLayout);
    QFile qss("C:/Users/lenovo/Desktop/order/IGR203-master/menu_restaurant/skin.qss");
    //QFile qss（“C:\Users\lenovo\Desktop\order\IGR203-master\menu_restaurant\skin.qss”）;

    qss.open(QFile::ReadOnly);
    if(qss.isOpen())
       {
          qApp->setStyleSheet(qss.readAll());
          qss.close();
       }

    panier = new PanierWindow();
    detail = new Form();

    for(map<string,plat*>::iterator it=Menu::Instance().platDuJour.begin(); it!=Menu::Instance().platDuJour.end();it++){
        platIntro* intro = new platIntro(it->second);
        platdujourList.push_back(intro);
        platdujourLayout.addWidget(intro);
        connect(intro,SIGNAL(addToPanier(plat*)),this, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(afficherDetails(plat*)),detail, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(addToPanier(plat*)),panier,SLOT(addPlat(plat*)));
    }

    for(map<string,plat*>::iterator it=Menu::Instance().entrees.begin(); it!=Menu::Instance().entrees.end();it++){
        if(!it->second) continue;
        platIntro* intro = new platIntro(it->second);
        entreeList.push_back(intro);
        entreeLayout.addWidget(intro);
        connect(intro,SIGNAL(addToPanier(plat*)),this, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(afficherDetails(plat*)),detail, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(addToPanier(plat*)),panier,SLOT(addPlat(plat*)));
    }
       //Menu::Instance().entrees.begin();
       // afficheDetail(plat1);
        for(map<string,plat*>::iterator it=Menu::Instance().plats.begin(); it!=Menu::Instance().plats.end();it++){
        if(!it->second) continue;
        platIntro* intro = new platIntro(it->second);
        platList.push_back(intro);
        platLayout.addWidget(intro);
        connect(intro,SIGNAL(addToPanier(plat*)),this, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(afficherDetails(plat*)),detail, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(addToPanier(plat*)),panier,SLOT(addPlat(plat*)));
    }
    for(map<string,plat*>::iterator it=Menu::Instance().desserts.begin(); it!=Menu::Instance().desserts.end();it++){
        if(!it->second) continue;
        platIntro* intro = new platIntro(it->second);
        dessertList.push_back(intro);
        dessertLayout.addWidget(intro);

        connect(intro,SIGNAL(addToPanier(plat*)),this, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(afficherDetails(plat*)),detail, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(addToPanier(plat*)),panier,SLOT(addPlat(plat*)));
    }
    for(map<string,plat*>::iterator it=Menu::Instance().boissons.begin(); it!=Menu::Instance().boissons.end();it++){
        if(!it->second) continue;
        platIntro* intro = new platIntro(it->second);
        boissonList.push_back(intro);
        boissonLayout.addWidget(intro);
        connect(intro,SIGNAL(addToPanier(plat*)),this, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(afficherDetails(plat*)),detail, SLOT(afficheDetail(plat*)));
        connect(intro,SIGNAL(addToPanier(plat*)),panier,SLOT(addPlat(plat*)));
        //connect(intro,SIGNAL(panierUpdated()),this,SLOT(resume()));
    }
    afficheDetail(Menu::Instance().entrees["Huitre"],0);
    afficheDetail(Menu::Instance().entrees["Huitre"],1);
    afficheDetail(Menu::Instance().plats["Confit de canard et haricots"],2);
    afficheDetail(Menu::Instance().desserts["creme brulee"],3);
    afficheDetail(Menu::Instance().boissons["vin rouge"],4);


    connect(preference, SIGNAL(confirm()),this,SLOT(updateLike()));
    connect(ne_mange_pas, SIGNAL(confirm()),this,SLOT(updatedisLike()));
    connect(ui->panierBtn, SIGNAL(clicked(bool)),this,SLOT(openPanier()));
    connect(panier,SIGNAL(panierUpdated()),this,SLOT(updatePanier()));
    connect(panier,SIGNAL(orderComfirmed()),this,SLOT(submitOrder()));









}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::afficheDetail(plat *selectedPlat, int index_window){
    /*

    std::cout << index_window << std::endl;
    if(index_window==-1) index_window=ui->tabWidget->currentIndex();
    switch(index_window)
    {
    case 0:
    {
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
    }
    case 1:
    {
    ui->e_name->setText(QString::fromStdString(selectedPlat->getNom()));
    ui->e_prix->setText(QString::number(selectedPlat->getPrix()));
    ui->e_calorie->setText(QString::number(selectedPlat->getCalorie()));
    ui->e_note->setText(QString::number(selectedPlat->getAvis()));
    std::string s;
   // vector<std::string> v=selectedPlat->getDescription();
   // s = accumulate(v.begin(), v.end(), s);
    s=selectedPlat->getDescription();
    ui->e_description->setText(QString::fromStdString(s));

    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->e_picture->setPixmap(image2);
    }
    case 2:
    {
    if(ui->tab_3->isActiveWindow())
    ui->p_name->setText(QString::fromStdString(selectedPlat->getNom()));
    ui->p_prix->setText(QString::number(selectedPlat->getPrix()));
    ui->p_calorie->setText(QString::number(selectedPlat->getCalorie()));
    ui->p_note->setText(QString::number(selectedPlat->getAvis()));
    std::string s;
    //vector<std::string> v=selectedPlat->getIngredient();
    //s = accumulate(v.begin(), v.end(), s);
     s=selectedPlat->getDescription();
    ui->p_description->setText(QString::fromStdString(s));

    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->p_picture->setPixmap(image2);
    }
    case 3:
    {
    // if(ui->tab_4->isActiveWindow())
    ui->d_name->setText(QString::fromStdString(selectedPlat->getNom()));
    ui->d_prix->setText(QString::number(selectedPlat->getPrix()));
    ui->d_calorie->setText(QString::number(selectedPlat->getCalorie()));
    ui->d_note->setText(QString::number(selectedPlat->getAvis()));
    std::string s;
    //vector<std::string> v=selectedPlat->getIngredient();
    //s = accumulate(v.begin(), v.end(), s);
    s=selectedPlat->getDescription();
    ui->d_description->setText(QString::fromStdString(s));

    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->d_picture->setPixmap(image2);
    }
    case 4:
    {
    // if(ui->tab_5->isActiveWindow())
    ui->b_name->setText(QString::fromStdString(selectedPlat->getNom()));
    ui->b_prix->setText(QString::number(selectedPlat->getPrix()));
    ui->b_calorie->setText(QString::number(selectedPlat->getCalorie()));
    ui->b_note->setText(QString::number(selectedPlat->getAvis()));
    std::string s;
    //vector<std::string> v=selectedPlat->getIngredient();
    //s = accumulate(v.begin(), v.end(), s);
     s=selectedPlat->getDescription();
    ui->b_description->setText(QString::fromStdString(s));

    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->b_picture->setPixmap(image2);
    }

    }
    */
    std::cout << index_window << std::endl;
    if(index_window==-1) index_window=ui->tabWidget->currentIndex();
    switch(index_window)
    {
    case 0:
    {
    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->pj_picture->setPixmap(image2);
    }
    case 1:
    {
    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->e_picture->setPixmap(image2);
    }
    case 2:
    {
    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->p_picture->setPixmap(image2);
    }
    case 3:
    {
    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->d_picture->setPixmap(image2);
    }
    case 4:
    {
    QPixmap *image = selectedPlat->getImage();
    QPixmap image2 = image->scaled(200,200,Qt::KeepAspectRatio);
    ui->b_picture->setPixmap(image2);
    }

    }
}


void MainWindow::like_label()
{
    switch (preference->label) {
    case 0 :
        updateLike(&platdujourLayout,platdujourList);
        break;
    case 1:
         updateLike(&entreeLayout,entreeList);
         break;
    case 2:
        updateLike(&platLayout,platList);
        break;
    case 3:
        updateLike(&dessertLayout,dessertList);
        break;
    case 4:
        updateLike(&boissonLayout,boissonList);
        break;
    default:
        break;
    }
}

void MainWindow::dislike_label()
{
    switch (ne_mange_pas->label) {
    case 0 :
        updatedisLike(&platdujourLayout,platdujourList);
        break;
    case 1:
         updatedisLike(&entreeLayout,entreeList);
         break;
    case 2:
        updatedisLike(&platLayout,platList);
        break;
    case 3:
        updatedisLike(&dessertLayout,dessertList);
        break;
    case 4:
        updatedisLike(&boissonLayout,boissonList);
        break;
    default:
        break;
    }
}

void MainWindow::on_boisson_addlike_clicked()
{
     preference->label=4;
     preference->show();
}



void MainWindow::on_boisson_adddislike_clicked()
{
     ne_mange_pas->label=4;
     ne_mange_pas ->show();
}


void MainWindow::on_dessert_addlike_clicked()
{
     preference->label=3;
     preference->show();
}


void MainWindow::on_dessert_adddislike_clicked()
{
     ne_mange_pas->label=3;
    ne_mange_pas ->show();
}


void MainWindow::on_plat_addlike_clicked()
{
     preference->label=2;
//     preference->list = this->getplatList();
//     preference->platLayout =this->getentreeLayout();
//     platLayout.removeWidget(platList[0]);
//     platLayout.addWidget(platList[0]);
     preference->show();
}


void MainWindow::on_plat_adddislike_clicked()
{
     ne_mange_pas->label=2;
    ne_mange_pas ->show();
}



void MainWindow::on_entree_addlike_clicked()
{
     preference->label=1;
     preference->show();
}


void MainWindow::on_entree_adddislike_clicked()
{
     ne_mange_pas->label=1;
     ne_mange_pas ->show();
}

void MainWindow::on_platdujour_addlike_clicked()
{
    preference->label=0;
    preference->show();
}


void MainWindow::on_platdujour_adddislike_clicked()
{
     ne_mange_pas->label=0;
    ne_mange_pas ->show();
}

void MainWindow::updateLike(){
//    updateLike(&platdujourLayout,platdujourList);
    updateLike(&entreeLayout,entreeList);
    updateLike(&platLayout,platList);
//    updateLike(&dessertLayout,dessertList);
//    updateLike(&boissonLayout,boissonList);
}

void MainWindow::updatedisLike(){
    updatedisLike(&platdujourLayout,platdujourList);
    updatedisLike(&entreeLayout,entreeList);
    updatedisLike(&platLayout,platList);
    updatedisLike(&dessertLayout,dessertList);
    updatedisLike(&boissonLayout,boissonList);
}

void MainWindow::updateLike( QVBoxLayout* layout_,vector<platIntro*> &list_)
{
//        cout<<"label    "<<preference->label<<endl;
    if(layout_ == &entreeLayout){
        cout << "entree" << endl;
    }
    else if(layout_ == &platLayout){
        cout << "plat" << endl;
    }
        int len =0;
        vector<platIntro*> deletedlist;
        vector<platIntro*>::iterator iter;
        for (iter=list_.begin();iter!=list_.end();iter++)
            {
              len =  (**iter)._plat->getIngredient().size();
              for (int i=0;i<len;i++)
              {
                  vector<string>::iterator iter1;
                  for(iter1=preference->ingrediantName.begin();iter1!=preference->ingrediantName.end();iter1++)
                  {
                  if ((**iter)._plat->getIngredient()[i]==(*iter1))
                  {

                  deletedlist.push_back((*iter));
                  layout_->removeWidget(*iter);
                  break;
                  }
                  }
              }
            }

        for (iter=deletedlist.begin();iter!=deletedlist.end();iter++)
        {
//             cout<<(**iter)._plat->getNom()<<endl;
             layout_->insertWidget(0,(*iter));

        }
//   preference->ingrediantName.clear();

}
 void MainWindow:: updatedisLike(QVBoxLayout* layout_,vector<platIntro*> &list_)
 {
     int len =0;
     vector<platIntro*> deletedlist;
     deletedlist.clear();
     vector<platIntro*>::iterator iter;
     for (iter=list_.begin();iter!=list_.end();iter++)
         {
           len =  (**iter)._plat->getIngredient().size();
           for (int i=0;i<len;i++)
           {
               vector<string>::iterator iter1;
               for(iter1=ne_mange_pas->ingrediantName.begin();iter1!=ne_mange_pas->ingrediantName.end();iter1++)
               {
               if ((**iter)._plat->getIngredient()[i]==(*iter1))
               {
//               cout<<(**iter)._plat->getIngredient()[i]<<endl;
               (**iter).hide();
               break;
               }
               }
           }
         }
//     ne_mange_pas->ingrediantName.clear();

 }

void  MainWindow::on_tabWidget_clicked(){

   // void updatePanier(int index_window);
}


/*
 void MainWindow::updatePanier(int index_window){
    ui->nomPlatLbl->setText(QString::number(panier->getNumPlat()));
    ui->sommeLbl->setText(QString::number(panier->getSomme()));




    //me
    if(index_window==-1) index_window=ui->tabWidget->currentIndex();
    switch(index_window)
    {
    case 0:
    {
        _listPlat = panier->getListPlat();
        for(int i=0; i<_listPlat.size(); i++){
            QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
            plats.push_back(tmp);
            ui->gridLayout_re->addWidget(tmp,i,0);
            QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
            prix.push_back(tmpPrix);
            ui->gridLayout_re->addWidget(tmpPrix,i,1);
            QComboBox* tmpClt = new QComboBox;
            tmpClt->addItems(clist);
            clients.push_back(tmpClt);
            ui->gridLayout_re->addWidget(tmpClt,i,2);
            QPushButton* deleteBtn = new QPushButton("Delete");
            ui->gridLayout_re->addWidget(deleteBtn,i,3);
            btnGroup.addButton(deleteBtn,i);
           // somme+=_listPlat[i]->getPrix();
        }
    }
    case 1:
    {
        _listPlat = panier->getListPlat();
        for(int i=0; i<_listPlat.size(); i++){
            QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
            plats.push_back(tmp);
            ui->gridLayout_re_2->addWidget(tmp,i,0);
            QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
            prix.push_back(tmpPrix);
            ui->gridLayout_re_2->addWidget(tmpPrix,i,1);
            QComboBox* tmpClt = new QComboBox;
            tmpClt->addItems(clist);
            clients.push_back(tmpClt);
            ui->gridLayout_re_2->addWidget(tmpClt,i,2);
            QPushButton* deleteBtn = new QPushButton("Delete");
            ui->gridLayout_re_2->addWidget(deleteBtn,i,3);
            btnGroup.addButton(deleteBtn,i);
        }
    }
    case 2:
    {
        _listPlat = panier->getListPlat();
        for(int i=0; i<_listPlat.size(); i++){
            QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
            plats.push_back(tmp);
            ui->gridLayout_re_3->addWidget(tmp,i,0);
            QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
            prix.push_back(tmpPrix);
            ui->gridLayout_re_3->addWidget(tmpPrix,i,1);
            QComboBox* tmpClt = new QComboBox;
            tmpClt->addItems(clist);
            clients.push_back(tmpClt);
            ui->gridLayout_re_3->addWidget(tmpClt,i,2);
            QPushButton* deleteBtn = new QPushButton("Delete");
            ui->gridLayout_re_3->addWidget(deleteBtn,i,3);
            btnGroup.addButton(deleteBtn,i);
        }
    }
        case 3:
        {
            _listPlat = panier->getListPlat();
            for(int i=0; i<_listPlat.size(); i++){
                QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
                plats.push_back(tmp);
                ui->gridLayout_re_4->addWidget(tmp,i,0);
                QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
                prix.push_back(tmpPrix);
                ui->gridLayout_re_4->addWidget(tmpPrix,i,1);
                QComboBox* tmpClt = new QComboBox;
                tmpClt->addItems(clist);
                clients.push_back(tmpClt);
                ui->gridLayout_re_4->addWidget(tmpClt,i,2);
                QPushButton* deleteBtn = new QPushButton("Delete");
                ui->gridLayout_re_4->addWidget(deleteBtn,i,3);
                btnGroup.addButton(deleteBtn,i);
            }
        }
        case 4:
        {
            _listPlat = panier->getListPlat();
            for(int i=0; i<_listPlat.size(); i++){
                QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
                plats.push_back(tmp);
                ui->gridLayout_re_5->addWidget(tmp,i,0);
                QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
                prix.push_back(tmpPrix);
                ui->gridLayout_re_5->addWidget(tmpPrix,i,1);
                QComboBox* tmpClt = new QComboBox;
                tmpClt->addItems(clist);
                clients.push_back(tmpClt);
                ui->gridLayout_re_5->addWidget(tmpClt,i,2);
                QPushButton* deleteBtn = new QPushButton("Delete");
                ui->gridLayout_re_5->addWidget(deleteBtn,i,3);
                btnGroup.addButton(deleteBtn,i);
            }
        }
    }
 }
*/
void MainWindow::openPanier(){
    panier->open();
}


void MainWindow::updatePanier(int index_window){
   ui->nomPlatLbl->setText(QString::number(panier->getNumPlat()));
   ui->sommeLbl->setText(QString::number(panier->getSomme()));


       _listPlat = panier->getListPlat();
       for(int i=0; i<_listPlat.size(); i++){
           QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
           plats.push_back(tmp);
           ui->gridLayout_re->addWidget(tmp,i,0);
           QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
           prix.push_back(tmpPrix);
           ui->gridLayout_re->addWidget(tmpPrix,i,1);
           QComboBox* tmpClt = new QComboBox;
           tmpClt->addItems(clist);
           clients.push_back(tmpClt);
           ui->gridLayout_re->addWidget(tmpClt,i,2);
           QPushButton* deleteBtn = new QPushButton("Delete");
           ui->gridLayout_re->addWidget(deleteBtn,i,3);
           btnGroup.addButton(deleteBtn,i);
          // somme+=_listPlat[i]->getPrix();
       }


       for(int i=0; i<_listPlat.size(); i++){
           QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
           plats.push_back(tmp);
           ui->gridLayout_re_2->addWidget(tmp,i,0);
           QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
           prix.push_back(tmpPrix);
           ui->gridLayout_re_2->addWidget(tmpPrix,i,1);
           QComboBox* tmpClt = new QComboBox;
           tmpClt->addItems(clist);
           clients.push_back(tmpClt);
           ui->gridLayout_re_2->addWidget(tmpClt,i,2);
           QPushButton* deleteBtn = new QPushButton("Delete");
           ui->gridLayout_re_2->addWidget(deleteBtn,i,3);
           btnGroup.addButton(deleteBtn,i);
       }



       for(int i=0; i<_listPlat.size(); i++){
           QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
           plats.push_back(tmp);
           ui->gridLayout_re_3->addWidget(tmp,i,0);
           QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
           prix.push_back(tmpPrix);
           ui->gridLayout_re_3->addWidget(tmpPrix,i,1);
           QComboBox* tmpClt = new QComboBox;
           tmpClt->addItems(clist);
           clients.push_back(tmpClt);
           ui->gridLayout_re_3->addWidget(tmpClt,i,2);
           QPushButton* deleteBtn = new QPushButton("Delete");
           ui->gridLayout_re_3->addWidget(deleteBtn,i,3);
           btnGroup.addButton(deleteBtn,i);
       }


           for(int i=0; i<_listPlat.size(); i++){
               QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
               plats.push_back(tmp);
               ui->gridLayout_re_4->addWidget(tmp,i,0);
               QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
               prix.push_back(tmpPrix);
               ui->gridLayout_re_4->addWidget(tmpPrix,i,1);
               QComboBox* tmpClt = new QComboBox;
               tmpClt->addItems(clist);
               clients.push_back(tmpClt);
               ui->gridLayout_re_4->addWidget(tmpClt,i,2);
               QPushButton* deleteBtn = new QPushButton("Delete");
               ui->gridLayout_re_4->addWidget(deleteBtn,i,3);
               btnGroup.addButton(deleteBtn,i);
           }



           for(int i=0; i<_listPlat.size(); i++){
               QLabel* tmp = new QLabel(QString::fromStdString(_listPlat[i]->getNom()));
               plats.push_back(tmp);
               ui->gridLayout_re_5->addWidget(tmp,i,0);
               QLabel* tmpPrix = new QLabel(QString::number(_listPlat[i]->getPrix()));
               prix.push_back(tmpPrix);
               ui->gridLayout_re_5->addWidget(tmpPrix,i,1);
               QComboBox* tmpClt = new QComboBox;
               tmpClt->addItems(clist);
               clients.push_back(tmpClt);
               ui->gridLayout_re_5->addWidget(tmpClt,i,2);
               QPushButton* deleteBtn = new QPushButton("Delete");
               ui->gridLayout_re_5->addWidget(deleteBtn,i,3);
               btnGroup.addButton(deleteBtn,i);
           }


}
