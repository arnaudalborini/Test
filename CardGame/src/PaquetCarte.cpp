#include "PaquetCarte.hpp"

#include <algorithm>
#include <iostream>

using CardGame::PaquetCarte;
using CardGame::IdCarte;
using std::cout;
using std::endl;

PaquetCarte::PaquetCarte(){
    mCartes.push_back(1);
}

PaquetCarte::~PaquetCarte(){}

void PaquetCarte::initializePaquet( vector<IdCarte> vecCartes){
    cout << "bonjour" << endl;
    cout << vecCartes[0]<< endl;
    mCartes = vector<IdCarte>(vecCartes.size());
    std::copy(vecCartes.begin(),vecCartes.end(),mCartes.end());
}

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