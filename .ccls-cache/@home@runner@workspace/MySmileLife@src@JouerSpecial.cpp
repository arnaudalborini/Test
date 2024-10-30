#include "JouerSpecial.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteGenerator.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "MyShuffle.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "Player.hpp"
#include "StatutPlateau.hpp"

#include "JouerCarteMSL.hpp"
#include "JouerSpecial.hpp"

using CardGame::Hand;
using CardGame::IdCarte;
using CardGame::InfosJoueur;
using CardGame::Plateau;
using CardGame::Player;
using MySmileLife::CarteMSL;
using MySmileLife::JouerMalus;
using MySmileLife::JouerSpecial;

using MySmileLife::CarteSousType;
using MySmileLife::DetailPlateau;
using MySmileLife::EmplacementsPlateau;

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

bool isMarriedButNotAdulterous(const Plateau *plat) {
  return ((plat->getStatut(MySmileLife::estMarie)) &&
          (plat->getStatut(MySmileLife::estAdultere) == false));
}
bool hasEligibleProfession(const Plateau *plat) {
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
bool canPlayMalusCard(const Plateau *plat, const Player *pp,
                      const MySmileLife::JouerCarteMSL *jCarte) {
  int nbMalus = plat->getNbCarte(EmplacementsPlateau::EMalus);
  for (auto indice = 0; indice < nbMalus; indice++) {
    int IdMalus = plat->showIdN(EmplacementsPlateau::EMalus, indice);
    if (jCarte->peutEtreJouee(pp, IdMalus)) {
      return true;
    }
  }
  return false;
}

bool JouerSpecial::peutEtreJoueeSpecial(const Player *pp,
                                        const CarteMSL *crt) const {
  if (crt->getType() != carteSpecial) {
    return false;
  }
  Plateau *plat = getMonitor()->getPlateauPlayer(pp);
  switch (crt->getSType()) {
  case csAdultere:
    return isMarriedButNotAdulterous(plat);
  case csGrandPrixExcellence:
    return hasEligibleProfession(plat);
  case csVengeance:
    return canPlayMalusCard(plat, pp,
                            dynamic_cast<const JouerCarteMSL *>(this));
  default:
    return true;
  }
}

bool JouerSpecial::jouerCarteSpecial(const Player *pp,
                                     const CarteMSL *crt) const {
  if (peutEtreJoueeSpecial(pp, crt) == false) {
    return false;
  }
  if (crt->getSType() == csCasino) {
    getMonitor()->getPlateau()->addLast(ESpecial, crt->getId());
  } else {
    getMonitor()->getPlateauPlayer(pp)->addLast(ESpecial, crt->getId());
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

void JouerSpecial::jouerAdultere(const Player *pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(estAdultere, 1);
}

void JouerSpecial::jouerTroc(const Player *pp) const {
  const Player *cc =
      getCible(pp, getCGen()->getCarteByType(carteSpecial, csTroc));
  Hand *jh = getMonitor()->getInfosJoueurs(pp)->getHand();
  Hand *ch = getMonitor()->getInfosJoueurs(cc)->getHand();

  int nbCjh = jh->getNbCarte();
  int nbCch = ch->getNbCarte();

  bool ppProtege =
      getMonitor()->getInfosJoueurs(pp)->getPlateau()->getStatut(TrocProtege);
  bool ccProtege =
      getMonitor()->getInfosJoueurs(cc)->getPlateau()->getStatut(TrocProtege);
  IdCarte idPPProtege, idCCProtege;
  if (ppProtege) {
    idPPProtege = jh->getCarte(pp->choisirIndiceHazard(0, nbCjh - 1));
    nbCjh = jh->getNbCarte();
  }
  if (ccProtege) {
    idCCProtege = jh->getCarte(pp->choisirIndiceHazard(0, nbCch - 1));
    nbCch = ch->getNbCarte();
  }
  int choixPP = pp->choisirIndiceHazard(0, nbCch - 1);
  int choixCC = cc->choisirIndiceHazard(0, nbCjh - 1);
  IdCarte idPP = jh->getCarte(choixCC);
  IdCarte idCC = ch->getCarte(choixPP);
  jh->addCarte(idCC);
  ch->addCarte(idPP);
  if (ppProtege) {
    jh->addCarte(idPPProtege);
  }
  if (ccProtege) {
    ch->addCarte(idCCProtege);
  }
}

void JouerSpecial::jouerCasino(const Player *pp) const {
  getMonitor()->getPlateau()->setStatut(casinoOuvert, 1);
}

void JouerSpecial::jouerChance(const Player *pp) const {
  CardGame::PaquetCarte *pioche = getMonitor()->getPioche();
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

void JouerSpecial::jouerPiston(const Player *pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(PistonActif, 1);
}

void JouerSpecial::jouerAnniversaire(const Player *pp) const {
  int nbJoueur = getMonitor()->getNbPlayer();
  int indPlayer = getMonitor()->getIndPlayer(pp);
  for (auto ind = 0; ind < nbJoueur; ind++) {
    if (ind != indPlayer) {
      const Player *cc = getMonitor()->getPlayer(ind);
      const vector<IdCarte> salD =
          getMonitor()->getInfosJoueurs(cc)->getPlateau()->showAllIdByEP(
              ESalairesD);
      if (salD.size() > 0) {
        int indCrt = cc->choisirUneCarte(salD);
        IdCarte id = getMonitor()->getInfosJoueurs(cc)->getPlateau()->getN(
            ESalairesD, indCrt);
        jouerCarteSalaire(cc, getCarteMSL(id));
      }
    }
  }
}

void JouerSpecial::jouerArcEnCiel(const Player *pp) const {
  const Hand *h = getMonitor()->getInfosJoueurs(pp)->getHand();
  for (auto indice = 0; indice < 3; indice++) {
    int n = pp->choisirIndiceCarteAJouerMain(h);
    IdCarte id = h->getIdCarte(n);
    if (peutEtreJouee(pp, id)) {
      getMonitor()->getInfosJoueurs(pp)->getHand()->getCarte(n);
      jouerCarte(pp, id);
    }
  }
  getMonitor()->getPlateauPlayer(pp)->setStatut(ArcEnCielJoue, 1);
}

void JouerSpecial::jouerEtoileFilante(const Player *pp) const {
  choisirEtJouerUneCarteDefausse(pp);
}

void JouerSpecial::jouerHeritage(const Player *pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(HeritageDisponible, 3);
}

void JouerSpecial::jouerTsunami() const {
  vector<Hand *> vecH;
  vector<int> vecNbCarte;
  vector<IdCarte> vecCrt;
  for (auto ind = 0; ind < getMonitor()->getNbPlayer(); ind++) {
    vecH[ind] = getMonitor()->getInfosJoueurs(ind)->getHand();
    vecNbCarte[ind] = vecH[ind]->getNbCarte();
    for (auto indh = 0; indh < vecNbCarte[ind]; indh++) {
      vecCrt.push_back(vecH[ind]->getCarte(0));
    }
  }
  //CardGame::myShuffle(vecCrt);
  for (auto ind = 0; ind < getMonitor()->getNbPlayer(); ind++) {
    for (auto indh = 0; indh < vecNbCarte[ind]; indh++) {
      IdCarte id = vecCrt.back();
      vecCrt.pop_back();
      vecH[ind]->addCarte(id);
    }
  }
}

void JouerSpecial::jouerVengeance(const Player *pp) const {
  const vector<IdCarte> malusC = getMonitor()->getInfosJoueurs(pp)->getPlateau()->showAllIdByEP(EMalus);
  if (malusC.size() > 0) {
    int indCrt = pp->choisirUneCarte(malusC);
    IdCarte id = getMonitor()->getInfosJoueurs(pp)->getPlateau()->getN( EMalus, indCrt);
    jouerCarte(pp, id);
  }
}

void JouerSpecial::jouerLegionHonneur(const Player *pp) const {
  // rien à faire
}

void JouerSpecial::jouerGrandPrix(const Player *pp) const {
  getMonitor()->getPlateauPlayer(pp)->setStatut(SalaireMax, 4);
}
