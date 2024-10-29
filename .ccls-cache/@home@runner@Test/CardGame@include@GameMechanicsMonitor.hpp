#ifndef GAMEMECHANICSMONITOR_HPP
#define GAMEMECHANICSMONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsMonitor{
        public:      
            virtual Plateau*        getPlateau()const=0;
            virtual Plateau*        getPlateauPlayer(int indPlayer)const=0;
            virtual Plateau*        getPlateauPlayer(const Player* pp)const=0;
            virtual PaquetCarte*    getPioche()const=0;
            virtual PaquetCarte*    getDefausse()const=0;
            virtual InfosJoueur*    getInfosJoueurs(int ind)const=0;
            virtual InfosJoueur*    getInfosJoueurs(const Player* pp)const=0;
            virtual const Player*   getPlayer(int ind)const=0;
            virtual int             getNbPlayer()const=0;
            virtual int             getIndPlayer(const Player* pp)const=0;
            virtual void            defausser(IdCarte crt, int indPlayer)const=0;
            virtual void            defausserDernier( int indPlayer, int EP)const=0;
            virtual void            defausserTout(int indPlayer, int EP)const=0;
            virtual void            incStatut(int indPlayer, int statut, int inc)const=0;
    };
}

#endif //MONITOR_HPP