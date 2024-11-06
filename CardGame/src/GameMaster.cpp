#include "GameMaster.hpp"
#include "ConcreteMonitor.hpp"
#include "InfosJoueur.hpp"

using CardGame::GameMaster;

GameMaster::GameMaster(int nj, _p_GameMechanics gm){
    mMonitor = dynamic_pointer_cast<GameMasterMonitor>(make_shared<ConcreteMonitor>());
    initGame(nj, gm);
}

GameMaster::~GameMaster()
{
}

void GameMaster::initGame(int nj, _p_GameMechanics gm){
    mMonitor->initiateElements(nj,gm);
    mNbJoueur = nj;
    for(int ind=0;ind<4;ind++){
        mJoueurPret.push_back(false);
    }
}

 CardGame::_pc_PlayerInterface GameMaster::login(_pc_Player pp)
{
    int ind = 0;
    while ( (mJoueurPret[ind]) && (ind< mNbJoueur) ){
        ind++;
    }
    if(ind < mNbJoueur){
        mJoueurPret[ind] = true;
        mMonitor->addPlayer(pp,ind);
        return shared_from_this();
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



int   GameMaster::getIdPlayer(_pc_Player pp)const{return mMonitor->getIndPlayer(pp);}
CardGame::_pc_InfosJoueur GameMaster::getInfosJoueurs(int indPlayer)const{return mMonitor->getInfosJoueurs(indPlayer);}
CardGame::_pc_Plateau GameMaster::getPlateauGeneral()const{return mMonitor->getPlateauGeneral();}
CardGame::_pc_PaquetCarte GameMaster::getPioche()const{return mMonitor->getPioche();}
CardGame::_pc_PaquetCarte GameMaster::getDefausse()const{return mMonitor->getDefausse();}
CardGame::_pc_Carte GameMaster::getCarte(IdCarte idC)const{return mMonitor->getCarte(idC);}

int GameMaster::getStatutPlayer(int indPlayer, int dp) const{return getInfosJoueurs(indPlayer)->getPlateau()->getStatut(dp);}
