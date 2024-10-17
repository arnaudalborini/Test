#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Monitor{
        private:
            vector<InfosJoueur*> mJoueurs;
            PaquetCarte* mPioche;
            PaquetCarte* mDefausse;
            Plateau* mPlateau;
            GameMechanics* mGameMechanics;
        public:
            Monitor();
            ~Monitor();
    };
}

#endif //MONITOR_HPP