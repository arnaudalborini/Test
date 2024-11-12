#ifndef CONCRETEMONITOR_HPP
#define CONCRETEMONITOR_HPP

#include "CardGame.hpp"
#include "Monitor.hpp"

namespace CardGame {
class ConcreteMonitor : public Monitor, public std::enable_shared_from_this<ConcreteMonitor> {
private:
  int mNbJoueur;
  _p_GameMechanics mGameMechanics;
  vector<_p_InfosJoueur> mInfosJoueurs;
  vector<_pc_Player> mPlayer;
  _p_Plateau mPlateau;
  _p_PaquetCarte mPioche;
  _p_PaquetCarte mDefausse;
  map<_pc_Player, int> mapIdPlayer;
protected:
  _pc_Player getPlayer(int ind) const override;
public:
  ConcreteMonitor();
  ~ConcreteMonitor();
  // GameMechanicsMonitor
  _p_Plateau getPlateauGeneral() const override;
  _p_Plateau getPlateauPlayer(int indPlayer) const override;
  _p_Plateau getPlateauPlayer( _pc_Player pp) const override;
  _p_PaquetCarte getPioche() const override;
  _p_PaquetCarte getDefausse() const override;
  _p_InfosJoueur getInfosJoueurs(int ind) const override;
  _p_InfosJoueur getInfosJoueurs(_pc_Player pp) const override;
  int getIndPlayer(_pc_Player pp) const override;
  int getNbPlayer() const override;
  void defausser(IdCarte crt, int indPlayer) const override;
  void defausserDernier(int indPlayer, int EP) const override;
  void defausserTout(int indPlayer, int EP) const override;
  int  getStatut(int indPlayer, int statut) const override;
  void incStatut(int indPlayer, int statut, int inc) const override;
  void setStatut(int indPlayer, int statut, int value) const override;
  void incStatutGeneral(int statut, int inc) const override;
  void setStatutGeneral(int statut, int value) const override;
  int  getStatutGeneral(int statut) const override;
  virtual int getNbCarteHand(int indPlayer)const;
  virtual IdCarte joueurPioche(int indPlayer)const;
  virtual IdCarte joueurDefausse(int indPlayer)const;
  virtual void voirMainAutresJoueur(_pc_Player pp)const;
  virtual void voirNProchainesCartesPioche(_pc_Player pp, int N)const;
  // GameMasterMonitor
  void initiateElements(int nbJoueurs, _p_GameMechanics gm) override;
  void addPlayer(_pc_Player pp, int index) override;
  void startGame() override;
  void removePlayer(int indice) override;
  int getWinner() const override;
  _pc_Carte getCarte(IdCarte idC) const override;
  // PlateaMonitor
  virtual void effetQuitterPlateau(const int indPlayer,
                                   const IdCarte idCrt) override;
  // HandMonitor
  virtual void effetQuitterHand(const int indPlayer,
                                const IdCarte idCrt) override;
};
} // namespace CardGame

#endif // MONITOR_HPP