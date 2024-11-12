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

void voirNProchainesCartesPioche(CardGame::_pc_Player pp, CardGame::_pc_GameMechanicsMonitor mMonitor, int N){
    CardGame::_p_PaquetCarte pioche = mMonitor->getPioche();
    int nbcarte = pioche->getNbCarte();
    int indDebut = (nbcarte>=N)?nbcarte-1-N:0;
    std::vector<CardGame::IdCarte> vecId;
    for(int indice = indDebut;indice<nbcarte;indice++){
        vecId.push_back(pioche->showNeme(indice));
    }
    pp->showNCartesPioche(vecId);
}

void voirMainAutresJoueur(CardGame::_pc_Player pp, CardGame::_pc_GameMechanicsMonitor mMonitor)
{
    int indPlayer = mMonitor->getIndPlayer(pp);
    for(int indice=0;indice<mMonitor->getNbPlayer();indice++){
        if(indice==indPlayer){
            continue;
        }
        CardGame::_pc_Hand jH = mMonitor->getInfosJoueurs(indice)->getHand();
        pp->showHandAutreJoueur(jH,indice);
    }
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
    IdCarte id;

    switch(crt->getSType()){
        case csAstronaute:
            choisirEtJouerUneCarteDefausse(pp);
            break;
        case csJournaliste:
            voirMainAutresJoueur(pp,mMonitor);
            break;
        case csMedium:
            voirNProchainesCartesPioche(pp,mMonitor,13);
            break;
        case csPolicier:
            //TODO licenciement des bandits et gourou
            break;
        default:
        break;
    }
    return true;
}