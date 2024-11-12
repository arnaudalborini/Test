#ifndef EFFETCARTEPLATEAU_HPP
#define EFFETCARTEPLATEAU_HPP

#include "MySmileLife.hpp"

namespace MySmileLife{
    class EffetCartePlateauMain{
        private:
            weak_ptr<const CardGame::GameMechanicsMonitor> mMonitor;
            weak_ptr<const CarteGenerateurStandard> cGen;

            void effetEntrerPlateauSpe(const int indPlayer, const CarteSousType cst)const;
            void effetQuitterPlateauSpe(const int indPlayer, const CarteSousType cst)const;
            void effetEntrerPlateauMetier(const int indPlayer, _pc_CarteMSL crt)const;
            void effetQuitterPlateauMetier(const int indPlayer, _pc_CarteMSL crt)const;
        public:
            EffetCartePlateauMain(weak_ptr<const CarteGenerateurStandard> cc,weak_ptr<const CardGame::GameMechanicsMonitor> mm);
            void effetEntrerPlateau(const int indPlayer, _pc_CarteMSL crt, EmplacementsPlateau EP)const;
            void effetQuitterPlateau(const int indPlayer, _pc_CarteMSL crt, EmplacementsPlateau EP)const;
            void effetEntrerHand(const int indPlayer, _pc_CarteMSL crt)const;
            void effetQuitterHand(const int indPlayer, _pc_CarteMSL crt)const;
    };
}

#endif