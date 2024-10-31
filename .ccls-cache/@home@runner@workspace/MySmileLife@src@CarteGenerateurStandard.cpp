#include "CarteGenerateurStandard.hpp"
#include "MySmileLife.hpp"

#include "Carte.hpp"
#include "CarteMSL.hpp"
#include "MyShuffle.hpp"
#include "CartesMSLConfig.hpp"

using namespace MySmileLife;

CarteGenerateurStandard::CarteGenerateurStandard() {
  for(auto elt:vecMSLCarte){
    mMapMSLCarte[{elt.cType, elt.csType}].insert(elt.id);
    addCarte( new CarteMSL(elt.id, elt.nom, elt.nbSmile, elt.cType, elt.csType));
  }
}

void CarteGenerateurStandard::genCartesPioche(vector<IdCarte> &vecCartes) {
  for(auto elt:vecMSLCarte){
    for(auto ind=0;ind<elt.nbCarte;ind++){
      vecCartes.push_back(elt.id);
    }
  }
  //CardGame::myShuffle(vecCartes);
}

IdCarte CarteGenerateurStandard::getCarteByType(CarteType ct, CarteSousType cst, string nom)const {
  set<IdCarte> sId = getSetIdCarte(ct, cst);
  for (auto elt : sId) {
      
    if (dynamic_cast<const CarteMSL*>( getCarteById(elt) )->getName() == nom) {
      return elt;
    }
  }
  return -1;
}

IdCarte CarteGenerateurStandard::getCarteByType(CarteType ct, CarteSousType cst)const {
  return getFirstSetIdCarte(ct, cst);
}
