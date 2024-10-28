#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "MySmileLife.hpp"
#include "CartesAlgo.hpp"
#include "JouerCarteMSL.hpp"

namespace MySmileLife{
    class CartesAlgoMSL final:public CardGame::CartesAlgo{
        private:
            const JouerCarteMSL* jCarte;

        public:
            CartesAlgoMSL(CardGame::CarteGenerator* cc,CardGame::GameMechanicsMonitor* mm):CardGame::CartesAlgo(cc,mm),jCarte(new JouerCarteMSL(cc,mm)){}
            ~CartesAlgoMSL(){delete jCarte;}
            
            bool peutEtreJouee(const Player *pp, IdCarte id)const override{return jCarte->peutEtreJouee(pp,id);}
            bool jouerCarte(const Player* pp, IdCarte id)const override{return jCarte->jouerCarte(pp,id);}

            int getNbSmile(const Plateau *pp, IdCarte id)const;
    };
}

#endif