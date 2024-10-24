#include "GameMaster.hpp"
#include "GameMasterMonitor.hpp"
#include "Monitor.hpp"
#include "InfosJoueur.hpp"
#include "Plateau.hpp"

using CardGame::GameMaster;

GameMaster::GameMaster(int nj, GameMechanics* gm){
    mMonitor = new Monitor();
    initGame(nj, gm);
}

GameMaster::~GameMaster()
{
    delete mMonitor;
}

void GameMaster::initGame(int nj, GameMechanics *gm){
    mMonitor->initiateElements(nj,gm);
    mNbJoueur = nj;
    for(int ind=0;ind<4;ind++){
        mJoueurPret.push_back(false);
    }
}

 const CardGame::PlayerInterface* GameMaster::login(const Player *pp)
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind < mNbJoueur){
        mJoueurPret[ind] = true;
        mMonitor->addPlayer(pp,ind);
        mapIdPlayer[pp] = ind;
        return dynamic_cast<const PlayerInterface*>(this);
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



int   GameMaster::getIdPlayer(const Player* pp)const{return mapIdPlayer.at(pp);}
const CardGame::InfosJoueur* GameMaster::getInfosJoueurs(int indPlayer)const{return mMonitor->getInfosJoueurs(indPlayer);}
const CardGame::Plateau* GameMaster::getPlateau()const{return mMonitor->getPlateau();}
const CardGame::PaquetCarte* GameMaster::getPioche()const{return mMonitor->getPioche();}
const CardGame::PaquetCarte* GameMaster::getDefausse()const{return mMonitor->getDefausse();}
const CardGame::Carte* GameMaster::getCarte(IdCarte idC)const{return nullptr;}

int GameMaster::getStatutPlayer(int indPlayer, int dp) const{return getInfosJoueurs(indPlayer)->getPlateau()->getStatut(dp);}
