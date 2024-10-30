#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "CartesAlgo.hpp"
#include "JouerCarteMSL.hpp"
#include "MySmileLife.hpp"

namespace MySmileLife {
class CartesAlgoMSL final : public CardGame::CartesAlgo {
private:
  const JouerCarteMSL *jCarte;

public:
  CartesAlgoMSL(const CardGame::CarteGenerator *cc,
                const CardGame::GameMechanicsMonitor *mm)
      : CardGame::CartesAlgo(cc, mm), jCarte(new JouerCarteMSL(cc, mm)) {
    cout << "CartesAlgoMSL:" << cc << " " << mm << endl;
  }
  ~CartesAlgoMSL() { delete jCarte; }

  bool peutEtreJouee(const Player *pp, IdCarte id) const override {
    cout << "CartesAlgoMSL:peutEtreJouee" << endl;
    return jCarte->peutEtreJouee(pp, id);
  }
  bool jouerCarte(const Player *pp, IdCarte id) const override {
    return jCarte->jouerCarte(pp, id);
  }

  int getNbSmile(const Plateau *pp, IdCarte id) const;

  void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt) override;
  void effetQuitterHand(const int indPlayer, const IdCarte idCrt) override;
};
} // namespace MySmileLife

#endif