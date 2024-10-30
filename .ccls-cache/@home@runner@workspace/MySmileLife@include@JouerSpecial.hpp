#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "JouerMalus.hpp"
#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife {
class JouerSpecial {
protected:
     virtual const CarteMSL *getCarteMSL(IdCarte id) const = 0;
  bool peutEtreJoueeSpecial(const Player *pp, const CarteMSL *crt) const;
  bool jouerCarteSpecial(const Player *pp, const CarteMSL *crt) const;
  virtual void choisirEtJouerUneCarteDefausse(const Player *pp) const = 0;
  virtual bool jouerCarteSalaire(const Player *pp,
                                 const CarteMSL *crt) const = 0;

public:
  virtual const CarteGenerateurStandard *getCGen() const = 0;
  virtual const CardGame::GameMechanicsMonitor *getMonitor() const = 0;
  virtual bool peutEtreJouee(const Player *pp, IdCarte id) const = 0;
  virtual bool jouerCarte(const Player *pp, IdCarte id) const = 0;
  virtual const Player *getCible(const Player *pp, IdCarte id) const = 0;

private:
  void jouerAdultere(const Player *pp) const;
  void jouerTroc(const Player *pp) const;
  void jouerCasino(const Player *pp) const;
  void jouerChance(const Player *pp) const;
  void jouerPiston(const Player *pp) const;
  void jouerAnniversaire(const Player *pp) const;
  void jouerArcEnCiel(const Player *pp) const;
  void jouerEtoileFilante(const Player *pp) const;
  void jouerHeritage(const Player *pp) const;
  void jouerTsunami() const;
  void jouerVengeance(const Player *pp) const;
  void jouerLegionHonneur(const Player *pp) const;
  void jouerGrandPrix(const Player *pp) const;
};
} // namespace MySmileLife
#endif