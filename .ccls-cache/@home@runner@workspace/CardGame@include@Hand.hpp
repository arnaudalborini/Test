#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<IdCarte> mCartes;
            HandMonitor* mMonitor;
            const int idPlayer;
        public:
            Hand(HandMonitor* mm,const int idP);
            ~Hand();
            void addCarte(IdCarte crt);
            IdCarte getCarte(int ind);
            int getNbCarte()const;
            int getIdCarte(int ind)const;
    };
};

#endif