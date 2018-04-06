#ifndef PLAT_H
#define PLAT_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
class plat : public QFrame
{
    Q_OBJECT
public:
    explicit plat(QWidget *parent , QString n, QString p, int pr,QString i);

    QLabel *img;
    QPushButton *button;
    QLabel *label;

    QString name;
    QString imgpath;
    int price;
    QString ingred;

    const static int minh=220;



signals:
    void ordered(plat* );
public slots:
    void orderedslot();
};

#endif // PLAT_H
