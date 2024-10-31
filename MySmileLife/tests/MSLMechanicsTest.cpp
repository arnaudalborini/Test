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

using namespace MySmileLife;

MSLMechanicsTest::MSLMechanicsTest(
    const vector<int> &vH, const vector<int> &vS,
    const vector<vector<CardGame::IdCarte>> &mP) {
  vecInitHand = vH;
  vecInitStatuts = vS;
  vecInitPlateau = mP;
}

MSLMechanicsTest::~MSLMechanicsTest() {}

void MSLMechanicsTest::playTurn(int indPlayer) const {
  cout << "MSLMechanicsTest::playTurn: " << indPlayer << endl;
  const MSLPlayer *pp = dynamic_cast<const MSLPlayer *>(getPlayer(indPlayer));
  Hand *jHand = getJoueurHand(indPlayer);
  Plateau *platJ = getJoueurPlateau(indPlayer);
  Plateau *platGeneral = getMainPlateau();
  cout << "Statut" << endl;
  for (auto ind = 0; ind < platJ->getStatutMax(); ind++) {
    cout << "Statut " << ind << " : " << platJ->getStatut(ind) << endl;
  }
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
}

std::vector<int> MSLMechanicsTest::getJoueurInitialStatuts() const {
  return vector<int>(vecInitStatuts.begin(), vecInitStatuts.end());
}

std::vector<int> MSLMechanicsTest::getInitialStatuts() const {
  return vector<int>();
}

std::vector<std::vector<IdCarte>>
MSLMechanicsTest::genMapCartePlateauInitial() const {
  return vector<vector<IdCarte>>(vecInitPlateau.begin(), vecInitPlateau.end());
}

void MSLMechanicsTest::initSpeficiGame() {
  int indPlayer = 0;
  Hand *jHand = getJoueurHand(indPlayer);
  for (auto elt : vecInitHand) {
    jHand->addCarte(elt);
  }
}