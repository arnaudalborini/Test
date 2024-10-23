#ifndef GAMEMECHANICS_HPP
#define GAMEMECHANICS_HPP

#include "CardGame.hpp"

namespace CardGame{
    class GameMechanics{
        protected:
            GameMechanicsMonitor* mMonitor;
            CarteGenerator* cGen;
            vector<int> mTourAPasser;

            void joueurPioche(int indPlayer)const;
            void remplirMain(int indPlayer)const;
            int getNbCartePioche()const;
            int getNbCarteDefausse()const;
            void addCarteDefausse(IdCarte idC, int IdPlayer)const;
            void addCarteDefausse(IdCarte idC)const;
            const Player* getPlayer(int indPlayer)const;
            Hand* getJoueurHand(int indPlayer)const;
        public:
            GameMechanics();
            ~GameMechanics();
            void setMonitor(Monitor* mm);
            void initGame()const;
            void startGame();

            virtual vector<IdCarte> genVecCartesPioche()const=0;
            virtual vector<IdCarte> genVecCartesDefausse()const=0;
            virtual map<EmplacementPlateauGeneral,IdCarte> genMapCartePlateauInitial()const=0;
            virtual void playTurn(int indPlayer)const=0;
            virtual int getStandardHandNbCarte()const=0;
            virtual bool endGameCondition()const=0;
            virtual int getWinnerPlayer()const=0;
    };
};

#endif