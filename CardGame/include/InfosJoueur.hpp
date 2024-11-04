#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"
#include "InfosJoueurMonitor.hpp"

namespace CardGame {
class InfosJoueur {
private:
  _p_Hand mHand;
  _p_Plateau mPlateau;
  const int mPlayerId;
  _p_InfosJoueurMonitor mMonitor;

public:
  InfosJoueur(_p_InfosJoueurMonitor mm, const int PlayerId=-1);
  InfosJoueur(_p_InfosJoueurMonitor mm, const CardGame::_p_GameMechanics gm,
              const int PlayerId=-1);
  ~InfosJoueur();
  _p_Hand getHand() {return mHand; }
  _p_Plateau getPlateau() { return mPlateau; }

  _pc_Hand getHand() const { return mHand; }
  _pc_Plateau getPlateau() const { return mPlateau; }
};
}; // namespace CardGame

#endif
