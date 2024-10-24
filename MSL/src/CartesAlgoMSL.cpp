#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;

const CarteMSL *CartesAlgoMSL::getCarteMSL(IdCarte id) const{return dynamic_cast<const CarteMSL*>( cGen->getCarteById(id) );;}

bool CartesAlgoMSL::peutEtreJoueeAnimal(const Player *pp, const CarteMSL *crt) const{return true;}

bool CartesAlgoMSL::peutEtreJoueeEnfant(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeEtude(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeFlirt(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMaison(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMariage(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeMetier(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeSalaire(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeSpecial(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::peutEtreJoueeVoyage(const Player *pp, const CarteMSL *crt) const
{
    return false;
}

bool CartesAlgoMSL::jouerCarteAnimal(const Player *pp, const CarteMSL *crt) const
{
    return false;
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