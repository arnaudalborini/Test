#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "Player.hpp"
#include "MySmileLife.hpp"
#include <string>

namespace MySmileLife{
    class BasicBot:public CardGame::Player{
        public:
            virtual string getName()const{return "basicbot";}
    };
}

#endif