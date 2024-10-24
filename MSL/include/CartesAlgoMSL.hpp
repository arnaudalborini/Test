#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "MySmileLife.hpp"
#include "CartesAlgo.hpp"

namespace MySmileLife{
    class CartesAlgoMSL:public CardGame::CartesAlgo{
        private:
            const CarteMSL* getCarteMSL(CardGame::IdCarte id)const;
        public:
            CartesAlgoMSL(const CardGame::CarteGenerator* cc,const CardGame::GameMechanicsMonitor* mm):CardGame::CartesAlgo(cc,mm){}
            ~CartesAlgoMSL(){}
            virtual bool peutEtreJouee(const CardGame::Player *pp, CardGame::IdCarte id)const;
            virtual bool jouerCarte(const CardGame::Player* pp, CardGame::IdCarte id)const;
    };
}

#endif