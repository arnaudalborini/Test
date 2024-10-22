#ifndef CARTE_H
#define CARTE_H

#include "MySmileLife.hpp"
#include "InfosJoueur.hpp"

namespace MySmileLife{
    class Carte{
        private:
            int mId;
            string mName;
            int mNbSmile;
            CarteType mCrtType;
        public:
            Carte(int id, string nn, int ss, CarteType cT):mId(id),mName(nn),mNbSmile(ss),mCrtType(cT){};
            ~Carte(){}
            int getId()const{return mId;};
            string getName()const{return mName;}
    };
};

#endif
