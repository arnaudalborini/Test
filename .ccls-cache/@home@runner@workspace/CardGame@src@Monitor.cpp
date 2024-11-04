#include "Monitor.hpp"
#include "GameMechanics.hpp"
#include "InfosJoueur.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "InfosJoueurMonitor.hpp"

using CardGame::InfosJoueur;
using CardGame::Monitor;
using CardGame::PaquetCarte;
using CardGame::Plateau;
using CardGame::Player;

Monitor::Monitor() {
  mPioche = new PaquetCarte();
  mDefausse = new PaquetCarte();
  mInfosJoueurs = vector<InfosJoueur *>();
  mPlayer = vector<PCPlayer >();
  mPlateau = new Plateau(this,-1);
}

Monitor::~Monitor() { /*
      delete mPioche;
      delete mDefausse;
      delete mPlateau;
      for(auto inf:mInfosJoueurs){
          delete inf;
      }*/
}

PPlateau Monitor::getPlateau() const { return mPlateau; }
PPlateau Monitor::getPlateauPlayer(int indPlayer) const {
  return getInfosJoueurs(indPlayer)->getPlateau();
}
PPlateau Monitor::getPlateauPlayer(PCPlayer pp) const {
  return getInfosJoueurs(pp)->getPlateau();
}
PPaquetCarte Monitor::getPioche() const { return mPioche; }
PPaquetCarte Monitor::getDefausse() const { return mDefausse; }
PInfosJoueur Monitor::getInfosJoueurs(int ind) const {
  return mInfosJoueurs[ind];
}
PInfosJoueur Monitor::getInfosJoueurs(PCPlayer pp) const {
  return getInfosJoueurs(getIndPlayer(pp));
}
PCPlayer Monitor::getPlayer(int ind) const { return mPlayer[ind]; }
int Monitor::getIndPlayer(PCPlayer pp) const { return mapIdPlayer.at(pp); }

int Monitor::getNbPlayer() const { return mNbJoueur; }

void Monitor::defausser(IdCarte id, int indPlayer) const {
  mDefausse->addCarte(id, indPlayer);
}

void Monitor::defausserDernier(int indPlayer, int EP) const {
  defausser(getInfosJoueurs(indPlayer)->getPlateau()->getLast(EP), indPlayer);
}

void Monitor::defausserTout(int indPlayer, int EP) const {
  PPlateau p = getInfosJoueurs(indPlayer)->getPlateau();
  int NbCrt = p->getNbCarte(EP);
  for (int ind = 0; ind < NbCrt; ind++) {
    defausser(p->getLast(EP), indPlayer);
  }
}

void Monitor::incStatut(int indPlayer, int statut, int inc) const {
  getInfosJoueurs(indPlayer)->getPlateau()->incStatut(statut, inc);
}

void Monitor::initiateElements(int nbJoueurs, PGameMechanics gm) {
  mNbJoueur = nbJoueurs;
  mGameMechanics = gm;
  mPlayer = vector<PCPlayer >(nbJoueurs);
  mInfosJoueurs = vector<PInfosJoueur >(nbJoueurs);
  for (auto ind = 0; ind < nbJoueurs; ind++) {
    mInfosJoueurs[ind] = make_shared<InfosJoueur>(this,mGameMechanics, ind);
  }
  mGameMechanics->setMonitor(make_shared<Monitor>(this));
}

void Monitor::addPlayer(PCPlayer pp, int index) {
  cout << "Monitor::addPlayer: " << pp << " " << index << endl;
  mPlayer[index] = pp;
  mapIdPlayer[pp] = index;
}
void Monitor::removePlayer(int index) { mPlayer[index] = nullptr; }
void Monitor::startGame() { mGameMechanics->startGame(); }
int Monitor::getWinner() const { return mGameMechanics->getWinnerPlayer(); }

CardGame::PCCarte Monitor::getCarte(IdCarte idC) const {
  return mGameMechanics->getCarte(idC);
}

void Monitor::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterPlateau(indPlayer, idCrt);
}

void Monitor::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterHand(indPlayer, idCrt);
}