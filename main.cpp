#include "additionwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdditionWindow w;
    w.show();

    return a.exec();
}
