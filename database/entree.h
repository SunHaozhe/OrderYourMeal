#ifndef ENTREE_H
#define ENTREE_H
#include "cuisine.h"

class Entree : public Cuisine
{
public:
    Entree();
    Entree(unsigned int sn, std::string m, float n, std::string i);
};

#endif // ENTREE_H
