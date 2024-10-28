#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Player{
        public:
            virtual string getName()const=0;
            virtual int choisirUneCarteAJouer(PaquetCarte* paq)const=0;
            virtual void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const=0;
    };
};

#endif