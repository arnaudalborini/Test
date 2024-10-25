#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"
#include "GameMasterMonitor.hpp"

namespace CardGame{
    class Monitor:public GameMasterMonitor{
        protected:
            int mNbJoueur;
            GameMechanics*          mGameMechanics;
            vector<InfosJoueur*>    mInfosJoueurs;
            vector<const Player*>   mPlayer;
            Plateau*                mPlateau;
            PaquetCarte*            mPioche;
            PaquetCarte*            mDefausse;
            map<const Player*,int>  mapIdPlayer;
        public:
            Monitor();
            ~Monitor();
            // GameMechanicsMonitor
            Plateau*        getPlateau()const override;
            PaquetCarte*    getPioche()const override;
            PaquetCarte*    getDefausse()const override;
            InfosJoueur*    getInfosJoueurs(int ind)const override;
            const Player*   getPlayer(int ind)const override;
            int             getIndPlayer(const Player* pp)const override;
            int             getNbPlayer()const override;
            // GameMasterMonitor
            void initiateElements(int nbJoueurs,GameMechanics* gm) override;
            void addPlayer(const Player* pp, int index) override;
            void startGame() override;
            void removePlayer(int indice) override;
            int  getWinner()const override;
    };
}

#endif //MONITOR_HPP