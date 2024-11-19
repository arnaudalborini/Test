#ifndef HAND_HPP
#define HAND_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"

namespace CardGame{
    class Hand{
        private:
            vector<IdCarte> mCartes;
            int maxHandSize;
        protected:
            virtual weak_ptr<HandMonitor> getHandMonitor()const=0;
            virtual int getIdPlayer()const=0;
        public:
            Hand();
            ~Hand();
            void addCarteHand(IdCarte crt);
            IdCarte getCarteHand(int ind);
            int getNbCarteHand()const;
            int getIdCarteHand(int ind)const;
            void setMaxHandSize(int hSize);
            int getMaxHandSize()const;
            
    };
}

#endif