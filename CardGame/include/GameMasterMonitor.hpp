#ifndef GAMEMASTERMONITOR_HPP
#define GAMEMASTERMONITOR_HPP

#include "CardGame.hpp"
#include "Monitor.hpp"

namespace CardGame{
    class GameMasterMonitor:public Monitor{
        public:
            GameMasterMonitor();
            ~GameMasterMonitor();
            
            void initiateElements(int nbJoueurs,GameMechanics* gm);
            void addPlayer(const Player* pp, int index);
            void startGame();
            void removePlayer(int indice);
            int getWinner()const;
    };
}

#endif //MONITOR_HPP