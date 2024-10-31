#ifndef MSLMECHANICSTEST_HPP
#define MSLMECHANICSTEST_HPP

#include "../include/MSLMechanics.hpp"
#include "GameMechanicsSpe.hpp"
#include "MySmileLife.hpp"
#include "TestScenario.hpp"

namespace MySmileLife::Tests {
using namespace MySmileLife;
class MSLMechanicsTest : public MSLMechanics {
private:
  TestScenario test;
  void printHand(const Hand* h)const;
  void printStatut(const Plateau* h)const;
  void printPlateau(const Plateau* h)const;

public:
  MSLMechanicsTest(const TestScenario &test);
  ~MSLMechanicsTest();
  // methodes reimplementees
  void playTurn(int indPlayer) const override;
  vector<int> getJoueurInitialStatuts() const override;
  vector<int> getInitialStatuts() const override;
  vector<vector<IdCarte>> genMapCartePlateauInitial() const override;
  void initSpeficiGame() override;
};
} // namespace MySmileLife::Tests
#endif