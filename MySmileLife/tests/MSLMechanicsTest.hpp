#ifndef MSLMECHANICSTEST_HPP
#define MSLMECHANICSTEST_HPP

#include "../include/MSLMechanics.hpp"
#include "GameMechanicsSpe.hpp"
#include "MySmileLife.hpp"

namespace MySmileLife {
class MSLMechanicsTest : public MSLMechanics {
private:
  vector<int> vecInitHand;
  vector<int> vecInitStatuts;
  vector<vector<CardGame::IdCarte>> vecInitPlateau;

public:
  MSLMechanicsTest(const vector<int> &vH, const vector<int> &vS,
                   const vector<vector<CardGame::IdCarte>> &mP);
  ~MSLMechanicsTest();
  // methodes reimplementees
  void playTurn(int indPlayer) const override;
  vector<int> getJoueurInitialStatuts() const override;
  vector<int> getInitialStatuts() const override;
  vector<vector<IdCarte>> genMapCartePlateauInitial() const override;
  void initSpeficiGame() override;
};
} // namespace MySmileLife
#endif