#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"

namespace CardGame{
    class GameMaster: public GameInterface{
        public:
            GameMaster();
            ~GameMaster();
            virtual int login(const Player* pp);
    };
};

#endif