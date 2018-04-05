#ifndef BOISSON_H
#define BOISSON_H


#include "plat.h"

using namespace std;

class boisson : public plat
{
public:
    boisson();
    boisson(string _nom, int _avis=0, int _prix=0, const QString _imagePath="");

    float getAlcool_degre() const;
    void setAlcool_degre(float value);

    vector<int> getTaille() const;
    void setTaille(vector<int> value);


    int getCalorie() const;
    void setCalorie(int value);

    vector<string> getIngredient() const;
    void setIngredient(const vector<string> &value);

    bool isAlcool();

    void printAttrib();
private:
    float alcool_degre;
    vector<int> taille; // 25cl, 50cl etc...
};

#endif // BOISSON_H
