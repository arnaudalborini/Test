#include "CartesAlgoMSL.hpp"
#include "CarteGenerator.hpp"
#include "CarteMSL.hpp"
#include "Plateau.hpp"

using MySmileLife::CartesAlgoMSL;

int CartesAlgoMSL::getNbSmile(CardGame::_pc_Plateau pp, IdCarte id) const {
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(id));
  if ((crt->getType() == carteAnimal) && (crt->getSType() == csLicorne)) {
    if ((pp->getStatut(DetailPlateau::ArcEnCielJoue)) &&
        (pp->getStatut(DetailPlateau::EtoileFilanteJouee))) {
      return crt->getNbSmile() * 2;
    }
  }
  return crt->getNbSmile();
}

void CartesAlgoMSL::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP) {
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  mEffet->effetQuitterPlateau(indPlayer,crt, static_cast<EmplacementsPlateau>(EP));
}
void CartesAlgoMSL::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  mEffet->effetQuitterHand(indPlayer,crt);
}
void MySmileLife::CartesAlgoMSL::effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP)
{
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  mEffet->effetEntrerPlateau(indPlayer,crt, static_cast<EmplacementsPlateau>(EP));
}

void MySmileLife::CartesAlgoMSL::effetEntrerHand(const int indPlayer, const IdCarte idCrt)
{
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  mEffet->effetEntrerHand(indPlayer,crt);
}
