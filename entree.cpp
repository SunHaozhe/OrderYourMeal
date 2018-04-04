#include "entree.h"
using namespace std;

Entree::Entree()
{

}

Entree::Entree(unsigned int sn, string m, float n, string i)
{
    this->serial_number = sn;
    this->name = m;
    this->price = n;
    this->image = i;
    this->type = 1;
}
