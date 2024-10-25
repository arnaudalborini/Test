#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "Plateau.hpp"
#include "GameMechanics.hpp"
#include "StatutPlateau.hpp"

using CardGame::InfosJoueur;

InfosJoueur::InfosJoueur():mHand(new Hand()),mPlateau(new Plateau()){}

InfosJoueur::InfosJoueur(const CardGame::GameMechanics* gm):mHand(new Hand()),mPlateau(new Plateau(gm->getJoueurInitialStatuts())){}

InfosJoueur::~InfosJoueur()
{
    delete mHand;
    delete mPlateau;
}
