#ifndef MSLPLAYER_HPP
#define MSLPLAYER_HPP

#include "Player.hpp"
#include "MySmileLife.hpp"
#include "PlayerInterface.hpp"
#include "CarteMSL.hpp"

namespace MySmileLife{
    class MSLPlayer:public Player{
        protected:
            const CarteMSL* getCarteMSL(IdCarte idC)const{return dynamic_cast<const CarteMSL*>(pI->getCarte(idC));}
        public:
            MSLPlayer(CardGame::GameInterface * gI):Player(gI){}
            virtual ~MSLPlayer(){}
    };
}

#endif