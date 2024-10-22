#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"

namespace CardGame{
    class GameMaster: public GameInterface{
        private:
            GameMasterMonitor* mMonitor;
            int mNbJoueur;
            vector<bool> mJoueurPret;
            vector<Player*> mJoueurs;
        public:
            GameMaster();
            ~GameMaster();
            void initGame(int nj, GameMechanics* gm);
            virtual int login(const Player* pp);
            void startGame();
            int getWinner()const;
    };
};

#endif