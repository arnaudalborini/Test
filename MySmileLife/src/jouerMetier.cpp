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

    plat->setStatut(aUnTravail,1);
    plat->setStatut(Profession,crt->getSType());
    plat->setStatut(SalaireMax,crt->getMetierSalaireMax());
    plat->addCarteToEP(EMetier,crt->getId());
    IdCarte id;

    switch(crt->getSType()){
        case csArchitecte:
            plat->setStatut(MaisonOfferte,1);
            break;
        case csAstronaute:
            choisirEtJouerUneCarteDefausse(pp);
            break;
        case csAvocat:
            plat->setStatut(ResistantDivorce,1);
            break;
        case csBandit:
            plat->setStatut(ResistantLicenciement,1);
            plat->setStatut(ResistantImpots,1);
            plat->setStatut(RisquePrison,1);
            break;
        case csBarman:
            plat->setStatut(FlirtIllimites,1);
            plat->setStatut(Interimaire,1);
            break;
        case csChefDesAchats:
        case csChefDesVentes:
            plat->setStatut(TrocProtege,1);
            break;
        case csChercheur:
            plat->setStatut(LimiteCarte6,1);
            break;
        case csGaragiste:
            plat->setStatut(ResistantAccident,1);
            break;
        case csJournaliste:
            voirMainAutresJoueur(pp,mMonitor);
            break;
        case csMedium:
            voirNProchainesCartesPioche(pp,mMonitor,13);
            break;
        case csMedecin:
        case csChirurgien:
            plat->setStatut(EtudesContinues,1);
        case csPharmacien:
            plat->setStatut(ResistantMaladie,1);
            break;
        case csPiloteDeLigne:
            plat->setStatut(VoyagesGratuit,1);
            break;
        case csPolicier:
            plat->setStatut(Fonctionnaire,1);
            mMonitor->getPlateauGeneral()->setStatut(antiBandit,1);
            mMonitor->getPlateauGeneral()->setStatut(antiGourou,1);
            break;
        case csMilitaire:
            plat->setStatut(Fonctionnaire,1);
            mMonitor->getPlateauGeneral()->setStatut(antiAttentat,1);
            break;
        case csGrandProf:
        case csProf:
            plat->setStatut(Fonctionnaire,1);
            break;
        case csServeur:
        case csStripteaser:
            plat->setStatut(Interimaire,1);
            break;
        default:
        break;
    }
    return true;
}