#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "CardGame.hpp"

#include "GameMechanicsMonitor.hpp"
#include "GameMasterMonitor.hpp"
#include "InfosJoueurMonitor.hpp"

namespace CardGame{
    class Monitor: public GameMasterMonitor, public GameMechanicsMonitor, public InfosJoueurMonitor{

        public:/*
            //GameMasterMonitor
            virtual void initiateElements(int nbJoueurs,_p_GameMechanics gm)=0;
            virtual void addPlayer(_pc_Player pp, int index)=0;
            virtual void startGame()=0;
            virtual void removePlayer(int indice)=0;
            virtual int getWinner()const=0;
            virtual int getIndPlayer(_pc_Player pp)const=0;
            virtual _pc_Carte getCarte(IdCarte idC)const=0;
            
            //GameMechanicsMonitor
            virtual _p_Plateau        getPlateau()const=0;
            virtual _p_Plateau        getPlateauPlayer(int indPlayer)const=0;
            virtual _p_Plateau        getPlateauPlayer(_pc_Player pp)const=0;
            virtual _p_PaquetCarte    getPioche()const=0;
            virtual _p_PaquetCarte    getDefausse()const=0;
            virtual _p_InfosJoueur    getInfosJoueurs(int ind)const=0;
            virtual _p_InfosJoueur    getInfosJoueurs(_pc_Player pp)const=0;
            virtual _pc_Player        getPlayer(int ind)const=0;
            virtual int             getNbPlayer()const=0;
            virtual int             getIndPlayer(_pc_Player pp)const=0;
            virtual void            defausser(IdCarte crt, int indPlayer)const=0;
            virtual void            defausserDernier( int indPlayer, int EP)const=0;
            virtual void            defausserTout(int indPlayer, int EP)const=0;
            virtual void            incStatut(int indPlayer, int statut, int inc)const=0;
                
            //InfosJoueurMonitor
            virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt)=0;
            virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) = 0;
            */
    };
}

#endif