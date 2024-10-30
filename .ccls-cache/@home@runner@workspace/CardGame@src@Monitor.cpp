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
  mPlayer = vector<const Player *>();
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

Plateau *Monitor::getPlateau() const { return mPlateau; }
Plateau *Monitor::getPlateauPlayer(int indPlayer) const {
  return getInfosJoueurs(indPlayer)->getPlateau();
}
Plateau *Monitor::getPlateauPlayer(const Player *pp) const {
  return getInfosJoueurs(pp)->getPlateau();
}
PaquetCarte *Monitor::getPioche() const { return mPioche; }
PaquetCarte *Monitor::getDefausse() const { return mDefausse; }
InfosJoueur *Monitor::getInfosJoueurs(int ind) const {
  return mInfosJoueurs[ind];
}
InfosJoueur *Monitor::getInfosJoueurs(const Player *pp) const {
  return getInfosJoueurs(getIndPlayer(pp));
}
const Player *Monitor::getPlayer(int ind) const { return mPlayer[ind]; }
int Monitor::getIndPlayer(const Player *pp) const { return mapIdPlayer.at(pp); }

int Monitor::getNbPlayer() const { return mNbJoueur; }

void Monitor::defausser(IdCarte id, int indPlayer) const {
  mDefausse->addCarte(id, indPlayer);
}

void Monitor::defausserDernier(int indPlayer, int EP) const {
  defausser(getInfosJoueurs(indPlayer)->getPlateau()->getLast(EP), indPlayer);
}

void Monitor::defausserTout(int indPlayer, int EP) const {
  Plateau *p = getInfosJoueurs(indPlayer)->getPlateau();
  int NbCrt = p->getNbCarte(EP);
  for (int ind = 0; ind < NbCrt; ind++) {
    defausser(p->getLast(EP), indPlayer);
  }
}

void Monitor::incStatut(int indPlayer, int statut, int inc) const {
  getInfosJoueurs(indPlayer)->getPlateau()->incStatut(statut, inc);
}

void Monitor::initiateElements(int nbJoueurs, GameMechanics *gm) {
  mNbJoueur = nbJoueurs;
  mGameMechanics = gm;
  mPlayer = vector<const Player *>(nbJoueurs);
  mInfosJoueurs = vector<InfosJoueur *>(nbJoueurs);
  for (auto ind = 0; ind < nbJoueurs; ind++) {
    mInfosJoueurs[ind] = new InfosJoueur(this,mGameMechanics, ind);
  }
  mGameMechanics->setMonitor(dynamic_cast<Monitor *>(this));
}

void Monitor::addPlayer(const Player *pp, int index) {
  cout << "Monitor::addPlayer: " << pp << " " << index << endl;
  mPlayer[index] = pp;
  mapIdPlayer[pp] = index;
}
void Monitor::removePlayer(int index) { mPlayer[index] = nullptr; }
void Monitor::startGame() { mGameMechanics->startGame(); }
int Monitor::getWinner() const { return mGameMechanics->getWinnerPlayer(); }

const CardGame::Carte *Monitor::getCarte(IdCarte idC) const {
  return mGameMechanics->getCarte(idC);
}

void Monitor::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterPlateau(indPlayer, idCrt);
}

void Monitor::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterHand(indPlayer, idCrt);
}