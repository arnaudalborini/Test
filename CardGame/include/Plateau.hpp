#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "CardGame.hpp"
#include "PlateauMonitor.hpp"

namespace CardGame{
    class Plateau{
            vector<vector<IdCarte>> mVecCarte;
            vector<int> mVecStatut;
            _p_PlateauMonitor mMonitor;
        protected:
            virtual int getIdPlayer()const;
        public:
            Plateau(_p_PlateauMonitor mm);
            Plateau(_p_PlateauMonitor mm,const vector<int> &vecStatut);
            ~Plateau();

            void addCarteToEP(int EP, IdCarte crt);
            int getNbCarteByEP(int EP)const;

            IdCarte showIdLastByEP(int EP)const;
            IdCarte getLastByEP(int EP);
            IdCarte showIdNByEP(int EP,int N)const;
            IdCarte getNByEP(int EP,int N);
            vector<IdCarte> showAllIdAllEP()const;
            const vector<IdCarte> showAllIdByEP(int ET)const;

            int getStatut(int statutKey)const{return mVecStatut.at(statutKey);}
            void initStatut(const vector<int> &vecSt){mVecStatut=vector<int>(vecSt.begin(),vecSt.end());}
            void initCartesPlateau(const vector<vector<IdCarte>> &initVec){mVecCarte.clear();mVecCarte=vector<vector<IdCarte>>(initVec.begin(),initVec.end());}
            void setStatut(int statutKey, int value){mVecStatut[statutKey]=value;}  

            void incStatut(int statutKey, int inc=1){mVecStatut[statutKey]+=inc;}
            int getStatutMax()const{return mVecStatut.size();}
            int getEPMax()const{return mVecCarte.size();}
    };
};

#endif