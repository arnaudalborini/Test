#include "PaquetCarte.hpp"

#include <algorithm>

using CardGame::PaquetCarte;
using CardGame::IdCarte;

PaquetCarte::PaquetCarte(){}

PaquetCarte::~PaquetCarte(){}

void PaquetCarte::initializePaquet(const vector<IdCarte> &vecCartes){std::copy(vecCartes.begin(),vecCartes.end(),mCartes.begin());}

IdCarte PaquetCarte::piocher()
{
    IdCarte idCrt= mCartes.back();
    mCartes.pop_back();
    return idCrt;
}

int PaquetCarte::showIdLast()const{return mCartes.back();}

int PaquetCarte::getNbCarte() const
{
    return mCartes.size();
}
