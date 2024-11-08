#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "CardGame.hpp"
#include "MSLPlayer.hpp"
#include "MySmileLife.hpp"
#include <string>

namespace MySmileLife {
class BasicBot : public MSLPlayer {
private:
  void afficherCarte(_pc_CarteMSL carte) const;
  void afficherCarte(IdCarte id) const;

public:
  BasicBot(){};
  virtual ~BasicBot(){};

  string getName() const override { return "basicbot"; }
  int choisirUneCarte(CardGame::_p_PaquetCarte paq) const override {
    return 0;
  }
  int choisirUneCarte(const vector<IdCarte> &vecId) const override {
    return 0;
  }
  void showNCartesPioche(const vector<IdCarte> &vecIdPioche) const override;
  void showHandAutreJoueur(CardGame::_pc_Hand h, int indAutrePlayer) const override;
  int choisirSalairePourPayer(
      const vector<IdCarte> &vecIdSalairesDisponibles) const override;
  int choisirIndiceCarteAJouerMain(CardGame::_pc_Hand h) const override { return 0; };
  int choisirCible(IdCarte id) const override{ return 0; }
  int choisirIndiceHazard(int indiceMin, int indiceMax) const override{
    return 0;
  }
};
} // namespace MySmileLife

#endif