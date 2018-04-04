#include "plat.h"
using namespace std;

Plat::Plat()
{

}

Plat::Plat(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 2;
}
