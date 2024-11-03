#include "GameMaster.hpp"
#include "GameMasterMonitor.hpp"
#include "Monitor.hpp"
#include "InfosJoueur.hpp"
#include "Plateau.hpp"

using CardGame::GameMaster;

GameMaster::GameMaster(int nj, PGameMechanics gm){
    mMonitor = make_shared<Monitor>();
    initGame(nj, gm);
}

GameMaster::~GameMaster()
{
}

void GameMaster::initGame(int nj, PGameMechanics gm){
    mMonitor->initiateElements(nj,gm);
    mNbJoueur = nj;
    for(int ind=0;ind<4;ind++){
        mJoueurPret.push_back(false);
    }
}

 CardGame::PCPlayerInterface GameMaster::login(PCPlayer pp)
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind < mNbJoueur){
        mJoueurPret[ind] = true;
        mMonitor->addPlayer(pp,ind);
        return make_shared<const PlayerInterface>(this);
    }
    return nullptr;
}

void GameMaster::startGame()
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind == mNbJoueur){
        cout << "----tout les joueurs sont prets: debut de la partie-----" << endl;
        mMonitor->startGame();
    }
}

int GameMaster::getWinner() const{return mMonitor->getWinner();}



int   GameMaster::getIdPlayer(PCPlayer pp)const{return mMonitor->getIndPlayer(pp);}
CardGame::PCInfosJoueur GameMaster::getInfosJoueurs(int indPlayer)const{return mMonitor->getInfosJoueurs(indPlayer);}
CardGame::PCPlateau GameMaster::getPlateau()const{return mMonitor->getPlateau();}
CardGame::PCPaquetCarte GameMaster::getPioche()const{return mMonitor->getPioche();}
CardGame::PCPaquetCarte GameMaster::getDefausse()const{return mMonitor->getDefausse();}
CardGame::PCCarte GameMaster::getCarte(IdCarte idC)const{return mMonitor->getCarte(idC);}

int GameMaster::getStatutPlayer(int indPlayer, int dp) const{return getInfosJoueurs(indPlayer)->getPlateau()->getStatut(dp);}
