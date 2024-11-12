#include "EffetCartePlateau.hpp"
#include "GameMechanicsMonitor.hpp"
#include "CarteMSL.hpp"

#include "InfosJoueur.hpp"

#include "CarteGenerateurStandard.hpp"

using MySmileLife::EffetCartePlateauMain;

EffetCartePlateauMain::EffetCartePlateauMain(weak_ptr<const CarteGenerateurStandard> cc,weak_ptr<const CardGame::GameMechanicsMonitor> mm) : mMonitor(mm),cGen(cc)
{
}

void EffetCartePlateauMain::effetEntrerPlateauSpe(const int indPlayer, const CarteSousType cst) const
{
    switch(cst){
        case csAdultere:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::estAdultere,1);
            break;
        case csArcEnCiel:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ArcEnCielJoue,1);
            break;
        case csCasino:
            mMonitor.lock()->setStatutGeneral(DetailPlateau::casinoOuvert,1);
            break;
        case csEtoileFilante:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::EtoileFilanteJouee,1);
            break;
        case csGrandPrixExcellence:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::SalaireMax,4);
            break;
        case csHeritage:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::HeritageDisponible,3);
            break;
        case csPiston:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::PistonActif,3);
            break;
        default:
            break;
    }
}
void EffetCartePlateauMain::effetQuitterPlateauSpe(const int indPlayer, const CarteSousType cst) const
{
    switch(cst){
        case csAdultere:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::estAdultere,0);
            break;
        default:
            break;
    }
}

void EffetCartePlateauMain::effetEntrerPlateauMetier(const int indPlayer, _pc_CarteMSL crt) const
{
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::aUnTravail,1);
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Profession,crt->getSType());
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::SalaireMax,crt->getMetierSalaireMax());
    switch (crt->getSType())
    {
    case csArchitecte:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::MaisonOfferte,1);
        break;
    case csAvocat:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantDivorce,1);
        break;
    case csBandit:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::RisquePrison,1);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantImpots,1);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantLicenciement,1);
        break;
    case csBarman:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::FlirtIllimites,1);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Interimaire,1);
        break;
    case csChefDesAchats:
    case csChefDesVentes:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::TrocProtege,1);
        break;
    case csChercheur:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::LimiteCarte6,1);
        break;
    case csGaragiste:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantAccident,1);
        break;
    case csMedecin:
    case csChirurgien:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::EtudesContinues,1);
    case csPharmacien:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantMaladie,1);
        break;
    case csPiloteDeLigne:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::VoyagesGratuit,1);
        break;
    case csPolicier:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiBandit,1);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiGourou,1);
        break;
    case csMilitaire:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiAttentat,1);
        break;
    case csGrandProf:
    case csProf:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        break;
    case csServeur:
    case csStripteaser:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Interimaire,1);
        break;
    default:
        break;
    }
}
void EffetCartePlateauMain::effetQuitterPlateauMetier(const int indPlayer, _pc_CarteMSL crt) const
{
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::aUnTravail,0);
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Profession,0);
    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::SalaireMax,0);
    switch (crt->getSType())
    {
    case csArchitecte:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::MaisonOfferte,0);
        break;
    case csAvocat:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantDivorce,0);
        break;
    case csBandit:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::RisquePrison,0);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantImpots,0);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantLicenciement,0);
        break;
    case csBarman:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::FlirtIllimites,0);
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Interimaire,0);
        break;
    case csChefDesAchats:
    case csChefDesVentes:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::TrocProtege,0);
        break;
    case csChercheur:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::LimiteCarte6,0);
        break;
    case csGaragiste:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantAccident,0);
        break;
    case csMedecin:
    case csChirurgien:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::EtudesContinues,0);
    case csPharmacien:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::ResistantMaladie,0);
        break;
    case csPiloteDeLigne:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::VoyagesGratuit,0);
        break;
    case csPolicier:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiBandit,0);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiGourou,0);
        break;
    case csMilitaire:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        mMonitor.lock()->setStatutGeneral(DetailPlateau::antiAttentat,0);
        break;
    case csGrandProf:
    case csProf:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        break;
    case csServeur:
    case csStripteaser:
        mMonitor.lock()->setStatut(indPlayer,DetailPlateau::Interimaire,0);
        break;
    default:
        break;
    }
}
void EffetCartePlateauMain::effetEntrerPlateau(const int indPlayer, _pc_CarteMSL crt, EmplacementsPlateau EP) const
{
    switch( crt->getType() ){
        case CarteType::carteEnfant:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NbEnfant,1);
            break;
        case CarteType::carteEtude:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NbAnneeEtude,crt->getNbEtude());
            if(EP==EmplacementsPlateau::EEtudes){
                mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DerniereEtudeRedoublable,crt->getNbEtude());
            }
            break;
        case CarteType::carteFlirt:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NombreFlirt,1);
            if(EP==EFlirt){
                CarteSousType lieuFlirt = crt->getSType();
                mMonitor.lock()->setStatut(indPlayer,DetailPlateau::LieuDernierFlirt,lieuFlirt);
            }
            break;
        case CarteType::carteMariage:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::estMarie,1);
            break;
        case CarteType::carteMetier:
            effetEntrerPlateauMetier(indPlayer,crt);
            break;
        case CarteType::carteSalaire:
            if(EP==ESalairesD){
                mMonitor.lock()->incStatut(indPlayer,DetailPlateau::SalairesDisponibles,crt->getSalaire());
                mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DernierSalaireDisponible,crt->getSalaire());
            }
            break;
        case CarteType::carteSpecial:
            effetEntrerPlateauSpe(indPlayer,crt->getSType());
            break;
        default:
            break;
    }
}

