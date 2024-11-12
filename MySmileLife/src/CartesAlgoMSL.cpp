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

void CartesAlgoMSL::effetQuitterPlateau(const int indPlayer,
                                        const IdCarte idCrt, int EP) {
  cout << "CartesAlgoMSL::effetQuitterPlateau" << endl;
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  cout << "CartesAlgoMSL::effetQuitterPlateau: indPlayer " << indPlayer << " crt: " << crt->getName() << endl;
  mEffet->effetQuitterPlateau(indPlayer,crt, static_cast<EmplacementsPlateau>(EP));
}
void CartesAlgoMSL::effetQuitterHand(const int indPlayer,
                                     const CardGame::IdCarte idCrt) {
  cout << "CartesAlgoMSL::effetQuitterHand" << endl;
  _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(idCrt));
  cout << "CartesAlgoMSL::effetQuitterHand: indPlayer " << indPlayer << " crt: " << crt->getName() << endl;
  mEffet->effetQuitterHand(indPlayer,crt);
}