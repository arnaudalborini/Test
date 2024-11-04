#include "CarteGenerateurStandard.hpp"
#include "MySmileLife.hpp"

#include "Carte.hpp"
#include "CarteMSL.hpp"
#include "MyShuffle.hpp"
#include "CartesMSLConfig.hpp"

using MySmileLife::CarteGenerateurStandard;

CarteGenerateurStandard::CarteGenerateurStandard() {
  for(auto elt:vecMSLCarte){
    mMapMSLCarte[{elt.cType, elt.csType}].insert(elt.id);
    CardGame::_pc_Carte pcCrt = make_shared<const CarteMSL>(elt.id, elt.nom, elt.nbSmile, elt.cType, elt.csType);
    addCarte(pcCrt );
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

CardGame::IdCarte CarteGenerateurStandard::getCarteByType(CarteType ct, CarteSousType cst, string nom)const {
  set<IdCarte> sId = getSetIdCarte(ct, cst);
  for (auto elt : sId) {
    _pc_CarteMSL pcCmsl = std::dynamic_pointer_cast<const CarteMSL>(getCarteById(elt));
    if (pcCmsl->getName() == nom) {
      return elt;
    }
  }
  return -1;
}

CardGame::IdCarte CarteGenerateurStandard::getCarteByType(CarteType ct, CarteSousType cst)const {
  return getFirstSetIdCarte(ct, cst);
}
CardGame::IdCarte CarteGenerateurStandard::getFirstSetIdCarte(CarteType ct, CarteSousType cst)const{

  return (mMapMSLCarte.has({ct,cst}))?*(mMapMSLCarte[{ct,cst}].begin()):-1;
}