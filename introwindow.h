#ifndef INTROWINDOW_H
#define INTROWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "clientinput.h"
#include "like.h"
class IntroWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit IntroWindow(QWidget* like,QWidget* _dislike,QWidget *parent = 0);
//    ClientInput* getClient() {return &clients;}
signals:
    void FINISHED();

public slots:
    void onNextClicked();
    void onSkipClicked();
private:
    QString introQuestion[3];
    QLabel introText;
    int qIdx;// index of the introduction question
    QLabel introLabel; // to display the corresponding question
    QPushButton nextBtn;
    QPushButton skipBtn;
    QPushButton addClient;

    QWidget* answer;
//    ClientInput clients;
    QWidget* preference;
    QWidget* dislike;
    QVBoxLayout* vlayout;
//    preference = new Like();
};

#endif // INTROWINDOW_H
