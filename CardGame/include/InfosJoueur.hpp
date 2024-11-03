#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"
#include "InfosJoueurMonitor.hpp"

namespace CardGame {
class InfosJoueur {
private:
  PHand mHand;
  PPlateau mPlateau;
  const int mPlayerId;
  PInfosJoueurMonitor mMonitor;

public:
  InfosJoueur(PInfosJoueurMonitor mm, const int PlayerId=-1);
  InfosJoueur(PInfosJoueurMonitor mm, const CardGame::PGameMechanics gm,
              const int PlayerId=-1);
  ~InfosJoueur();
  PHand getHand() {return mHand; }
  PPlateau getPlateau() { return mPlateau; }

  PCHand getHand() const { return mHand; }
  PCPlateau getPlateau() const { return mPlateau; }
};
}; // namespace CardGame

#endif
