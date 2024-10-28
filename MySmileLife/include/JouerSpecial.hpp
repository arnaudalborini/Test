#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include <limits>

namespace MySmileLife{
    class JouerSpecial{
        protected:
            bool peutEtreJoueeSpecial(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSpecial(const Player *pp, const CarteMSL* crt)const;
        public:            
            virtual const CarteGenerateurStandard*          getCGen()const=0;
            virtual const CardGame::GameMechanicsMonitor*   getMonitor()const=0;
    };
}
#endif