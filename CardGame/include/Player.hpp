#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Player{
        public:
            virtual string getName()const=0;
            virtual int choisirUneCarteAJouer(PaquetCarte* paq)const=0;
            virtual void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const=0;
            virtual void showHandAutreJoueur(const Hand* h, int indAutrePlayer)const=0;
            virtual int choisirSalairePourPayer(const vector<IdCarte>& vecIdSalairesDisponibles)const=0;
            virtual int choisirIndiceCarteAJouerMain(const Hand* h)const=0;
            virtual int choisirCible(IdCarte id)const=0;
    };
};

#endif