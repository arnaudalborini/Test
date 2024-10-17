#include "hello_test.hpp"
#include "Carte.hpp"
#include "InfosJoueur.hpp"

void sayHello(){
    CardGame::InfosJoueur jj = CardGame::InfosJoueur();
    CardGame::Carte *crt = new CardGame::Carte(&jj);
    delete crt;
}