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
    if(crt->getSType()==csCasino){
        getMonitor()->getPlateau()->addLast(ESpecial,crt->getId());
    }else{
        getMonitor()->getPlateauPlayer(pp)->addLast(ESpecial,crt->getId());
    }
    switch(crt->getSType()){
        case csAdultere:
            jouerAdultere(pp);
            break;
        case csTroc:
            jouerTroc(pp);
            break;
        case csCasino:
            jouerCasino(pp);
            break;
        case csChance:
            jouerChance(pp);
            break;
        case csPiston:
            jouerPiston(pp);
            break;
        case csAnniversaire:
            jouerAnniversaire(pp);
            break;
        case csArcEnCiel:
            jouerArcEnCiel(pp);
            break;
        case csEtoileFilante:
            jouerEtoileFilante(pp);
            break;
        case csHeritage:
            jouerHeritage(pp);
            break;
        case csTsunami:
            jouerTsunami(pp);
            break;
        case csVengeance:
            jouerVengeance(pp);
            break;
        case csLegionHonneur:
            jouerLegionHonneur(pp);
            break;
        case csGrandPrixExcellence:
            jouerGrandPrix(pp);
            break;
    }
    return true;
}

void JouerSpecial::jouerAdultere(const Player *pp) const
{
    getMonitor()->getPlateauPlayer(pp)->setStatut(estAdultere,1);
}

void JouerSpecial::jouerTroc(const Player *pp) const
{
    //TODO
}

void JouerSpecial::jouerCasino(const Player *pp) const
{
    getMonitor()->getPlateau()->setStatut(casinoOuvert,1);
}

void JouerSpecial::jouerChance(const Player *pp) const
{
    //TODO
}

void JouerSpecial::jouerPiston(const Player *pp) const
{
    getMonitor()->getPlateauPlayer(pp)->setStatut(PistonActif,1);
}

void JouerSpecial::jouerAnniversaire(const Player *pp) const
{
    //TODO
}

void JouerSpecial::jouerArcEnCiel(const Player *pp) const
{
    //TODO: jouer 3 cartes et repriochez
    getMonitor()->getPlateauPlayer(pp)->setStatut(ArcEnCielJoue,1);
}

void JouerSpecial::jouerEtoileFilante(const Player *pp) const
{
    choisirEtJouerUneCarteDefausse(pp);
}

void JouerSpecial::jouerHeritage(const Player *pp) const
{
    getMonitor()->getPlateauPlayer(pp)->setStatut(HeritageDisponible,3);
}

void JouerSpecial::jouerTsunami(const Player *pp) const
{
    //TODO
}

void JouerSpecial::jouerVengeance(const Player *pp) const
{
    //TODO
}

void JouerSpecial::jouerLegionHonneur(const Player *pp) const
{
    //rien à faire
}

void JouerSpecial::jouerGrandPrix(const Player *pp) const
{
    getMonitor()->getPlateauPlayer(pp)->setStatut(SalaireMax,4);
}
