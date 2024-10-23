#ifndef STATUTPLATEAU_HPP
#define STATUTPLATEAU_HPP

#include "CardGame.hpp"

namespace CardGame{
    class StatutPlateau{
        private:
            map<int,int> mMapStatut;
        protected:
        public:
            StatutPlateau(){mMapStatut=map<int,int>();}
            virtual ~StatutPlateau(){};
            int getStatut(int statutKey)const{return mMapStatut.at(statutKey);}
            void setStatut(int statutKey, int value){mMapStatut[statutKey]=value;}
    };
}

#endif