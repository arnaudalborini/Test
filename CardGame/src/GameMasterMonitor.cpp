#include "GameMasterMonitor.hpp"
#include "PaquetCarte.hpp"
#include "GameMechanics.hpp"

using CardGame::GameMasterMonitor;

GameMasterMonitor::GameMasterMonitor(){}

GameMasterMonitor::~GameMasterMonitor(){}

void GameMasterMonitor::initiateElements(int nbJoueurs, GameMechanics *gm)
{
    mNbJoueur = nbJoueurs;
    mGameMechanics = gm;
    gm->setMonitor(this);
    mInfosJoueurs = vector<InfosJoueur*>(nbJoueurs);
    mPlayer = vector<Player*>(nbJoueurs);
}

void GameMasterMonitor::addPlayer(Player *pp, int index)
{
}

void GameMasterMonitor::startGame()
{
}

void GameMasterMonitor::removePlayer(int indice)
{
}