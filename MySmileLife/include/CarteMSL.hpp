#ifndef CARTE_H
#define CARTE_H

#include "MySmileLife.hpp"
#include "InfosJoueur.hpp"
#include "Carte.hpp"

namespace MySmileLife{
    class CarteMSL:public CardGame::Carte{
        private:
            int mId;
            string mName;
            int mNbSmile;
            CarteType mCType;
            CarteSousType mCsType;
        public:
            CarteMSL(int id, string nn, int ss, CarteType cT, CarteSousType cST=CarteSousType::AucunSousType):Carte(id),mName(nn),mNbSmile(ss),mCType(cT),mCsType(cST){};
            ~CarteMSL(){}
            int getId()const{return mId;};
            string getName()const{return mName;}
            int getNbSmile()const{return mNbSmile;}
            CarteType getType()const{return mCType;}
            CarteSousType getSType()const{return mCsType;}
    };
};

#endif
