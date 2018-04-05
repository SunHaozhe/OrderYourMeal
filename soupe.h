#ifndef SOUPE_H
#define SOUPE_H
#include "cuisine.h"

class Soupe : public Cuisine
{
public:
    Soupe();
    Soupe(unsigned int sn, std::string m, float n, std::string i);
};

#endif // SOUPE_H
