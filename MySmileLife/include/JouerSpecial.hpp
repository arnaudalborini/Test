#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife {
class JouerSpecial: public std::enable_shared_from_this<JouerSpecial> {
protected:
     virtual _pc_CarteMSL getCarteMSL(IdCarte id) const = 0;
  bool peutEtreJoueeSpecial(CardGame::_pc_Player pp, _pc_CarteMSL crt) const;
  bool jouerCarteSpecial(CardGame::_pc_Player pp, _pc_CarteMSL crt) const;
  virtual void choisirEtJouerUneCarteDefausse(CardGame::_pc_Player pp) const = 0;
  virtual bool jouerCarteSalaire(CardGame::_pc_Player pp,
                                 _pc_CarteMSL crt) const = 0;

public:
  virtual _pc_CarteGenerateurStandard getCGen() const = 0;
  virtual CardGame::_pc_GameMechanicsMonitor getMonitor() const = 0;
  virtual bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id) const = 0;
  virtual bool jouerCarte(CardGame::_pc_Player pp, IdCarte id) const = 0;
  virtual CardGame::_pc_Player getCible(CardGame::_pc_Player pp, IdCarte id) const = 0;

private:
  void jouerAdultere(CardGame::_pc_Player pp) const;
  void jouerTroc(CardGame::_pc_Player pp) const;
  void jouerCasino(CardGame::_pc_Player pp) const;
  void jouerChance(CardGame::_pc_Player pp) const;
  void jouerPiston(CardGame::_pc_Player pp) const;
  void jouerAnniversaire(CardGame::_pc_Player pp) const;
  void jouerArcEnCiel(CardGame::_pc_Player pp) const;
  void jouerEtoileFilante(CardGame::_pc_Player pp) const;
  void jouerHeritage(CardGame::_pc_Player pp) const;
  void jouerTsunami() const;
  void jouerVengeance(CardGame::_pc_Player pp) const;
  void jouerLegionHonneur(CardGame::_pc_Player pp) const;
  void jouerGrandPrix(CardGame::_pc_Player pp) const;
};
} // namespace MySmileLife
#endif