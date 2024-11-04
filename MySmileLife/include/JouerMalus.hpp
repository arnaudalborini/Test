#ifndef JOUERMALUS_HPP
#define JOUERMALUS_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMalus: private std::enable_shared_from_this<JouerMalus>{
        protected:
            bool peutEtreJoueeMalus(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMalus(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
        public:            
            virtual _pc_CarteGenerateurStandard          getCGen()const=0;
            virtual CardGame::_pc_GameMechanicsMonitor   getMonitor()const=0;
            virtual bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id)const=0;
            virtual bool jouerCarte(CardGame::_pc_Player pp, IdCarte id)const=0;
            virtual CardGame::_pc_Player getCible(CardGame::_pc_Player pp, IdCarte id)const=0;

        private:
            bool peutEtreJoueeMalus(CardGame::_pc_Player pp, CarteSousType st, CardGame::_pc_Player Cible) const;

            void jouerAccident(CardGame::_pc_Player pp)const;
            void jouerAttentat()const;
            void jouerBurnout(CardGame::_pc_Player pp)const;
            void jouerDivorce(CardGame::_pc_Player pp)const;
            void jouerImpots(CardGame::_pc_Player pp)const;
            void jouerLicenciement(CardGame::_pc_Player pp)const;
            void jouerMaladie(CardGame::_pc_Player pp)const;
            void jouerPrison()const;
            void jouerRedoublement(CardGame::_pc_Player pp)const;

    };
}
#endif