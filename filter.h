#ifndef FILTER_H
#define FILTER_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <iostream>
#include <QVector>
#include <QLayout>
#include <QLabel>


using namespace std;

namespace Ui {
class Filter;
}

class Filter : public QWidget
{
    Q_OBJECT

public:
    explicit Filter(QWidget *parent = 0);
    ~Filter();
    int label;
    QVector<QString> ingrediantName;
    QCheckBox *ing1;
    QCheckBox *ing2;
    QCheckBox *ing3;
    QCheckBox *ing4;
    QCheckBox *ing5;
    QCheckBox *ing6;
    QCheckBox *ing7;
    QCheckBox *ing8;


signals:
    void confirm();

public slots:

    void confirmSLOT();

private:
    QWidget* choicesWidget;
    QVBoxLayout* mainLayout;



private:
    Ui::Filter *ui;




};

#endif // FILTER_H
