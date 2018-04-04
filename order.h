#ifndef ORDER_H
#define ORDER_H
#include "cuisine.h"

class Order
{
public:
    Order();
    Order(unsigned i);
    void addCuisine();        //加一份这个菜
    void deleteCuisine();     //减一份这个菜
    float cuisinePrice(Cuisine ** cuisines);     //单价乘数量
    void showCuisine(Cuisine ** cuisines);
    float showSel();  //输出个人喜好的值
    float showSucre();
    float showPiment();
    void setPeference(float a, float b, float c); //设定个人喜好的值
    void addSel();
    void reduceSel();
    void addSucre();
    void reduceSucre();
    void addPiment();
    void reducePiment();

private:
    unsigned cuisine_serial;  //这个菜的序列号
    unsigned int number = 0;  //这个菜点了几份
    float sel = 50.0;
    float sucre = 50.0;
    float piment = 0.0;
};

#endif // ORDER_H
