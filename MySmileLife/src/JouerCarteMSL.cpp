#include "JouerCarteMSL.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "MSLPlayer.hpp"
#include "PaquetCarte.hpp"

using MySmileLife::JouerCarteMSL;

int JouerCarteMSL::getStatut(CardGame::_pc_Player pp, int statut) const
{
    return mMonitor.lock()->getStatut(pp,statut);
}

void JouerCarteMSL::setStatut(CardGame::_pc_Player pp, int statut, int value) const
{
    mMonitor.lock()->setStatut(pp,statut,value);
}

void JouerCarteMSL::incStatut(CardGame::_pc_Player pp, int statut, int value) const
{
    mMonitor.lock()->incStatut(pp,statut,value);
}

void MySmileLife::JouerCarteMSL::addCarteToEP(CardGame::_pc_Player pp, int EP, IdCarte id) const{mMonitor.lock()->addCarteToEP(pp,EP,id);}

MySmileLife::_pc_CarteMSL JouerCarteMSL::getCarteMSL(IdCarte id) const { return dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(id)); }

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
    if(getStatut(pp,estMarie)){
        return true;
    }
    if(getStatut(pp,NombreBebePossibleHorsMariage)>0){
        incStatut(pp,NombreBebePossibleHorsMariage,-1);
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if(getStatut(pp,aUnTravail)==false){
        if(getStatut(pp,NbAnneeEtude) + crt->getParam()<=6){
            return true;
        }
    }
    if(getStatut(pp,EtudesContinues)){
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if( getStatut(pp,estMarie) ){
        if(getStatut(pp,estAdultere)){
            return true;
        }
    }else{
        if(getStatut(pp,Profession)==csBarman){
            return true;
        }else{
            if(getStatut(pp,NombreFlirt)<5){
                return true;
            }
        }
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    int prixBase = crt->getParam();
    int tresorerie = getStatut(pp,SalairesDisponibles) + (getStatut(pp,HeritageDisponible)?3:0);
    int prix = getStatut(pp,estMarie)?prixBase/2:prixBase;
    return (tresorerie>prix);
}

bool JouerCarteMSL::peutEtreJoueeMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    return (getStatut(pp,estMarie)==false) && (getStatut(pp,NombreFlirt)>0);
}

bool JouerCarteMSL::peutEtreJoueeSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    return (getStatut(pp,aUnTravail)>0) && (getStatut(pp,SalaireMax)>=crt->getParam());
}

bool JouerCarteMSL::peutEtreJoueeVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    int tresorerie = getStatut(pp,SalairesDisponibles) + (getStatut(pp,HeritageDisponible)?3:0);
    return ( tresorerie > crt->getParam() );
}

bool JouerCarteMSL::jouerCarteAnimal(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    addCarteToEP(pp,EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEnfant(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    addCarteToEP(pp,EEnfant,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if(getStatut(pp,aUnTravail)==false){
        if(getStatut(pp,NbAnneeEtude) + crt->getParam()<=6){
            addCarteToEP(pp,EEtudes,crt->getId());
            setStatut(pp,DerniereEtudeRedoublable,crt->getParam());
        }
    }
    if(getStatut(pp,EtudesContinues)){
        addCarteToEP(pp,EEtudesContinues,crt->getId());
    }
    incStatut(pp,NbAnneeEtude,crt->getParam());
    return true;
}

bool JouerCarteMSL::jouerCarteFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if( getStatut(pp,estMarie) ){
        if(getStatut(pp,estAdultere)){
            addCarteToEP(pp,EFlirt,crt->getId());
        }
    }else{
        if( (getStatut(pp,Profession)==csBarman) || (getStatut(pp,NombreFlirt)<5) ){
            addCarteToEP(pp,EFlirt,crt->getId());
        }
    }
    return true;
}

void JouerCarteMSL::payer(CardGame::_pc_Player pp, CardGame::_p_Plateau plat, int prix)const{
    if(getStatut(pp,HeritageDisponible)>0){
        setStatut(pp,HeritageDisponible,0);
        prix-=3;
    }
    _pc_MSLPlayer mslPP = dynamic_pointer_cast<const MSLPlayer>(pp);   
    while(prix>0){
        const vector<IdCarte> vecId = plat->showAllIdByEP(ESalairesD);
        int indice = mslPP->choisirSalairePourPayer(vecId);
        indice = (indice<0)?0:indice;
        indice = (indice>static_cast<int>(vecId.size()))?vecId.size()-1:indice;
        IdCarte id = plat->getNByEP(ESalairesD,indice);
        int salCrt = getCarteMSL(id)->getParam();
        addCarteToEP(pp,EDivers,id);
        incStatut(pp,SalairesDisponibles,-salCrt);
        prix -= salCrt;
    }
}

bool JouerCarteMSL::jouerCarteMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    int prixBase = crt->getParam();
    int prix = getStatut(pp,estMarie)?prixBase/2:prixBase;
    payer(pp,plat,prix);
    addCarteToEP(pp,EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    addCarteToEP(pp,EMariage,crt->getId());
    setStatut(pp,estMarie,true);
    return true;
}

bool JouerCarteMSL::jouerCarteSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    addCarteToEP(pp,ESalairesD,crt->getId());
    incStatut(pp,SalairesDisponibles,crt->getParam());
    return true;
}

bool JouerCarteMSL::jouerCarteVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{    
    CardGame::_p_Plateau plat = mMonitor.lock()->getPlateauPlayer(pp);
    payer(pp,plat,crt->getParam());
    addCarteToEP(pp,EDivers,crt->getId());
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
