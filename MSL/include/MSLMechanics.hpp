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
<<<<<<< HEAD
            int  getStatutPlayer(int indPlayer, DetailPlateau dp)const;
            void setStatutPlayer(int indPlayer, DetailPlateau dp, int value);
            void incStatutPlayer(int indPlayer, DetailPlateau dp, int inc=1);
            void decStatutPlayer(int indPlayer, DetailPlateau dp, int inc=1);
=======
>>>>>>> 8ace211 (setStatutplayer)
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