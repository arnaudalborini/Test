#ifndef GAMEMECHANICSMONITOR_HPP
#define GAMEMECHANICSMONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsMonitor{
        public:      
            virtual _p_InfosJoueur    getInfosJoueurs(int ind)const=0;
            virtual _p_Plateau        getPlateauGeneral()const=0;
            virtual _p_PaquetCarte    getPioche()const=0;
            virtual _p_PaquetCarte    getDefausse()const=0;
            virtual _p_Plateau        getPlateauPlayer(int indPlayer)const=0;
            virtual _pc_Player        getPlayer(int ind)const=0;
            virtual int             getNbPlayer()const=0;
            virtual int             getIndPlayer(_pc_Player pp)const=0;
            virtual void            defausser(IdCarte crt, int indPlayer)const=0;
            virtual void            defausserDernier( int indPlayer, int EP)const=0;
            virtual void            defausserTout(int indPlayer, int EP)const=0;
            virtual int             getStatut(int indPlayer, int statut)const=0;
            virtual void            incStatut(int indPlayer, int statut, int inc)const=0;
            virtual void            setStatut(int indPlayer, int statut, int inc)const=0;
            virtual void            incStatutGeneral(int statut, int inc)const=0;
            virtual void            setStatutGeneral(int statut, int inc)const=0;
            virtual int             getStatutGeneral(int statut)const=0;
            virtual int             getNbCarteHand(int indPlayer)const=0;
            virtual IdCarte         joueurPioche(int indPlayer)const=0;
            virtual IdCarte         joueurDefausse(int indPlayer)const=0;

            virtual vector<IdCarte>     showHand(int indPlayer)const=0;
            virtual IdCarte             getCarteHand(int indPlayer, int indCarte)const=0;

            virtual void voirMainAutresJoueur(int indPlayer) const=0;
            virtual void voirNProchainesCartesPioche(int indPlayer, int N)const=0;
            virtual void addCarteToEP(int indPlayer, int EP, IdCarte id)const=0;
            
            virtual void            addCarteToEP(_pc_Player pp, int EP, IdCarte id)const=0;
            virtual _p_Plateau      getPlateauPlayer(_pc_Player pp)const=0;
            virtual _p_InfosJoueur  getInfosJoueurs(_pc_Player pp)const=0;
            virtual void voirMainAutresJoueur(_pc_Player pp)const=0;
            virtual void voirNProchainesCartesPioche(_pc_Player pp, int N)const=0;
            virtual int             getStatut(_pc_Player pp, int statut)const=0;
            virtual void            incStatut(_pc_Player pp, int statut, int inc)const=0;
            virtual void            setStatut(_pc_Player pp, int statut, int inc)const=0;
            virtual void            setMaxHandSize( _pc_Player pp, int value )const=0;
            virtual void            setMaxHandSize( int indPlayer, int value )const=0;
            virtual int             getMaxHandSize( int indPlayer )const=0;
            virtual int             getMaxHandSize(_pc_Player pp) const=0;
    };
}

#endif //MONITOR_HPP