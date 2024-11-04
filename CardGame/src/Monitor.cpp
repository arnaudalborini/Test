#include "Monitor.hpp"
#include "GameMechanics.hpp"
#include "InfosJoueur.hpp"
#include "PaquetCarte.hpp"

using CardGame::Monitor;

Monitor::Monitor() {
  mPioche = make_shared<PaquetCarte>();
  mDefausse = make_shared<PaquetCarte>();
  mInfosJoueurs = vector<_p_InfosJoueur>();
  mPlayer = vector<_pc_Player>();
  mPlateau = make_shared<Plateau>(shared_from_this());
}

Monitor::~Monitor() {}

CardGame::_p_Plateau Monitor::getPlateau() const { return mPlateau; }
CardGame::_p_Plateau Monitor::getPlateauPlayer(int indPlayer) const {
  return getInfosJoueurs(indPlayer)->getPlateau();
}
CardGame::_p_Plateau Monitor::getPlateauPlayer(_pc_Player pp) const {
  return getInfosJoueurs(pp)->getPlateau();
}
CardGame::_p_PaquetCarte Monitor::getPioche() const { return mPioche; }
CardGame::_p_PaquetCarte Monitor::getDefausse() const { return mDefausse; }
CardGame::_p_InfosJoueur Monitor::getInfosJoueurs(int ind) const {
  return mInfosJoueurs[ind];
}
CardGame::_p_InfosJoueur Monitor::getInfosJoueurs(_pc_Player pp) const {
  return getInfosJoueurs(getIndPlayer(pp));
}
CardGame::_pc_Player Monitor::getPlayer(int ind) const { return mPlayer[ind]; }
int Monitor::getIndPlayer(_pc_Player pp) const { return mapIdPlayer.at(pp); }

int Monitor::getNbPlayer() const { return mNbJoueur; }

void Monitor::defausser(IdCarte id, int indPlayer) const {
  mDefausse->addCarte(id, indPlayer);
}

void Monitor::defausserDernier(int indPlayer, int EP) const {
  defausser(getInfosJoueurs(indPlayer)->getPlateau()->getLast(EP), indPlayer);
}

void Monitor::defausserTout(int indPlayer, int EP) const {
  _p_Plateau p = getInfosJoueurs(indPlayer)->getPlateau();
  int NbCrt = p->getNbCarte(EP);
  for (int ind = 0; ind < NbCrt; ind++) {
    defausser(p->getLast(EP), indPlayer);
  }
}

void Monitor::incStatut(int indPlayer, int statut, int inc) const {
  getInfosJoueurs(indPlayer)->getPlateau()->incStatut(statut, inc);
}

void Monitor::initiateElements(int nbJoueurs, _p_GameMechanics gm) {
  mNbJoueur = nbJoueurs;
  mGameMechanics = gm;
  mPlayer = vector<_pc_Player>(nbJoueurs);
  mInfosJoueurs = vector<_p_InfosJoueur>(nbJoueurs);
  for (auto ind = 0; ind < nbJoueurs; ind++) {
    mInfosJoueurs[ind] = make_shared<InfosJoueur>(shared_from_this(),mGameMechanics->getJoueurInitialStatuts(), ind);
  }
  mGameMechanics->setMonitor(shared_from_this());
}

void Monitor::addPlayer(_pc_Player pp, int index) {
  cout << "Monitor::addPlayer: " << pp << " " << index << endl;
  mPlayer[index] = pp;
  mapIdPlayer[pp] = index;
}
void Monitor::removePlayer(int index) { mPlayer[index] = nullptr; }
void Monitor::startGame() { mGameMechanics->startGame(); }
int Monitor::getWinner() const { return mGameMechanics->getWinnerPlayer(); }

CardGame::_pc_Carte Monitor::getCarte(IdCarte idC) const {
  return mGameMechanics->getCarte(idC);
}

void Monitor::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterPlateau(indPlayer, idCrt);
}

void Monitor::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterHand(indPlayer, idCrt);
}