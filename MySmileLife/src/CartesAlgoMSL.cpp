#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

const CarteMSL *CartesAlgoMSL::getCarteMSL(IdCarte id) const{return dynamic_cast<const CarteMSL*>( cGen->getCarteById(id) );;}

Plateau *MySmileLife::CartesAlgoMSL::getPlateauPlayer(const Player *pp) const
{
    return mMonitor->getInfosJoueurs(mMonitor->getIndPlayer(pp))->getPlateau();
}

bool CartesAlgoMSL::peutEtreJoueeAnimal(const Player *pp, const CarteMSL *crt) const{return true;}

bool CartesAlgoMSL::peutEtreJoueeEnfant(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    if(plat->getStatut(estMarie)){
        return true;
    }
    if(plat->getStatut(NombreBebePossibleHorsMariage)>0){
        plat->incStatut(NombreBebePossibleHorsMariage,-1);
        return true;
    }
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeEtude(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
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

bool CartesAlgoMSL::peutEtreJoueeFlirt(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    if( plat->getStatut(estMarie) ){
        if(plat->getStatut(estAdultere)){
            return true;
        }
    }else{
        if(plat->getStatut(DetailPlateau::TypeMetier)==csBarman){
            return true;
        }else{
            if(plat->getStatut(DetailPlateau::NbFlirt)<5){
                return true;
            }
        }
    }
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMaison(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    int prixBase = crt->getPrixMaison();
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    int prix = plat->getStatut(estMarie)?prixBase/2:prixBase;
    return (tresorerie>prix);
}

bool CartesAlgoMSL::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMariage(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    return (plat->getStatut(estMarie)==false) && (plat->getStatut(NbFlirt)>0);
}

bool CartesAlgoMSL::peutEtreJoueeSalaire(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    return (plat->getStatut(aUnTravail)>0) && (plat->getStatut(SalaireMax)>=crt->getSalaire());
}

bool CartesAlgoMSL::peutEtreJoueeSpecial(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeVoyage(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    int tresorerie = plat->getStatut(SalairesDisponibles) + (plat->getStatut(HeritageDisponible?3:0));
    return ( tresorerie > crt->getPrixVoyage() );
}

bool CartesAlgoMSL::jouerCarteAnimal(const Player *pp, const CarteMSL *crt) const
{
    cout << "jouerCarteAnimal ---- "<<endl;
    cout << "getIndPlayer : "<< pp << "    " << mMonitor << endl;
    cout << mMonitor->getNbPlayer() << endl;
    /*cout << mMonitor->getInfosJoueurs(0) << endl;
    cout << mMonitor->getPlayer(0) << endl;
    cout << mMonitor->getPlayer(1) << endl;
    int indPlayer = mMonitor->getIndPlayer(pp);
    cout << "getInfosJoueurs  "<<endl;
    InfosJoueur * infP = mMonitor->getInfosJoueurs(indPlayer);
    cout << "getPlateau  "<<endl;
    Plateau* plat = infP->getPlateau();
    cout << "addLast  "<<endl;
    plat->addLast(EmplacementsPlateau::EDivers, crt->getId());
    cout << "addlast<<endl";*/
    return true;
}

bool CartesAlgoMSL::jouerCarteEnfant(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteEtude(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteFlirt(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteMaison(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteMalus(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteMariage(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteMetier(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteSalaire(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteSpecial(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteVoyage(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJouee(const Player *pp, IdCarte id) const
{
    const CarteMSL* crt = getCarteMSL( id );
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

bool CartesAlgoMSL::jouerCarte(const Player *pp, IdCarte id) const
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

int CartesAlgoMSL::getNbSmile(const Plateau *pp, IdCarte id) const
{
    const CarteMSL* crt = getCarteMSL( id );
    if( (crt->getType()==carteAnimal) && ( crt->getSType() == csLicorne) ){
        if((pp->getStatut(DetailPlateau::ArcEnCielJoue))&&(pp->getStatut(DetailPlateau::EtoileFilanteJouee))){
            return crt->getNbSmile() * 2;
        }
    }
    return crt->getNbSmile();
}
