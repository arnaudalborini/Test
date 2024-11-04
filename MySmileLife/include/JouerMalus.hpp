#ifndef JOUERMALUS_HPP
#define JOUERMALUS_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMalus: private std::enable_shared_from_this<JouerMalus>{
        protected:
            bool peutEtreJoueeMalus(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMalus(_pc_Player pp, _pc_CarteMSL crt)const;
        public:            
            virtual _pc_CarteGenerateurStandard          getCGen()const=0;
            virtual _pc_GameMechanicsMonitor   getMonitor()const=0;
            virtual bool peutEtreJouee(_pc_Player pp, IdCarte id)const=0;
            virtual bool jouerCarte(_pc_Player pp, IdCarte id)const=0;
            virtual _pc_Player getCible(_pc_Player pp, IdCarte id)const=0;

        private:
            bool peutEtreJoueeMalus(_pc_Player pp, CarteSousType st, _pc_Player Cible) const;

            void jouerAccident(_pc_Player pp)const;
            void jouerAttentat()const;
            void jouerBurnout(_pc_Player pp)const;
            void jouerDivorce(_pc_Player pp)const;
            void jouerImpots(_pc_Player pp)const;
            void jouerLicenciement(_pc_Player pp)const;
            void jouerMaladie(_pc_Player pp)const;
            void jouerPrison()const;
            void jouerRedoublement(_pc_Player pp)const;

    };
}
#endif