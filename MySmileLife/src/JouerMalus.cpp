#include "JouerMalus.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "InfosJoueur.hpp"


using MySmileLife::JouerMalus;

bool JouerMalus::peutEtreJoueeMalus(CardGame::_pc_Player pp, CarteSousType st, CardGame::_pc_Player cible) const
{
    if(cible==nullptr){
        return false;
    }
    int indCible = getMonitor()->getIndPlayer(cible);
    switch(st){
        case csAccidents:
            return (getMonitor()->getStatut(indCible,ResistantAccident) == 0);
        case csAttentat:
            return ( getMonitor()->getStatutGeneral(antiAttentat) == 0 );
        case csBurnOut:
            return (getMonitor()->getStatut(indCible,aUnTravail));
        case csDivorce:
            return ( (getMonitor()->getStatut(indCible,ResistantDivorce) == 0) && (getMonitor()->getStatut(indCible,estMarie)) );
        case csImpotsRevenus:
            return ( (getMonitor()->getStatut(indCible,ResistantImpots) == 0) && (getMonitor()->getStatut(indCible,aUnTravail)) && (getMonitor()->getStatut(indCible,SalairesDisponibles)>0) );
        case csLicenciement:
            return ( (getMonitor()->getStatut(indCible,ResistantLicenciement) == 0) && (getMonitor()->getStatut(indCible,aUnTravail)) );
        case csMaladie:
            return (getMonitor()->getStatut(indCible,ResistantMaladie) == 0);
        case csPrison:
            return getMonitor()->getStatut(indCible,RisquePrison);
        case csRedoublement:
            return ( (getMonitor()->getStatut(indCible,aUnTravail) == 0) && (getMonitor()->getStatut(indCible,DerniereEtudeRedoublable)>0) );
        default:
            return false;
    }
}
bool JouerMalus::peutEtreJoueeMalus(CardGame::_pc_Player pp,_pc_CarteMSL crt) const
{
    if(crt->getType()!=carteMalus){
        return false;
    }
    int indJoueur = getMonitor()->getIndPlayer(pp);
    for(int indice=0;indice<getMonitor()->getNbPlayer();indice++){
        if(indice==indJoueur){
            continue;
        }
        CardGame::_pc_Player Cible = getMonitor()->getPlayer(indice);
        if(peutEtreJoueeMalus(pp,crt->getSType(),Cible)){
            return true;
        }
    }
    return false;
}

void JouerMalus::jouerAccident(int indCible)const{
    getMonitor()->incStatut(indCible,TourAPasser,1);
}
void JouerMalus::jouerAttentat()const{
    for(int indPlayer=0;indPlayer<getMonitor()->getNbPlayer();indPlayer++){
        getMonitor()->defausserTout( indPlayer, EEnfant );
    }
}
void JouerMalus::jouerBurnout(int indCible)const{
    getMonitor()->incStatut(indCible,TourAPasser,1);
}
void JouerMalus::jouerDivorce(int indCible)const{
    getMonitor()->defausserTout( indCible, EMariage );
}
void JouerMalus::jouerImpots(int indCible)const{
    getMonitor()->defausserDernier( indCible, ESalairesD );
}
void JouerMalus::jouerLicenciement(int indCible)const{
    getMonitor()->defausserTout( indCible, EMetier );
}
void JouerMalus::jouerMaladie(int indCible)const{
    getMonitor()->incStatut(indCible,TourAPasser,1);
}
void JouerMalus::jouerPrison()const{
    for(int indPlayer=0;indPlayer<getMonitor()->getNbPlayer();indPlayer++){
        if(getMonitor()->getStatutGeneral(DetailPlateau::RisquePrison)){
            getMonitor()->defausserTout( indPlayer, EMetier );
            getMonitor()->incStatut(indPlayer,TourAPasser,3);
        }
    }
}
void JouerMalus::jouerRedoublement(int indCible)const{
    getMonitor()->defausserDernier( indCible, EEtudes );
}

bool JouerMalus::jouerCarteMalus(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    int indPlayer = getMonitor()->getIndPlayer(pp);
    IdCarte idCrt = crt->getId();
    CarteSousType cstCrt = crt->getSType();
    if(peutEtreJoueeMalus(pp,crt)==false){
        return false;
    }
    switch(cstCrt){
        //Malus se jouant au niveau général, sans cible particulière
        case csAttentat:
            jouerAttentat();
            getMonitor()->defausser(idCrt,indPlayer);
            return true;
        case csPrison:
            jouerPrison();
            getMonitor()->defausser(idCrt,indPlayer);
            return true;
        default:
            break;
    }
    CardGame::_pc_Player cible = getCible(pp,cstCrt);
    if(peutEtreJoueeMalus(pp,cstCrt,cible) == false ){
        return false;
    }
    int indCible = getMonitor()->getIndPlayer(cible);
    getMonitor()->addCarteToEP(indCible,EMalus,idCrt);
    switch(cstCrt){
        case csAccidents:
            jouerAccident(indCible);
            break;
        case csBurnOut:
            jouerBurnout(indCible);
            break;
        case csDivorce:
            jouerDivorce(indCible);
            break;
        case csImpotsRevenus:
            jouerImpots(indCible);
            break;
        case csLicenciement:
            jouerLicenciement(indCible);
            break;
        case csMaladie:
            jouerMaladie(indCible);
            break;
        case csRedoublement:
            jouerRedoublement(indCible);
            break;
        default:
            break;
    }
    return true;
}