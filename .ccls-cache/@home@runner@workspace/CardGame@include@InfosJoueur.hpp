#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"
#include "InfosJoueurMonitor.hpp"

namespace CardGame {
class InfosJoueur {
private:
  Hand *mHand;
  Plateau *mPlateau;
  const int mPlayerId;
  InfosJoueurMonitor *mMonitor;

public:
  InfosJoueur(InfosJoueurMonitor *mm, const int PlayerId=-1);
  InfosJoueur(InfosJoueurMonitor *mm, const CardGame::GameMechanics *gm,
              const int PlayerId=-1);
  ~InfosJoueur();
  Hand *getHand() { return mHand; }
  Plateau *getPlateau() { return mPlateau; }

  const Hand *getHand() const { return mHand; }
  const Plateau *getPlateau() const { return mPlateau; }
};
}; // namespace CardGame

#endif
