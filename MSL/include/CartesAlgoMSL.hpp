#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "MySmileLife.hpp"
#include "CartesAlgo.hpp"

namespace MySmileLife{
    class CartesAlgoMSL:public CardGame::CartesAlgo{
        private:
            const CarteMSL* getCarteMSL(CardGame::IdCarte id)const;

            bool peutEtreJoueeAnimal(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEnfant(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEtude(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeFlirt(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMaison(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMalus(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMariage(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMetier(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeSalaire(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeSpecial(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeVoyage(const CardGame::Player *pp, const CarteMSL* crt)const;
            
            bool jouerCarteAnimal(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEnfant(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEtude(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteFlirt(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMaison(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMalus(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMariage(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMetier(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSalaire(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSpecial(const CardGame::Player *pp, const CarteMSL* crt)const;
            bool jouerCarteVoyage(const CardGame::Player *pp, const CarteMSL* crt)const;
        public:
            CartesAlgoMSL(const CardGame::CarteGenerator* cc,const CardGame::GameMechanicsMonitor* mm):CardGame::CartesAlgo(cc,mm){}
            ~CartesAlgoMSL(){}
            virtual bool peutEtreJouee(const CardGame::Player *pp, CardGame::IdCarte id)const;
            virtual bool jouerCarte(const CardGame::Player* pp, CardGame::IdCarte id)const;
    };
}

#endif