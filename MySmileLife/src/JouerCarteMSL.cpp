#include "JouerCarteMSL.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Player.hpp"
#include "PaquetCarte.hpp"

using MySmileLife::JouerCarteMSL;
using MySmileLife::CarteMSL;

const CarteMSL *JouerCarteMSL::getCarteMSL(IdCarte id) const{return dynamic_cast<const CarteMSL*>( cGen->getCarteById(id) );;}

bool JouerCarteMSL::peutEtreJouee(const Player *pp, IdCarte id) const
{
    const CarteMSL* crt = getCarteMSL( id );
    cout << "JouerCarteMSL::peutEtreJouee: "<< id << " - " << crt->getName() << endl;
    switch( crt->getType() ){
        case CarteType::carteAnimal:
            cout << "carteAnimal" << endl;
            return peutEtreJoueeAnimal(pp,crt);
        case CarteType::carteEnfant:
            cout << "carteEnfant" << endl;
            return peutEtreJoueeEnfant(pp,crt);
        case CarteType::carteEtude:
            cout << "carteEtude" << endl;
            return peutEtreJoueeEtude(pp,crt);
        case CarteType::carteFlirt:
            cout << "carteFlirt" << endl;
            return peutEtreJoueeFlirt(pp,crt);
        case CarteType::carteMaison:
            cout << "carteMaison" << endl;
            return peutEtreJoueeMaison(pp,crt);
        case CarteType::carteMalus:
            cout << "carteMalus" << endl;
            return peutEtreJoueeMalus(pp,crt);
        case CarteType::carteMariage:
            cout << "carteMariage" << endl;
            return peutEtreJoueeMariage(pp,crt);
        case CarteType::carteMetier:
            cout << "carteMetier" << endl;
            return peutEtreJoueeMetier(pp,crt);
        case CarteType::carteSalaire:
            cout << "carteSalaire" << endl;
            return peutEtreJoueeSalaire(pp,crt);
        case CarteType::carteSpecial:
            cout << "carteSpecial" << endl;
            return peutEtreJoueeSpecial(pp,crt);
        case CarteType::carteVoyage:
            cout << "carteVoyage" << endl;
            return peutEtreJoueeVoyage(pp,crt);
    }
    return false;
}

bool JouerCarteMSL::jouerCarte(const Player *pp, IdCarte id) const
{
    if(peutEtreJouee(pp,id)==false){
        return false;
    }
    const CarteMSL* crt = getCarteMSL( id );
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

const MySmileLife::CarteGenerateurStandard *MySmileLife::JouerCarteMSL::getCGen() const{return dynamic_cast<const MySmileLife::CarteGenerateurStandard *>(cGen);}
const CardGame::GameMechanicsMonitor *MySmileLife::JouerCarteMSL::getMonitor() const{return mMonitor;}

bool JouerCarteMSL::peutEtreJoueeAnimal(const Player *pp, const CarteMSL *crt) const{return true;}

bool JouerCarteMSL::peutEtreJoueeEnfant(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(estMarie)){
        return true;
    }
    if(plat->getStatut(NombreBebePossibleHorsMariage)>0){
        plat->incStatut(NombreBebePossibleHorsMariage,-1);
        return true;
    }
    return false;
}

bool JouerCarteMSL::peutEtreJoueeEtude(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
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

bool JouerCarteMSL::peutEtreJoueeFlirt(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
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

bool JouerCarteMSL::peutEtreJoueeMaison(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    return (tresorerie>prix);
}

bool JouerCarteMSL::peutEtreJoueeMariage(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    return (plat->getStatut(estMarie)==false) && (plat->getStatut(NombreFlirt)>0);
}

bool JouerCarteMSL::peutEtreJoueeSalaire(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    return (plat->getStatut(aUnTravail)>0) && (plat->getStatut(SalaireMax)>=crt->getSalaire());
}

bool JouerCarteMSL::peutEtreJoueeVoyage(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    return ( tresorerie > crt->getPrixVoyage() );
}

bool JouerCarteMSL::jouerCarteAnimal(const Player *pp, const CarteMSL *crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEnfant(const Player *pp, const CarteMSL *crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EEnfant,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteEtude(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
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

bool JouerCarteMSL::jouerCarteFlirt(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
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

void JouerCarteMSL::payer(const Player* pp, Plateau* plat, int prix)const{
    if(plat->getStatut(HeritageDisponible?3:0)){
        plat->setStatut(HeritageDisponible,0);
        prix-=3;
    }
    while(prix>0){
        const vector<IdCarte> vecId = plat->showAllIdByEP(ESalairesD);
        int indice = pp->choisirSalairePourPayer(vecId);
        indice = (indice<0)?0:indice;
        indice = (indice>vecId.size())?vecId.size()-1:indice;
        IdCarte id = plat->getN(ESalairesD,indice);
        int salCrt = getCarteMSL(id)->getSalaire();
        plat->addLast(EDivers,id);
        plat->incStatut(SalairesDisponibles,-salCrt);
        prix -= salCrt;
    }
}

bool JouerCarteMSL::jouerCarteMaison(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    payer(pp,plat,prix);
    plat->addLast(EDivers,crt->getId());
    return true;
}

bool JouerCarteMSL::jouerCarteMariage(const Player *pp, const CarteMSL *crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(EMariage,crt->getId());
    mMonitor->getPlateauPlayer(pp)->setStatut(estMarie,true);
    return true;
}

bool JouerCarteMSL::jouerCarteSalaire(const Player *pp, const CarteMSL *crt) const
{
    mMonitor->getPlateauPlayer(pp)->addLast(ESalairesD,crt->getId());
    mMonitor->getPlateauPlayer(pp)->incStatut(SalairesDisponibles,crt->getSalaire());
    return true;
}

bool JouerCarteMSL::jouerCarteVoyage(const Player *pp, const CarteMSL *crt) const
{    
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    payer(pp,plat,crt->getPrixVoyage());
    plat->addLast(EDivers,crt->getId());
    return true;
}

void JouerCarteMSL::choisirEtJouerUneCarteDefausse(const Player *pp) const
{
    int indiceCarte = pp->choisirUneCarteAJouer(mMonitor->getDefausse());
    IdCarte id = mMonitor->getDefausse()->piocherNeme( indiceCarte );
    if(peutEtreJouee(pp,id)){
        jouerCarte(pp,id);
    }
}

const CardGame::Player *JouerCarteMSL::getCible(const Player *pp, IdCarte id) const
{
    int indCible = pp->choisirCible(id);
    return mMonitor->getPlayer(indCible);
}
