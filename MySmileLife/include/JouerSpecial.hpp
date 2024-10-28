#ifndef JOUERSPECIAL_HPP
#define JOUERSPECIAL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include <limits>

namespace MySmileLife{
    class JouerSpecial{
            CardGame::CarteGenerator* cGen;
            const CardGame::GameMechanicsMonitor* mMonitor;
            const JouerMalus* jMalus;

        public:
            JouerSpecial(CardGame::CarteGenerator* cg, CardGame::GameMechanicsMonitor* mm):cGen(cg),mMonitor(mm),jMalus(new JouerMalus(cg,mm)){}
            ~JouerSpecial(){delete jMalus;}
            bool peutEtreJoueeSpecial(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSpecial(const Player *pp, const CarteMSL* crt)const;
    };
}
#endif