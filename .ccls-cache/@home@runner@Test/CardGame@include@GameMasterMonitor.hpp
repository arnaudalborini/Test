#ifndef GAMEMASTERMONITOR_HPP
#define GAMEMASTERMONITOR_HPP

#include "CardGame.hpp"
#include "GameMechanicsMonitor.hpp"

namespace CardGame{
    class GameMasterMonitor: public GameMechanicsMonitor{
        public:
            virtual void initiateElements(int nbJoueurs,GameMechanics* gm)=0;
            virtual void addPlayer(const Player* pp, int index)=0;
            virtual void startGame()=0;
            virtual void removePlayer(int indice)=0;
            virtual int getWinner()const=0;
            virtual int getIndPlayer(const Player* pp)const=0;
            virtual const Carte* getCarte(IdCarte idC)const=0;
    };
}

#endif //GAMEMASTERMONITOR_HPP