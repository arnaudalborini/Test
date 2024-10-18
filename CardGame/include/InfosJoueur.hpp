#ifndef INFOSJOUEUR_H
#define INFOSJOUEUR_H

#include "CardGame.hpp"

namespace CardGame
{
    class InfosJoueur{
        private:
            Hand* mHand;
            PlateauJoueur* mPlateauJoueur;
        public:
            InfosJoueur();
            ~InfosJoueur();
    };
};

#endif
