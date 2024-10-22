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
    cout << "setmonitor" << endl;
    gm->setMonitor( dynamic_cast<Monitor*>( this ));
}

void GameMasterMonitor::addPlayer(const Player *pp, int index)
{
    mPlayer[index] = pp;
}

void GameMasterMonitor::startGame()
{
    mGameMechanics->startGame();
}

void GameMasterMonitor::removePlayer(int index)
{
    mPlayer[index] = nullptr;
}

int CardGame::GameMasterMonitor::getWinner() const{return mGameMechanics->getWinnerPlayer();}
