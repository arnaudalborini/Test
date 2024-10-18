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
            void initiatePioche(const vector<IdCarte> &mCartes);
            void initiateDefausse(const vector<IdCarte> &mCartes);
    };
}

#endif //MONITOR_HPP