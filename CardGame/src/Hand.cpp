#include "Hand.hpp"

using CardGame::Hand;
using CardGame::IdCarte;

Hand::Hand(){}

Hand::~Hand(){}

IdCarte Hand::getCarte(int ind)
{
    IdCarte crt = mCartes[ind];
    mCartes.erase(mCartes.begin()+ind);
    return crt;
}

void Hand::addCarte(IdCarte crt){mCartes.push_back(crt);}
int Hand::getNbCarte()const {return static_cast<int>(mCartes.size()); }
int Hand::getIdCarte(int ind)const{return mCartes[ind];}
