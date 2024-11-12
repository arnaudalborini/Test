#include "JouerCarteMSL.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "MSLPlayer.hpp"
#include "PaquetCarte.hpp"

using MySmileLife::JouerCarteMSL;

MySmileLife::_pc_CarteMSL JouerCarteMSL::getCarteMSL(IdCarte id) const{return dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(id));}

bool JouerCarteMSL::peutEtreJouee(CardGame::_pc_Player pp, IdCarte id) const
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

bool JouerCarteMSL::jouerCarte(CardGame::_pc_Player pp, IdCarte id) const
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

MySmileLife::_pc_CarteGenerateurStandard JouerCarteMSL::getCGen() const{return dynamic_pointer_cast<const MySmileLife::CarteGenerateurStandard>(cGen.lock());}
CardGame::_pc_GameMechanicsMonitor JouerCarteMSL::getMonitor() const{return mMonitor.lock();}

bool JouerCarteMSL::peutEtreJoueeAnimal(CardGame::_pc_Player pp, _pc_CarteMSL crt) const{return true;}

bool JouerCarteMSL::peutEtreJoueeEnfant(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    if(plat->getStatut(estMarie)){
        return true;
    }
    if(plat->getStatut(NombreBebePossibleHorsMariage)>0){
        plat->incStatut(NombreBebePossibleHorsMariage,-1);
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
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

bool JouerCarteMSL::peutEtreJoueeFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
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

bool JouerCarteMSL::peutEtreJoueeMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    return (tresorerie>prix);
}

bool JouerCarteMSL::peutEtreJoueeMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    return (plat->getStatut(estMarie)==false) && (plat->getStatut(NombreFlirt)>0);
}

bool JouerCarteMSL::peutEtreJoueeSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    return (plat->getStatut(aUnTravail)>0) && (plat->getStatut(SalaireMax)>=crt->getSalaire());
}

bool JouerCarteMSL::peutEtreJoueeVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    return ( tresorerie > crt->getPrixVoyage() );
}

bool JouerCarteMSL::jouerCarteAnimal(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEnfant(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EEnfant,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    if(plat->getStatut(aUnTravail)==false){
        if(plat->getStatut(NbAnneeEtude) + crt->getNbEtude()<=6){
            mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EEtudes,crt->getId());
            mMonitor.lock()->getPlateauPlayer(pp)->setStatut(DerniereEtudeRedoublable,crt->getNbEtude());
        }
    }
    if(plat->getStatut(EtudesContinues)){
        mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EEtudesContinues,crt->getId());
    }
    mMonitor.lock()->getPlateauPlayer(pp)->incStatut(NbAnneeEtude,crt->getNbEtude());
    return true;
}

bool JouerCarteMSL::jouerCarteFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    if( plat->getStatut(estMarie) ){
        if(plat->getStatut(estAdultere)){
            mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EFlirtAdultere,crt->getId());
        }
    }else{
        if( (plat->getStatut(Profession)==csBarman) || (plat->getStatut(NombreFlirt)<5) ){
            mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EFlirt,crt->getId());
        }
    }
    return true;
}

void JouerCarteMSL::payer(CardGame::_pc_Player pp, CardGame::_p_Plateau plat, int prix)const{
    if(plat->getStatut(HeritageDisponible)>0){
        plat->setStatut(HeritageDisponible,0);
        prix-=3;
    }
    _pc_MSLPlayer mslPP = dynamic_pointer_cast<const MSLPlayer>(pp);   
    while(prix>0){
        const vector<IdCarte> vecId = plat->showAllIdByEP(ESalairesD);
        int indice = mslPP->choisirSalairePourPayer(vecId);
        indice = (indice<0)?0:indice;
        indice = (indice>vecId.size())?vecId.size()-1:indice;
        IdCarte id = plat->getNByEP(ESalairesD,indice);
        int salCrt = getCarteMSL(id)->getSalaire();
        plat->addCarteToEP(EDivers,id);
        plat->incStatut(SalairesDisponibles,-salCrt);
        prix -= salCrt;
    }
}

bool JouerCarteMSL::jouerCarteMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    payer(pp,plat,prix);
    plat->addCarteToEP(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(EMariage,crt->getId());
    mMonitor.lock()->getPlateauPlayer(pp)->setStatut(estMarie,true);
    return true;
}

bool JouerCarteMSL::jouerCarteSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    mMonitor.lock()->getPlateauPlayer(pp)->addCarteToEP(ESalairesD,crt->getId());
    mMonitor.lock()->getPlateauPlayer(pp)->incStatut(SalairesDisponibles,crt->getSalaire());
    return true;
}

bool JouerCarteMSL::jouerCarteVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{    
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    payer(pp,plat,crt->getPrixVoyage());
    plat->addCarteToEP(EDivers,crt->getId());
    return true;
}

void JouerCarteMSL::choisirEtJouerUneCarteDefausse(CardGame::_pc_Player pp) const
{
    int indiceCarte = pp->choisirUneCarte(mMonitor.lock()->getDefausse());
    IdCarte id = mMonitor.lock()->getDefausse()->piocherNeme( indiceCarte );
    if(peutEtreJouee(pp,id)){
        jouerCarte(pp,id);
    }
}

CardGame::_pc_Player JouerCarteMSL::getCible(CardGame::_pc_Player pp, IdCarte id) const
{
    int indCible = pp->choisirCible(id);
    return mMonitor.lock()->getPlayer(indCible);
}