void EffetCartePlateauMain::effetQuitterPlateau(const int indPlayer, _pc_CarteMSL crt, EmplacementsPlateau EP) const
{
    switch( crt->getType() ){
        case CarteType::carteEnfant:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NbEnfant,-1);
            break;
        case CarteType::carteEtude:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NbAnneeEtude,-crt->getNbEtude());
            if(EP==EmplacementsPlateau::EEtudes){
                IdCarte lastEtuId = mMonitor.lock()->getInfosJoueurs(indPlayer)->getLastByEP(EP);
                if(lastEtuId == -1){
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DerniereEtudeRedoublable,0);
                }else{
                    int nbEtu = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(lastEtuId))->getNbEtude();
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DerniereEtudeRedoublable,nbEtu);
                }
            }
            break;
        case CarteType::carteFlirt:
            mMonitor.lock()->incStatut(indPlayer,DetailPlateau::NombreFlirt,-1);
            if(EP==EFlirt){
                IdCarte lastFlirtId = mMonitor.lock()->getInfosJoueurs(indPlayer)->getLastByEP(EP);
                if(lastFlirtId == -1){
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::LieuDernierFlirt,0);
                }else{
                    CarteSousType lieuFlirt = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(lastFlirtId))->getSType();
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::LieuDernierFlirt,lieuFlirt);
                }
            }
            break;
        case CarteType::carteMariage:
            mMonitor.lock()->setStatut(indPlayer,DetailPlateau::estMarie,0);
            break;
        case CarteType::carteMetier:
            effetQuitterPlateauMetier(indPlayer,crt);
            break;
        case CarteType::carteSalaire:
            if(EP==ESalairesD){
                mMonitor.lock()->incStatut(indPlayer,DetailPlateau::SalairesDisponibles,-crt->getSalaire());
                IdCarte lastSalId = mMonitor.lock()->getInfosJoueurs(indPlayer)->getLastByEP(EP);
                if(lastSalId == -1){
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DernierSalaireDisponible,0);
                }else{
                    int nbSal = dynamic_pointer_cast<const CarteMSL>(cGen.lock()->getCarteById(lastSalId))->getSalaire();
                    mMonitor.lock()->setStatut(indPlayer,DetailPlateau::DernierSalaireDisponible,nbSal);
                }
            }
            break;
        case CarteType::carteSpecial:
            effetQuitterPlateauSpe(indPlayer,crt->getSType());
            break;
        default:
            break;
    }
}

void EffetCartePlateauMain::effetEntrerHand(const int indPlayer, _pc_CarteMSL crt) const
{
}

void EffetCartePlateauMain::effetQuitterHand(const int indPlayer, _pc_CarteMSL crt) const
{
}