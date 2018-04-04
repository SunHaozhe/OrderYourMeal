#include "order.h"
#include <iostream>
using namespace std;

Order::Order(unsigned i)
{
    this->cuisine_serial = i;
}

void Order::addCuisine()
{
    this->number++;
}

void Order::deleteCuisine()
{
    if(this->number > 0)
    {
        this->number--;
    }
}

float Order::cuisinePrice(Cuisine ** cuisines)
{
    return this->number * cuisines[this->cuisine_serial]->showPrice();
}

void Order::showCuisine(Cuisine ** cuisines)
{
    cout<<cuisines[this->cuisine_serial]->showName();
}

void Order::setPeference(float a, float b, float c)
{
    this->sel = a;
    this->sucre = b;
    this->piment = c;
}

void Order::addSel()
{
    if(this->sel < 100.0)
    {
        this->sel++;
    }
}

void Order::reduceSel()
{
    if(this->sel > 0.0)
    {
        this->sel--;
    }
}

void Order::addSucre()
{
    if(this->sucre < 100.0)
    {
        this->sucre++;
    }
}

void Order::reduceSucre()
{
    if(this->sucre > 0.0)
    {
        this->sucre--;
    }
}

void Order::addPiment()
{
    if(this->piment < 100.0)
    {
        this->piment++;
    }
}

void Order::reducePiment()
{
    if(this->piment > 0.0)
    {
        this->piment--;
    }
}

float Order::showSel()
{
    return this->sel;
}

float Order::showSucre()
{
    return this->sel;
}

float Order::showPiment()
{
    return this->sel;
}
