#ifndef JOUERCARTEMSL_HPP
#define JOUERCARTEMSL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include "JouerMetier.hpp"
#include "JouerSpecial.hpp"

namespace MySmileLife{
    class JouerCarteMSL:public JouerMetier, public JouerSpecial, public JouerMalus{
        private:
            const CardGame::CarteGenerator* cGen;
            const CardGame::GameMechanicsMonitor* mMonitor;
            
            const CarteMSL* getCarteMSL(IdCarte id)const;
            void payer(const Player* pp, Plateau* plat, int prix)const;

            bool peutEtreJoueeAnimal(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEnfant(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeEtude(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeFlirt(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMaison(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeMariage(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeSalaire(const Player *pp, const CarteMSL* crt)const;
            bool peutEtreJoueeVoyage(const Player *pp, const CarteMSL* crt)const;

            bool jouerCarteAnimal(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEnfant(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteEtude(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteFlirt(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMaison(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMariage(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteSalaire(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteVoyage(const Player *pp, const CarteMSL* crt)const;
        public:
            JouerCarteMSL(const CardGame::CarteGenerator* cc, const CardGame::GameMechanicsMonitor* mm):cGen(cc),mMonitor(mm){}            
            bool peutEtreJouee(const Player *pp, IdCarte id)const;
            bool jouerCarte(const Player* pp, IdCarte id)const;
            const CarteGenerateurStandard* getCGen()const override;
            const CardGame::GameMechanicsMonitor* getMonitor()const override;
    };
}

#endif