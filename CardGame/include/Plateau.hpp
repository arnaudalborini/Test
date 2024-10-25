#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Plateau{
            map<int,vector<IdCarte>> mMapCarte;
            vector<int> mVecStatut;
        public:
            Plateau();
            Plateau(vector<int> mapStatut);
            ~Plateau();

            void addLast(int EP, IdCarte crt);
            int getNbCarte(int EP)const;

            IdCarte showIdLast(int EP)const;
            IdCarte getLast(int EP);
            IdCarte showIdN(int EP,int N)const;
            IdCarte getN(int EP,int N);
            vector<IdCarte> showAllId()const;
            
            int getStatut(int statutKey)const{return mVecStatut.at(statutKey);}
            void setStatut(int statutKey, int value){mVecStatut[statutKey]=value;}  

            void incStatut(int statutKey, int inc=1){mVecStatut[statutKey]+=inc;}     
    };
};

#endif