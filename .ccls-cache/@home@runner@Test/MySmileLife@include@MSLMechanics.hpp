#ifndef MSLMECHANICS_HPP
#define MSLMECHANICS_HPP

#include "MySmileLife.hpp"
#include "GameMechanicsSpe.hpp"

namespace MySmileLife{
    class MSLMechanics final:public CardGame::GameMechanicsSpe{
        private:
            const CarteMSL* getCarteFromId(IdCarte id)const;
            int  countSmile(Plateau* plateauJoueur)const;
        public:
            MSLMechanics();   
            ~MSLMechanics();   
            //methodes reimplementees  
            void initSpeficiGame() override;
            int  getStandardHandNbCarte()const override; 
            int  getWinnerPlayer()const override;
            void playTurn(int indPlayer) const override;
            vector<int> getJoueurInitialStatuts() const override;
            vector<int> getInitialStatuts()const override;
            map<int,vector<IdCarte>> genMapCartePlateauInitial()const override;
    };
}
#endif