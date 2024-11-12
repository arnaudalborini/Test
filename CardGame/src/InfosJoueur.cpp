#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"
#include "GameMechanics.hpp"

using CardGame::InfosJoueur;

CardGame::weak_ptr<CardGame::HandMonitor> InfosJoueur::getHandMonitor() const{return mMonitor.lock();}

int InfosJoueur::getIdPlayer() const{return mPlayerId;}

InfosJoueur::InfosJoueur(_p_InfosJoueurMonitor mm, const int PlayerId) :
    Plateau(dynamic_pointer_cast<PlateauMonitor>(mm)), 
    Hand(), 
    mPlayerId(PlayerId),
    mMonitor(mm)
{
}

InfosJoueur::InfosJoueur(_p_InfosJoueurMonitor mm, const vector<IdCarte> &vec,const int PlayerId):
    Plateau(dynamic_pointer_cast<PlateauMonitor>(mm),vec),
    Hand(),
    mPlayerId(PlayerId),
    mMonitor(mm)
{
}

InfosJoueur::~InfosJoueur()
{
}

CardGame::_p_Hand InfosJoueur::getHand()
{
    return dynamic_pointer_cast<Hand>(shared_from_this());
}

CardGame::_pc_Hand InfosJoueur::getHand()const
{
    return dynamic_pointer_cast<const Hand>(shared_from_this());
}

CardGame::_p_Plateau InfosJoueur::getPlateau()
{
    return dynamic_pointer_cast<Plateau>(shared_from_this());
}

CardGame::_pc_Plateau InfosJoueur::getPlateau()const
{
    return dynamic_pointer_cast<const Plateau>(shared_from_this());
}
