#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"
#include "InfosJoueurMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"

namespace CardGame {
class InfosJoueur:public Plateau, public Hand, public std::enable_shared_from_this<InfosJoueur> {
private:
  const int mPlayerId;
  weak_ptr<InfosJoueurMonitor> mMonitor;

protected:
  virtual weak_ptr<HandMonitor> getHandMonitor()const;
  virtual int getIdPlayer()const;

public:
  InfosJoueur(_p_InfosJoueurMonitor mm, const int PlayerId=-1);
  InfosJoueur(_p_InfosJoueurMonitor mm, const vector<IdCarte> &vec, const int PlayerId=-1);
  ~InfosJoueur();
  _p_Hand getHand();
  _p_Plateau getPlateau();

  _pc_Hand getHand() const;
  _pc_Plateau getPlateau() const;
};
}; // namespace CardGame

#endif
