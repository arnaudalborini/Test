#ifndef JOUERCARTEMSL_HPP
#define JOUERCARTEMSL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include "JouerMetier.hpp"
#include "JouerSpecial.hpp"

namespace MySmileLife{
    class JouerCarteMSL:public JouerMetier, public JouerSpecial, public JouerMalus{
        private:
            weak_ptr<const CardGame::CarteGenerator> cGen;
            weak_ptr<const CardGame::GameMechanicsMonitor> mMonitor;

            int getStatut(CardGame::_pc_Player pp, int statut)const;
            void setStatut(CardGame::_pc_Player pp, int statut,int value)const;
            void incStatut(CardGame::_pc_Player pp, int statut,int value)const;
            void addCarteToEP(CardGame::_pc_Player pp, int EP,IdCarte id)const;

            _pc_CarteMSL getCarteMSL(IdCarte id)const override;
            void payer(CardGame::_pc_Player  pp, CardGame::_p_Plateau plat, int prix)const;

            bool peutEtreJoueeAnimal(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeEnfant(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;

            bool jouerCarteAnimal(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteEnfant(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteEtude(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteFlirt(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMaison(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMariage(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt)const override;
            bool jouerCarteVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            void choisirEtJouerUneCarteDefausse(CardGame::_pc_Player  pp)const override;
            CardGame::_pc_Player  getCible(CardGame::_pc_Player  pp, IdCarte id)const override;
        public:
            JouerCarteMSL(weak_ptr<const CardGame::CarteGenerator> cc, weak_ptr<const CardGame::GameMechanicsMonitor> mm):cGen( cc ),mMonitor( mm ){}            
            bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id)const override;
            bool jouerCarte(CardGame::_pc_Player  pp, IdCarte id)const override;
            _pc_CarteGenerateurStandard getCGen()const override;
            CardGame::_pc_GameMechanicsMonitor getMonitor()const override;
    };
}

#endif