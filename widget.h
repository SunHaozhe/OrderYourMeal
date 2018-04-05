#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "plat.h"
#include <QXmlStreamReader>
#include <QDebug>
#include <QFile>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class plat_preference {
public:
    int sucre;
    int sel;
    int piment;

    plat_preference(int su=50, int se=50, int pi=50){
        sucre=su;
        sel=se;
        piment=pi;
    }

};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, int tn=321);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::Widget *ui;
    void readMenu();
    void readEntry();
    QVector<plat*> orderlist;
    QVector<plat_preference*> preflist;

    int tableNumber;
    int total=0;

    void showMenu(int type);
    QXmlStreamReader *reader;

    int selectedOrder;
    QPushButton* current;
    QVBoxLayout * menutype[7];
    QScrollArea * menuPage[7];

signals:
    void finaliser(int tn,int p);

public slots:
    void addOrder(plat*p);
    void displayPlat(int c);
    void updateprefsucre(int v);
    void updateprefsel(int v);
    void updateprefpim(int v);

};

#endif // WIDGET_H
