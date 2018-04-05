#ifndef PANIERWINDOW_H
#define PANIERWINDOW_H


#include <QDialog>
#include "panier.h"
#include "platintro.h"
#include <QComboBox>
#include <vector>
#include <QButtonGroup>
#include "clientinput.h"
#include "clientedit.h"
namespace Ui {
class PanierWindow;
}

class PanierWindow : public QDialog, public panier
{
    Q_OBJECT

public:
//    explicit PanierWindow(QWidget *parent = 0);
    PanierWindow(QWidget *parent=0,vector<plat*> _listPlat={}, int _numClient=0, int _somme=0, int _numTable=0);
    ~PanierWindow();
    void setClient() {
        cltInput = new clientEdit();
        std::cout << "set client" << std::endl;
        connect(cltInput,SIGNAL(cancel(bool)),this,SLOT(updateClient(bool)));
        clist.push_back("---");
        for(int i=0; i<4; i++){
            QString name = ClientInput::Instance().getClient(i);
            if(!name.isEmpty()){
                clist.push_back(name);
            }
        }
    }
    int getNumPlat() const {return numPlat;}

    void setStatic();

    void clear(){

        for(int i=0; i<plats.size(); i++){
            delete plats[i];
        }
        for(int i=0; i<prix.size(); i++){
            delete prix[i];
        }
        for(int i=0; i<clients.size(); i++){
            delete clients[i];
        }
        QList<QAbstractButton*> bs = btnGroup.buttons();
        for(int i=0; i<bs.size(); i++){
            btnGroup.removeButton(bs[i]);
            delete bs[i];
        }
                plats.clear();
                prix.clear();
                clients.clear();
        listPlat.clear();
        numPlat=0;
        somme = 0;
    }

signals:
    void panierUpdated();
    void orderComfirmed();

public slots:
    void addPlat(plat*);
    void deletePlat(int idx);
    void addClient();
    void updateClient(bool);
    void confirmOrder();
    void payBill();
private:
    Ui::PanierWindow *ui;
//    std::vector<platIntro*> plats;
    std::vector<QLabel*> plats;
    std::vector<QLabel*> prix;
    std::vector<QComboBox*> clients;
    QButtonGroup btnGroup;
    clientEdit* cltInput;
    QStringList clist;
    int numPlat;
    bool isStatic;
};

#endif // PANIERWINDOW_H
