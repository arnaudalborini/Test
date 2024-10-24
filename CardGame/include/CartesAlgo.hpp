#ifndef CARTESALGO_HPP
#define CARTESALGO_HPP

#include "CardGame.hpp"

namespace CardGame{
    class CartesAlgo{
        protected:
            const CarteGenerator* cGen;
            const GameMechanicsMonitor* mMonitor;
        public:
            CartesAlgo(const CarteGenerator* cc,const GameMechanicsMonitor* mm):cGen(cc),mMonitor(mm){}
            ~CartesAlgo(){}
            virtual bool peutEtreJouee(const Player *pp, IdCarte id)const;
            virtual bool jouerCarte(const Player* pp, IdCarte id)const;
    };
}

#endif