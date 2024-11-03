#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"
#include "GameMechanics.hpp"
#include "StatutPlateau.hpp"

using CardGame::InfosJoueur;

InfosJoueur::InfosJoueur(PInfosJoueurMonitor mm, const int PlayerId):
    mHand(make_shared<Hand>(mm,PlayerId)),
    mPlateau(make_shared<Plateau>(mm,PlayerId)),
    mPlayerId(PlayerId),
    mMonitor(mm){}

InfosJoueur::InfosJoueur(PInfosJoueurMonitor mm, const CardGame::PGameMechanics gm,const int PlayerId):
    mHand(make_shared<Hand>(mm,PlayerId)),
    mPlateau(make_shared<Plateau>(mm,gm->getJoueurInitialStatuts(),PlayerId)),
    mPlayerId(PlayerId),
    mMonitor(mm){}

InfosJoueur::~InfosJoueur()
{
}
