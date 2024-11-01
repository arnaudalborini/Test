#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

#include "CardGame.hpp"

namespace CardGame {
class GameMechanics {
protected:
  GameMechanicsMonitor *mMonitor;
  CarteGenerator *cGen;
  CartesAlgo *cAlgo;

  void joueurPioche(int indPlayer) const;
  void remplirMain(int indPlayer) const;
  int getNbCartePioche() const;
  int getNbCarteDefausse() const;
  void addCarteDefausse(IdCarte idC, int IdPlayer) const;
  void addCarteDefausse(IdCarte idC) const;
  const Player *getPlayer(int indPlayer) const;
  Hand *getJoueurHand(int indPlayer) const;
  Plateau *getJoueurPlateau(int indPlayer) const;
  Plateau *getMainPlateau() const;
  int getStatutPlayer(int indPlayer, int dp) const;
  void setStatutPlayer(int indPlayer, int dp, int value);
  void incStatutPlayer(int indPlayer, int dp, int inc = 1);
  void decStatutPlayer(int indPlayer, int dp, int inc = 1);

  bool peutEtreJouee(const Player *pp, IdCarte id) const;
  bool jouerCarte(const Player *pp, IdCarte id) const;

public:
  GameMechanics();
  ~GameMechanics();
  void setMonitor(Monitor *mm);
  void initGame();
  void startGame();
  const Carte *getCarte(IdCarte idC) const;

  virtual void initSpeficiGame(){};
  virtual vector<IdCarte> genVecCartesPioche() const = 0;
  virtual vector<IdCarte> genVecCartesDefausse() const = 0;
  virtual vector<vector<IdCarte>> genMapCartePlateauInitial() const = 0;
  virtual vector<int> getInitialStatuts() const = 0;
  virtual vector<int> getJoueurInitialStatuts() const = 0;
  virtual void playTurn(int indPlayer) const = 0;
  virtual int getStandardHandNbCarte() const = 0;
  virtual bool endGameCondition() const = 0;
  virtual int getWinnerPlayer() const = 0;

  virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt)=0;
  virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt)=0;
};
}; // namespace CardGame

#endif