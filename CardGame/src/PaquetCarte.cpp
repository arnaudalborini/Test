#include "PaquetCarte.hpp"

#include <algorithm>
#include <iostream>

using CardGame::PaquetCarte;
using CardGame::IdCarte;
using std::cout;
using std::endl;

PaquetCarte::PaquetCarte(){}

PaquetCarte::~PaquetCarte(){}

void PaquetCarte::initializePaquet( vector<IdCarte> &vecCartes){
    mCartes = vector<IdCarte>(vecCartes.size());
    cout << "mCArtes size" << mCartes.size() << endl;
    std::copy(vecCartes.begin(),vecCartes.end(),mCartes.end());
    for (auto crt:vecCartes){
        cout << crt << endl;
    }
}

void PaquetCarte::initializePaquet(const vector<IdCarte> &vecCartes, const vector<int> &playedBy)
{
    mCartes = vector<IdCarte>(vecCartes.size());
    mPlayedBy = vector<int>(playedBy.size());
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