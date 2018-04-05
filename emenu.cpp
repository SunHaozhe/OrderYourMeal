#include "emenu.h"


eMenu::eMenu()
{
    mode = INTRO;
    like = new Like();
    dislike = new Dislike();
    intro = new IntroWindow(like->getWidget(),dislike->getWidget());
    hp = new HomePage();
    connect(intro,SIGNAL(FINISHED()),this,SLOT(introFinished()));
    connect(hp,SIGNAL(menu()),this,SLOT(openMenu()));
    firstTime = true;

    order = new PanierWindow();
    order->setStatic();
    connect(hp,SIGNAL(order()),order,SLOT(open()));


}

void eMenu::start(){
//    intro->show();
    hp->show();
}

void eMenu::introFinished(){
    intro->close();
    like->restoreWidget();
    dislike->restoreWidget();
    mw = new MainWindow(like,dislike);

    connect(mw,SIGNAL(orderSubmitted()),this,SLOT(updateOrder()));
    mw->show();
    like->confirmSLOT();
    dislike->confirmSLOT();
    mw->updateLike();
    mw->updatedisLike();
    mw->setClient();
}

void eMenu::openMenu(){
    if(firstTime) {intro->show();firstTime=false;}
    else mw->show();
}

void eMenu::updateOrder(){
    std::vector<plat*> platlist = mw->panier->getListPlat();
    order->updateClient(true);
    for(int i=0; i<platlist.size(); i++){
        order->addPlat(platlist[i]);
    }
    mw->panier->clear();
    mw->hide();


}
