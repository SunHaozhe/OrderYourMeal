#ifndef FOOD_LIST_H
#define FOOD_LIST_H


#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <QImage>

using namespace std;

class food_list
{
public:
    food_list(QListWidget * list);
private:
    QListWidget * list;
    vector<QListWidgetItem *> items;
};

#endif // FOOD_LIST_H
