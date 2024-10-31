#include "MSLTests.hpp"

#include "GameMaster.hpp"
#include "MSLMechanicsTest.hpp"

using namespace MySmileLife;
using namespace MySmileLife::Tests;

void MSLTests::TestCarteUnitaire() {
  vector<int> vHand = {0, 1, 2, 3, 4};
  vector<int> vStatuts = vector<int>(MAXSTATUTPLATEAU);
  vector<vector<IdCarte>> vecInitPlateau =
      vector<vector<IdCarte>>(MAXEMPLACEMENTPLATEAU);

  for (auto ind = 0; ind < MAXSTATUTPLATEAU; ind++) {
    vStatuts[ind] = 1;
  }
  for (auto ind = 0; ind < MAXEMPLACEMENTPLATEAU; ind++) {
    vecInitPlateau.at(ind) = vector<IdCarte>();
  }
  MySmileLife::MSLMechanicsTest gMe =
      MySmileLife::MSLMechanicsTest(vHand, vStatuts, vecInitPlateau);
  CardGame::GameMaster gm = CardGame::GameMaster(2, &gMe);
  CardGame::GameInterface *gI = dynamic_cast<CardGame::GameInterface *>(&gm);
  CreationJoueur(gI);
  gm.startGame();
}