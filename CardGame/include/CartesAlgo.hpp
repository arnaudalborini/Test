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
  virtual bool peutEtreJouee([[maybe_unused]]_pc_Player pp, [[maybe_unused]]IdCarte id) const {return false;}
  virtual bool jouerCarte([[maybe_unused]]_pc_Player pp, [[maybe_unused]]IdCarte id) const { return false; }

  virtual void effetQuitterPlateau([[maybe_unused]]const int indPlayer, [[maybe_unused]]const IdCarte idCrt, int EP) {}
  virtual void effetQuitterHand([[maybe_unused]]const int indPlayer, [[maybe_unused]]const IdCarte idCrt) {}
};
} // namespace CardGame

#endif