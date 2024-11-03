#ifndef CARTESALGO_HPP
#define CARTESALGO_HPP

#include "CardGame.hpp"

namespace CardGame {
class CartesAlgo {
protected:
  PCCarteGenerator cGen;
  PCGameMechanicsMonitor mMonitor;

public:
  CartesAlgo(PCCarteGenerator cc, PCGameMechanicsMonitor mm)
      : cGen(cc), mMonitor(mm) {}
  ~CartesAlgo() {}
  virtual bool peutEtreJouee(PCPlayer pp, IdCarte id) const {return false;}
  virtual bool jouerCarte(PCPlayer pp, IdCarte id) const { return false; }

  virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) {}
  virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) {}
};
} // namespace CardGame

#endif