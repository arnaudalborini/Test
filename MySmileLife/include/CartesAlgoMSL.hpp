#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "CartesAlgo.hpp"
#include "JouerCarteMSL.hpp"
#include "MySmileLife.hpp"
#include "EffetCartePlateau.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CarteGenerator.hpp"

namespace MySmileLife {
class CartesAlgoMSL final : public CardGame::CartesAlgo {
private:
  _pc_JouerCarteMSL jCarte;
  _pc_EffetCartePlateau mEffet;

public:
  CartesAlgoMSL(weak_ptr<const CardGame::CarteGenerator> cc, weak_ptr<const CardGame::GameMechanicsMonitor> mm)
      : CardGame::CartesAlgo(cc, mm){
        jCarte = make_shared<const JouerCarteMSL>(cc, mm);
        mEffet = make_shared<const EffetCartePlateauMain>( dynamic_pointer_cast<const CarteGenerateurStandard>(cc.lock()), mm );
      }
  ~CartesAlgoMSL() {  }

  bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id) const override {return jCarte->peutEtreJouee(pp, id);}
  bool jouerCarte(CardGame::_pc_Player pp, IdCarte id) const override {
    return jCarte->jouerCarte(pp, id);
  }

  int getNbSmile(CardGame::_pc_Plateau pp, IdCarte id) const;

  void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP) override;
  void effetQuitterHand(const int indPlayer, const IdCarte idCrt) override;
  void effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP) override;
  void effetEntrerHand(const int indPlayer, const IdCarte idCrt) override;
};
} // namespace MySmileLife

#endif