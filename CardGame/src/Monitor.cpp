#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "InfosJoueur.hpp"
#include "GameMechanics.hpp"

using CardGame::Monitor;
using CardGame::Plateau;
using CardGame::PaquetCarte;
using CardGame::InfosJoueur;
using CardGame::Player;

Monitor::Monitor(){
    mPioche = new PaquetCarte();
    mDefausse = new PaquetCarte();
    mInfosJoueurs = vector<InfosJoueur*>();
    mPlayer = vector<const Player*>();
    mPlateau = new Plateau();
}

Monitor::~Monitor(){
    delete mPioche;
    delete mDefausse;
    delete mPlateau;
    for(auto inf:mInfosJoueurs){
        delete inf;
    }
}

Plateau*        Monitor::getPlateau()                const{return mPlateau;}
PaquetCarte*    Monitor::getPioche()                 const{return mPioche; }
PaquetCarte*    Monitor::getDefausse()               const{return mDefausse;}
InfosJoueur*    Monitor::getInfosJoueurs(int ind)    const{return mInfosJoueurs[ind];}
const Player*   Monitor::getPlayer(int ind)          const{return mPlayer[ind];}

int Monitor::getNbPlayer() const{return mNbJoueur;}

void Monitor::initiateElements(int nbJoueurs, GameMechanics *gm)
{
    mNbJoueur = nbJoueurs;
    mGameMechanics = gm;
    mPlayer       = vector<const Player *>(nbJoueurs);
    mInfosJoueurs = vector<InfosJoueur *>(nbJoueurs);
    for(auto ind=0;ind<nbJoueurs;ind++){
        mInfosJoueurs[ind] = new InfosJoueur(gm);
    }
    gm->setMonitor( dynamic_cast<Monitor*>( this ));
}

void Monitor::addPlayer(const Player *pp, int index){mPlayer[index] = pp;}
void Monitor::removePlayer(int index){mPlayer[index] = nullptr;}
void Monitor::startGame(){mGameMechanics->startGame();}
int Monitor::getWinner()const{return mGameMechanics->getWinnerPlayer();}


