#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

#include "JouerCarteMSL.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

int CartesAlgoMSL::getNbSmile(const Plateau *pp, IdCarte id) const
{
    const CarteMSL* crt = dynamic_cast<const CarteMSL*>( cGen->getCarteById( id ));
    if( (crt->getType()==carteAnimal) && ( crt->getSType() == csLicorne) ){
        if((pp->getStatut(DetailPlateau::ArcEnCielJoue))&&(pp->getStatut(DetailPlateau::EtoileFilanteJouee))){
            return crt->getNbSmile() * 2;
        }
    }
    return crt->getNbSmile();
}
