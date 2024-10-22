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
        public:
            Monitor();
            virtual ~Monitor();
            // GameMechanicsMonitor
            virtual Plateau*        getPlateau()const;
            virtual PaquetCarte*    getPioche()const;
            virtual PaquetCarte*    getDefausse()const;
            virtual InfosJoueur*    getInfosJoueurs(int ind)const;
            virtual const Player*   getPlayer(int ind)const;
            virtual int             getNbPlayer()const;
            // GameMasterMonitor
            virtual void initiateElements(int nbJoueurs,GameMechanics* gm);
            virtual void addPlayer(const Player* pp, int index);
            virtual void startGame();
            virtual void removePlayer(int indice);
            virtual int  getWinner()const;
    };
}

#endif //MONITOR_HPP