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
            bool peutEtreJouee(const CarteMSL* mslCrt)const;
            void jouerCarte(const CarteMSL* mslCrt);
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