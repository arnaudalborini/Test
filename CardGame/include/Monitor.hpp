#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"
#include "GameMasterMonitor.hpp"

#include "InfosJoueurMonitor.hpp"

namespace CardGame {
class Monitor : public GameMasterMonitor,
                public InfosJoueurMonitor {
protected:
  int mNbJoueur;
  PGameMechanics mGameMechanics;
  vector<PInfosJoueur> mInfosJoueurs;
  vector<PCPlayer> mPlayer;
  PPlateau mPlateau;
  PPaquetCarte mPioche;
  PPaquetCarte mDefausse;
  map<PCPlayer, int> mapIdPlayer;

public:
  Monitor();
  ~Monitor();
  // GameMechanicsMonitor
  PPlateau getPlateau() const override;
  PPlateau getPlateauPlayer(int indPlayer) const override;
  PPlateau getPlateauPlayer( PCPlayer pp) const override;
  PPaquetCarte getPioche() const override;
  PPaquetCarte getDefausse() const override;
  PInfosJoueur getInfosJoueurs(int ind) const override;
  PInfosJoueur getInfosJoueurs(PCPlayer pp) const override;
  PCPlayer getPlayer(int ind) const override;
  int getIndPlayer(PCPlayer pp) const override;
  int getNbPlayer() const override;
  void defausser(IdCarte crt, int indPlayer) const override;
  void defausserDernier(int indPlayer, int EP) const override;
  void defausserTout(int indPlayer, int EP) const override;
  void incStatut(int indPlayer, int statut, int inc) const override;
  // GameMasterMonitor
  void initiateElements(int nbJoueurs, PGameMechanics gm) override;
  void addPlayer(PCPlayer pp, int index) override;
  void startGame() override;
  void removePlayer(int indice) override;
  int getWinner() const override;
  PCCarte getCarte(IdCarte idC) const override;
  // PlateaMonitor
  virtual void effetQuitterPlateau(const int indPlayer,
                                   const IdCarte idCrt) override;
  // HandMonitor
  virtual void effetQuitterHand(const int indPlayer,
                                const IdCarte idCrt) override;
};
} // namespace CardGame

#endif // MONITOR_HPP