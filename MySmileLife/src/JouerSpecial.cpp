#include "JouerSpecial.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "InfosJoueur.hpp"
#include "MyShuffle.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"
#include "JouerCarteMSL.hpp"

using MySmileLife::JouerSpecial;

/*
        csAdultere,
        csTroc,
        csCasino,
        csChance,
        csPiston,
        csAnniversaire,
        csArcEnCiel,
        csEtoileFilante,
        csHeritage,
        csTsunami,
        csVengeance,
        csLegionHonneur,
        csGrandPrixExcellence,
*/

bool isMarriedButNotAdulterous(CardGame::_pc_Plateau plat) {
  return ((plat->getStatut(MySmileLife::estMarie)) &&
          (plat->getStatut(MySmileLife::estAdultere) == false));
}
bool hasEligibleProfession(CardGame::_pc_Plateau plat) {
  if (plat->getStatut(MySmileLife::aUnTravail)) {
    switch (plat->getStatut(MySmileLife::Profession)) {
    case MySmileLife::csJournaliste:
    case MySmileLife::csEcrivain:
    case MySmileLife::csChercheur:
      return true;
    default:
      return false;
    }
  } else {
    return false;
  }
}
bool canPlayMalusCard(CardGame::_pc_Plateau plat, CardGame::_pc_Player pp, MySmileLife::_pc_JouerCarteMSL jCarte) {
  int nbMalus = plat->getNbCarteByEP(MySmileLife::EmplacementsPlateau::EMalus);
  for (auto indice = 0; indice < nbMalus; indice++) {
    int IdMalus = plat->showIdNByEP(MySmileLife::EmplacementsPlateau::EMalus, indice);
    if (jCarte->peutEtreJouee(pp, IdMalus)) {
      return true;
    }
  }
  return false;
}

bool JouerSpecial::peutEtreJoueeSpecial(CardGame::_pc_Player pp, _pc_CarteMSL crt) const {
  if (crt->getType() != carteSpecial) {
    return false;
  }
  CardGame::_p_Plateau plat = getMonitor()->getPlateauPlayer(pp);
  switch (crt->getSType()) {
  case csAdultere:
    return isMarriedButNotAdulterous(plat);
  case csGrandPrixExcellence:
    return hasEligibleProfession(plat);
  case csVengeance:
    
    return canPlayMalusCard(plat, pp, dynamic_pointer_cast<const JouerCarteMSL>(shared_from_this()));
  default:
    return true;
  }
}

bool JouerSpecial::jouerCarteSpecial(CardGame::_pc_Player pp, _pc_CarteMSL crt) const {
  if (peutEtreJoueeSpecial(pp, crt) == false) {
    return false;
  }
  if (crt->getSType() == csCasino) {
    getMonitor()->getPlateau()->addCarteToEP(ESpecial, crt->getId());
  } else {
    getMonitor()->getPlateauPlayer(pp)->addCarteToEP(ESpecial, crt->getId());
  }
  switch (crt->getSType()) {
  case csAdultere:
    jouerAdultere(pp);
    break;
  case csTroc:
    jouerTroc(pp);
    break;
  case csCasino:
    jouerCasino(pp);
    break;
  case csChance:
    jouerChance(pp);
    break;
  case csPiston:
    jouerPiston(pp);
    break;
  case csAnniversaire:
    jouerAnniversaire(pp);
    break;
  case csArcEnCiel:
    jouerArcEnCiel(pp);
    break;
  case csEtoileFilante:
    jouerEtoileFilante(pp);
    break;
  case csHeritage:
    jouerHeritage(pp);
    break;
  case csTsunami:
    jouerTsunami();
    break;
  case csVengeance:
    jouerVengeance(pp);
    break;
  case csLegionHonneur:
    jouerLegionHonneur(pp);
    break;
  case csGrandPrixExcellence:
    jouerGrandPrix(pp);
    break;
  }
  return true;
}

void JouerSpecial::jouerAdultere(CardGame::_pc_Player pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(estAdultere, 1);
}

void JouerSpecial::jouerTroc(CardGame::_pc_Player pp) const {
  CardGame::_pc_Player cc = getCible(pp, getCGen()->getCarteByType(carteSpecial, csTroc));
  CardGame::_p_Hand jh = getMonitor()->getInfosJoueurs(pp)->getHand();
  CardGame::_p_Hand ch = getMonitor()->getInfosJoueurs(cc)->getHand();

  int nbCjh = jh->getNbCarteHand();
  int nbCch = ch->getNbCarteHand();

  bool ppProtege = getMonitor()->getInfosJoueurs(pp)->getPlateau()->getStatut(TrocProtege);
  bool ccProtege = getMonitor()->getInfosJoueurs(cc)->getPlateau()->getStatut(TrocProtege);
  IdCarte idPPProtege, idCCProtege;
  if (ppProtege) {
    idPPProtege = jh->getCarteHand(pp->choisirIndiceHazard(0, nbCjh - 1));
    nbCjh = jh->getNbCarteHand();
  }
  if (ccProtege) {
    idCCProtege = jh->getCarteHand(pp->choisirIndiceHazard(0, nbCch - 1));
    nbCch = ch->getNbCarteHand();
  }
  int choixPP = pp->choisirIndiceHazard(0, nbCch - 1);
  int choixCC = cc->choisirIndiceHazard(0, nbCjh - 1);
  IdCarte idPP = jh->getCarteHand(choixCC);
  IdCarte idCC = ch->getCarteHand(choixPP);
  jh->addCarteHand(idCC);
  ch->addCarteHand(idPP);
  if (ppProtege) {
    jh->addCarteHand(idPPProtege);
  }
  if (ccProtege) {
    ch->addCarteHand(idCCProtege);
  }
}

