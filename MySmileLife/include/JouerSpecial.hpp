#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "JouerMalus.hpp"
#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife {
class JouerSpecial: private std::enable_shared_from_this<JouerSpecial> {
protected:
     virtual PCCarteMSL getCarteMSL(IdCarte id) const = 0;
  bool peutEtreJoueeSpecial(PCPlayer pp, PCCarteMSL crt) const;
  bool jouerCarteSpecial(PCPlayer pp, PCCarteMSL crt) const;
  virtual void choisirEtJouerUneCarteDefausse(PCPlayer pp) const = 0;
  virtual bool jouerCarteSalaire(PCPlayer pp,
                                 PCCarteMSL crt) const = 0;

public:
  virtual PCCarteGenerateurStandard getCGen() const = 0;
  virtual CardGame::PCGameMechanicsMonitor getMonitor() const = 0;
  virtual bool peutEtreJouee(PCPlayer pp, IdCarte id) const = 0;
  virtual bool jouerCarte(PCPlayer pp, IdCarte id) const = 0;
  virtual PCPlayer getCible(PCPlayer pp, IdCarte id) const = 0;

private:
  void jouerAdultere(PCPlayer pp) const;
  void jouerTroc(PCPlayer pp) const;
  void jouerCasino(PCPlayer pp) const;
  void jouerChance(PCPlayer pp) const;
  void jouerPiston(PCPlayer pp) const;
  void jouerAnniversaire(PCPlayer pp) const;
  void jouerArcEnCiel(PCPlayer pp) const;
  void jouerEtoileFilante(PCPlayer pp) const;
  void jouerHeritage(PCPlayer pp) const;
  void jouerTsunami() const;
  void jouerVengeance(PCPlayer pp) const;
  void jouerLegionHonneur(PCPlayer pp) const;
  void jouerGrandPrix(PCPlayer pp) const;
};
} // namespace MySmileLife
#endif