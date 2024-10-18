#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanics{
        private:
            vector<IdCarte> mCartes;
            GameMechanicsMonitor* mMonitor;
            CarteGenerator* cGen;
        public:
            GameMechanics();
            ~GameMechanics();
            void setMonitor(Monitor* mm);
            void setCarteGenerator(CarteGenerator* cg);
            virtual vector<IdCarte> genVecCartesPioche()const;
            virtual vector<IdCarte> genVecCartesDefausse()const;
            void initiatePlateau()const;
    };
};

#endif