#ifndef MENU_H
#define MENU_H


#include "plat.h"
#include "boisson.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <QXmlStreamReader>
#include <QWidget>
using std::map;
using std::vector;

class Menu
{
public:
    //Singleton mode
    static Menu& Instance(){
        static Menu instance;
        return instance;
    }
    void print(){
        std::cout << "Hello" << std::endl;
    }

    map<string,plat *> entrees;
    map<string,plat *> plats;
    map<string,plat *> desserts;
    map<string,plat *> boissons;
    map<string,plat *> platDuJour;
private:
    Menu();
//    ~Menu();
    Menu(const Menu&);
    Menu& operator=(const Menu&);

    void createPlat(QXmlStreamReader&, plat *, string type);
    void createPlatDuJour(QXmlStreamReader&);


    int prixPlatDuJour;
    void createBoisson(QXmlStreamReader &rxml, boisson *p, string type);
};

#endif // MENU_H
