#include "plat.h"



plat::plat(){
    setImage(":xml/image/testpic2.png");
}

plat::plat(string _nom, vector<string> _ingredient, int _avis, int _calorie, int _prix, const QString _imagePath){
    setNom(_nom);
    setIngredient(_ingredient);
    setAvis(_avis);
    setCalorie(_calorie);
    setPrix(_prix);
    setImage(_imagePath);
}

plat::~plat(){
    delete(image);
}

string plat::getNom() const
{
    return nom;
}

void plat::setNom(const string &_nom)
{
    nom = _nom;
}
vector<string> plat::getIngredient() const
{
    return ingredient;
}

void plat::setIngredient(const vector<string> &_ingredient)
{
    ingredient = _ingredient;
}
int plat::getAvis() const
{
    return avis;
}

void plat::setAvis(int _avis)
{
    if (_avis >= 0 && _avis <= 5)
        avis = _avis;
    else
        ERROR_BAD_VALUE(avis, _avis);
}
int plat::getCalorie() const
{
    return calorie;
}

void plat::setCalorie(int _calorie)
{
    if (_calorie > 0)
        calorie = _calorie;
    else
        ERROR_BAD_VALUE(calorie, _calorie);
}
int plat::getPrix() const
{
    return prix;
}

void plat::setPrix(int _prix)
{
    if (prix >= 0)
        prix = _prix;
    else
        ERROR_BAD_VALUE(prix, _prix);
}
QPixmap * plat::getImage() const
{
    return image;
}

void plat::setImage(const QString path)
{
    if (path.size() > 0)
        image = new QPixmap(path);
    else
        ERROR_BAD_VALUE(image, path.toStdString());
}

string plat::getDescription() const
{
    return description;
}

void plat::setDescription(const string &value)
{
    description = value;
}

void plat::printAttrib()
{
    cout << "Print " << nom << endl << "    Ingredients:" << endl;
    for(vector<string>::iterator it = ingredient.begin(); it != ingredient.end(); ++it){
        cout << "                    " << *it << endl;
    }
    cout << "    avis " << avis << endl
         << "    calorie " << calorie << endl
         << "    prix " << prix << endl
         << "    description " << description <<endl;

}



