#include "boisson.h"

boisson::boisson(){}


boisson::boisson(string _nom, int _avis, int _prix, const QString _imagePath):
    plat(_nom, {}, _avis, 0,_prix, _imagePath){}

float boisson::getAlcool_degre() const
{
    return alcool_degre;
}

void boisson::setAlcool_degre(float value)
{
    if (value >= 0)
        alcool_degre = value;
    else
        ERROR_BAD_VALUE(alcool_degre, value);
}

vector<int> boisson::getTaille() const
{
    return taille;
}

void boisson::setTaille(vector<int> value)
{
    taille = value;
}

bool boisson::isAlcool()
{
    return (alcool_degre > 0);
}


// Surcharge des fonctions de traitement des attributs non utilisés pour renvoyer une erreur

int boisson::getCalorie() const
{
    ERROR_NO_ATTRIB(calorie, boisson);
    return -1;
}

void boisson::setCalorie(int value)
{
    UNUSED(value);
    ERROR_NO_ATTRIB(calorie, boisson);
}

vector<string> boisson::getIngredient() const
{
    ERROR_NO_ATTRIB(ingredient, boisson);
    return {};
}

void boisson::setIngredient(const vector<string> &value)
{
    UNUSED(value);
    ERROR_NO_ATTRIB(ingredient, boisson);
}

void boisson::printAttrib()
{
    cout << "Print " << nom << endl << "    Taille:" << endl;
    for(vector<int>::iterator it = taille.begin(); it != taille.end(); ++it){
        cout << "                    " << *it << endl;
    }
    cout << "    avis " << avis << endl
         << "    alcool " << alcool_degre << endl
         << "    prix " << prix << endl
         << "    description " << description <<endl;

}

