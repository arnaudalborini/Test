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
            Hand*           getHand(){return mHand;}
            Plateau*        getPlateau(){return mPlateau;}
            
            const Hand*     getHand()const{return mHand;}
            const Plateau*  getPlateau()const{return mPlateau;}

    };
};

#endif
