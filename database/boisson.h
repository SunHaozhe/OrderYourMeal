#ifndef BOISSON_H
#define BOISSON_H
#include "cuisine.h"

class Boisson : public Cuisine
{
public:
    Boisson();
    Boisson(unsigned int sn, std::string m, float n, std::string i);
};

#endif // BOISSON_H
