#ifndef STATUTPLATEAU_HPP
#define STATUTPLATEAU_HPP

#include "CardGame.hpp"

namespace CardGame{
    class StatutPlateau{
        private:
            vector<int> mVecStatut;
        protected:
        public:
            StatutPlateau(){mVecStatut=vector<int>();}
            StatutPlateau(vector<int> vecStatut):mVecStatut(vecStatut){}
            virtual ~StatutPlateau(){};
            int getStatut(int statutKey)const{return mVecStatut.at(statutKey);}
            void setStatut(int statutKey, int value){mVecStatut[statutKey]=value;}
    };
}

#endif