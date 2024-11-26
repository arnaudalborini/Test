#ifndef MSLMECHANICS_HPP
#define MSLMECHANICS_HPP

#include "MySmileLife.hpp"
#include "GameMechanicsSpe.hpp"

namespace MySmileLife{
    class MSLMechanics :public CardGame::GameMechanicsSpe{
        private:
            void remplirMain(int indPlayer)const;
        protected:
            _pc_CarteMSL getMSLCarteById(IdCarte id)const;
            _pc_MSLPlayer getMSLPlayer(int indPlayer)const;
            int  countSmile(CardGame::_p_Plateau plateauJoueur)const;
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
            vector<vector<IdCarte>> genMapCartePlateauInitial()const override;
                        
            void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP) override;
            void effetQuitterHand(const int indPlayer, const IdCarte idCrt) override;
            void effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP) override;
            void effetEntrerHand(const int indPlayer, const IdCarte idCrt) override;
    };
}
#endif