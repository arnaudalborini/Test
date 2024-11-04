#ifndef JOUERCARTEMSL_HPP
#define JOUERCARTEMSL_HPP

#include "MySmileLife.hpp"
#include "JouerMalus.hpp"
#include "JouerMetier.hpp"
#include "JouerSpecial.hpp"

namespace MySmileLife{
    class JouerCarteMSL:public JouerMetier, public JouerSpecial, public JouerMalus{
        private:
            CardGame::_pc_CarteGenerator cGen;
            CardGame::_pc_GameMechanicsMonitor mMonitor;
            
            _pc_CarteMSL getCarteMSL(IdCarte id)const;
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
            bool jouerCarteSalaire(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteVoyage(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            void choisirEtJouerUneCarteDefausse(CardGame::_pc_Player  pp)const override;
            CardGame::_pc_Player  getCible(CardGame::_pc_Player  pp, IdCarte id)const override;
        public:
            JouerCarteMSL(CardGame::_pc_CarteGenerator cc, CardGame::_pc_GameMechanicsMonitor mm):cGen( cc ),mMonitor( mm ){}            
            bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id)const;
            bool jouerCarte(CardGame::_pc_Player  pp, IdCarte id)const;
            _pc_CarteGenerateurStandard getCGen()const override;
            CardGame::_pc_GameMechanicsMonitor getMonitor()const override;
    };
}

#endif