#ifndef MSLPLAYER_HPP
#define MSLPLAYER_HPP

#include "Player.hpp"
#include "MySmileLife.hpp"

namespace MySmileLife{
    class MSLPlayer:public CardGame::Player{
        public:
            virtual string getName()const=0;
    };
}

#endif