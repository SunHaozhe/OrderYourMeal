#ifndef HALAL_H
#define HALAL_H
#include "cuisine.h"

class Halal : public Cuisine
{
public:
    Halal();
    Halal(unsigned int sn, std::string m, float n, std::string i);
};

#endif // HALAL_H
