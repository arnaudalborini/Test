#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"
#include "PlayerInterface.hpp"

namespace CardGame{
    class GameMaster: public GameInterface, public PlayerInterface{
        private:
            GameMasterMonitor* mMonitor;
            int mNbJoueur;
            vector<bool> mJoueurPret;
            vector<Player*> mJoueurs;
            map<const Player*,int> mapIdPlayer;
            void initGame(int nj, GameMechanics* gm);
        public:
            GameMaster(int nj, GameMechanics* gm);
            ~GameMaster();
            void startGame();
            int getWinner()const;
        public:
            //GameInterface
            virtual const PlayerInterface* login(const Player* pp);
            virtual int   getIdPlayer(const Player*)const;
            //PlayerInterface
            virtual const InfosJoueur*  getInfosJoueurs(int indPlayer)const;
            virtual const Plateau*      getPlateau()const;
            virtual const PaquetCarte*  getPioche()const;
            virtual const PaquetCarte*  getDefausse()const;
            virtual const Carte*        getCarte(IdCarte idC)const;
            virtual int                 getStatutPlayer(int indPlayer, int dp)const;
    };
};

#endif