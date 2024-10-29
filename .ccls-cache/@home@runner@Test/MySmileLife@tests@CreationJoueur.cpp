#include "MySmileLife.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

void MySmileLife::CreationJoueur(CardGame::GameInterface * gI){
    BasicBot* bb1 = new BasicBot(gI);
    BasicBot* bb2 = new BasicBot(gI);
    bb1->login();
    bb2->login();
}