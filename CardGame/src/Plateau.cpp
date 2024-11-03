#include "Plateau.hpp"
#include "StatutPlateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

Plateau::Plateau(PPlateauMonitor mm,int playerInd):mMonitor(mm),playerId(playerInd){}
Plateau::Plateau(PPlateauMonitor mm,vector<int> vecStatut,int playerInd):mMonitor(mm),mVecStatut(vecStatut),playerId(playerInd){}
Plateau::~Plateau(){}

IdCarte Plateau::showIdN(int EP, int N)const
{
    if(getNbCarte(EP) >= N+1){
        return mVecCarte.at(EP)[N];
    }else{
        return IdCarte(-1);
    }
}
IdCarte Plateau::showIdLast(int EP)const { 
    if(getNbCarte(EP) == 0){
        return IdCarte(-1);
    }else{
        return mVecCarte.at(EP).back();
    }
}
IdCarte Plateau::getLast(int EP){return getN(EP,getNbCarte(EP)-1);}
IdCarte Plateau::getN(int EP,int N)
{
    if(getNbCarte(EP) >= N+1){
        IdCarte id = mVecCarte.at(EP)[N];
        mVecCarte.at(EP).erase(mVecCarte.at(EP).begin()+N);
        mMonitor->effetQuitterPlateau(playerId,id);
        return id;
    }else{
        return IdCarte(-1);
    }
}
void Plateau::addLast( int EP, IdCarte crt){
    mVecCarte[EP].push_back(crt);
}
int Plateau::getNbCarte(int EP) const{
    if(EP >= 0 && EP < mVecCarte.size()){
        return static_cast<int>(mVecCarte.at(EP).size());
    }else{
        return -1;
    }
}

std::vector<IdCarte> Plateau::showAllId()const{
    vector<IdCarte> vecId;
    for (auto EPvecId : mVecCarte){
        vecId.insert(vecId.end(),EPvecId.begin(),EPvecId.end());
    }
    return vecId;
}

const std::vector<IdCarte> Plateau::showAllIdByEP(int EP) const{
    if(EP >= 0 && EP < mVecCarte.size()){
        return mVecCarte.at(EP);
    }else{
        return vector<IdCarte>();
    }
}
