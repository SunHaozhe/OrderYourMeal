#include "soupe.h"
using namespace std;

Soupe::Soupe()
{

}

Soupe::Soupe(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 5;
}
