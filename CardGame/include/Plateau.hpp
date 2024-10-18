#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Plateau{
            map<int,vector<IdCarte>> mMapCarte;
        public:
            Plateau();
            ~Plateau();

            void addLast(int EP, IdCarte crt);
            int getNbCarte(int EP)const;

            int getIdLast(int EP)const;
            IdCarte getLast(int EP);
            int getIdN(int EP,int N)const;
            IdCarte getN(int EP,int N);
    };
};

#endif