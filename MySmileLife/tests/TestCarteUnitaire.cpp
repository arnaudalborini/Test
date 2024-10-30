#include "MSLTests.hpp"

#include "MSLMechanics.hpp"
#include "GameMaster.hpp"

using namespace::MySmileLife;
using namespace::MySmileLife::Tests;

void MSLTests::TestCarteUnitaire(){
    MSLMechanics gMe        = MSLMechanics();
    CardGame::GameMaster gm = CardGame::GameMaster(2,&gMe);
    CardGame::GameInterface* gI = dynamic_cast<CardGame::GameInterface*>(&gm);
    CreationJoueur(gI);
}