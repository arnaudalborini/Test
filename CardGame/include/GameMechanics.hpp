#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanics{
        private:
            GameMechanicsMonitor* mMonitor;
            CarteGenerator* cGen;
            vector<int> mTourAPasser;

            void joueurPioche(int indPlayer)const;
            void remplirMain(int indPlayer)const;
        public:
            GameMechanics();
            ~GameMechanics();
            void setMonitor(Monitor* mm);
            void setCarteGenerator(CarteGenerator* cg);
            void initGame()const;
            void startGame();
            virtual vector<IdCarte> genVecCartesPioche()const;
            virtual vector<IdCarte> genVecCartesDefausse()const;
            virtual map<EmplacementPlateauGeneral,IdCarte> genMapCartePlateauInitial()const;
            virtual void playTurn(const Player* pp)const;
            virtual int getStandardHandNbCarte()const;
            virtual bool endGameCondition()const;
    };
};

#endif