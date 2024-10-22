#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"

using CardGame::InfosJoueur;

InfosJoueur::InfosJoueur()
{
    mHand = new Hand();
    mPlateau = new Plateau();
}

InfosJoueur::~InfosJoueur()
{
    delete mHand;
    delete mPlateau;
}
