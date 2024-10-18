#include "PlateauJoueur.hpp"
#include "Carte.hpp"

using CardGame::PlateauJoueur;
using CardGame::Carte;

PlateauJoueur::PlateauJoueur(){}
PlateauJoueur::~PlateauJoueur(){}

const CardGame::Carte* PlateauJoueur::getLast(EmplacementPlateau EP){return getN(EP,getNbCarte(EP)-1);}
int CardGame::PlateauJoueur::getIdN(EmplacementPlateau EP, int N) const{return mMapCarte.at(EP)[N]->getId();}
const Carte *PlateauJoueur::getN(EmplacementPlateau EP,int N)
{
    const Carte* crt = mMapCarte.at(EP)[N];
    mMapCarte.at(EP).erase(mMapCarte.at(EP).begin()+N);
    return crt;
}
void PlateauJoueur::addLast( EmplacementPlateau EP, const Carte *crt){mMapCarte.at(EP).push_back(crt);}
int CardGame::PlateauJoueur::getNbCarte(EmplacementPlateau EP) const{return static_cast<int>(mMapCarte.at(EP).size());}
int PlateauJoueur::getIdLast(EmplacementPlateau EP) const { return mMapCarte.at(EP).back()->getId(); }
