#include "MSLTests.hpp"

#include "GameMaster.hpp"
#include "MSLMechanicsTest.hpp"
#include "TestScenario.hpp"

using namespace MySmileLife;
using namespace MySmileLife::Tests;

TestScenario setTestScenario1() {
  TestScenario test;
  test.setHand(vector<int>{10, 41, 42, 31, 14});
  map<int, int> tmpS = {{MySmileLife::DetailPlateau::estMarie, 1},
                        {MySmileLife::DetailPlateau::estAdultere, 1},
                        {MySmileLife::DetailPlateau::NombreFlirt, 8}};
  test.setStatuts(tmpS);
  map<int, vector<CardGame::IdCarte>> tmpP = {
      {MySmileLife::EmplacementsPlateau::EMariage, {69}},
      {MySmileLife::EmplacementsPlateau::ESpecial, {46}},
      {MySmileLife::EmplacementsPlateau::EFlirt,
       {59, 60, 61, 62, 63, 59, 60, 61}}};
  test.setPlateau(tmpP);
  return test;
}

void MSLTests::TestCarteUnitaire() {
  TestScenario test1 = setTestScenario1();
  cout << test1.getInitPlateau().size() << endl;

  MySmileLife::Tests::MSLMechanicsTest gMe =
      MySmileLife::Tests::MSLMechanicsTest(test1);
  CardGame::GameMaster gm = CardGame::GameMaster(2, &gMe);
  CardGame::GameInterface *gI = dynamic_cast<CardGame::GameInterface *>(&gm);
  CreationJoueur(gI);
  gm.startGame();
}