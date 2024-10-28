#ifndef BASICBOT_HPP
#define BASICBOT_HPP

#include "MSLPlayer.hpp"
#include "MySmileLife.hpp"
#include <string>

namespace MySmileLife{
    class BasicBot:public MSLPlayer{
        public:
            virtual string getName()const{return "basicbot";}
            virtual int choisirUneCarteAJouer(CardGame::PaquetCarte* paq)const{return 0;}
    };
}

#endif