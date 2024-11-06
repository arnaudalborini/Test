#ifndef PLAYERINTERFACE_HPP
#define PLAYERINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame {
class PlayerInterface {
public:
  virtual _pc_InfosJoueur getInfosJoueurs(int indPlayer) const = 0;
  virtual _pc_Plateau     getPlateauGeneral() const = 0;
  virtual _pc_PaquetCarte getPioche() const = 0;
  virtual _pc_PaquetCarte getDefausse() const = 0;
  virtual _pc_Carte       getCarte(IdCarte idC) const = 0;
  virtual int           getStatutPlayer(int indPlayer, int dp) const = 0;
  virtual int           getIdPlayer(_pc_Player pp) const = 0;
};
} // namespace CardGame

#endif