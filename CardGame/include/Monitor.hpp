#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Monitor{
        protected:
            int mNbJoueur;
            GameMechanics* mGameMechanics;
            vector<InfosJoueur*> mInfosJoueurs;
            vector<Player*> mPlayer;
            PaquetCarte* mPioche;
            PaquetCarte* mDefausse;
            Plateau* mPlateau;
        public:
            Monitor();
            virtual ~Monitor();
    };
}

#endif //MONITOR_HPP