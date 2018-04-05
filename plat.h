#ifndef PLAT_H
#define PLAT_H
#include "cuisine.h"

class Plat : public Cuisine
{
public:
    Plat();
    Plat(unsigned int sn, std::string m, float n, std::string i);


private:

};

#endif // PLAT_H
