#ifndef PLAYERINTERFACE_HPP
#define PLAYERINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame {
class PlayerInterface {
public:
  virtual const InfosJoueur *getInfosJoueurs(int indPlayer) const = 0;
  virtual const Plateau *getPlateau() const = 0;
  virtual const PaquetCarte *getPioche() const = 0;
  virtual const PaquetCarte *getDefausse() const = 0;
  virtual const Carte *getCarte(IdCarte idC) const = 0;
  virtual int getStatutPlayer(int indPlayer, int dp) const = 0;
  virtual int getIdPlayer(const Player *) const = 0;
};
} // namespace CardGame

#endif