#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<const Carte*> mCartes;
        public:
            Hand();
            ~Hand();
            void addCarte(const Carte* crt);
            const Carte* getCarte(int ind);
            int getNbCarte()const;
            int getIdCarte(int ind)const;
    };
};

#endif