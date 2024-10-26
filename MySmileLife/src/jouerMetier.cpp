#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"

using MySmileLife::CartesAlgoMSL;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

bool CartesAlgoMSL::peutEtreJoueeMetier(const Player *pp, const CarteMSL *crt) const
{
    Plateau* plat = getPlateauPlayer(pp);
    if(crt->getType())
    int nbAnneeEtudeRequise = crt->getMetierNbAnnee();
    return false;
}