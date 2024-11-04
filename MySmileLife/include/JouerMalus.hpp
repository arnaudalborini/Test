#ifndef JOUERMALUS_HPP
#define JOUERMALUS_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMalus: private std::enable_shared_from_this<JouerMalus>{
        protected:
            bool peutEtreJoueeMalus(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteMalus(PCPlayer pp, PCCarteMSL crt)const;
        public:            
            virtual PCCarteGenerateurStandard          getCGen()const=0;
            virtual PCGameMechanicsMonitor   getMonitor()const=0;
            virtual bool peutEtreJouee(PCPlayer pp, IdCarte id)const=0;
            virtual bool jouerCarte(PCPlayer pp, IdCarte id)const=0;
            virtual PCPlayer getCible(PCPlayer pp, IdCarte id)const=0;

        private:
            bool peutEtreJoueeMalus(PCPlayer pp, CarteSousType st, PCPlayer Cible) const;

            void jouerAccident(PCPlayer pp)const;
            void jouerAttentat()const;
            void jouerBurnout(PCPlayer pp)const;
            void jouerDivorce(PCPlayer pp)const;
            void jouerImpots(PCPlayer pp)const;
            void jouerLicenciement(PCPlayer pp)const;
            void jouerMaladie(PCPlayer pp)const;
            void jouerPrison()const;
            void jouerRedoublement(PCPlayer pp)const;

    };
}
#endif