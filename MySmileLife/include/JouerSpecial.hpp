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
            virtual void choisirEtJouerUneCarteDefausse(const Player* pp)const=0;
        public:            
            virtual const CarteGenerateurStandard*          getCGen()const=0;
            virtual const CardGame::GameMechanicsMonitor*   getMonitor()const=0;
        private:
            void jouerAdultere(const Player* pp)const;
            void jouerTroc(const Player* pp)const;
            void jouerCasino(const Player* pp)const;
            void jouerChance(const Player* pp)const;
            void jouerPiston(const Player* pp)const;
            void jouerAnniversaire(const Player* pp)const;
            void jouerArcEnCiel(const Player* pp)const;
            void jouerEtoileFilante(const Player* pp)const;
            void jouerHeritage(const Player* pp)const;
            void jouerTsunami(const Player* pp)const;
            void jouerVengeance(const Player* pp)const;
            void jouerLegionHonneur(const Player* pp)const;
            void jouerGrandPrix(const Player* pp)const;
    };
}
#endif