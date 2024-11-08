#ifndef JOUERMETIER_HPP
#define JOUERMETIER_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMetier: public std::enable_shared_from_this<JouerMetier>{
        protected:
            bool peutEtreJoueeMetier(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            bool jouerCarteMetier(CardGame::_pc_Player pp, _pc_CarteMSL crt)const;
            virtual void choisirEtJouerUneCarteDefausse(CardGame::_pc_Player pp)const=0;
        public:            
            virtual _pc_CarteGenerateurStandard          getCGen()const=0;
            virtual CardGame::_pc_GameMechanicsMonitor   getMonitor()const=0;
            virtual bool peutEtreJouee(CardGame::_pc_Player pp, IdCarte id)const=0;
            virtual bool jouerCarte(CardGame::_pc_Player pp, IdCarte id)const=0;
    };
    namespace Metier{
        struct ProprietesMetier{
                int salaireMax;
                int nbAnneeEtudeRequises;
        };
        const map<int,ProprietesMetier> mapMetier = {
            { csArchitecte, { 3 , 4 } },
            { csAstronaute, { 4 , 6 } },
            { csAvocat, { 3 , 4 } },
            { csBandit, { 4 , 0 } },
            { csBarman, { 1 , 0 } },
            
            { csChefDesAchats, { 3 , 3 } },
            { csChefDesVentes, { 3 , 3 } },
            { csChercheur, { 2 , 6 } },
            { csChirurgien, { 4 , 6 } },
            { csDesigner, { 3 , 4 } },
            
            { csEcrivain, { 1 , 0 } },
            { csGaragiste, { 2 , 1 } },
            { csGourou, { 3 , 0 } },
            { csGrandProf, { 3 , std::numeric_limits<int>::max() } },
            { csJardinier, { 1 , 1 } },
            
            { csJournaliste, { 2 , 3 } },
            { csMedecin, { 4 , 6 } },
            { csMedium, { 1 , 0 } },
            { csMilitaire, { 1 , 0 } },
            { csPharmacien, { 3 , 5 } },
            
            { csPiloteDeLigne, { 4 , 5 } },
            { csPizzaiolo, { 2 , 0 } },
            { csPlombier, { 1 , 1 } },
            { csPolicier, { 1 , 1 } },
            { csProf, { 2 , 2 } },
            
            { csServeur, { 1 , 0 } },
            { csStripteaser, { 1 , 0 } },
        };
    }
}
#endif