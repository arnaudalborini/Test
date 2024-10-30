#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"

namespace CardGame{
    class Player{
        private:
            const PlayerInterface* pI;
        protected:
            const PlayerInterface* getPlayerInterface()const{return pI;}
        public:
            Player():pI(nullptr){}

            void login(GameInterface* gI){ 
                if(pI==nullptr){
                    pI=gI->login(this);
                }
            }
            bool isLoggedIn()const{return pI!=nullptr;}
    
            virtual string getName()const=0;
            virtual int choisirUneCarteAJouer(PaquetCarte* paq)const=0;
            virtual void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const=0;
            virtual void showHandAutreJoueur(const Hand* h, int indAutrePlayer)const=0;
            virtual int choisirIndiceCarteAJouerMain(const Hand* h)const=0;
            virtual int choisirCible(IdCarte id)const=0;
            virtual int choisirIndiceHazard(int indiceMin,int indiceMax)const=0;
    };
};

#endif