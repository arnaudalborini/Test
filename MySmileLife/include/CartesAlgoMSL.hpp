#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "CartesAlgo.hpp"
#include "JouerCarteMSL.hpp"
#include "MySmileLife.hpp"

namespace MySmileLife {
class CartesAlgoMSL final : public CardGame::CartesAlgo {
private:
  _pc_JouerCarteMSL jCarte;

public:
  CartesAlgoMSL(CardGame::_pc_CarteGenerator cc,
                CardGame::_pc_GameMechanicsMonitor mm)
      : CardGame::CartesAlgo(cc, mm){
        jCarte = make_shared<const JouerCarteMSL>(cc, mm);
      }
  ~CartesAlgoMSL() {  }

  bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id) const override {return jCarte->peutEtreJouee(pp, id);}
  bool jouerCarte(CardGame::_pc_Player pp, IdCarte id) const override {
    return jCarte->jouerCarte(pp, id);
  }

  int getNbSmile(CardGame::_pc_Plateau pp, IdCarte id) const;

  void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) override;
  void effetQuitterHand(const int indPlayer, const IdCarte idCrt) override;
};
} // namespace MySmileLife

#endif