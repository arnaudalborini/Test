#include "ConcreteMonitor.hpp"
#include "GameMechanics.hpp"
#include "InfosJoueur.hpp"
#include "PaquetCarte.hpp"

using CardGame::ConcreteMonitor;

ConcreteMonitor::ConcreteMonitor() {
  mPioche = make_shared<PaquetCarte>();
  mDefausse = make_shared<PaquetCarte>();
  mInfosJoueurs = vector<_p_InfosJoueur>();
  mPlayer = vector<_pc_Player>();
}

ConcreteMonitor::~ConcreteMonitor() {}

CardGame::_p_Plateau ConcreteMonitor::getPlateauGeneral() const { return mPlateau; }
CardGame::_p_Plateau ConcreteMonitor::getPlateauPlayer(int indPlayer) const {
  return getInfosJoueurs(indPlayer)->getPlateau();
}
CardGame::_p_Plateau ConcreteMonitor::getPlateauPlayer(_pc_Player pp) const {
  return getInfosJoueurs(pp)->getPlateau();
}
CardGame::_p_PaquetCarte ConcreteMonitor::getPioche() const { return mPioche; }
CardGame::_p_PaquetCarte ConcreteMonitor::getDefausse() const { return mDefausse; }
CardGame::_p_InfosJoueur ConcreteMonitor::getInfosJoueurs(int ind) const {
  return mInfosJoueurs[ind];
}
CardGame::_p_InfosJoueur ConcreteMonitor::getInfosJoueurs(_pc_Player pp) const {
  return getInfosJoueurs(getIndPlayer(pp));
}
CardGame::_pc_Player ConcreteMonitor::getPlayer(int ind) const { return mPlayer[ind]; }
int ConcreteMonitor::getIndPlayer(_pc_Player pp) const { return mapIdPlayer.at(pp); }

int ConcreteMonitor::getNbPlayer() const { return mNbJoueur; }

void ConcreteMonitor::defausser(IdCarte id, int indPlayer) const {
  mDefausse->addCarte(id, indPlayer);
}

void ConcreteMonitor::defausserDernier(int indPlayer, int EP) const {
  defausser(getInfosJoueurs(indPlayer)->getPlateau()->getLastByEP(EP), indPlayer);
}

void ConcreteMonitor::defausserTout(int indPlayer, int EP) const {
  _p_Plateau p = getInfosJoueurs(indPlayer)->getPlateau();
  int NbCrt = p->getNbCarteByEP(EP);
  for (int ind = 0; ind < NbCrt; ind++) {
    defausser(p->getLastByEP(EP), indPlayer);
  }
}

void ConcreteMonitor::incStatut(int indPlayer, int statut, int inc) const {
  getInfosJoueurs(indPlayer)->getPlateau()->incStatut(statut, inc);
}

void ConcreteMonitor::initiateElements(int nbJoueurs, _p_GameMechanics gm) {
  shared_ptr<ConcreteMonitor> tmp = shared_from_this();
  mPlateau = make_shared<Plateau>(tmp);
  mNbJoueur = nbJoueurs;
  mGameMechanics = gm;
  mPlayer = vector<_pc_Player>(nbJoueurs);
  mInfosJoueurs = vector<_p_InfosJoueur>(nbJoueurs);
  for (auto ind = 0; ind < nbJoueurs; ind++) {
    mInfosJoueurs[ind] = make_shared<InfosJoueur>(shared_from_this(),mGameMechanics->getJoueurInitialStatuts(), ind);
  }
  mGameMechanics->setMonitor(shared_from_this());
}

void ConcreteMonitor::addPlayer(_pc_Player pp, int index) {
  cout << "Monitor::addPlayer: " << pp << " " << index << endl;
  mPlayer[index] = pp;
  mapIdPlayer[pp] = index;
}
void ConcreteMonitor::removePlayer(int index) { mPlayer[index] = nullptr; }
void ConcreteMonitor::startGame() { mGameMechanics->startGame(); }
int ConcreteMonitor::getWinner() const { return mGameMechanics->getWinnerPlayer(); }

CardGame::_pc_Carte ConcreteMonitor::getCarte(IdCarte idC) const {
  return mGameMechanics->getCarte(idC);
}

void ConcreteMonitor::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterPlateau(indPlayer, idCrt);
}

void ConcreteMonitor::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterHand(indPlayer, idCrt);
}