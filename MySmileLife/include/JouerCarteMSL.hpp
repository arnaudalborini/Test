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
            void payer(_pc_Player  pp, _p_Plateau plat, int prix)const;

            bool peutEtreJoueeAnimal(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeEnfant(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeEtude(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeFlirt(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeMaison(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeMariage(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeSalaire(_pc_Player pp, _pc_CarteMSL crt)const;
            bool peutEtreJoueeVoyage(_pc_Player pp, _pc_CarteMSL crt)const;

            bool jouerCarteAnimal(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteEnfant(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteEtude(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteFlirt(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMaison(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMariage(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteSalaire(_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteVoyage(_pc_Player pp, _pc_CarteMSL crt)const;
            void choisirEtJouerUneCarteDefausse(_pc_Player  pp)const override;
            _pc_Player  getCible(_pc_Player  pp, IdCarte id)const override;
        public:
            JouerCarteMSL(CardGame::_pc_CarteGenerator cc, CardGame::_pc_GameMechanicsMonitor mm):cGen( cc ),mMonitor( mm ){}            
            bool peutEtreJouee(_pc_Player pp, IdCarte id)const;
            bool jouerCarte(_pc_Player  pp, IdCarte id)const;
            _pc_CarteGenerateurStandard getCGen()const override;
            _pc_GameMechanicsMonitor getMonitor()const override;
    };
}

#endif