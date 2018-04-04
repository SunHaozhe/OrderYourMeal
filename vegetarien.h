#ifndef VEGETARIEN_H
#define VEGETARIEN_H
#include "cuisine.h"

class Vegetarien : public Cuisine
{
public:
    Vegetarien();
    Vegetarien(unsigned int sn, std::string m, float n, std::string i);
};

#endif // VEGETARIEN_H
