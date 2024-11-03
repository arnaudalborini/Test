#ifndef GAMEMECHANICSMONITOR_HPP
#define GAMEMECHANICSMONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsMonitor{
        public:      
            virtual PPlateau        getPlateau()const=0;
            virtual PPlateau        getPlateauPlayer(int indPlayer)const=0;
            virtual PPlateau        getPlateauPlayer(PCPlayer pp)const=0;
            virtual PPaquetCarte    getPioche()const=0;
            virtual PPaquetCarte    getDefausse()const=0;
            virtual PInfosJoueur    getInfosJoueurs(int ind)const=0;
            virtual PInfosJoueur    getInfosJoueurs(PCPlayer pp)const=0;
            virtual PCPlayer        getPlayer(int ind)const=0;
            virtual int             getNbPlayer()const=0;
            virtual int             getIndPlayer(PCPlayer pp)const=0;
            virtual void            defausser(IdCarte crt, int indPlayer)const=0;
            virtual void            defausserDernier( int indPlayer, int EP)const=0;
            virtual void            defausserTout(int indPlayer, int EP)const=0;
            virtual void            incStatut(int indPlayer, int statut, int inc)const=0;
    };
}

#endif //MONITOR_HPP