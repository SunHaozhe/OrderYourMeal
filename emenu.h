#ifndef EMENU_H
#define EMENU_H


#include "mainwindow.h"
#include "introwindow.h"
#include "emenu.h"
#include "like.h"
#include "dislike.h"
#include "homepage.h"
#include "panierwindow.h"

#include "clientedit.h"
class eMenu : public QObject
{
    Q_OBJECT
public:
    eMenu();
    void start();
private slots:
    void introFinished();
    void openMenu();
    void updateOrder();
private:
    // three mode enum : introduction, order, afterorder
    enum MODE { INTRO, ORDER, AFTERORDER } mode;
    MainWindow* mw;
    IntroWindow* intro;
    Like* like;
    Dislike* dislike;
    HomePage* hp;
    PanierWindow* order;
    bool firstTime;

};

#endif // EMENU_H
