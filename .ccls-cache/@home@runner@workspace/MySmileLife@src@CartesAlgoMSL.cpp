#include "CartesAlgoMSL.hpp"
#include "CarteGenerator.hpp"
#include "CarteMSL.hpp"
#include "Plateau.hpp"

using MySmileLife::CartesAlgoMSL;

int CartesAlgoMSL::getNbSmile(const Plateau *pp, IdCarte id) const {
  const CarteMSL *crt = dynamic_cast<const CarteMSL *>(cGen->getCarteById(id));
  if ((crt->getType() == carteAnimal) && (crt->getSType() == csLicorne)) {
    if ((pp->getStatut(DetailPlateau::ArcEnCielJoue)) &&
        (pp->getStatut(DetailPlateau::EtoileFilanteJouee))) {
      return crt->getNbSmile() * 2;
    }
  }
  return crt->getNbSmile();
}

void CartesAlgoMSL::effetQuitterPlateau(const int indPlayer,
                                        const CardGame::IdCarte idCrt) {
  cout << "CartesAlgoMSL::effetQuitterPlateau" << endl;
  const CarteMSL *crt =
      dynamic_cast<const CarteMSL *>(cGen->getCarteById(idCrt));
  cout << "CartesAlgoMSL::effetQuitterPlateau: indPlayer " << indPlayer
       << " crt: " << crt->getName() << endl;
}
void CartesAlgoMSL::effetQuitterHand(const int indPlayer,
                                     const CardGame::IdCarte idCrt) {
  cout << "CartesAlgoMSL::effetQuitterHand" << endl;
  const CarteMSL *crt =
      dynamic_cast<const CarteMSL *>(cGen->getCarteById(idCrt));
  cout << "CartesAlgoMSL::effetQuitterHand: indPlayer " << indPlayer
       << " crt: " << crt->getName() << endl;
}