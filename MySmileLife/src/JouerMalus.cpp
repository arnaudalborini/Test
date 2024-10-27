#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

#include "JouerMalus.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

/*
        csAccidents,
        csAttentat,
        csBurnOut,
        csDivorce,
        csImpotsRevenus,
        csLicenciement,
        csMaladie,
        csPrison,
        csRedoublement,
*/

bool CartesAlgoMSL::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt) const
{
    if(crt->getType()!=carteMalus){
        return false;
    }
    switch(crt->getSType()){
        case csAccidents:
            return false;
        case csAttentat:
            return false;
        case csBurnOut:
            return false;
        case csDivorce:
            return false;
        case csImpotsRevenus:
            return false;
        case csLicenciement:
            return false;
        case csMaladie:
            return false;
        case csPrison:
            return false;
        case csRedoublement:
            return false;
        default:
            return false;
    }
}

bool CartesAlgoMSL::jouerCarteMalus(const Player *pp, const CarteMSL *crt) const
{
    return false;
}