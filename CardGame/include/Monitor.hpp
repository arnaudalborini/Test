#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Monitor{
        protected:
            int mNbJoueur;
            GameMechanics*          mGameMechanics;
            vector<InfosJoueur*>    mInfosJoueurs;
            vector<const Player*>   mPlayer;
            Plateau*                mPlateau;
            PaquetCarte*            mPioche;
            PaquetCarte*            mDefausse;
        public:
            Monitor();
            virtual ~Monitor();
    };
}

#endif //MONITOR_HPP