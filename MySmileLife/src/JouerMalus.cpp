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
bool CartesAlgoMSL::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt, const Player* cible) const
{
    Plateau* plat = getPlateauPlayer(pp);
    Plateau* platCible = getPlateauPlayer(cible);
    switch(crt->getSType()){
        case csAccidents:
            return (platCible->getStatut(ResistantAccident) == 0);
        case csAttentat:
            return ( mMonitor->getPlateau()->getStatut(antiAttentat) == 0 );
        case csBurnOut:
            return (platCible->getStatut(aUnTravail));
        case csDivorce:
            return ( (platCible->getStatut(ResistantDivorce) == 0) && (platCible->getStatut(estMarie)) );
        case csImpotsRevenus:
            return ( (platCible->getStatut(ResistantImpots) == 0) && (platCible->getStatut(aUnTravail)) && (platCible->getStatut(SalairesDisponibles)>0) );
        case csLicenciement:
            return ( (platCible->getStatut(ResistantLicenciement) == 0) && (platCible->getStatut(aUnTravail)) );
        case csMaladie:
            return (platCible->getStatut(ResistantMaladie) == 0);
        case csPrison:
            return platCible->getStatut(RisquePrison);
        case csRedoublement:
            return ( (platCible->getStatut(aUnTravail) == 0) && (platCible->getStatut(DerniereEtudeRedoublable)>0) );
        default:
            return false;
    }
}
bool CartesAlgoMSL::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt) const
{
    if(crt->getType()!=carteMalus){
        return false;
    }
    int indJoueur = mMonitor->getIndPlayer(pp);
    for(int indice=0;indice<mMonitor->getNbPlayer();indice++){
        if(indice==indJoueur){
            continue;
        }
        const Player* Cible = mMonitor->getPlayer(indice);
        if(peutEtreJoueeMalus(pp,crt,Cible)){
            return true;
        }
    }
    return false;
}

bool CartesAlgoMSL::jouerCarteMalus(const Player *pp, const CarteMSL *crt) const
{
    return false;
}