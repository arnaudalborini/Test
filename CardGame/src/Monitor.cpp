#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "InfosJoueur.hpp"

using CardGame::Monitor;

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

