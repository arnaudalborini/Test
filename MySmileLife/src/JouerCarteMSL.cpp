#include "JouerCarteMSL.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "MSLPlayer.hpp"
#include "PaquetCarte.hpp"

using MySmileLife::JouerCarteMSL;
using MySmileLife::_pc_CarteMSL;

_pc_CarteMSL JouerCarteMSL::getCarteMSL(IdCarte id) const{return dynamic_pointer_cast<const CarteMSL>(cGen->getCarteById(id));}

bool JouerCarteMSL::peutEtreJouee(_pc_Player pp, IdCarte id) const
{
    _pc_CarteMSL crt = getCarteMSL( id );
    switch( crt->getType() ){
        case CarteType::carteAnimal:
            return peutEtreJoueeAnimal(pp,crt);
        case CarteType::carteEnfant:
            return peutEtreJoueeEnfant(pp,crt);
        case CarteType::carteEtude:
            return peutEtreJoueeEtude(pp,crt);
        case CarteType::carteFlirt:
            return peutEtreJoueeFlirt(pp,crt);
        case CarteType::carteMaison:
            return peutEtreJoueeMaison(pp,crt);
        case CarteType::carteMalus:
            return peutEtreJoueeMalus(pp,crt);
        case CarteType::carteMariage:
            return peutEtreJoueeMariage(pp,crt);
        case CarteType::carteMetier:
            return peutEtreJoueeMetier(pp,crt);
        case CarteType::carteSalaire:
            return peutEtreJoueeSalaire(pp,crt);
        case CarteType::carteSpecial:
            return peutEtreJoueeSpecial(pp,crt);
        case CarteType::carteVoyage:
            return peutEtreJoueeVoyage(pp,crt);
    }
    return false;
}

bool JouerCarteMSL::jouerCarte(_pc_Player pp, IdCarte id) const
{
    if(peutEtreJouee(pp,id)==false){
        return false;
    }
    _pc_CarteMSL crt = getCarteMSL( id );
    switch( crt->getType() ){
        case CarteType::carteAnimal:
            return jouerCarteAnimal(pp,crt);
        case CarteType::carteEnfant:
            return jouerCarteEnfant(pp,crt);
        case CarteType::carteEtude:
            return jouerCarteEtude(pp,crt);
        case CarteType::carteFlirt:
            return jouerCarteFlirt(pp,crt);
        case CarteType::carteMaison:
            return jouerCarteMaison(pp,crt);
        case CarteType::carteMalus:
            return jouerCarteMalus(pp,crt);
        case CarteType::carteMariage:
            return jouerCarteMariage(pp,crt);
        case CarteType::carteMetier:
            return jouerCarteMetier(pp,crt);
        case CarteType::carteSalaire:
            return jouerCarteSalaire(pp,crt);
        case CarteType::carteSpecial:
            return jouerCarteSpecial(pp,crt);
        case CarteType::carteVoyage:
            return jouerCarteVoyage(pp,crt);
    }
    return false;
}

MySmileLife::_pc_CarteGenerateurStandard MySmileLife::JouerCarteMSL::getCGen() const{return dynamic_pointer_cast<const MySmileLife::CarteGenerateurStandard>(cGen);}
CardGame::_pc_GameMechanicsMonitor MySmileLife::JouerCarteMSL::getMonitor() const{return mMonitor;}

bool JouerCarteMSL::peutEtreJoueeAnimal(_pc_Player pp, _pc_CarteMSL crt) const{return true;}

