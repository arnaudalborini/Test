#include "MSLTests.hpp"

#include "GameMaster.hpp"
#include "MSLMechanicsTest.hpp"
#include "TestScenario.hpp"
#include "CarteGenerateurStandard.hpp"

using namespace MySmileLifeTests;

const CarteGenerateurStandard cGen = CarteGenerateurStandard();

const IdCarte idMariage = cGen.getCarteByType(CarteType::carteMariage,CarteSousType::csAucun);
const IdCarte idLicorne = cGen.getCarteByType(CarteType::carteAnimal,CarteSousType::csLicorne);

IdCarte idMet(CarteSousType cst){return cGen.getCarteByType(CarteType::carteMetier,cst);}
IdCarte idEtu(int nbAnne){return cGen.getCarteByType(CarteType::carteEtude,csEtudeSimple)+nbAnne-1;}
IdCarte idMaison(int prix){
  switch(prix){
    case 6:
      return cGen.getCarteByType(CarteType::carteMaison,csMaison6);
    case 8:
      return cGen.getCarteByType(CarteType::carteMaison,csMaison8);
    default:
      return cGen.getCarteByType(CarteType::carteMaison,csMaison10);
  }
}

IdCarte idSal( int nb ){return cGen.getCarteByType(CarteType::carteMaison,csSalaire1)+nb-1;}
IdCarte idSpe(CarteSousType cst){return cGen.getCarteByType(CarteType::carteSpecial,cst);}
IdCarte idMal(CarteSousType cst){return cGen.getCarteByType(CarteType::carteMalus,cst);}
IdCarte idFlirt(int lieu){return cGen.getCarteByType(CarteType::carteFlirt,csAuParc)+lieu-1;}
IdCarte idAni( int nb ){return cGen.getCarteByType(CarteType::carteAnimal,csAucun)+nb-1;}
IdCarte idVoy( int nb ){return cGen.getCarteByType(CarteType::carteVoyage,csAucun,"Londres")+nb-1;}
IdCarte idEnfF( int nb ){return cGen.getCarteByType(CarteType::carteEnfant,csFille,"Leia")+nb-1;}
IdCarte idEnfG( int nb ){return cGen.getCarteByType(CarteType::carteEnfant,csGarcon,"Luke")+nb-1;}

TestScenario setTestScenario1() {
  TestScenario test;
  IdCarte id1 = idMariage;
  IdCarte id2 = idLicorne;
  IdCarte id3 = idMet(csMedium);
  IdCarte id4 = idSal(3);
  IdCarte id5 = idAni(4);
  test.setHand(vector<int>{id1, id2, id3, id4, id5});
  map<int, int> tmpS = {{MySmileLife::DetailPlateau::estMarie, 1},
                        {MySmileLife::DetailPlateau::Profession, -1},
                        {MySmileLife::DetailPlateau::estAdultere, 1},
                        {MySmileLife::DetailPlateau::NbAnneeEtude, 3},
                        {MySmileLife::DetailPlateau::LieuDernierFlirt, 61},
                        {MySmileLife::DetailPlateau::DerniereEtudeRedoublable, 30},
                        {MySmileLife::DetailPlateau::NombreFlirt, 8},
                        {MySmileLife::DetailPlateau::NbEnfant, 2}};
  test.setStatuts(tmpS);
  map<int, vector<CardGame::IdCarte>> tmpP = {
      {MySmileLife::EmplacementsPlateau::EMariage, {idMariage}},
      {MySmileLife::EmplacementsPlateau::ESpecial, {idSpe(csAdultere)}},
      {MySmileLife::EmplacementsPlateau::EEtudes,  {idEtu(2),idEtu(1)}},
      {MySmileLife::EmplacementsPlateau::EEnfant,  {idEnfF(1),idEnfG(1)}},
      {MySmileLife::EmplacementsPlateau::EFlirt,   {idFlirt(1),idFlirt(2),idFlirt(3),idFlirt(4),idFlirt(7),idFlirt(8),idFlirt(9),idFlirt(10)}}};
  test.setPlateau(tmpP);
  return test;
}

TestScenario setTestEtude() {
  TestScenario test;
  IdCarte id1 = idEtu(1);
  IdCarte id2 = idEtu(2);
  IdCarte id3 = id1;
  IdCarte id4 = id2;
  IdCarte id5 = id1;
  test.setHand(vector<int>{id1, id2, id3, id4, id5});
  map<int, int> tmpS = {{MySmileLife::DetailPlateau::Profession, -1},
                        {MySmileLife::DetailPlateau::NbAnneeEtude, 0},
                        {MySmileLife::DetailPlateau::DerniereEtudeRedoublable, 0}};
  test.setStatuts(tmpS);
  map<int, vector<CardGame::IdCarte>> tmpP = {};
  test.setPlateau(tmpP);
  return test;
}

void MSLTests::TestCarteUnitaire() {
  TestScenario test1 = setTestScenario1();
  cout << test1.getInitPlateau().size() << endl;
  TestScenario testEtu = setTestScenario1();
  cout << testEtu.getInitPlateau().size() << endl;


  shared_ptr<MySmileLifeTests::MSLMechanicsTest> gMe = make_shared<MySmileLifeTests::MSLMechanicsTest>( testEtu );
  CardGame::_p_GameMaster gm = make_shared<CardGame::GameMaster>(2, gMe );
  CardGame::_p_GameInterface gI = dynamic_pointer_cast<CardGame::GameInterface>(gm);
  CreationJoueur(gI);
  gm->startGame();
}