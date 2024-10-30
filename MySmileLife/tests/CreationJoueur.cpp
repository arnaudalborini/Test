#include "MSLTests.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

using MySmileLife::Tests::MSLTests;

void MSLTests::CreationJoueur(CardGame::GameInterface * gI){
    BasicBot* bb1 = new BasicBot();
    BasicBot* bb2 = new BasicBot();
    bb1->login(gI);
    bb2->login(gI);
}