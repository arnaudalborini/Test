#include "Plateau.hpp"
#include "StatutPlateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

Plateau::Plateau(PlateauMonitor* mm,int playerInd):mMonitor(mm),playerId(playerInd){}
Plateau::Plateau(const PlateauMonitor* mm,vector<int> vecStatut,int playerInd):mMonitor(mm),mVecStatut(vecStatut),playerId(playerInd){}
Plateau::~Plateau(){}

IdCarte Plateau::showIdN(int EP, int N)const{return mMapCarte.at(EP)[N];}
IdCarte Plateau::showIdLast(int EP)const { return mMapCarte.at(EP).back(); }
IdCarte Plateau::getLast(int EP){return getN(EP,getNbCarte(EP)-1);}
IdCarte Plateau::getN(int EP,int N)
{
    IdCarte crt = mMapCarte.at(EP)[N];
    mMapCarte.at(EP).erase(mMapCarte.at(EP).begin()+N);
    mMonitor->effetQuitterPlateau(playerId,crt);
    return crt;
}
void Plateau::addLast( int EP, IdCarte crt){mMapCarte[EP].push_back(crt);}
int Plateau::getNbCarte(int EP) const{
    map<int, vector<IdCarte>>::const_iterator it = mMapCarte.find(EP);
    if(it != mMapCarte.end()){
        return static_cast<int>(it->second.size());
    }
    return 0;
}

std::vector<IdCarte> Plateau::showAllId()const{
    vector<IdCarte> vecId;
    for (auto pairEPvecId : mMapCarte){
        vecId.insert(vecId.end(),pairEPvecId.second.begin(),pairEPvecId.second.end());
    }
    return vecId;
}

const std::vector<IdCarte> Plateau::showAllIdByEP(int ET) const{return mMapCarte.at(ET);}
