#include "introwindow.h"
#include <QVBoxLayout>


IntroWindow::IntroWindow(QWidget *like, QWidget* _dislike,QWidget *parent) : preference(like), dislike(_dislike),QMainWindow(parent)
{
    setMinimumSize(600,300);
    qIdx = 0;
    introText.setParent(this);
    introText.setText("Welcom! \n \
        In the following steps, you are going to answer several question\n \
        in order to set the basic information about your preference\n \
        and give you a brief guide on how to use our eMenu.\n\
        You could also skip this section by clicking SKIP. All the settings could be modifed when ordering.\n\
        If you don't want to answer centain questions, just leave it blank and click NEXT.");

    introQuestion[0] = "By adding the name(nickname or even an id) of each client, \n\
        you could associate the order directly to a certain person.";

    introQuestion[1] = "Please choose your preferred ingredient/flavor:";

    introQuestion[2]= "Please choose the ingredients/flavors that you don't want to occur in your dishes:";

    introLabel.setParent(this);
    introLabel.setText(introQuestion[0]);

    skipBtn.setText("SKIP");
    nextBtn.setText("NEXT");

    connect(&skipBtn,SIGNAL(clicked(bool)), this, SLOT(onSkipClicked()));
    connect(&nextBtn,SIGNAL(clicked(bool)), this, SLOT(onNextClicked()));

    QWidget *wdgt =  new QWidget();
    vlayout = new QVBoxLayout();

    answer = &ClientInput::Instance();
//    answer = preference;
    wdgt->setLayout(vlayout);
    vlayout->addWidget(&introText);
    vlayout->addWidget(&introLabel);
    vlayout->addWidget(answer);
    vlayout->addWidget(&nextBtn);
    vlayout->addWidget(&skipBtn);
    this->setCentralWidget(wdgt);
}

void IntroWindow::onNextClicked(){
    if(qIdx==2) onSkipClicked();
    else{
        qIdx++;
        introLabel.setText(introQuestion[qIdx]);
        if(qIdx==1){
            // change the answer content to the preference choices
            answer->hide();
            answer = preference;
            vlayout->insertWidget(2,answer);
            std::cout << "preference" << std::endl;
        }
        else if(qIdx==2){
            // to the dislike choices
            answer->hide();
            answer = dislike;
            vlayout->insertWidget(2,answer);
        }
    }
}

void IntroWindow::onSkipClicked(){
    preference->show();
    dislike->show();
    emit FINISHED();
}
