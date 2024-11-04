#ifndef MSLPLAYER_HPP
#define MSLPLAYER_HPP

#include "CarteMSL.hpp"
#include "MySmileLife.hpp"
#include "Player.hpp"
#include "PlayerInterface.hpp"

namespace MySmileLife {
class MSLPlayer : public Player {
protected:
  _pc_CarteMSL getCarteMSL(IdCarte idC) const {
    return dynamic_pointer_cast<const CarteMSL>(getPlayerInterface()->getCarte(idC));
  }

public:
  MSLPlayer() : Player() {}
  virtual ~MSLPlayer() {}
  virtual int choisirSalairePourPayer(
      const vector<IdCarte> &vecIdSalairesDisponibles) const = 0;
};
} // namespace MySmileLife

#endif