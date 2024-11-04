#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardGame.hpp"
#include "GameInterface.hpp"

namespace CardGame{
    class Player: private std::enable_shared_from_this<Player>{
        private:
            PCPlayerInterface pI;
        protected:
            PCPlayerInterface getPlayerInterface()const{return pI;}
        public:
            Player():pI(nullptr){}

            void login(PGameInterface gI){ 
                if(pI==nullptr){
                    pI=gI->login( shared_from_this() );
                }
            }
            bool isLoggedIn()const{return pI!=nullptr;}
    
            virtual string getName()const=0;
            virtual int choisirUneCarte(PPaquetCarte paq)const=0;
            virtual int choisirUneCarte(const vector<IdCarte>& vecId)const=0;
            virtual void showNCartesPioche(const vector<IdCarte>& vecIdPioche)const=0;
            virtual void showHandAutreJoueur(PCHand h, int indAutrePlayer)const=0;
            virtual int choisirIndiceCarteAJouerMain(PCHand h)const=0;
            virtual int choisirCible(IdCarte id)const=0;
            virtual int choisirIndiceHazard(int indiceMin,int indiceMax)const=0;
    };
};

#endif