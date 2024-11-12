#ifndef CARTESALGO_HPP
#define CARTESALGO_HPP

#include "CardGame.hpp"

namespace CardGame {
class CartesAlgo {
protected:
  weak_ptr<const CarteGenerator> cGen;
  weak_ptr<const GameMechanicsMonitor> mMonitor;

public:
  CartesAlgo(weak_ptr<const CarteGenerator> cc, weak_ptr<const GameMechanicsMonitor> mm)
      : cGen(cc), mMonitor(mm) {}
  ~CartesAlgo() {}
  virtual bool peutEtreJouee(_pc_Player pp, IdCarte id) const {return false;}
  virtual bool jouerCarte(_pc_Player pp, IdCarte id) const { return false; }

  virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP) {}
  virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) {}
};
} // namespace CardGame

#endif