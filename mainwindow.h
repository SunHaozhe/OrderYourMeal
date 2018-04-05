#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include "plat.h"
#include "platintro.h"
#include "like.h"
#include "dislike.h"
#include "panierwindow.h"
#include "panier.h"
#include <QFile>

#include "form.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Like* _like, Dislike* _dislike, QWidget *parent = 0);
    ~MainWindow();
//    void SetUpLayout();
    void updateLike(QVBoxLayout* layout_,vector<platIntro*> &list_);
    void updatedisLike(QVBoxLayout* layout_,vector<platIntro*> &list_);

    vector<platIntro*> entreeList;
    vector<platIntro*> platList;
    vector<platIntro*> dessertList;
    vector<platIntro*> boissonList;
    vector<platIntro*> platdujourList;

    QVBoxLayout entreeLayout;
    QVBoxLayout platLayout;
    QVBoxLayout dessertLayout;
    QVBoxLayout boissonLayout;
    QVBoxLayout platdujourLayout;

    PanierWindow* panier;


    //
    Form * detail;
    void setPreference(Like* _like) {preference = _like;}
    void setDislike(Dislike* _dislike) {ne_mange_pas = _dislike;}
    void setClient(){ panier->setClient();}

signals:
    void orderSubmitted();
public slots:
    void updateLike();
    void updatedisLike();
private slots:
    void submitOrder(){emit orderSubmitted();}

    void afficheDetail(plat*,int index_window=-1);
     void on_boisson_addlike_clicked();

     void on_boisson_adddislike_clicked();

     void on_dessert_addlike_clicked();

     void on_dessert_adddislike_clicked();

     void on_plat_addlike_clicked();

     void on_plat_adddislike_clicked();

     void on_entree_addlike_clicked();

     void on_entree_adddislike_clicked();

     void on_platdujour_addlike_clicked();

     void on_platdujour_adddislike_clicked();

     void like_label();
     void dislike_label();

     void openPanier();

     void updatePanier(int index_window=-1);


     //me
     void on_tabWidget_clicked();


   //me
     //void resume();

private:
    Ui::MainWindow *ui;
    Like *preference;
    Dislike *ne_mange_pas;

//me
    std::vector<QLabel*> plats;
    std::vector<QLabel*> prix;
    std::vector<QComboBox*> clients;
    QButtonGroup btnGroup;
    clientEdit* cltInput;
    QStringList clist;
    int numPlat;
    bool isStatic;

    std::vector<plat*>  _listPlat;



    void updateDisplayList();
};

#endif // MAINWINDOW_H
