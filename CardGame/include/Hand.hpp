#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<IdCarte> mCartes;
        protected:
            virtual _p_HandMonitor getHandMonitor()const=0;
            virtual int getIdPlayer()const=0;
        public:
            Hand();
            ~Hand();
            void addCarteHand(IdCarte crt);
            IdCarte getCarteHand(int ind);
            int getNbCarteHand()const;
            int getIdCarteHand(int ind)const;
    };
};

#endif