#ifndef CARTE_H
#define CARTE_H

#include "MySmileLife.hpp"
#include "InfosJoueur.hpp"
#include "CardGame/include/Carte.hpp"

namespace MySmileLife{
    class CarteMSL:public CardGame::Carte{
        private:
            int mId;
            string mName;
            int mNbSmile;
            CarteType mCrtType;
        public:
            CarteMSL(int id, string nn, int ss, CarteType cT):mId(id),mName(nn),mNbSmile(ss),mCrtType(cT){};
            ~CarteMSL(){}
            int getId()const{return mId;};
            string getName()const{return mName;}
    };
};

#endif
