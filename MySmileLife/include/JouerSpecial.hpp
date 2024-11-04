#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "JouerMalus.hpp"
#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife {
class JouerSpecial: private std::enable_shared_from_this<JouerSpecial> {
protected:
     virtual _pc_CarteMSL getCarteMSL(IdCarte id) const = 0;
  bool peutEtreJoueeSpecial(_pc_Player pp, _pc_CarteMSL crt) const;
  bool jouerCarteSpecial(_pc_Player pp, _pc_CarteMSL crt) const;
  virtual void choisirEtJouerUneCarteDefausse(_pc_Player pp) const = 0;
  virtual bool jouerCarteSalaire(_pc_Player pp,
                                 _pc_CarteMSL crt) const = 0;

public:
  virtual _pc_CarteGenerateurStandard getCGen() const = 0;
  virtual CardGame::_pc_GameMechanicsMonitor getMonitor() const = 0;
  virtual bool peutEtreJouee(_pc_Player pp, IdCarte id) const = 0;
  virtual bool jouerCarte(_pc_Player pp, IdCarte id) const = 0;
  virtual _pc_Player getCible(_pc_Player pp, IdCarte id) const = 0;

private:
  void jouerAdultere(_pc_Player pp) const;
  void jouerTroc(_pc_Player pp) const;
  void jouerCasino(_pc_Player pp) const;
  void jouerChance(_pc_Player pp) const;
  void jouerPiston(_pc_Player pp) const;
  void jouerAnniversaire(_pc_Player pp) const;
  void jouerArcEnCiel(_pc_Player pp) const;
  void jouerEtoileFilante(_pc_Player pp) const;
  void jouerHeritage(_pc_Player pp) const;
  void jouerTsunami() const;
  void jouerVengeance(_pc_Player pp) const;
  void jouerLegionHonneur(_pc_Player pp) const;
  void jouerGrandPrix(_pc_Player pp) const;
};
} // namespace MySmileLife
#endif