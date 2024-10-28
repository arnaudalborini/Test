#ifndef JOUERMALUS_HPP
#define JOUERMALUS_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMalus{
        protected:
            bool peutEtreJoueeMalus(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMalus(const Player *pp, const CarteMSL* crt)const;
        public:            
            virtual const CarteGenerateurStandard*          getCGen()const=0;
            virtual const CardGame::GameMechanicsMonitor*   getMonitor()const=0;
            virtual bool peutEtreJouee(const Player *pp, IdCarte id)const=0;
            virtual bool jouerCarte(const Player* pp, IdCarte id)const=0;

        private:
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

    };
}
#endif