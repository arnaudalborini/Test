#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"
#include "JouerMetier.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

bool CartesAlgoMSL::peutEtreJoueeMetier(const Player *pp, const CarteMSL *crt) const
{
    if(crt->getType()!=carteMetier){
        return false;
    }
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    int nbAnneeEtudeRequise = crt->getMetierNbAnnee();
    int sMax = crt->getMetierSalaireMax();
    if( (plat->getStatut(aUnTravail)==false) || (plat->getStatut(Interimaire)) ){
        if(plat->getStatut(NbAnneeEtude)>=nbAnneeEtudeRequise){
            return true;
        }
        if(plat->getStatut(PistonActif)){
            return true;
        }
    }
    return false;
}

bool CartesAlgoMSL::jouerCarteMetier(const Player *pp, const CarteMSL *crt) const
{
    return false;
}