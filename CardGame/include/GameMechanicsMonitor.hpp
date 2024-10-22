#ifndef GAMEMECHANICSMONITOR_HPP
#define GAMEMECHANICSMONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsMonitor{
        public:      
            virtual Plateau*        getPlateau()const=0;
            virtual PaquetCarte*    getPioche()const=0;
            virtual PaquetCarte*    getDefausse()const=0;
            virtual InfosJoueur*    getInfosJoueurs(int ind)const=0;
            virtual const Player*   getPlayer(int ind)const=0;
            virtual int             getNbPlayer()const=0;
    };
}

#endif //MONITOR_HPP