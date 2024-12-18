#ifndef GAMEMECHANICSSPE_HPP
#define GAMEMECHANICSSPE_HPP

#include "CardGame.hpp"
#include "GameMechanics.hpp"

namespace CardGame {
class GameMechanicsSpe : public GameMechanics {
public:
  GameMechanicsSpe();
  virtual ~GameMechanicsSpe();
  virtual vector<IdCarte> genVecCartesPioche() const override;
  virtual vector<IdCarte> genVecCartesDefausse() const override;
  virtual vector<vector<IdCarte>> genMapCartePlateauInitial() const override;
  virtual vector<int> getJoueurInitialStatuts() const override;
  virtual vector<int> getInitialStatuts() const override;
  virtual void playTurn(int indPlayer) const override;
  virtual int getStandardHandNbCarte() const override;
  virtual bool endGameCondition() const override;
  virtual int getWinnerPlayer() const override;
  virtual void effetQuitterPlateau([[maybe_unused]]const int indPlayer,
                                   [[maybe_unused]]const IdCarte idCrt, int EP) override {}
  virtual void effetQuitterHand([[maybe_unused]]const int indPlayer,
                                [[maybe_unused]]const IdCarte idCrt) override {}
  virtual void effetEntrerPlateau([[maybe_unused]]const int indPlayer, [[maybe_unused]]const IdCarte idCrt, int EP) override{};
  virtual void effetEntrerHand([[maybe_unused]]const int indPlayer,[[maybe_unused]] const IdCarte idCrt) override{};
};
} // namespace CardGame
#endif