void JouerSpecial::jouerCasino(CardGame::_pc_Player pp) const {
  getMonitor()->getPlateau()->setStatut(casinoOuvert, 1);
}

void JouerSpecial::jouerChance(CardGame::_pc_Player pp) const {
  CardGame::_p_PaquetCarte pioche = getMonitor()->getPioche();
  vector<IdCarte> vecId = vector<IdCarte>(3);
  vecId[0] = pioche->piocher();
  vecId[1] = pioche->piocher();
  vecId[2] = pioche->piocher();
  int choix = pp->choisirUneCarte(vecId);
  for (auto ind = 0; ind < 3; ind++) {
    if (choix == ind) {
      jouerCarte(pp, vecId[ind]);
    } else {
      getMonitor()->defausser(vecId[ind], -1);
    }
  }
}

void JouerSpecial::jouerPiston(CardGame::_pc_Player pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(PistonActif, 1);
}

void JouerSpecial::jouerAnniversaire(CardGame::_pc_Player pp) const {
  int nbJoueur = getMonitor()->getNbPlayer();
  int indPlayer = getMonitor()->getIndPlayer(pp);
  for (auto ind = 0; ind < nbJoueur; ind++) {
    if (ind != indPlayer) {
      CardGame::_pc_Player cc = getMonitor()->getPlayer(ind);
      const vector<IdCarte> salD =
          getMonitor()->getInfosJoueurs(cc)->getPlateau()->showAllIdByEP(ESalairesD);
      if (salD.size() > 0) {
        int indCrt = cc->choisirUneCarte(salD);
        IdCarte id = getMonitor()->getInfosJoueurs(cc)->getPlateau()->getNByEP(ESalairesD, indCrt);
        jouerCarteSalaire(cc, getCarteMSL(id));
      }
    }
  }
}

void JouerSpecial::jouerArcEnCiel(CardGame::_pc_Player pp) const {
  CardGame::_pc_Hand h = getMonitor()->getInfosJoueurs(pp)->getHand();
  for (auto indice = 0; indice < 3; indice++) {
    int n = pp->choisirIndiceCarteAJouerMain(h);
    IdCarte id = h->getIdCarteHand(n);
    if (peutEtreJouee(pp, id)) {
      getMonitor()->getInfosJoueurs(pp)->getCarteHand(n);
      jouerCarte(pp, id);
    }
  }
  getMonitor()->getPlateauPlayer(pp)->setStatut(ArcEnCielJoue, 1);
}

void JouerSpecial::jouerEtoileFilante(CardGame::_pc_Player pp) const {
  choisirEtJouerUneCarteDefausse(pp);
}

void JouerSpecial::jouerHeritage(CardGame::_pc_Player pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(HeritageDisponible, 3);
}

void JouerSpecial::jouerTsunami() const {
  vector<CardGame::_p_Hand> vecH;
  vector<int> vecNbCarte;
  vector<IdCarte> vecCrt;
  for (auto ind = 0; ind < getMonitor()->getNbPlayer(); ind++) {
    CardGame::_p_InfosJoueur ij = getMonitor()->getInfosJoueurs(ind);
    vecH.push_back( ij->getHand());
    vecNbCarte.push_back( vecH[ind]->getNbCarteHand() );
    for (auto indh = 0; indh < vecNbCarte[ind]; indh++) {
      vecCrt.push_back(vecH[ind]->getCarteHand(0));
    }
  }
  //CardGame::myShuffle(vecCrt);
  for (auto ind = 0; ind < getMonitor()->getNbPlayer(); ind++) {
    for (auto indh = 0; indh < vecNbCarte[ind]; indh++) {
      IdCarte id = vecCrt.back();
      vecCrt.pop_back();
      vecH[ind]->addCarteHand(id);
    }
  }
}

void JouerSpecial::jouerVengeance(CardGame::_pc_Player pp) const {
  const vector<IdCarte> malusC = getMonitor()->getInfosJoueurs(pp)->getPlateau()->showAllIdByEP(EMalus);
  if (malusC.size() > 0) {
    int indCrt = pp->choisirUneCarte(malusC);
    IdCarte id = getMonitor()->getInfosJoueurs(pp)->getPlateau()->getNByEP( EMalus, indCrt);
    jouerCarte(pp, id);
  }
}

void JouerSpecial::jouerLegionHonneur(CardGame::_pc_Player pp) const {
  // rien à faire
}

void JouerSpecial::jouerGrandPrix(CardGame::_pc_Player pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(SalaireMax, 4);
}
