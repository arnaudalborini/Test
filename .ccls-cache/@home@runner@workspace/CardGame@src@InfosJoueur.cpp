#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"
#include "GameMechanics.hpp"
#include "StatutPlateau.hpp"

using CardGame::InfosJoueur;

InfosJoueur::InfosJoueur(InfosJoueurMonitor *mm, const int PlayerId):
    mHand(new Hand(mm,PlayerId)),
    mPlateau(new Plateau(mm,PlayerId)),
    mPlayerId(PlayerId),
    mMonitor(mm){}

InfosJoueur::InfosJoueur(InfosJoueurMonitor *mm, const CardGame::GameMechanics* gm,const int PlayerId):
    mHand(new Hand(mm,PlayerId)),
    mPlateau(new Plateau(mm,gm->getJoueurInitialStatuts(),PlayerId)),
    mPlayerId(PlayerId),
    mMonitor(mm){}

InfosJoueur::~InfosJoueur()
{
    delete mHand;
    delete mPlateau;
}
