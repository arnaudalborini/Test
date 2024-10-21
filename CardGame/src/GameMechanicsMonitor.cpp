#include "GameMechanicsMonitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"

using CardGame::GameMechanicsMonitor;
using CardGame::IdCarte;
using CardGame::Plateau;

GameMechanicsMonitor::GameMechanicsMonitor(){}
GameMechanicsMonitor::~GameMechanicsMonitor(){}

void GameMechanicsMonitor::initiatePioche(const vector<IdCarte> &mCartes){mPioche->initializePaquet(mCartes);}
void GameMechanicsMonitor::initiateDefausse(const vector<IdCarte> &mCartes){mDefausse->initializePaquet(mCartes);}

Plateau* GameMechanicsMonitor::getPlateau(){return mPlateau;}