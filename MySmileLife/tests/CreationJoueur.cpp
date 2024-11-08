#include "MSLTests.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

using namespace MySmileLifeTests;
using namespace MySmileLife;

void MSLTests::CreationJoueur(CardGame::_p_GameInterface  gI){
    _p_BasicBot bb1 = std::make_shared<BasicBot>();
    _p_BasicBot bb2 = std::make_shared<BasicBot>();
    bb1->login(gI);
    bb2->login(gI);
}