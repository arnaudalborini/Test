#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "MSLPlayer.hpp"
#include "MySmileLife.hpp"
#include <string>

namespace MySmileLife{
    class BasicBot:public MSLPlayer{
        public:
            string getName()const override{return "basicbot";}
            int choisirUneCarteAJouer(CardGame::PaquetCarte* paq)const override{return 0;}
            void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const override;
            void showHandAutreJoueur(const Hand* h, int indAutrePlayer)const override;
            virtual int choisirSalairePourPayer(const vector<IdCarte>& vecIdSalairesDisponibles)const;
    };
}

#endif