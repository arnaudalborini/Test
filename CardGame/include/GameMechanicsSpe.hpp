#ifndef GAMEMECHANICSSPE_HPP
#define GAMEMECHANICSSPE_HPP

#include "GameMechanics.hpp"
#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsSpe:public GameMechanics{
        public:
            GameMechanicsSpe(); 
            virtual ~GameMechanicsSpe();  
            virtual vector<IdCarte> genVecCartesPioche()const;
            virtual vector<IdCarte> genVecCartesDefausse()const;
            virtual map<EmplacementPlateauGeneral,IdCarte> genMapCartePlateauInitial()const;
            virtual vector<int>     getJoueurInitialStatuts()const;
            virtual void playTurn(int indPlayer)const;
            virtual int  getStandardHandNbCarte()const;
            virtual bool endGameCondition()const;
            virtual int  getWinnerPlayer()const;
    };
}
#endif