#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "Player.hpp"
#include <string>

namespace Test{
    class BasicBot:public CardGame::Player{
        public:
            virtual std::string getName()const{return "basicbot";}
    };
}

#endif