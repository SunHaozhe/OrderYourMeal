#ifndef CLIENTEDIT_H
#define CLIENTEDIT_H


#include <QDialog>
#include "clientinput.h"
class clientEdit : public QDialog
{
    Q_OBJECT

public:
    explicit clientEdit(QWidget *parent = 0);
    ~clientEdit();

//    void setClient(ClientInput* _client) {delete client;client=_client;}
//    ClientInput* getClient() {return client;}

signals:
    void cancel(bool);

public slots:
    void cancelButtonClicked();
    void confirmButtonClicked();

private:
    ClientInput* client;
};

#endif // CLIENTEDIT_H
