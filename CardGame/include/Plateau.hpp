#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "CardGame.hpp"
#include "PlateauMonitor.hpp"

namespace CardGame{
    class Plateau{
            PlateauMonitor* mMonitor;
            const int playerId;
            vector<vector<IdCarte>> mVecCarte;
            vector<int> mVecStatut;
        public:
            Plateau(PlateauMonitor* mm,int playerInd=-1);
            Plateau(PlateauMonitor* mm,vector<int> vecStatut,int playerInd=-1);
            ~Plateau();

            void addLast(int EP, IdCarte crt);
            int getNbCarte(int EP)const;

            IdCarte showIdLast(int EP)const;
            IdCarte getLast(int EP);
            IdCarte showIdN(int EP,int N)const;
            IdCarte getN(int EP,int N);
            vector<IdCarte> showAllId()const;
            const vector<IdCarte> showAllIdByEP(int ET)const;

            int getStatut(int statutKey)const{return mVecStatut.at(statutKey);}
            void initStatut(const vector<int> &vecSt){mVecStatut=vector<int>(vecSt.begin(),vecSt.end());}
            void initMap(const vector<vector<IdCarte>> &initMap){mVecCarte=vector<vector<IdCarte>>(initMap.begin(),initMap.end());}
            void setStatut(int statutKey, int value){mVecStatut[statutKey]=value;}  

            void incStatut(int statutKey, int inc=1){mVecStatut[statutKey]+=inc;}
    int getStatutMax()const{return mVecStatut.size();}
    int getEPMax()const{return mVecCarte.size();}
    };
};

#endif