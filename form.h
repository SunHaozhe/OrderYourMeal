#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDialog>
#include"plat.h"

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

signals:
    void finishcon();

private:
    Ui::Form *ui;
private slots:
    void afficheDetail(plat *selectedPlat);
};

#endif // FORM_H
