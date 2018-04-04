#include "dessert.h"
using namespace std;

Dessert::Dessert()
{

}

Dessert::Dessert(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 4;
}
