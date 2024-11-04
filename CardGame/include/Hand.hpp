#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<IdCarte> mCartes;
            _p_HandMonitor mMonitor;
            const int idPlayer;
        public:
            Hand(_p_HandMonitor mm,const int idP);
            ~Hand();
            void addCarte(IdCarte crt);
            IdCarte getCarte(int ind);
            int getNbCarte()const;
            int getIdCarte(int ind)const;
    };
};

#endif