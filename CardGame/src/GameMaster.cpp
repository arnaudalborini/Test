#include "GameMaster.hpp"
#include "GameMasterMonitor.hpp"

using CardGame::GameMaster;

GameMaster::GameMaster()
{
    mMonitor = new GameMasterMonitor();
}

GameMaster::~GameMaster()
{
    if(mMonitor!=nullptr){
        delete mMonitor;
        mMonitor=nullptr;
    }
}

void GameMaster::initGame(int nj, GameMechanics *gm){
    mMonitor->initiateElements(nj,gm);
    mNbJoueur = nj;
    for(int ind=0;ind<4;ind++){
        mJoueurPret.push_back(false);
    }
}

int GameMaster::login(const Player *pp)
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind < mNbJoueur){
        mJoueurPret[ind] = true;
        mMonitor->addPlayer(pp,ind);
        return ind;
    }
    return -1;
}

void GameMaster::startGame()
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind == mNbJoueur){
        mMonitor->startGame();
    }
}
