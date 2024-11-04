#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"
#include "PlayerInterface.hpp"

namespace CardGame{
    class GameMaster: public GameInterface, public PlayerInterface, private std::enable_shared_from_this<GameMaster>{
        private:
            PGameMasterMonitor mMonitor;
            int mNbJoueur;
            vector<bool> mJoueurPret;
            vector<PPlayer> mJoueurs;
            void initGame(int nj, PGameMechanics gm);
        public:
            GameMaster(int nj, PGameMechanics gm);
            ~GameMaster();
            void startGame();
            int getWinner()const;
        public:
            //GameInterface
            virtual PCPlayerInterface   login(PCPlayer pp);
            virtual int                 getIdPlayer(PCPlayer pp)const;
            //PlayerInterface
            virtual PCInfosJoueur       getInfosJoueurs(int indPlayer)const;
            virtual PCPlateau           getPlateau()const;
            virtual PCPaquetCarte       getPioche()const;
            virtual PCPaquetCarte       getDefausse()const;
            virtual PCCarte             getCarte(IdCarte idC)const;
            virtual int                 getStatutPlayer(int indPlayer, int dp)const;
    };
};

#endif