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
    cout << "initiateElements" << endl;
    mMonitor->initiateElements(nj,gm);
    cout << "push_back joueurpret" << endl;
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

int GameMaster::getWinner() const{return mMonitor->getWinner();}
