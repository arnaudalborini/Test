#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanics{
        private:
            vector<IdCarte> mCartes;
            GameMechanicsMonitor* mMonitor;
            CarteGenerator* cGen;

            void joueurPioche(int indPlayer)const;
            void remplirMain(int indPlayer)const;
        public:
            GameMechanics();
            ~GameMechanics();
            void setMonitor(Monitor* mm);
            void setCarteGenerator(CarteGenerator* cg);
            virtual vector<IdCarte> genVecCartesPioche()const;
            virtual vector<IdCarte> genVecCartesDefausse()const;
            virtual map<EmplacementPlateauGeneral,IdCarte> genMapCartePlateauInitial()const;
            void initGame()const;
            void startGame()const;
            virtual void playTurn(const Player* pp)const;
            virtual int getStandardHandNbCarte()const{return 1;}
    };
};

#endif