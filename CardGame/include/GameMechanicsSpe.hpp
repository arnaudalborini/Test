#ifndef GAMEMECHANICSSPE_HPP
#define GAMEMECHANICSSPE_HPP

#include "GameMechanics.hpp"
#include "CardGame.hpp"

namespace CardGame{
    class GameMechanicsSpe:public GameMechanics{
        public:
            GameMechanicsSpe(); 
            virtual ~GameMechanicsSpe();  
            virtual vector<IdCarte> genVecCartesPioche()const override;
            virtual vector<IdCarte> genVecCartesDefausse()const override;
            virtual map<int,vector<IdCarte>> genMapCartePlateauInitial()const override;
            virtual vector<int>     getJoueurInitialStatuts()const override;
            virtual vector<int>     getInitialStatuts()const override;
            virtual void playTurn(int indPlayer)const override;
            virtual int  getStandardHandNbCarte()const override;
            virtual bool endGameCondition()const override;
            virtual int  getWinnerPlayer()const override;
    };
}
#endif