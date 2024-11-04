#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"
#include "GameMechanics.hpp"

using CardGame::InfosJoueur;

InfosJoueur::InfosJoueur(_p_InfosJoueurMonitor mm, const int PlayerId):
    mPlayerId(PlayerId),
    mMonitor(mm)
{ 
        mHand       = make_shared<Hand>(mm,PlayerId);
        mPlateau    = make_shared<Plateau>(mm,PlayerId);
}

InfosJoueur::InfosJoueur(_p_InfosJoueurMonitor mm, const CardGame::_p_GameMechanics gm,const int PlayerId):
    mPlayerId(PlayerId),
    mMonitor(mm)
{
        mHand       = make_shared<Hand>(mm,PlayerId);
        mPlateau    = make_shared<Plateau>(mm,gm->getJoueurInitialStatuts(),PlayerId);
}

InfosJoueur::~InfosJoueur()
{
}
