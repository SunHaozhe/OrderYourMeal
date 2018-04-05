#include "boisson.h"
using namespace std;

Boisson::Boisson()
{

}

Boisson::Boisson(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 3;
}
