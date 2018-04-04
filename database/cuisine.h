#ifndef CUISINE_H
#define CUISINE_H
#include <string>

class Cuisine
{
public:
    Cuisine();
    Cuisine(unsigned int sn, std::string m, float n, std::string i); //初始化菜名 价格 图片
    std::string showName();
    float showPrice();
    void showImage();
    unsigned int showType();
    unsigned int showSerialnumber();


protected:
    unsigned int serial_number; //菜的编号（内部管理？）
    std::string name;  //菜名
    float price;    //菜的价格
    std::string image; //每道菜对应的图片（不是很确定是不是用一个string来调用图片）
    unsigned int type; //菜属于哪个种类 1.entree 2.plat 3.boisson 4.dessert 5.soupe 6.halal 7.vegetarien
    unsigned int number = 0; //这道菜被点了几份
    float sel;
    float sucre;
    float piment;
};

#endif // CUISINE_H