bool JouerCarteMSL::peutEtreJoueeEnfant(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(estMarie)){
        return true;
    }
    if(plat->getStatut(NombreBebePossibleHorsMariage)>0){
        plat->incStatut(NombreBebePossibleHorsMariage,-1);
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeEtude(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(aUnTravail)==false){
        if(plat->getStatut(NbAnneeEtude) + crt->getNbEtude()<=6){
            return true;
        }
    }
    if(plat->getStatut(EtudesContinues)){
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeFlirt(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if( plat->getStatut(estMarie) ){
        if(plat->getStatut(estAdultere)){
            return true;
        }
    }else{
        if(plat->getStatut(Profession)==csBarman){
            return true;
        }else{
            if(plat->getStatut(NombreFlirt)<5){
                return true;
            }
        }
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeMaison(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    return (tresorerie>prix);
}

bool JouerCarteMSL::peutEtreJoueeMariage(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    return (plat->getStatut(estMarie)==false) && (plat->getStatut(NombreFlirt)>0);
}

bool JouerCarteMSL::peutEtreJoueeSalaire(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    return (plat->getStatut(aUnTravail)>0) && (plat->getStatut(SalaireMax)>=crt->getSalaire());
}

bool JouerCarteMSL::peutEtreJoueeVoyage(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    return ( tresorerie > crt->getPrixVoyage() );
}

bool JouerCarteMSL::jouerCarteAnimal(_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEnfant(_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EEnfant,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEtude(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(aUnTravail)==false){
        if(plat->getStatut(NbAnneeEtude) + crt->getNbEtude()<=6){
            mMonitor->getPlateauPlayer(pp)->addLast(EEtudes,crt->getId());
            mMonitor->getPlateauPlayer(pp)->setStatut(DerniereEtudeRedoublable,crt->getNbEtude());
        }
    }
    if(plat->getStatut(EtudesContinues)){
        mMonitor->getPlateauPlayer(pp)->addLast(EEtudesContinues,crt->getId());
    }
    mMonitor->getPlateauPlayer(pp)->incStatut(NbAnneeEtude,crt->getNbEtude());
    return true;
}

bool JouerCarteMSL::jouerCarteFlirt(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if( plat->getStatut(estMarie) ){
        if(plat->getStatut(estAdultere)){
            mMonitor->getPlateauPlayer(pp)->addLast(EFlirtAdultere,crt->getId());
        }
    }else{
        if( (plat->getStatut(Profession)==csBarman) || (plat->getStatut(NombreFlirt)<5) ){
            mMonitor->getPlateauPlayer(pp)->addLast(EFlirt,crt->getId());
        }
    }
    return true;
}

void JouerCarteMSL::payer(_pc_Player pp, _p_Plateau plat, int prix)const{
    if(plat->getStatut(HeritageDisponible?3:0)){
        plat->setStatut(HeritageDisponible,0);
        prix-=3;
    }
    _pc_MSLPlayer mslPP = dynamic_pointer_cast<const MSLPlayer>(pp);   
    while(prix>0){
        const vector<IdCarte> vecId = plat->showAllIdByEP(ESalairesD);
        int indice = mslPP->choisirSalairePourPayer(vecId);
        indice = (indice<0)?0:indice;
        indice = (indice>vecId.size())?vecId.size()-1:indice;
        IdCarte id = plat->getN(ESalairesD,indice);
        int salCrt = getCarteMSL(id)->getSalaire();
        plat->addLast(EDivers,id);
        plat->incStatut(SalairesDisponibles,-salCrt);
        prix -= salCrt;
    }
}

bool JouerCarteMSL::jouerCarteMaison(_pc_Player pp, _pc_CarteMSL crt) const
{
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    payer(pp,plat,prix);
    plat->addLast(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteMariage(_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EMariage,crt->getId());
    mMonitor->getPlateauPlayer(pp)->setStatut(estMarie,true);
    return true;
}

bool JouerCarteMSL::jouerCarteSalaire(_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(ESalairesD,crt->getId());
    mMonitor->getPlateauPlayer(pp)->incStatut(SalairesDisponibles,crt->getSalaire());
    return true;
}

bool JouerCarteMSL::jouerCarteVoyage(_pc_Player pp, _pc_CarteMSL crt) const
{    
    _p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    payer(pp,plat,crt->getPrixVoyage());
    plat->addLast(EDivers,crt->getId());
    return true;
}

void JouerCarteMSL::choisirEtJouerUneCarteDefausse(_pc_Player pp) const
{
    int indiceCarte = pp->choisirUneCarte(mMonitor->getDefausse());
    IdCarte id = mMonitor->getDefausse()->piocherNeme( indiceCarte );
    if(peutEtreJouee(pp,id)){
        jouerCarte(pp,id);
    }
}

CardGame::_pc_Player JouerCarteMSL::getCible(_pc_Player pp, IdCarte id) const
{
    int indCible = pp->choisirCible(id);
    return mMonitor->getPlayer(indCible);
}
