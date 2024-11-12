#include "Plateau.hpp"

using CardGame::Plateau;
using CardGame::IdCarte;

int Plateau::getIdPlayer() const{return -1;}

Plateau::Plateau(_p_PlateauMonitor mm):mMonitor(mm){}
Plateau::Plateau(_p_PlateauMonitor mm,const vector<int> &vecStatut) : mVecStatut(vecStatut),mMonitor(mm) {}
Plateau::~Plateau(){}

IdCarte Plateau::showIdNByEP(int EP, int N)const
{
    if(getNbCarteByEP(EP) >= N+1){
        return mVecCarte.at(EP)[N];
    }else{
        return IdCarte(-1);
    }
}
IdCarte Plateau::showIdLastByEP(int EP)const { 
    if(getNbCarteByEP(EP) == 0){
        return IdCarte(-1);
    }else{
        return mVecCarte.at(EP).back();
    }
}
IdCarte Plateau::getLastByEP(int EP){return getNByEP(EP,getNbCarteByEP(EP)-1);}
IdCarte Plateau::getNByEP(int EP,int N)
{
    if(getNbCarteByEP(EP) >= N+1){
        IdCarte id = mVecCarte.at(EP)[N];
        mVecCarte.at(EP).erase(mVecCarte.at(EP).begin()+N);
        (mMonitor.lock())->effetQuitterPlateau(getIdPlayer(),id);
        return id;
    }else{
        return IdCarte(-1);
    }
}
void Plateau::addCarteToEP( int EP, IdCarte crt){
    mVecCarte[EP].push_back(crt);
}
int Plateau::getNbCarteByEP(int EP) const{
    if(EP >= 0 && EP < static_cast<int>( mVecCarte.size())){
        return static_cast<int>(mVecCarte.at(EP).size());
    }else{
        return -1;
    }
}

std::vector<IdCarte> Plateau::showAllIdAllEP()const{
    vector<IdCarte> vecId;
    for (auto EPvecId : mVecCarte){
        vecId.insert(vecId.end(),EPvecId.begin(),EPvecId.end());
    }
    return vecId;
}

const std::vector<IdCarte> Plateau::showAllIdByEP(int EP) const{
    if(EP >= 0 && EP < static_cast<int>(mVecCarte.size())){
        return mVecCarte.at(EP);
    }else{
        return vector<IdCarte>();
    }
}
