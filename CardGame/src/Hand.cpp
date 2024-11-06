#include "Hand.hpp"

using CardGame::Hand;

Hand::Hand(){}

Hand::~Hand(){}

CardGame::IdCarte Hand::getCarteHand(int ind)
{
    IdCarte crt = mCartes[ind];
    mCartes.erase(mCartes.begin()+ind);
    (getHandMonitor().lock())->effetQuitterHand(getIdPlayer(),crt);
    return crt;
}

void Hand::addCarteHand(IdCarte crt){mCartes.push_back(crt);}
int Hand::getNbCarteHand()const {return static_cast<int>(mCartes.size()); }
int Hand::getIdCarteHand(int ind)const{return mCartes[ind];}
