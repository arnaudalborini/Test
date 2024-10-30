#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<IdCarte> mCartes;
        public:
            Hand();
            ~Hand();
            void addCarte(IdCarte crt);
            IdCarte getCarte(int ind);
            int getNbCarte()const;
            int getIdCarte(int ind)const;
    };
};

#endif