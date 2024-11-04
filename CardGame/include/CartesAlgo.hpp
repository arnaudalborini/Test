#ifndef CARTESALGO_HPP
#define CARTESALGO_HPP

#include "CardGame.hpp"

namespace CardGame {
class CartesAlgo {
protected:
  _pc_CarteGenerator cGen;
  _pc_GameMechanicsMonitor mMonitor;

public:
  CartesAlgo(_pc_CarteGenerator cc, _pc_GameMechanicsMonitor mm)
      : cGen(cc), mMonitor(mm) {}
  ~CartesAlgo() {}
  virtual bool peutEtreJouee(_pc_Player pp, IdCarte id) const {return false;}
  virtual bool jouerCarte(_pc_Player pp, IdCarte id) const { return false; }

  virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {}
  virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) {}
};
} // namespace CardGame

#endif