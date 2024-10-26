#ifndef CARTE_H
#define CARTE_H

#include "MySmileLife.hpp"
#include "Carte.hpp"

namespace MySmileLife{
    class CarteMSL final:public Carte{
        private:
            string mName;
            int mNbSmile;
            CarteType mCType;
            CarteSousType mCsType;
        public:
            CarteMSL(int id, string nn, int ss, CarteType cT, CarteSousType cST=CarteSousType::csAucun):Carte(id),mName(nn),mNbSmile(ss),mCType(cT),mCsType(cST){};
            ~CarteMSL(){}
            string getName()const{return mName;}
            int getNbSmile()const{return mNbSmile;}
            CarteType getType()const{return mCType;}
            CarteSousType getSType()const{return mCsType;}
            
            int getMetierNbAnnee()const;
            int getMetierSalaireMax()const;
            int getNbEtude()const;
            int getPrixMaison()const;
            int getPrixVoyage()const;
            int getSalaire()const;
    };
};

#endif
