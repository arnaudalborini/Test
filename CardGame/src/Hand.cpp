#include "Hand.hpp"
#include "Carte.hpp"
using CardGame::Hand;

Hand::Hand()
{
}

Hand::~Hand()
{
}

const CardGame::Carte *CardGame::Hand::getCarte(int ind)
{
    const Carte* crt = mCartes[ind];
    mCartes.erase(mCartes.begin()+ind);
    return crt;
}

void Hand::addCarte(const Carte *crt){mCartes.push_back(crt);}
int Hand::getNbCarte()const {return static_cast<int>(mCartes.size()); }
int Hand::getIdCarte(int ind)const{return mCartes[ind]->getId();}
