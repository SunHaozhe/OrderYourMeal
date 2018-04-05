#include "menu.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QDebug>


//two functions to assist the xml parsing
//createPlat and createPlatDuJour
//using std::stoi;
void Menu::createPlat(QXmlStreamReader& rxml, plat * p, string type){
    while(!rxml.atEnd()){
        rxml.readNext();
        if(rxml.isEndElement() && rxml.name()==QString::fromStdString(type)) break;
        if(rxml.isEndDocument()) continue;
        if(rxml.name()=="nom"){
            p->setNom(rxml.readElementText().toStdString());
        }
        else if(rxml.name()=="ingredient"){
            //split the ingredients into a vector
            vector<string> ingres;
            stringstream ss(rxml.readElementText().toStdString());
            string tok;
            while(std::getline(ss,tok,',')) ingres.push_back(tok);
            p->setIngredient(ingres);
        }
        else if(rxml.name()=="description"){
            p->setDescription(rxml.readElementText().toStdString());
        }
        else if(rxml.name()=="prix"){
            p->setPrix(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="calorie"){
            p->setCalorie(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="etoile"){
            p->setAvis(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="image"){
            p->setImage(QString::fromStdString(rxml.readElementText().toStdString()));
        }
    }
//    p->printAttrib();
}

void Menu::createPlatDuJour(QXmlStreamReader& rxml){
    while(!rxml.atEnd()){
        rxml.readNext();
        if(rxml.isEndElement()&&rxml.name()=="plat_du_jour") break;
        if(rxml.isStartElement()){
            if(rxml.name()=="prix")
                prixPlatDuJour=rxml.readElementText().toInt();
            else if(rxml.name()=="entree_")
                platDuJour["entree"]=entrees[rxml.readElementText().toStdString()];
            else if(rxml.name()=="plat_")
                platDuJour["plat"]=plats[rxml.readElementText().toStdString()];
            else if(rxml.name()=="dessert_")
                platDuJour["dessert"]=desserts[rxml.readElementText().toStdString()];
            else if(rxml.name()=="vin_")
                platDuJour["vin"]=boissons[rxml.readElementText().toStdString()];
        }
    }
}

void Menu::createBoisson(QXmlStreamReader& rxml, boisson * p, string type){
    while(!rxml.atEnd()){
        rxml.readNext();
        if(rxml.isEndElement() && rxml.name()==QString::fromStdString(type)) break;
        if(rxml.isEndDocument()) continue;
        if(rxml.name()=="nom"){
            p->setNom(rxml.readElementText().toStdString());
        }
        else if(rxml.name()=="description"){
            p->setDescription(rxml.readElementText().toStdString());
        }
        else if(rxml.name()=="alcool"){
            p->setAlcool_degre(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="prix"){
            p->setPrix(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="taille"){
            //split the taille into a vector
            vector<int> tailles;
            stringstream ss(rxml.readElementText().toStdString());
            string tok;
            while(std::getline(ss,tok,',')) tailles.push_back(atoi(tok.c_str()));
            p->setTaille(tailles);
        }
        else if(rxml.name()=="etoile"){
            p->setAvis(rxml.readElementText().toInt());
        }
        else if(rxml.name()=="image"){
            p->setImage(QString::fromStdString(rxml.readElementText().toStdString()));
        }
    }
//    p->printAttrib();

}

Menu::Menu()
{
//    std::cout << "In the constructer of the menu" << std::endl;
    QString qpath = ":/xml/menu";
    QFile file(qpath);

    if(!file.open(QFile::ReadOnly|QFile::Text)){
        std::cerr << "Error: Cannot read file " << qPrintable(qpath)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
    }

    QXmlStreamReader rxml(&file);

    while(!rxml.atEnd()){

        rxml.readNext();
        if(rxml.isStartElement()){
            if(rxml.name()=="menu") continue;
            if(rxml.name()=="plat_du_jour") createPlatDuJour(rxml);
            else
            {
                string type=rxml.name().toString().toStdString();
                if(type == "entree" || type == "plat" || type == "dessert"){
                    plat * p(new plat());
                    createPlat(rxml,p,type);
                    if(type=="entree")entrees[p->getNom()]=p;
                    else if(type=="plat")plats[p->getNom()]=p;
                    else if(type=="dessert")desserts[p->getNom()]=p;
                }
                else if(type == "boisson"){
                    boisson * b(new boisson());
                    createBoisson(rxml, b, type);
                    boissons[b->getNom()]=b;
                }
            }
        }

        if (rxml.hasError())
        {
            qDebug() << "Error:";
            qDebug()<< rxml.errorString();
            break;
        }
    }
//    std::cout << "Instance constructed successfully" << std::endl;
}

//Menu::~Menu(){
//    std::cout << "Deconstructer" << std::endl;
//}
