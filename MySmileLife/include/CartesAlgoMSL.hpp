#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "CartesAlgo.hpp"
#include "JouerCarteMSL.hpp"
#include "MySmileLife.hpp"

namespace MySmileLife {
class CartesAlgoMSL final : public CardGame::CartesAlgo {
private:
  PCJouerCarteMSL jCarte;

public:
  CartesAlgoMSL(CardGame::PCCarteGenerator cc,
                CardGame::PCGameMechanicsMonitor mm)
      : CardGame::CartesAlgo(cc, mm), jCarte(make_shared<const JouerCarteMSL>(cc, mm)) {}
  ~CartesAlgoMSL() {  }

  bool peutEtreJouee(PCPlayer pp, IdCarte id) const override {return jCarte->peutEtreJouee(pp, id);}
  bool jouerCarte(PCPlayer pp, IdCarte id) const override {
    return jCarte->jouerCarte(pp, id);
  }

  int getNbSmile(PCPlateau pp, IdCarte id) const;

  void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) override;
  void effetQuitterHand(const int indPlayer, const IdCarte idCrt) override;
};
} // namespace MySmileLife

#endif