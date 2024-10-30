#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "CardGame.hpp"
#include "MSLPlayer.hpp"
#include "MySmileLife.hpp"
#include <string>

namespace MySmileLife {
class BasicBot : public MSLPlayer {
private:
  void afficherCarte(const CarteMSL *carte) const;
  void afficherCarte(CardGame::IdCarte id) const;

public:
  BasicBot(){};
  virtual ~BasicBot(){};

  string getName() const override { return "basicbot"; }
  int choisirUneCarte(CardGame::PaquetCarte *paq) const override {
    return 0;
  }
  int choisirUneCarte(const vector<IdCarte> &vecId) const {
    return 0;
  }
  void showNCartesPioche(const vector<IdCarte> &vecIdPioche) const override;
  void showHandAutreJoueur(const Hand *h, int indAutrePlayer) const override;
  int choisirSalairePourPayer(
      const vector<IdCarte> &vecIdSalairesDisponibles) const override;
  int choisirIndiceCarteAJouerMain(const Hand *h) const override { return 0; };
  int choisirCible(IdCarte id) const override{ return 0; }
  int choisirIndiceHazard(int indiceMin, int indiceMax) const override{
    return 0;
  }
};
} // namespace MySmileLife

#endif