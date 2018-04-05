#include "halal.h"
using namespace std;

Halal::Halal()
{

}

Halal::Halal(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 6;
}
