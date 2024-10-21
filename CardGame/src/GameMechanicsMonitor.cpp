#include "GameMechanicsMonitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "Player.hpp"

using CardGame::GameMechanicsMonitor;
using CardGame::IdCarte;

GameMechanicsMonitor::GameMechanicsMonitor(){}
GameMechanicsMonitor::~GameMechanicsMonitor(){}

CardGame::Plateau*        GameMechanicsMonitor::getPlateau()                const{return mPlateau;}
CardGame::PaquetCarte*    GameMechanicsMonitor::getPioche()                 const{return mPioche; }
CardGame::PaquetCarte*    GameMechanicsMonitor::getDefausse()               const{return mDefausse;}
CardGame::InfosJoueur*    GameMechanicsMonitor::getInfosJoueursP(int ind)   const{return mInfosJoueurs[ind];}
const CardGame::Player*   GameMechanicsMonitor::getPlayerP(int ind)         const{return mPlayer[ind];}

int GameMechanicsMonitor::getNbPlayer() const{return mNbJoueur;}
