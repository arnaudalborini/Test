#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"
#include "PlayerInterface.hpp"

namespace CardGame{
    class GameMaster: public GameInterface, public PlayerInterface, private std::enable_shared_from_this<GameMaster>{
        private:
            _p_GameMasterMonitor mMonitor;
            int mNbJoueur;
            vector<bool> mJoueurPret;
            vector<_p_Player> mJoueurs;
            void initGame(int nj, _p_GameMechanics gm);
        public:
            GameMaster(int nj, _p_GameMechanics gm);
            ~GameMaster();
            void startGame();
            int getWinner()const;
        public:
            //GameInterface
            virtual _pc_PlayerInterface   login(_pc_Player pp);
            virtual int                 getIdPlayer(_pc_Player pp)const;
            //PlayerInterface
            virtual _pc_InfosJoueur       getInfosJoueurs(int indPlayer)const;
            virtual _pc_Plateau           getPlateau()const;
            virtual _pc_PaquetCarte       getPioche()const;
            virtual _pc_PaquetCarte       getDefausse()const;
            virtual _pc_Carte             getCarte(IdCarte idC)const;
            virtual int                 getStatutPlayer(int indPlayer, int dp)const;
    };
};

#endif