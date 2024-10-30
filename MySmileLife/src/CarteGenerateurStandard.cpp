#include "CarteGenerateurStandard.hpp"
#include "MySmileLife.hpp"

#include "Carte.hpp"
#include "CarteMSL.hpp"
#include "MyShuffle.hpp"

using namespace MySmileLife;

CarteGenerateurStandard::CarteGenerateurStandard() : cptId(-1) {
  addMetier();
  addEtude();
  addSalaire();
  addSpecial();
  addEnfant();
  addFlirt();
  ;
  addMarriage();
  addMalus();
  addAnimal();
  addVoyage();
  addMaison();
}

void CarteGenerateurStandard::genCartesPioche(vector<IdCarte> &vecCartes) {
  cout << "CarteGenerateurStandard::genCartesPioche" << endl;
  IdCarte id;
  map<int, set<IdCarte>> mapCT = mmapMSLCarte.getMapByKey1(carteMetier);
  for (auto sIC : mapCT) {
    for (auto id : sIC.second) {
      vecCartes.push_back(id);
    }
  }
  id = getFirstSetIdCarte(carteEtude, csEtudeSimple);
  for (int i = 0; i < 22; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteEtude, csEtudeDouble);
  for (int i = 0; i < 3; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteSalaire, csSalaire1);
  for (int i = 0; i < 10; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteSalaire, csSalaire2);
  for (int i = 0; i < 10; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteSalaire, csSalaire3);
  for (int i = 0; i < 10; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteSalaire, csSalaire4);
  for (int i = 0; i < 10; i++) {
    vecCartes.push_back(id);
  }
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csAnniversaire));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csArcEnCiel));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csCasino));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csChance));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csEtoileFilante));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csHeritage));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csPiston));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csTroc));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csTsunami));
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csVengeance));
  id = getFirstSetIdCarte(carteSpecial, csAdultere);
  for (int i = 0; i < 3; i++) {
    vecCartes.push_back(id);
  }
  vecCartes.push_back(getFirstSetIdCarte(carteSpecial, csLegionHonneur));
  id = getFirstSetIdCarte(carteSpecial, csGrandPrixExcellence);
  for (int i = 0; i < 2; i++) {
    vecCartes.push_back(id);
  }
  mapCT = mmapMSLCarte.getMapByKey1(carteEnfant);
  for (auto mapS : mapCT) {
    for (IdCarte idC : mapS.second) {
      vecCartes.push_back(idC);
    }
  }
  mapCT = mmapMSLCarte.getMapByKey1(carteFlirt);
  for (auto mapS : mapCT) {
    for (IdCarte idC : mapS.second) {
      for (int i = 0; i < 2; i++) {
        vecCartes.push_back(idC);
      }
    }
  }
  id = getFirstSetIdCarte(carteMariage, csAucun);
  for (int i = 0; i < 7; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csAccidents);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csBurnOut);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csDivorce);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csImpotsRevenus);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csLicenciement);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csMaladie);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMalus, csRedoublement);
  for (int i = 0; i < 5; i++) {
    vecCartes.push_back(id);
  }
  vecCartes.push_back(getFirstSetIdCarte(carteMalus, csPrison));
  vecCartes.push_back(getFirstSetIdCarte(carteMalus, csAttentat));
  for (auto id : mmapMSLCarte[{carteAnimal, csAucun}]) {
    vecCartes.push_back(id);
  }
  vecCartes.push_back(getFirstSetIdCarte(carteAnimal, csLicorne));
  for (auto id : mmapMSLCarte[{carteVoyage, csAucun}]) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMaison, csMaison6);
  for (int i = 0; i < 2; i++) {
    vecCartes.push_back(id);
  }
  id = getFirstSetIdCarte(carteMaison, csMaison8);
  for (int i = 0; i < 2; i++) {
    vecCartes.push_back(id);
  }
  vecCartes.push_back(getFirstSetIdCarte(carteMaison, csMaison10));

  CardGame::myShuffle(vecCartes);
}

