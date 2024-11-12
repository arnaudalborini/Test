#ifndef JOUEURINTERFACE_HPP
#define JOUEURINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameInterface{
        public:
            virtual _pc_PlayerInterface login(_pc_Player pp)=0;
    };
}

#endif