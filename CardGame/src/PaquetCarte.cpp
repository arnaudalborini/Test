#include "PaquetCarte.hpp"

#include <algorithm>

using CardGame::PaquetCarte;
using CardGame::IdCarte;

PaquetCarte::PaquetCarte(){}

PaquetCarte::~PaquetCarte(){}

void PaquetCarte::initializePaquet(const vector<IdCarte> &vecCartes){std::copy(vecCartes.begin(),vecCartes.end(),mCartes.begin());}

void PaquetCarte::initializePaquet(const vector<IdCarte> &vecCartes, const vector<int> &playedBy)
{
    std::copy(vecCartes.begin(),vecCartes.end(),mCartes.begin());
    std::copy(playedBy.begin(),playedBy.end(),mPlayedBy.begin());
}

IdCarte PaquetCarte::piocher()
{
    IdCarte idCrt= mCartes.back();
    mCartes.pop_back();
    if(mPlayedBy.size()>0){
        mPlayedBy.pop_back();
    }
    return idCrt;
}

IdCarte PaquetCarte::showIdLast()const{return mCartes.back();}
int PaquetCarte::getNbCarte() const{return mCartes.size();}
void PaquetCarte::addCarte(IdCarte idC){mCartes.push_back(idC);}

void PaquetCarte::addCarte(IdCarte idC, int playedBy)
{
    mCartes.push_back(idC);
    mPlayedBy.push_back(playedBy);
}

int PaquetCarte::showLastPlayedBy()const{return mPlayedBy.back();}