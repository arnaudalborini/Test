#ifndef GAMEMECHANICSMONITOR_HPP
#define GAMEMECHANICSMONITOR_HPP

#include "CardGame.hpp"
#include "Monitor.hpp"

namespace CardGame{
    class GameMechanicsMonitor:public Monitor{
        private:
            GameMechanicsMonitor();
            ~GameMechanicsMonitor();
        public:            
            Plateau*        getPlateau()const;
            PaquetCarte*    getPioche()const;
            PaquetCarte*    getDefausse()const;
            InfosJoueur*    getInfosJoueursP(int ind)const;
            const Player*   getPlayerP(int ind)const;
            int             getNbPlayer()const;
    };
}

#endif //MONITOR_HPP