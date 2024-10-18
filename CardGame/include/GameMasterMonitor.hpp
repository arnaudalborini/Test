#ifndef GAMEMASTERMONITOR_HPP
#define GAMEMASTERMONITOR_HPP

#include "CardGame.hpp"
#include "Monitor.hpp"

namespace CardGame{
    class GameMasterMonitor:public Monitor{
        public:
            GameMasterMonitor();
            ~GameMasterMonitor();
            //////////////////GameMaster interface//////////////////////
            //créer tous les sous-éléments
            void initiateElements(int nbJoueurs,GameMechanics* gm);
            //log a player in
            void addPlayer(Player* pp, int index);
            //start the game
            void startGame();
            //enleve un joueur
            void removePlayer(int indice);
    };
}

#endif //MONITOR_HPP