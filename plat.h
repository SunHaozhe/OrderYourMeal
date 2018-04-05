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
    explicit plat(QWidget *parent , QString n, QString p, int pr);

    QLabel *img;
    QPushButton *button;
    QLabel *label;

    QString name;
    QString imgpath;
    int price;



signals:
    void ordered(plat* );
public slots:
    void orderedslot();
};

#endif // PLAT_H
