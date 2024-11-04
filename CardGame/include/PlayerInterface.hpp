#ifndef PLAYERINTERFACE_HPP
#define PLAYERINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame {
class PlayerInterface {
public:
  virtual PCInfosJoueur getInfosJoueurs(int indPlayer) const = 0;
  virtual PCPlateau     getPlateau() const = 0;
  virtual PCPaquetCarte getPioche() const = 0;
  virtual PCPaquetCarte getDefausse() const = 0;
  virtual PCCarte       getCarte(IdCarte idC) const = 0;
  virtual int           getStatutPlayer(int indPlayer, int dp) const = 0;
  virtual int           getIdPlayer(PCPlayer pp) const = 0;
};
} // namespace CardGame

#endif