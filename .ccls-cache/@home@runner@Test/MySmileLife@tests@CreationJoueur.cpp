#include "MySmileLife.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

void MySmileLife::CreationJoueur(CardGame::GameInterface * gI){
    BasicBot* bb1 = new BasicBot();
    BasicBot* bb2 = new BasicBot();
    bb1->login(gI);
    bb2->login(gI);
}