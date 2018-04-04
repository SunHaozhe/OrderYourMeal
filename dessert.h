#ifndef DESSERT_H
#define DESSERT_H
#include "cuisine.h"

class Dessert : public Cuisine
{
public:
    Dessert();
    Dessert(unsigned int sn, std::string m, float n, std::string i);
};

#endif // DESSERT_H
