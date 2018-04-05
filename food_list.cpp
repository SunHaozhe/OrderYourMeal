#include "food_list.h"


// Liste des define à modifier lorsque l'on utilisera le XML
#define NOMBRE_DE_PLAT  7

// TODO: Utiliser le XML
void fill_list(){
    for(int i = 0; i < NOMBRE_DE_PLAT; i++){
        QImage * image = new QImage(QString(":/xml/image/index.jpeg"));   //gaile
    }
}

food_list::food_list(QListWidget * list){
    list = this->list;
    fill_list();
}
