#include "Plateau.hpp"
#include "StatutPlateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

Plateau::Plateau():mStatut(new CardGame::StatutPlateau()){}
Plateau::~Plateau(){delete mStatut;}

IdCarte Plateau::showIdN(int EP, int N)const{return mMapCarte.at(EP)[N];}
IdCarte Plateau::showIdLast(int EP)const { return mMapCarte.at(EP).back(); }
IdCarte Plateau::getLast(int EP){return getN(EP,getNbCarte(EP)-1);}
IdCarte Plateau::getN(int EP,int N)
{
    IdCarte crt = mMapCarte.at(EP)[N];
    mMapCarte.at(EP).erase(mMapCarte.at(EP).begin()+N);
    return crt;
}
void Plateau::addLast( int EP, IdCarte crt){mMapCarte.at(EP).push_back(crt);}
int Plateau::getNbCarte(int EP) const{return static_cast<int>(mMapCarte.at(EP).size());}

std::vector<IdCarte> Plateau::showAllId()const{
    vector<IdCarte> vecId = vector<IdCarte>( mMapCarte.size() );
    for (auto pairEPvecId : mMapCarte){
        vecId.insert(vecId.end(),pairEPvecId.second.begin(),pairEPvecId.second.end());
    }
    return vecId;
}
