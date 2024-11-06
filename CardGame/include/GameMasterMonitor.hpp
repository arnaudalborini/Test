#ifndef GAMEMASTERMONITOR_HPP
#define GAMEMASTERMONITOR_HPP

#include "CardGame.hpp"
#include "GameMechanicsMonitor.hpp"

namespace CardGame{
    class GameMasterMonitor{
        public:
            virtual void initiateElements(int nbJoueurs,_p_GameMechanics gm)=0;
            virtual void addPlayer(_pc_Player pp, int index)=0;
            virtual void startGame()=0;
            virtual void removePlayer(int indice)=0;
            virtual int getWinner()const=0;
            virtual int getIndPlayer(_pc_Player pp)const=0;
            virtual _pc_Carte getCarte(IdCarte idC)const=0;
            virtual _p_InfosJoueur    getInfosJoueurs(int ind)const=0;
            virtual _p_InfosJoueur    getInfosJoueurs(_pc_Player pp)const=0;
            virtual _p_Plateau        getPlateauGeneral()const=0;
            virtual _p_PaquetCarte    getPioche()const=0;
            virtual _p_PaquetCarte    getDefausse()const=0;
    };
}

#endif //GAMEMASTERMONITOR_HPP