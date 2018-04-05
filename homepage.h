#ifndef HOMEPAGE_H
#define HOMEPAGE_H


#include <QMainWindow>

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

signals:
    void menu();
    void order();
    void help();

public slots:
    void menuClicked() {emit menu();}
    void orderClicked() {emit order();}
    void helpClicked() {emit help();}
    void guideClicked();

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
