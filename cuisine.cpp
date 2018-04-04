#include "cuisine.h"
using namespace std;

Cuisine::Cuisine()
{

}

Cuisine::Cuisine(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
}

float Cuisine::showPrice()
{
    return this->price;
}

string Cuisine::showName()
{
    return this->name;
}

unsigned int Cuisine::showType()
{
    return this->type;
}

unsigned int Cuisine::showSerialnumber()
{
    return this->serial_number;
}

void Cuisine::showImage()
{

}
