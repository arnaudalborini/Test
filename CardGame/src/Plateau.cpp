#include "Plateau.hpp"
#include "StatutPlateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

Plateau::Plateau(PlateauMonitor* mm,int playerInd):mMonitor(mm),playerId(playerInd){}
Plateau::Plateau(PlateauMonitor* mm,vector<int> vecStatut,int playerInd):mMonitor(mm),mVecStatut(vecStatut),playerId(playerInd){}
Plateau::~Plateau(){}

IdCarte Plateau::showIdN(int EP, int N)const
{
    if(getNbCarte(EP) >= N+1){
        return mMapCarte.at(EP)[N];
    }else{
        return IdCarte(-1);
    }
}
IdCarte Plateau::showIdLast(int EP)const { 
    if(getNbCarte(EP) == 0){
        return IdCarte(-1);
    }else{
        return mMapCarte.at(EP).back();
    }
}
IdCarte Plateau::getLast(int EP){return getN(EP,getNbCarte(EP)-1);}
IdCarte Plateau::getN(int EP,int N)
{
    if(getNbCarte(EP) >= N+1){
        IdCarte id = mMapCarte.at(EP)[N];
        mMapCarte.at(EP).erase(mMapCarte.at(EP).begin()+N);
        mMonitor->effetQuitterPlateau(playerId,id);
        return id;
    }else{
        return IdCarte(-1);
    }
}
void Plateau::addLast( int EP, IdCarte crt){
    mMapCarte[EP].push_back(crt);
}
int Plateau::getNbCarte(int EP) const{
    if(mMapCarte.find(EP) != mMapCarte.end()){
        return static_cast<int>(mMapCarte.at(EP).size());
    }else{
        return 0;
    }
}

std::vector<IdCarte> Plateau::showAllId()const{
    vector<IdCarte> vecId;
    for (auto pairEPvecId : mMapCarte){
        vecId.insert(vecId.end(),pairEPvecId.second.begin(),pairEPvecId.second.end());
    }
    return vecId;
}

const std::vector<IdCarte> Plateau::showAllIdByEP(int EP) const{
    cout << EP << endl;
    if(mMapCarte.find(EP) != mMapCarte.end()){
        return mMapCarte.at(EP);
    }else{
        return vector<IdCarte>();
    }
    return CardGame::myMapGet(mMapCarte,EP);
}
