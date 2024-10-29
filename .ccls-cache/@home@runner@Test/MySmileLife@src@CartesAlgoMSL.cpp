#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "Plateau.hpp"

using MySmileLife::CartesAlgoMSL;

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
