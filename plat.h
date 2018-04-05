#ifndef PLAT_H
#define PLAT_H
#include <string>
#include <vector>
#include <QPixmap>
#include <QString>
#include <iostream>


// Efface le warning de "unused variable"
#define UNUSED(var)         (void) var

// Affiche l'erreur quand on appelle un getter ou setter d'un attribut qui n'est pas utilisé dans la classe courante
#define ERROR_NO_ATTRIB(attribut, classe)       cout << "ERROR_NO_ATTRIB: No attribute " << #attribut <<         \
                                                " in class " << #classe << endl

// Affiche l'erreur si on met une mauvaise valeur dans un attribut
#define ERROR_BAD_VALUE(attribut, value)        cout << "ERROR_BAD_VALUE: " << #attribut << " cannot be " << value << endl

using namespace std;

class plat
{
public:
    plat(string _nom, vector<string> _ingredient={}, int _avis=-1, int _calorie=-1, int _prix=-1, const QString imagePath=":myImages/image/testpic2.png");
    plat();
     ~plat();

    string getNom() const;
    void setNom(const string &value);

    vector<string> getIngredient() const;
    void setIngredient(const vector<string> &value);

    int getAvis() const;
    void setAvis(int value);

    int getCalorie() const;
    void setCalorie(int value);

    int getPrix() const;
    void setPrix(int value);

    QPixmap * getImage() const;
    void setImage(const QString value);

    string getDescription() const;
    void setDescription(const string &value);

    void printAttrib();
protected:
    string nom;
    vector<string> ingredient;
    int avis;
    int calorie;
    int prix;
    QPixmap * image;
    string description;
};

#endif // PLAT_H
