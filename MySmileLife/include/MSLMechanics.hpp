#ifndef MSLMECHANICS_HPP
#define MSLMECHANICS_HPP

#include "MySmileLife.hpp"
#include "GameMechanicsSpe.hpp"

namespace MySmileLife{
    class MSLMechanics:public CardGame::GameMechanicsSpe{
        private:
        public:
            MSLMechanics();       
            /*
            virtual map<CardGame::EmplacementPlateauGeneral,CardGame::IdCarte> genMapCartePlateauInitial()const;
            virtual void playTurn(int indPlayer)const;
            virtual int getStandardHandNbCarte()const;
            virtual bool endGameCondition()const;
            virtual int getWinnerPlayer()const;
            virtual CardGame::Carte* getParamCarte(CardGame::IdCarte idC)const;*/
    };
}
#endif