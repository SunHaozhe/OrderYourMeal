#include "vegetarien.h"
using namespace std;

Vegetarien::Vegetarien()
{

}

Vegetarien::Vegetarien(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 7;
}
