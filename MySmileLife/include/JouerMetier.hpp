#ifndef JOUERMETIER_HPP
#define JOUERMETIER_HPP

#include "MySmileLife.hpp"
#include <limits>

namespace MySmileLife{
    class JouerMetier{
            CardGame::CarteGenerator* cGen;
            const CardGame::GameMechanicsMonitor* mMonitor;
        public:
            JouerMetier(CardGame::CarteGenerator* cg, CardGame::GameMechanicsMonitor* mm):cGen(cg),mMonitor(mm){}
            bool peutEtreJoueeMetier(const Player *pp, const CarteMSL* crt)const;
            bool jouerCarteMetier(const Player *pp, const CarteMSL* crt)const;
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