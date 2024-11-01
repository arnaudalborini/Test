#ifndef JOUEURINTERFACE_HPP
#define JOUEURINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameInterface{
        public:
            virtual const PlayerInterface* login(const Player* pp)=0;
    };
};

#endif