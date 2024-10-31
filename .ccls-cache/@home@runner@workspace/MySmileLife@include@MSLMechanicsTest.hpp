#ifndef MSLMECHANICSTEST_HPP
#define MSLMECHANICSTEST_HPP

#include "MySmileLife.hpp"
#include "GameMechanicsSpe.hpp"

namespace MySmileLife{
    class MSLMechanicsTest :public MSLMechanics{
        private:
            vector<int> vecInitHand;
        public:
            MSLMechanicsTest();   
            ~MSLMechanicsTest();   
            //methodes reimplementees
            void playTurn(int indPlayer) const override;
            vector<int> getJoueurInitialStatuts() const override;
            //vector<int> getInitialStatuts(const vector<int> &vecInit=vector<int>())const override;
            //map<int,vector<IdCarte>> genMapCartePlateauInitial()const override;
    };
}
#endif