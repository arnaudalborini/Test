#include "hello_test.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"

void sayHello(){
    CardGame::Joueur jj = CardGame::Joueur();
    CardGame::Carte *crt = new CardGame::Carte(&jj);
    delete crt;
}