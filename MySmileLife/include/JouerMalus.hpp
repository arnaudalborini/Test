#ifndef JOUERMALUS_HPP
#define JOUERMALUS_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMalus{
        private:
            CardGame::CarteGenerator* cGen;
            const CardGame::GameMechanicsMonitor* mMonitor;
            
            bool peutEtreJoueeMalus(const Player *pp, CarteSousType st, const Player* Cible) const;
            const Player* getCibleMalus(const Player* pp, CarteSousType typeMalus)const;

            void jouerAccident(const Player *pp)const;
            void jouerAttentat()const;
            void jouerBurnout(const Player *pp)const;
            void jouerDivorce(const Player *pp)const;
            void jouerImpots(const Player *pp)const;
            void jouerLicenciement(const Player *pp)const;
            void jouerMaladie(const Player *pp)const;
            void jouerPrison()const;
            void jouerRedoublement(const Player *pp)const;

        public:
            JouerMalus(CardGame::CarteGenerator* cg, CardGame::GameMechanicsMonitor* mm):cGen(cg),mMonitor(mm){}
            bool peutEtreJoueeMalus(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMalus(const Player *pp, const CarteMSL* crt)const;
    };
}
#endif