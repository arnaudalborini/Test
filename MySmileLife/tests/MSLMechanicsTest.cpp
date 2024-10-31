#include "MSLMechanicsTest.hpp"
#include "CardGame.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "CartesAlgoMSL.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "MSLPlayer.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "StatutPlateau.hpp"
#include "MSLTests.hpp"

using namespace MySmileLife;
using namespace MySmileLife::Tests;

MSLMechanicsTest::MSLMechanicsTest(const TestScenario &testP) { test = testP; }

MSLMechanicsTest::~MSLMechanicsTest() {}

void MSLMechanicsTest::playTurn(int indPlayer) const {
  cout << "MSLMechanicsTest::playTurn: " << indPlayer << endl;
  const MSLPlayer *pp = dynamic_cast<const MSLPlayer *>(getPlayer(indPlayer));
  Hand *jHand = getJoueurHand(indPlayer);
  Plateau *platJ = getJoueurPlateau(indPlayer);
  Plateau *platGeneral = getMainPlateau();
  cout << "Plateau: " << platJ->getEPMax() << endl;
  printHand(jHand);
  printStatut(platJ);
  printPlateau(platJ);
  /*
  joueurPioche(indPlayer);
  int nbCarte = jHand->getNbCarte();
  int id = jHand->getIdCarte(nbCarte - 1);
  IdCarte idC = jHand->getCarte(0);
  const CarteMSL *crt = dynamic_cast<const CarteMSL *>(cGen->getCarteById(idC));
  cout << "MSLMechanicsTest::playTurn:peutEtreJouee: " << crt->getName()
       << endl;

  if ((peutEtreJouee(pp, idC)) && (jouerCarte(pp, idC))) {
    cout << "Carte Jouee: " << getCarteFromId(idC)->getName() << endl;
  } else {
    cout << "MSLMechanicsTest::playTurn:addCarteDefausse" << endl;
    addCarteDefausse(idC, indPlayer);
  }
  */

  // on s'arrete la avec un joli seg fault
  Plateau *sf = nullptr;
  sf->showIdN(0, 1);
}

std::vector<int> MSLMechanicsTest::getJoueurInitialStatuts() const {
  return vector<int>();
}

std::vector<int> MSLMechanicsTest::getInitialStatuts() const {
  return vector<int>();
}

std::vector<std::vector<IdCarte>>
MSLMechanicsTest::genMapCartePlateauInitial() const {
  return vector<vector<IdCarte>>();
}

void MSLMechanicsTest::initSpeficiGame() {
  int indPlayer = 0;
  Hand *jHand = getJoueurHand(indPlayer);
  for (auto elt : test.getInitHand()) {
    jHand->addCarte(elt);
  }
  Plateau *platJ = getJoueurPlateau(indPlayer);
  platJ->initStatut(test.getInitStatuts());
  platJ->initMap(test.getInitPlateau());
}

void MSLMechanicsTest::printHand(const Hand *h) const
{
  cout << "Hand: ";
  for(auto ind=0;ind<h->getNbCarte();ind++){
    cout << getCarteFromId(h->getIdCarte(ind))->getName() << ",";
  }
  cout << endl;
}

void MSLMechanicsTest::printStatut(const Plateau *platJ) const
{
  cout << "Statuts: " << endl;
  for(auto ind=0;ind< platJ->getStatutMax();ind++){
    if(platJ->getStatut(ind)>0){
      cout << MySmileLife::toStringDP(DetailPlateau(ind)) << " " << platJ->getStatut(ind) << endl;
    }
  }
}

void MSLMechanicsTest::printPlateau(const Plateau *platJ) const
{  
  for (auto ind = 0; ind < platJ->getEPMax(); ind++) {
    if( platJ->getNbCarte(ind)>0 ){
      cout << MySmileLife::toStringEP(EmplacementsPlateau(ind)) << " : " << endl;
      for (auto ind2 = 0; ind2 < platJ->getNbCarte(ind); ind2++) {
        cout << "    " << ind2 << " : " << getCarteFromId(platJ->showIdN(ind, ind2))->getName() << endl;
      }
    }
  }
}