void CarteGenerateurStandard::addMetier() {
  addCarteMSL(
      new CarteMSL(++cptId, "Architecte", 2, carteMetier, csArchitecte));
  addCarteMSL(
      new CarteMSL(++cptId, "Astronaute", 2, carteMetier, csAstronaute));
  addCarteMSL(new CarteMSL(++cptId, "Avocat", 2, carteMetier, csAvocat));
  addCarteMSL(new CarteMSL(++cptId, "Bandit", 2, carteMetier, csBandit));
  addCarteMSL(new CarteMSL(++cptId, "Barman", 2, carteMetier, csBarman));

  addCarteMSL(
      new CarteMSL(++cptId, "ChefDesAchats", 2, carteMetier, csChefDesAchats));
  addCarteMSL(
      new CarteMSL(++cptId, "ChefDesVentes", 2, carteMetier, csChefDesVentes));
  addCarteMSL(new CarteMSL(++cptId, "Chercheur", 2, carteMetier, csChercheur));
  addCarteMSL(
      new CarteMSL(++cptId, "Chirurgien", 2, carteMetier, csChirurgien));
  addCarteMSL(new CarteMSL(++cptId, "Designer", 2, carteMetier, csDesigner));

  addCarteMSL(new CarteMSL(++cptId, "Ecrivain", 2, carteMetier, csEcrivain));
  addCarteMSL(new CarteMSL(++cptId, "Garagiste", 2, carteMetier, csGaragiste));
  addCarteMSL(new CarteMSL(++cptId, "GrandProf", 2, carteMetier, csGrandProf));
  addCarteMSL(new CarteMSL(++cptId, "Gourou", 2, carteMetier, csGourou));
  addCarteMSL(new CarteMSL(++cptId, "Jardinier", 2, carteMetier, csJardinier));

  addCarteMSL(
      new CarteMSL(++cptId, "Journaliste", 2, carteMetier, csJournaliste));
  addCarteMSL(new CarteMSL(++cptId, "Medecin", 2, carteMetier, csMedecin));
  addCarteMSL(new CarteMSL(++cptId, "Medium", 2, carteMetier, csMedium));
  addCarteMSL(new CarteMSL(++cptId, "Militaire", 2, carteMetier, csMilitaire));
  addCarteMSL(
      new CarteMSL(++cptId, "Pharmacien", 2, carteMetier, csPharmacien));

  addCarteMSL(
      new CarteMSL(++cptId, "PiloteDeLigne", 2, carteMetier, csPiloteDeLigne));
  addCarteMSL(new CarteMSL(++cptId, "Pizzaiolo", 2, carteMetier, csPizzaiolo));
  addCarteMSL(new CarteMSL(++cptId, "Plombier", 2, carteMetier, csPlombier));
  addCarteMSL(new CarteMSL(++cptId, "Policier", 2, carteMetier, csPolicier));
  addCarteMSL(new CarteMSL(++cptId, "ProfDeFrancais", 2, carteMetier, csProf));

  addCarteMSL(new CarteMSL(++cptId, "ProfDeMaths", 2, carteMetier, csProf));
  addCarteMSL(new CarteMSL(++cptId, "ProfDHistoire", 2, carteMetier, csProf));
  addCarteMSL(new CarteMSL(++cptId, "ProfDAnglais", 2, carteMetier, csProf));
  addCarteMSL(new CarteMSL(++cptId, "Serveur", 2, carteMetier, csServeur));
  addCarteMSL(
      new CarteMSL(++cptId, "Stripteaser", 2, carteMetier, csStripteaser));
}
void CarteGenerateurStandard::addEtude() {
  addCarteMSL(
      new CarteMSL(++cptId, "Etude Simple", 1, carteEtude, csEtudeSimple));
  addCarteMSL(
      new CarteMSL(++cptId, "Etude Double", 1, carteEtude, csEtudeDouble));
}
void CarteGenerateurStandard::addSalaire() {
  addCarteMSL(new CarteMSL(++cptId, "Salaire 1", 1, carteSalaire, csSalaire1));
  addCarteMSL(new CarteMSL(++cptId, "Salaire 2", 1, carteSalaire, csSalaire2));
  addCarteMSL(new CarteMSL(++cptId, "Salaire 3", 1, carteSalaire, csSalaire3));
  addCarteMSL(new CarteMSL(++cptId, "Salaire 4", 1, carteSalaire, csSalaire4));
}
void CarteGenerateurStandard::addSpecial() {
  // special 10
  addCarteMSL(
      new CarteMSL(++cptId, "Anniversaire", 0, carteSpecial, csAnniversaire));
  addCarteMSL(new CarteMSL(++cptId, "ArcEnCiel", 0, carteSpecial, csArcEnCiel));
  addCarteMSL(new CarteMSL(++cptId, "cCasino", 0, carteSpecial, csCasino));
  addCarteMSL(new CarteMSL(++cptId, "Chance", 0, carteSpecial, csChance));
  addCarteMSL(
      new CarteMSL(++cptId, "EtoileFilante", 0, carteSpecial, csEtoileFilante));
  addCarteMSL(new CarteMSL(++cptId, "Heritage", 0, carteSpecial, csHeritage));
  addCarteMSL(new CarteMSL(++cptId, "Piston", 0, carteSpecial, csPiston));
  addCarteMSL(new CarteMSL(++cptId, "Troc", 0, carteSpecial, csTroc));
  addCarteMSL(new CarteMSL(++cptId, "Tsunami", 0, carteSpecial, csTsunami));
  addCarteMSL(new CarteMSL(++cptId, "Vengeance", 0, carteSpecial, csVengeance));

  // Adulteres 3
  addCarteMSL(new CarteMSL(++cptId, "Adultere", 0, carteSpecial, csAdultere));

  // Les distinctions 3
  addCarteMSL(
      new CarteMSL(++cptId, "LegionHonneur", 3, carteSpecial, csLegionHonneur));
  addCarteMSL(new CarteMSL(++cptId, "GrandPrixExcellence", 4, carteSpecial,
                           csGrandPrixExcellence));
}
void CarteGenerateurStandard::addEnfant() {
  // 10: 5 de chaque sexe
  vector<std::string> vecStr = {"Leia", "Hermione", "Lara", "Diana", "Zelda"};
  for (auto str : vecStr) {
    addCarteMSL(new CarteMSL(++cptId, str, 2, carteEnfant, csFille));
  }
  vecStr.clear();
  vecStr = {"Luke", "Mario", "Luigi", "Harry", "Rocky"};
  for (auto str : vecStr) {
    addCarteMSL(new CarteMSL(++cptId, str, 2, carteEnfant, csGarcon));
  }
}
void CarteGenerateurStandard::addFlirt() {
  // total 20
  //  Sans bébé possible 8*2
  vector<CarteSousType> vecStr = {csAuParc,   csAuBar,         csAuTheatre,
                                  csAuCinema, csEnBoiteDeNuit, csAuRestaurant,
                                  csAuZoo,    csSurInternet};
  for (auto lieu : vecStr) {
    addCarteMSL(new CarteMSL(++cptId, "Flirt", 1, carteFlirt, lieu));
  }
  // avec bébé possible 2*2
  addCarteMSL(new CarteMSL(++cptId, "Flirt", 1, carteFlirt, csAuCamping));
  addCarteMSL(new CarteMSL(++cptId, "Flirt", 1, carteFlirt, csALHotel));
}
void CarteGenerateurStandard::addMarriage() {
  addCarteMSL(new CarteMSL(++cptId, "Mariage", 3, carteMariage, csAucun));
}
void CarteGenerateurStandard::addMalus() {
  addCarteMSL(new CarteMSL(++cptId, "Accidents", 0, carteMalus, csAccidents));
  addCarteMSL(new CarteMSL(++cptId, "Burne Out", 0, carteMalus, csBurnOut));
  addCarteMSL(new CarteMSL(++cptId, "Dit Vorce", 0, carteMalus, csDivorce));
  addCarteMSL(new CarteMSL(++cptId, "Un pot", 0, carteMalus, csImpotsRevenus));
  addCarteMSL(
      new CarteMSL(++cptId, "Lit 100 ciments", 0, carteMalus, csLicenciement));
  addCarteMSL(new CarteMSL(++cptId, "Mâle à dit", 0, carteMalus, csMaladie));
  addCarteMSL(
      new CarteMSL(++cptId, "Redoublement", 0, carteMalus, csRedoublement));
  addCarteMSL(new CarteMSL(++cptId, "Prison", 0, carteMalus, csPrison));
  addCarteMSL(new CarteMSL(++cptId, "Attentat", 0, carteMalus, csAttentat));
}
void CarteGenerateurStandard::addAnimal() {
  for (auto str : {"Chat", "chien", "Lapin", "Oiseau"}) {
    addCarteMSL(new CarteMSL(++cptId, str, 1, carteAnimal, csAucun));
  }
  addCarteMSL(new CarteMSL(++cptId, "Licorne", 3, carteAnimal, csLicorne));
}
void CarteGenerateurStandard::addVoyage() {
  for (auto str :
       {"Londres", "New York", "Rio de Janeiro", "Sydney", "Le Caire"}) {
    addCarteMSL(new CarteMSL(++cptId, str, 1, carteVoyage, csAucun));
  }
}
void CarteGenerateurStandard::addMaison() {
  addCarteMSL(new CarteMSL(++cptId, "Maison 6", 1, carteMaison, csMaison6));
  addCarteMSL(new CarteMSL(++cptId, "Maison 8", 2, carteMaison, csMaison8));
  addCarteMSL(new CarteMSL(++cptId, "Maison 10", 3, carteMaison, csMaison10));
}

void CarteGenerateurStandard::addCarteMSL(const CarteMSL *crt) {
  IdCarte id = crt->getId();
  CarteType ct = crt->getType();
  CarteSousType cst = crt->getSType();
  mmapMSLCarte[{ct, cst}].insert(id);
  addCarte(dynamic_cast<const Carte *>(crt));
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
