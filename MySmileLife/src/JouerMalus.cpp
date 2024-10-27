#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

#include "JouerMalus.hpp"

using MySmileLife::JouerMalus;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

const Player* JouerMalus::getCibleMalus(const Player* pp, CarteSousType typeMalus)const{
    return nullptr;
}

bool JouerMalus::peutEtreJoueeMalus(const Player *pp, CarteSousType st, const Player* cible) const
{
    if(cible==nullptr){
        return false;
    }
    Plateau* plat       = mMonitor->getPlateauPlayer(pp);
    Plateau* platCible  = mMonitor->getPlateauPlayer(cible);
    switch(st){
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
bool JouerMalus::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt) const
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
        if(peutEtreJoueeMalus(pp,crt->getSType(),Cible)){
            return true;
        }
    }
    return false;
}

void JouerMalus::jouerAccident(const Player *cible)const{
    mMonitor->incStatut(mMonitor->getIndPlayer(cible),TourAPasser,1);
}
void JouerMalus::jouerAttentat()const{
    for(int indPlayer=0;indPlayer<mMonitor->getNbPlayer();indPlayer++){
        mMonitor->defausserTout( indPlayer, EEnfant );
    }
}
void JouerMalus::jouerBurnout(const Player *cible)const{
    mMonitor->incStatut(mMonitor->getIndPlayer(cible),TourAPasser,1);
}
void JouerMalus::jouerDivorce(const Player *cible)const{
    mMonitor->defausserTout( mMonitor->getIndPlayer(cible), EMariage );
}
void JouerMalus::jouerImpots(const Player *cible)const{
    mMonitor->defausserDernier( mMonitor->getIndPlayer(cible), ESalairesD );
}
void JouerMalus::jouerLicenciement(const Player *cible)const{
    mMonitor->defausserTout( mMonitor->getIndPlayer(cible), EMetier );
}
void JouerMalus::jouerMaladie(const Player *cible)const{
    mMonitor->incStatut(mMonitor->getIndPlayer(cible),TourAPasser,1);
}
void JouerMalus::jouerPrison()const{
    for(int indPlayer=0;indPlayer<mMonitor->getNbPlayer();indPlayer++){
        Plateau * p = mMonitor->getInfosJoueurs(indPlayer)->getPlateau();
        if(p->getStatut(RisquePrison)){
            mMonitor->defausserTout( indPlayer, EMetier );
            mMonitor->incStatut(indPlayer,TourAPasser,3);
        }
    }
}
void JouerMalus::jouerRedoublement(const Player *cible)const{
    mMonitor->defausserDernier( mMonitor->getIndPlayer(cible), EEtudes );
}

bool JouerMalus::jouerCarteMalus(const Player *pp, const CarteMSL *crt) const
{
    if(peutEtreJoueeMalus(pp,crt)==false){
        return false;
    }
    switch(crt->getSType()){
        case csAttentat:
            jouerAttentat();
            mMonitor->getPlateauPlayer( pp )->addLast(EMalus, crt->getId());
            break;
        case csPrison:
            jouerPrison();
            break;
    }
    const Player* cible = getCibleMalus(pp,crt->getSType());
    if(peutEtreJoueeMalus(pp,crt->getSType(),cible) == false ){
        return false;
    }
    switch(crt->getSType()){
        case csAccidents:
            jouerAccident(cible);
            break;
        case csBurnOut:
            jouerBurnout(cible);
            break;
        case csDivorce:
            jouerDivorce(cible);
            break;
        case csImpotsRevenus:
            jouerImpots(cible);
            break;
        case csLicenciement:
            jouerLicenciement(cible);
            break;
        case csMaladie:
            jouerMaladie(cible);
            break;
        case csRedoublement:
            jouerRedoublement(cible);
            break;
    }
    return true;
}