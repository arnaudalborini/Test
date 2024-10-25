#include "CarteMSL.hpp"

using MySmileLife::CarteMSL;

int CarteMSL::getNbEtude() const
{
    switch( mCsType ){
        case csEtudeSimple:
            return 1;
        case csEtudeDouble:
            return 2;
        default:
            return 0;
    }
}

int CarteMSL::getPrixMaison() const
{
    switch( mCsType ){
        case csMaison6:
            return 6;
        case csMaison8:
            return 8;
        case csMaison10:
            return 10;
        default:
            return 0;
    }
}

int CarteMSL::getPrixVoyage() const{return PRIXVOYAGE;}

int MySmileLife::CarteMSL::getSalaire() const
{
    switch( mCsType ){
        case csSalaire1:
            return 1;
        case csSalaire2:
            return 2;
        case csSalaire3:
            return 3;
        case csSalaire4:
            return 4;
        default:
            return 0;
    }
}