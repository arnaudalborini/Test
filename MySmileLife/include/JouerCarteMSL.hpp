#ifndef JOUERCARTEMSL_HPP
#define JOUERCARTEMSL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include "JouerMetier.hpp"
#include "JouerSpecial.hpp"

namespace MySmileLife{
    class JouerCarteMSL:public JouerMetier, public JouerSpecial, public JouerMalus{
        private:
            CardGame::PCCarteGenerator cGen;
            CardGame::PCGameMechanicsMonitor mMonitor;
            
            PCCarteMSL getCarteMSL(IdCarte id)const;
            void payer(PCPlayer  pp, PPlateau plat, int prix)const;

            bool peutEtreJoueeAnimal(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeEnfant(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeEtude(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeFlirt(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeMaison(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeMariage(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeSalaire(PCPlayer pp, PCCarteMSL crt)const;
            bool peutEtreJoueeVoyage(PCPlayer pp, PCCarteMSL crt)const;

            bool jouerCarteAnimal(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteEnfant(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteEtude(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteFlirt(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteMaison(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteMariage(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteSalaire(PCPlayer pp, PCCarteMSL crt)const;
            bool jouerCarteVoyage(PCPlayer pp, PCCarteMSL crt)const;
            void choisirEtJouerUneCarteDefausse(PCPlayer  pp)const override;
            PCPlayer  getCible(PCPlayer  pp, IdCarte id)const override;
        public:
            JouerCarteMSL(CardGame::PCCarteGenerator cc, CardGame::PCGameMechanicsMonitor mm):cGen( cc ),mMonitor( mm ){}            
            bool peutEtreJouee(PCPlayer pp, IdCarte id)const;
            bool jouerCarte(PCPlayer  pp, IdCarte id)const;
            PCCarteGenerateurStandard getCGen()const override;
            PCGameMechanicsMonitor getMonitor()const override;
    };
}

#endif