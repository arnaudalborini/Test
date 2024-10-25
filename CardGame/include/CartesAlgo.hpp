#ifndef CARTESALGO_HPP
#define CARTESALGO_HPP

#include "CardGame.hpp"

namespace CardGame{
    class CartesAlgo{
        protected:
            CarteGenerator* cGen;
            GameMechanicsMonitor* mMonitor;
        public:
            CartesAlgo(CarteGenerator* cc,GameMechanicsMonitor* mm):cGen(cc),mMonitor(mm){}
            ~CartesAlgo(){}
            virtual bool peutEtreJouee(const Player *pp, IdCarte id)const{return false;}
            virtual bool jouerCarte(const Player* pp, IdCarte id)const{return false;}
    };
}

#endif