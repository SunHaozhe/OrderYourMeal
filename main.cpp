#include "mainwindow.h"
#include <QApplication>
#include "cuisine.h"
#include "entree.h"
#include "plat.h"
#include "boisson.h"
#include "dessert.h"
#include "soupe.h"
#include "halal.h"
#include "vegetarien.h"
#include "order.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Cuisine ** cuisines = new Cuisine * [100];
    unsigned int serial_number = 0;
    ////手动导入数据////
    cuisines[serial_number] = new Entree(serial_number, "Tomate Chevre", 2.2, "entree_tomate_chevre.jpg");
    serial_number++;
    cuisines[serial_number] = new Entree(serial_number, "Avocat avec Fruit de Mer", 2.6, "entree_avocat.jpg");
    serial_number++;
    cuisines[serial_number] = new Entree(serial_number, "Salade Legume", 1.8, "entree_salade_legume.jpg");
    serial_number++;
    cuisines[serial_number] = new Entree(serial_number, "Salade Pomme de Terre", 2.0, "entree_salade_pomme_de_terre.jpg");
    serial_number++;
    cuisines[serial_number] = new Entree(serial_number, "Pate Imperial", 2.0, "entree_pate_imperial.jpeg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Boeuf Bourguignon", 5.0, "plat_boeuf_bourguignon.jpg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Cuisse de Poulet Roti", 4.0, "plat_cuisses_de_poulet_roti.jpg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Filet du Poisson", 4.5, "plat_filet_du_poisson.jpg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Cotelette du Porc", 6.5, "plat_cotelette_du_porc.jpg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Tagliatelles au Bacon", 4.8, "plat_tagliatelles_au_bacon.jpg");
    serial_number++;
    cuisines[serial_number] = new Plat(serial_number, "Hambuger", 4.8, "plat_hambuger.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "Coca Cola", 1.0, "boisson_coca_cola.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "Sprite", 1.0, "boisson_sprite.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "Jus d'Orange", 1.5, "boisson_jus_dorange.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "The", 1.8, "boisson_the.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "Cafe", 2.0, "boisson_cafe.jpg");
    serial_number++;
    cuisines[serial_number] = new Boisson(serial_number, "Eau", 0.0, "boisson_eau.jpg");
    serial_number++;
    cuisines[serial_number] = new Dessert(serial_number, "Brownie", 3.0, "dessert_brownie.jpg");
    serial_number++;
    cuisines[serial_number] = new Dessert(serial_number, "Tarte au Potiron", 1.6, "desser_tarte_au_potiron.jpeg");
    serial_number++;
    cuisines[serial_number] = new Dessert(serial_number, "Creme Glacee", 2.0, "dessert_creme_glacee.jpg");
    serial_number++;
    cuisines[serial_number] = new Dessert(serial_number, "Mousse", 2.5, "dessert_mousse.jpg");
    serial_number++;
    cuisines[serial_number] = new Soupe(serial_number, "Soupe au Vermicelles", 2.4, "soupe_au_vermicelles.jpeg");
    serial_number++;
    cuisines[serial_number] = new Soupe(serial_number, "Soupe au Potiron", 2.2, "soupe_au_potiron.jpg");
    serial_number++;
    cuisines[serial_number] = new Soupe(serial_number, "Soupe au Cresson", 2.1, "soupe_cresson.jpeg");
    serial_number++;
    cuisines[serial_number] = new Halal(serial_number, "Saucisson du Boeuf", 4.5, "halal_saucisson_du_boeuf.jpg");
    serial_number++;
    cuisines[serial_number] = new Halal(serial_number, "Poulet avec Pomme de Terre", 4.0, "halal_poulet_avec_pomme_de_terre.jpg");
    serial_number++;
    cuisines[serial_number] = new Vegetarien(serial_number, "Nouilles Vegetarien", 3.5, "vegetarien_nouilles_vegetarien.jpg");
    serial_number++;
    cuisines[serial_number] = new Vegetarien(serial_number, "Sushi Vegetarien", 4.0, "vegetarian_sushi_vegetarian.jpg");
    serial_number++;
    //float i = cuisines[1]->showPrice();
    //cout<<i;

    Order ** orders = new Order * [serial_number];
    for(unsigned int i = 0; i < serial_number; i++)
    {
        orders[i] = new Order(i);
    }

    orders[0]->addCuisine();
    orders[5]->addCuisine();
    orders[11]->addCuisine();
    orders[17]->addCuisine();

    //cout<<orders[0]->cuisinePrice(cuisines);
    //orders[0]->addCuisine();
    //cout<<orders[0]->cuisinePrice(cuisines);
    //orders[0]->deleteCuisine();
    //cout<<orders[0]->cuisinePrice(cuisines);

    float total_price = 0.0;
    for(unsigned int i = 0; i < serial_number; i++)
    {
        total_price += orders[i]->cuisinePrice(cuisines);
    }
    cout<<total_price<<endl;
    orders[0]->setPeference(11.1, 12.1, 15.1);
    cout<<orders[0]->showSel()<<endl;
    orders[0]->addSel();
    cout<<orders[0]->showSel()<<endl;
    return a.exec();
}
