#ifndef TEST_HPP
#define TEST_HPP

#include "CardGame.hpp"

#include <iostream>
#include <string>

namespace MySmileLife{
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;

    enum CarteType:int{
        Aucun,
        Metier,
        Special,
        Malus,
        Etude,
        Salaire,
        Flirt,
        Mariage,
        Maison,
        Voyage,
        Animal
    };



    class BasicBot;
    class Carte;
    void CreationJoueur(CardGame::GameInterface* gI);
    void MySmileLifeTest();
}

#endif