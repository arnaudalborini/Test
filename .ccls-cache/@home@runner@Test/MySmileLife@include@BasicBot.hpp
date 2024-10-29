#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "MSLPlayer.hpp"
#include "MySmileLife.hpp"
#include "CardGame.hpp"
#include <string>

namespace MySmileLife{
    class BasicBot:public MSLPlayer{
        private:
            void afficherCarte(const CarteMSL* carte)const;
            void afficherCarte(CardGame::IdCarte id)const;
        public:
            BasicBot(CardGame::GameInterface * gI):MSLPlayer(gI){};
            virtual ~BasicBot(){};
    
            string getName()const override{return "basicbot";}
            int choisirUneCarteAJouer(CardGame::PaquetCarte* paq)const override{return 0;}
            void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const override;
            void showHandAutreJoueur(const Hand* h, int indAutrePlayer)const override;
            int choisirSalairePourPayer(const vector<IdCarte>& vecIdSalairesDisponibles)const override;
            int choisirIndiceCarteAJouerMain(const Hand* h)const override{return 0;};
            virtual int choisirCible(IdCarte id)const{return 0;}
    };
}

#endif