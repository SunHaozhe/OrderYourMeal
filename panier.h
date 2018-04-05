#ifndef PANIER_H
#define PANIER_H


#include <string>
#include <vector>
#include <QString>
#include "plat.h"

class panier
{
public:
    panier(vector<plat*> _listPlat={}, int _numClient=0, int _somme=0, int _numTable=0);
    ~panier();

    vector<plat*> getListPlat() const;
    void setListPlat(const vector<plat *> &value);

    int getNumTable() const;
    void setNumTable(int value);

    int getNumClient() const;
    void setNumClient(int value);

    int getSomme() const;
    void setSomme(int value);


protected:
    vector<plat*> listPlat;
    int numClient;
    int somme;
    int numTable;
};

#endif // PANIER_H
