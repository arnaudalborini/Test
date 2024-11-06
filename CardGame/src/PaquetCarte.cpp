#include "PaquetCarte.hpp"

using CardGame::PaquetCarte;
using CardGame::IdCarte;

PaquetCarte::PaquetCarte(){}

PaquetCarte::~PaquetCarte(){}

void PaquetCarte::initializePaquet( const vector<IdCarte> &vecCartes){mCartes.insert(mCartes.end(),vecCartes.begin(),vecCartes.end());}

void PaquetCarte::initializePaquet(const vector<IdCarte> &vecCartes, const vector<int> &playedBy)
{
    mCartes.insert(mCartes.end(),vecCartes.begin(),vecCartes.end());
    mPlayedBy.insert(mPlayedBy.end(),playedBy.begin(),playedBy.end());
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

IdCarte PaquetCarte::piocherNeme(int N)
{
    IdCarte idCrt= mCartes.at(N);
    mCartes.erase(mCartes.begin()+N);
    if(mPlayedBy.size()>0){
        mPlayedBy.erase(mPlayedBy.begin()+N);
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

IdCarte PaquetCarte::showNeme(int n) const
{
    return mCartes.at(n);
}
