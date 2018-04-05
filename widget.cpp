#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, int tn) :
    QWidget(parent),
    ui(new Ui::Widget), tableNumber(tn)
{
    ui->setupUi(this);
    setWindowTitle("Order Your Meal");

    orderlist.clear();
    preflist.clear();
    selectedOrder=-1;

    menutype[0]=ui->verticalLayout_2;
    menutype[1]=ui->verticalLayout_3;
    menutype[2]=ui->verticalLayout_4;
    menutype[3]=ui->verticalLayout_5;
    menutype[4]=ui->verticalLayout_7;
    menutype[5]=ui->verticalLayout_8;
    menutype[6]=ui->verticalLayout_9;

    menuPage[0]=ui->scrollArea;
    menuPage[1]=ui->scrollArea_2;
    menuPage[2]=ui->scrollArea_3;
    menuPage[3]=ui->scrollArea_4;
    menuPage[4]=ui->scrollArea_5;
    menuPage[5]=ui->scrollArea_6;
    menuPage[6]=ui->scrollArea_7;

    for(int i=0;i<7;i++)
    {
        menuPage[i]->hide();
    }


    QFile file(":/xml/res/menu.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug()<<"error read xml";

    }
    reader=new QXmlStreamReader();
    reader->setDevice(&file);



    while(!reader->atEnd()){

        if(reader->isStartElement())
        {

            if(reader->name() == "menu")
            {
                qDebug()<<"read menu";
                readMenu();
            }
            else
            {
                Q_ASSERT(reader->isStartElement() && (reader->name() == "menu"));
                reader->raiseError(QObject::tr("Not a menu"));
            }
        }
        else
        {

            reader->readNext();


        }


    }
    if(reader->hasError())
    {
        qDebug()<<reader->errorString();

    }


    for(int i=0;i<7;i++)
    {
        QSpacerItem* si=new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);

        menutype[i]->addSpacerItem(si);
    }

    showMenu(0);
    current=ui->pushButton;

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(displayPlat(int)));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(updateprefsucre(int)));
    connect(ui->horizontalSlider_2,SIGNAL(sliderMoved(int)),this,SLOT(updateprefsel(int)));
    connect(ui->horizontalSlider_3,SIGNAL(sliderMoved(int)),this,SLOT(updateprefpim(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::readMenu()
{
    reader->readNext();
    while(!reader->atEnd())
    {
        if(reader->isEndElement())
        {
            reader->readNext();
            break;
        }

        if(reader->isStartElement())
        {

            if(reader->name() == "entry")
            {
                qDebug()<<"in menu find entry";
                readEntry();
            }
            else
            {
                reader->raiseError(QObject::tr("no entry")+reader->name().toString());
            }
        }
        else
        {
            reader->readNext();
        }
    }
}

void Widget::readEntry()
{

    int type=reader->attributes().value("type").toString().toInt();
    if(type>6 || type<0)
    {
        qDebug()<<"error type";
        reader->raiseError("error type");
    }
    int price=reader->attributes().value("price").toString().toInt();
    QString name=reader->attributes().value("name").toString();
    QString path=reader->readElementText();
    path=":/img/res/"+path;

    plat * p=new plat(this,name,path,price);
    menutype[type]->addWidget(p);
    connect(p,SIGNAL(ordered(plat*)),this,SLOT(addOrder(plat*)));
    qDebug()<<"read entry plat : "<<name<<" at "<<path<<" of type "<<type;


    reader->readNext();




}

void Widget::showMenu(int type)
{
    for(int i=0;i<7;i++)
    {
        if(i!=type)
            menuPage[i]->hide();

        else
            menuPage[i]->show();
    }


}

void Widget::addOrder(plat *p)
{
    ui->listWidget->addItem(p->name+"      "+QString::number(p->price)+QString::fromUtf8("€"));


    orderlist.append(p);
    preflist.append( new plat_preference(50,50,50) );

    total+=p->price;
    ui->lcdNumber->display(total);

    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
}

void Widget::displayPlat(int c)
{

    if(c<orderlist.size() && c<preflist.size() && c>=0)
    {
        ui->label->setPixmap(QPixmap(orderlist[c]->imgpath));
        ui->label_5->setText(orderlist[c]->name);
        ui->horizontalSlider->setValue(preflist[c]->sucre);
        ui->horizontalSlider_2->setValue(preflist[c]->sel);
        ui->horizontalSlider_3->setValue(preflist[c]->piment);
        selectedOrder=c;
        qDebug()<<"selecte changed to "<<selectedOrder << preflist[c]->sucre<<preflist[c]->sel<<preflist[c]->piment;
    }
}

void Widget::updateprefsucre(int v)
{
    if(selectedOrder<preflist.size() && selectedOrder>=0)
    {
        preflist[selectedOrder]->sucre=v;
        qDebug()<<"update sucre"<<selectedOrder<<preflist[selectedOrder]->sucre;
    }
}

void Widget::updateprefsel(int v)
{
    if(selectedOrder<preflist.size()&& selectedOrder>=0){
        preflist[selectedOrder]->sel=v;
        qDebug()<<"update sel"<<selectedOrder<<preflist[selectedOrder]->sel;
    }
}

void Widget::updateprefpim(int v)
{
    if(selectedOrder<preflist.size()&& selectedOrder>=0){
        preflist[selectedOrder]->piment=v;
        qDebug()<<"update pim"<<selectedOrder<<preflist[selectedOrder]->piment;
    }
}

void Widget::on_pushButton_clicked()
{
    current->setDefault(false);
    showMenu(0);
    ui->pushButton->setDefault(true);
    current=ui->pushButton;
}

void Widget::on_pushButton_2_clicked()
{
    current->setDefault(false);
    showMenu(1);
    ui->pushButton_2->setDefault(true);
    current=ui->pushButton_2;
}

void Widget::on_pushButton_3_clicked()
{
    current->setDefault(false);
    showMenu(2);
    ui->pushButton_3->setDefault(true);
    current=ui->pushButton_3;
}

void Widget::on_pushButton_4_clicked()
{
    current->setDefault(false);
    showMenu(3);
    ui->pushButton_4->setDefault(true);
    current=ui->pushButton_4;
}

void Widget::on_pushButton_5_clicked()
{
    current->setDefault(false);
    showMenu(4);
    ui->pushButton_5->setDefault(true);
    current=ui->pushButton_5;
}

void Widget::on_pushButton_6_clicked()
{
    current->setDefault(false);
    showMenu(5);
    ui->pushButton_6->setDefault(true);
    current=ui->pushButton_6;
}

void Widget::on_pushButton_7_clicked()
{
    current->setDefault(false);
    showMenu(6);
    ui->pushButton_7->setDefault(true);
    current=ui->pushButton_7;
}

void Widget::on_pushButton_9_clicked()
{
    if(orderlist.size()>0){
        if (QMessageBox::Yes == QMessageBox::question(this,
                                                      tr("Supprimer"),
                                                      tr("Est-ce que vous être sûr de supprimer le plat?"),
                                                      QMessageBox::Yes | QMessageBox::No,
                                                      QMessageBox::No)) {


            total-=orderlist[selectedOrder]->price;
            ui->lcdNumber->display(total);
            orderlist.remove(selectedOrder);
            preflist.remove(selectedOrder);
            ui->listWidget->takeItem(selectedOrder);


            if(orderlist.size()==0)
                selectedOrder=-1;
            else
            {
                selectedOrder=ui->listWidget->currentRow();
                //ui->listWidget->setCurrentRow(0);
            }


        }
    }
}

void Widget::on_pushButton_11_clicked()
{
    emit finaliser(tableNumber, total );
    this->close();
}
