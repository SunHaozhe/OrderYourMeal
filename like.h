#ifndef LIKE_H
#define LIKE_H


#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <iostream>
#include <QDebug>
#include "plat.h"
#include "platintro.h"
using namespace std;
class Like : public QMainWindow
{
    Q_OBJECT
public:
    explicit Like(QWidget *parent = 0);
    QCheckBox *ing1;
    QCheckBox *ing2;
    QCheckBox *ing3;
    QCheckBox *ing4;
    QCheckBox *ing5;

    QVBoxLayout *platLayout;
    int label;
    vector<string> ingrediantName;
    vector<platIntro*> list;
    vector<platIntro*> deletedlist;

    QWidget* getWidget() { return choicesWidget;}
    QWidget* restoreWidget() {mainLayout->insertWidget(0,choicesWidget); choicesWidget->show();}
signals:
    void confirm();
public slots:
    void confirmSLOT();
private:
    QWidget* choicesWidget;
    QVBoxLayout * mainLayout;

};

#endif // LIKE_H
