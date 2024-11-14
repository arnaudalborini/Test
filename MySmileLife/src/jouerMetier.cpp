#include "JouerMetier.hpp"
#include "CarteMSL.hpp"
#include "GameMechanicsMonitor.hpp"
#include "InfosJoueur.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"

using MySmileLife::JouerMetier;

bool JouerMetier::peutEtreJoueeMetier(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if(crt->getType()!=carteMetier){
        return false;
    }
    CardGame::_p_Plateau plat = getMonitor()->getPlateauPlayer(pp);
    int nbAnneeEtudeRequise = crt->getParam(0);
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

bool JouerMetier::jouerCarteMetier(CardGame::_pc_Player pp, _pc_CarteMSL crt) const
{
    if(peutEtreJoueeMetier(pp,crt)==false){
        return false;
    }
    CardGame::_pc_GameMechanicsMonitor mMonitor = getMonitor();
    CardGame::_p_Plateau plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(aUnTravail)>0){
        mMonitor->defausserTout(mMonitor->getIndPlayer(pp),EMetier);
    }
    plat->addCarteToEP(EMetier,crt->getId());
    switch(crt->getSType()){
        case csAstronaute:
            choisirEtJouerUneCarteDefausse(pp);
            break;
        case csJournaliste:
            mMonitor->voirMainAutresJoueur(pp);
            break;
        case csMedium:
            mMonitor->voirNProchainesCartesPioche(pp,13);
            break;
        case csPolicier:
            //TODO licenciement des bandits et gourou
            break;
        default:
            break;
    }
    return true;
}