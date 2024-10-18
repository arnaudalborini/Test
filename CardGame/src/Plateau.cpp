#include "Plateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

Plateau::Plateau(){}
Plateau::~Plateau(){}

IdCarte Plateau::getLast(int EP){return getN(EP,getNbCarte(EP)-1);}
int CardGame::Plateau::getIdN(int EP, int N) const{return mMapCarte.at(EP)[N];}
IdCarte Plateau::getN(int EP,int N)
{
    IdCarte  crt = mMapCarte.at(EP)[N];
    mMapCarte.at(EP).erase(mMapCarte.at(EP).begin()+N);
    return crt;
}
void Plateau::addLast( int EP, IdCarte crt){mMapCarte.at(EP).push_back(crt);}
int CardGame::Plateau::getNbCarte(int EP) const{return static_cast<int>(mMapCarte.at(EP).size());}
int Plateau::getIdLast(int EP) const { return mMapCarte.at(EP).back(); }
