#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"

namespace CardGame
{
    class InfosJoueur{
        private:
            Hand* mHand;
            Plateau* mPlateau;
        public:
            InfosJoueur();
            ~InfosJoueur();
    };
};

#endif
