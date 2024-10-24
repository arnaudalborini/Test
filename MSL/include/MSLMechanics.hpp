#ifndef MSLMECHANICS_HPP
#define MSLMECHANICS_HPP

#include "MySmileLife.hpp"
#include "GameMechanicsSpe.hpp"

namespace MySmileLife{
    class MSLMechanics:public CardGame::GameMechanicsSpe{
        private:
            const CarteMSL* getCarteFromId(CardGame::IdCarte id)const;
            int  getSmileFromId(CardGame::IdCarte id)const;
            int  countSmile(CardGame::Plateau* plateauJoueur)const;
        public:
            MSLMechanics();   

            //methodes reimplementees  
            int  getStandardHandNbCarte()const; 
            int  getWinnerPlayer()const;
            void playTurn(int indPlayer) const;
            vector<int> getJoueurInitialStatuts() const;
    };
}
#endif