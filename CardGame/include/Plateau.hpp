#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Plateau{
            map<int,vector<IdCarte>> mMapCarte;
            StatutPlateau* mStatut;
        public:
            Plateau();
            ~Plateau();

            void addLast(int EP, IdCarte crt);
            int getNbCarte(int EP)const;

            IdCarte showIdLast(int EP)const;
            IdCarte getLast(int EP);
            IdCarte showIdN(int EP,int N)const;
            IdCarte getN(int EP,int N);
            vector<IdCarte> showAllId()const;

            StatutPlateau* getStatut(){return mStatut;}
            const StatutPlateau* getStatut()const{return mStatut;}            
    };
};

#endif