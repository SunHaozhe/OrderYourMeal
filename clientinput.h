#ifndef CLIENTINPUT_H
#define CLIENTINPUT_H


#include <QWidget>
//#include <string>
#include <QString>
#include <vector>
#include <QLineEdit>
#include <QComboBox>
namespace Ui {
class ClientInput;
}

class ClientInput : public QWidget
{
    Q_OBJECT

public:
    static ClientInput& Instance(){
        static ClientInput instance;
        return instance;
    }

    ~ClientInput();
//    int clientNum();
    QString getClient(int idx){
        if(idx<4 && !names[idx]->text().isEmpty()) return prefixs[idx]->currentText()+names[idx]->text();
        else return "";
    }
private:
    ClientInput(QWidget *parent = 0);
    ClientInput(const ClientInput&);
    ClientInput& operator=(const ClientInput&);
    Ui::ClientInput *ui;
    std::vector<QLineEdit*> names;
    std::vector<QComboBox*> prefixs;
};

#endif // CLIENTINPUT_H
