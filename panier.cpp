#include "panier.h"


panier::~panier()
{
}

panier::panier(vector<plat*> _listPlat, int _numClient, int _somme, int _numTable){

    listPlat = _listPlat;
    numClient = _numClient;
    somme = _somme;
    numTable = _numTable;
}


vector<plat*> panier::getListPlat() const
{
    return listPlat;
}

void panier::setListPlat(const vector<plat*> &_listPlat)
{
    listPlat = _listPlat;
}

int panier::getNumClient() const
{
    return numClient;
}

void panier::setNumClient(int _numClient)
{
    numClient = _numClient;
}

int panier::getNumTable() const
{
    return numTable;
}

void panier::setNumTable(int _numTable)
{
    numTable = _numTable;
}

int panier::getSomme() const
{
    return somme;
}
void panier::setSomme(int _somme)
{
    somme=_somme;
}

