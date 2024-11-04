#include "MSLTests.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

using MySmileLife::Tests::MSLTests;

void MSLTests::CreationJoueur(CardGame::PGameInterface  gI){
    PBasicBot bb1 = std::make_shared<BasicBot>();
    PBasicBot bb2 = std::make_shared<BasicBot>();
    bb1->login(gI);
    bb2->login(gI);
}