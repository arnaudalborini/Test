#include "CartesAlgoMSL.hpp"
#include "CarteMSL.hpp"
#include "CarteGenerator.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "InfosJoueur.hpp"
#include "StatutPlateau.hpp"
#include "JouerMetier.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"

using MySmileLife::JouerMetier;
using MySmileLife::CarteMSL;
using CardGame::Player;
using CardGame::IdCarte;
using CardGame::Plateau;
using CardGame::Hand;
using CardGame::InfosJoueur;

bool JouerMetier::peutEtreJoueeMetier(const Player *pp, const CarteMSL *crt) const
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

void voirNProchainesCartesPioche(int N){}
void choisirEtJouerUneCarteDefausse(const Player* pp, const CardGame::GameMechanicsMonitor* mMonitor)
{
    int indiceCarte = pp->choisirUneCarteAJouer(mMonitor->getDefausse());
    IdCarte id = mMonitor->getDefausse()->piocherNeme( indiceCarte );
    
}
void voirMainAutresJoueur(){}

bool JouerMetier::jouerCarteMetier(const Player *pp, const CarteMSL *crt) const
{
    if(peutEtreJoueeMetier(pp,crt)==false){
        return false;
    }
    Plateau* plat = mMonitor->getPlateauPlayer(pp);
    if(plat->getStatut(aUnTravail)>0){
        mMonitor->defausserTout(mMonitor->getIndPlayer(pp),EMetier);
    }

    plat->setStatut(aUnTravail,1);
    plat->setStatut(Profession,crt->getSType());
    plat->setStatut(SalaireMax,crt->getMetierSalaireMax());
    switch(crt->getSType()){
        case csArchitecte:
            plat->setStatut(MaisonOfferte,1);
            break;
        case csAstronaute:
            choisirEtJouerUneCarteDefausse();
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
            voirMainAutresJoueur();
            break;
        case csMedium:
            voirNProchainesCartesPioche(13);
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
            mMonitor->getPlateau()->setStatut(antiBandit,1);
            mMonitor->getPlateau()->setStatut(antiGourou,1);
            break;
        case csMilitaire:
            plat->setStatut(Fonctionnaire,1);
            mMonitor->getPlateau()->setStatut(antiAttentat,1);
            break;
        case csGrandProf:
        case csProf:
            plat->setStatut(Fonctionnaire,1);
            break;
        case csServeur:
        case csStripteaser:
            plat->setStatut(Interimaire,1);
            break;
    }
    return true;
}