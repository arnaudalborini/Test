#include "JouerSpecial.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

#include "JouerSpecial.hpp"
#include "JouerCarteMSL.hpp"

using MySmileLife::JouerSpecial;
using MySmileLife::JouerMalus;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

using MySmileLife::EmplacementsPlateau;
using MySmileLife::DetailPlateau;
using MySmileLife::CarteSousType;

/*
        csAdultere,
        csTroc,
        csCasino,
        csChance,
        csPiston,
        csAnniversaire,
        csArcEnCiel,
        csEtoileFilante,
        csHeritage,
        csTsunami,
        csVengeance,
        csLegionHonneur,
        csGrandPrixExcellence,
*/

bool isMarriedButNotAdulterous( const Plateau* plat ){ return ((plat->getStatut(MySmileLife::estMarie))&&(plat->getStatut(MySmileLife::estAdultere)==false));}
bool hasEligibleProfession( const Plateau* plat )
{ 
    if(plat->getStatut(MySmileLife::aUnTravail)){
        switch(plat->getStatut(MySmileLife::Profession)){
            case MySmileLife::csJournaliste:
            case MySmileLife::csEcrivain:
            case MySmileLife::csChercheur:
                return true;
            default:
                return false;
        }
    }else{
        return false;
    }
}
bool canPlayMalusCard( const Plateau* plat, const Player* pp, const MySmileLife::JouerCarteMSL* jCarte ){
    int nbMalus = plat->getNbCarte(EmplacementsPlateau::EMalus);
    for(auto indice=0; indice<nbMalus;indice++){
        int IdMalus = plat->showIdN(EmplacementsPlateau::EMalus,indice);
        if( jCarte->peutEtreJouee(pp,IdMalus)){
            return true;
        }
    }
    return false;
}

bool JouerSpecial::peutEtreJoueeSpecial(const Player *pp, const CarteMSL *crt) const
{
    if(crt->getType()!=carteSpecial){
        return false;
    }
    Plateau* plat = getMonitor()->getPlateauPlayer(pp);
    switch(crt->getSType()){
        case csAdultere:
            return isMarriedButNotAdulterous(plat);
        case csGrandPrixExcellence:
            return hasEligibleProfession(plat);
        case csVengeance:
            return canPlayMalusCard(plat,pp,dynamic_cast<const JouerCarteMSL*>(this));
        default:
            return true;
    }
}

bool JouerSpecial::jouerCarteSpecial(const Player *pp, const CarteMSL *crt) const
{
    if(peutEtreJoueeSpecial(pp,crt)==false){
        return false;
    }
    
    return true;
}