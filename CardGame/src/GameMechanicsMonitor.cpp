#include "GameMechanicsMonitor.hpp"
#include "PaquetCarte.hpp"

using CardGame::GameMechanicsMonitor;

GameMechanicsMonitor::GameMechanicsMonitor(){}
GameMechanicsMonitor::~GameMechanicsMonitor(){}

void GameMechanicsMonitor::initiatePioche(const vector<IdCarte> &mCartes){mPioche->initializePaquet(mCartes);}
void GameMechanicsMonitor::initiateDefausse(const vector<IdCarte> &mCartes){mDefausse->initializePaquet(mCartes);}