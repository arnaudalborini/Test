#ifndef CARTESALGOMSL_HPP
#define CARTESALGOMSL_HPP

#include "MySmileLife.hpp"
#include "CartesAlgo.hpp"

namespace MySmileLife{
    class CartesAlgoMSL final:public CardGame::CartesAlgo{
        private:
            const CarteMSL* getCarteMSL(IdCarte id)const;

            Plateau * getPlateauPlayer(const Player* pp)const;

            bool peutEtreJoueeAnimal(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEnfant(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEtude(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeFlirt(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMaison(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMariage(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMetier(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeSalaire(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeSpecial(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeVoyage(const Player *pp, const CarteMSL* crt)const;
            
            bool peutEtreJoueeMalus(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMalus(const Player *pp, const CarteMSL *crt, const Player* Cible) const;

            bool jouerCarteAnimal(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEnfant(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEtude(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteFlirt(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMaison(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMalus(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMariage(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMetier(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSalaire(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSpecial(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteVoyage(const Player *pp, const CarteMSL* crt)const;
        public:
            CartesAlgoMSL(CardGame::CarteGenerator* cc,CardGame::GameMechanicsMonitor* mm):CartesAlgo(cc,mm){}
            ~CartesAlgoMSL(){}
            bool peutEtreJouee(const Player *pp, IdCarte id)const override;
            bool jouerCarte(const Player* pp, IdCarte id)const override;

            int getNbSmile(const Plateau *pp, IdCarte id)const;
    };
}

#endif