#include "EffetCartePlateau.hpp"
#include "GameMechanicsMonitor.hpp"
#include "CarteMSL.hpp"

#include "InfosJoueur.hpp"

#include "CarteGenerateurStandard.hpp"

using MySmileLife::EffetCartePlateauMain;

EffetCartePlateauMain::EffetCartePlateauMain(weak_ptr<const CarteGenerateurStandard> cc,weak_ptr<const CardGame::GameMechanicsMonitor> mm) : mMonitor(mm),cGen(cc)
{
}

//Private
void EffetCartePlateauMain::effetEntrerPlateauSpe(const int indPlayer, const CarteSousType cst) const
{
    switch(cst){
        case csAdultere:
            setStatut(indPlayer,DetailPlateau::estAdultere,1);
            break;
        case csArcEnCiel:
            setStatut(indPlayer,DetailPlateau::ArcEnCielJoue,1);
            break;
        case csCasino:
            setStatutGeneral(DetailPlateau::casinoOuvert,1);
            break;
        case csEtoileFilante:
            setStatut(indPlayer,DetailPlateau::EtoileFilanteJouee,1);
            break;
        case csGrandPrixExcellence:
            setStatut(indPlayer,DetailPlateau::SalaireMax,4);
            break;
        case csHeritage:
            setStatut(indPlayer,DetailPlateau::HeritageDisponible,3);
            break;
        case csPiston:
            setStatut(indPlayer,DetailPlateau::PistonActif,3);
            break;
        default:
            break;
    }
}
void EffetCartePlateauMain::effetQuitterPlateauSpe(const int indPlayer, const CarteSousType cst) const
{
    switch(cst){
        case csAdultere:
            setStatut(indPlayer,DetailPlateau::estAdultere,0);
            break;
        default:
            break;
    }
}
void EffetCartePlateauMain::effetEntrerPlateauMetier(const int indPlayer, _pc_CarteMSL crt) const
{
    setStatut(indPlayer,DetailPlateau::aUnTravail,1);
    setStatut(indPlayer,DetailPlateau::Profession,crt->getSType());
    setStatut(indPlayer,DetailPlateau::SalaireMax,crt->getParam(1));
    switch (crt->getSType())
    {
    case csArchitecte:
        setStatut(indPlayer,DetailPlateau::MaisonOfferte,1);
        break;
    case csAvocat:
        setStatut(indPlayer,DetailPlateau::ResistantDivorce,1);
        break;
    case csBandit:
        setStatut(indPlayer,DetailPlateau::RisquePrison,1);
        setStatut(indPlayer,DetailPlateau::ResistantImpots,1);
        setStatut(indPlayer,DetailPlateau::ResistantLicenciement,1);
        break;
    case csBarman:
        setStatut(indPlayer,DetailPlateau::FlirtIllimites,1);
        setStatut(indPlayer,DetailPlateau::Interimaire,1);
        break;
    case csChefDesAchats:
    case csChefDesVentes:
        setStatut(indPlayer,DetailPlateau::TrocProtege,1);
        break;
    case csChercheur:
        setStatut(indPlayer,DetailPlateau::LimiteCarte6,1);
        mMonitor.lock()->setMaxHandSize(indPlayer,6);
        break;
    case csGaragiste:
        setStatut(indPlayer,DetailPlateau::ResistantAccident,1);
        break;
    case csMedecin:
    case csChirurgien:
        setStatut(indPlayer,DetailPlateau::EtudesContinues,1);
    case csPharmacien:
        setStatut(indPlayer,DetailPlateau::ResistantMaladie,1);
        break;
    case csPiloteDeLigne:
        setStatut(indPlayer,DetailPlateau::VoyagesGratuit,1);
        break;
    case csPolicier:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        setStatutGeneral(DetailPlateau::antiBandit,1);
        setStatutGeneral(DetailPlateau::antiGourou,1);
        break;
    case csMilitaire:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        setStatutGeneral(DetailPlateau::antiAttentat,1);
        break;
    case csGrandProf:
    case csProf:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,1);
        break;
    case csServeur:
    case csStripteaser:
        setStatut(indPlayer,DetailPlateau::Interimaire,1);
        break;
    default:
        break;
    }
}
void EffetCartePlateauMain::effetQuitterPlateauMetier(const int indPlayer, _pc_CarteMSL crt) const
{
    setStatut(indPlayer,DetailPlateau::aUnTravail,0);
    setStatut(indPlayer,DetailPlateau::Profession,0);
    setStatut(indPlayer,DetailPlateau::SalaireMax,0);
    switch (crt->getSType())
    {
    case csArchitecte:
        setStatut(indPlayer,DetailPlateau::MaisonOfferte,0);
        break;
    case csAvocat:
        setStatut(indPlayer,DetailPlateau::ResistantDivorce,0);
        break;
    case csBandit:
        setStatut(indPlayer,DetailPlateau::RisquePrison,0);
        setStatut(indPlayer,DetailPlateau::ResistantImpots,0);
        setStatut(indPlayer,DetailPlateau::ResistantLicenciement,0);
        break;
    case csBarman:
        setStatut(indPlayer,DetailPlateau::FlirtIllimites,0);
        setStatut(indPlayer,DetailPlateau::Interimaire,0);
        break;
    case csChefDesAchats:
    case csChefDesVentes:
        setStatut(indPlayer,DetailPlateau::TrocProtege,0);
        break;
    case csChercheur:
        setStatut(indPlayer,DetailPlateau::LimiteCarte6,0);
        mMonitor.lock()->setMaxHandSize(indPlayer,MySmileLife::DEFAULTMAXHANDSIZE);
        break;
    case csGaragiste:
        setStatut(indPlayer,DetailPlateau::ResistantAccident,0);
        break;
    case csMedecin:
    case csChirurgien:
        setStatut(indPlayer,DetailPlateau::EtudesContinues,0);
    case csPharmacien:
        setStatut(indPlayer,DetailPlateau::ResistantMaladie,0);
        break;
    case csPiloteDeLigne:
        setStatut(indPlayer,DetailPlateau::VoyagesGratuit,0);
        break;
    case csPolicier:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        setStatutGeneral(DetailPlateau::antiBandit,0);
        setStatutGeneral(DetailPlateau::antiGourou,0);
        break;
    case csMilitaire:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        setStatutGeneral(DetailPlateau::antiAttentat,0);
        break;
    case csGrandProf:
    case csProf:
        setStatut(indPlayer,DetailPlateau::Fonctionnaire,0);
        break;
    case csServeur:
    case csStripteaser:
        setStatut(indPlayer,DetailPlateau::Interimaire,0);
        break;
    default:
        break;
    }
}

void EffetCartePlateauMain::setStatut(int indPlayer, int statut, int value) const{mMonitor.lock()->setStatut(indPlayer,statut,value);}
void EffetCartePlateauMain::incStatut(int indPlayer, int statut, int value) const{mMonitor.lock()->incStatut(indPlayer,statut,value);}
void EffetCartePlateauMain::setStatutGeneral(int statut, int value) const{mMonitor.lock()->setStatutGeneral(statut,value);}

void EffetCartePlateauMain::changeStatutLast(int indPlayer, int mainStatut, int dernierStatut, int EP, int value) const
{
    int updateValue = 0;
    incStatut(indPlayer,mainStatut,value);
    IdCarte lastId = showIdLastByEP(indPlayer, EP);
    if(lastId != -1){
        updateValue = getCrt(lastId)->getParam();
    }
    setStatut(indPlayer,dernierStatut,updateValue);
}

MySmileLife::_pc_CarteMSL EffetCartePlateauMain::getCrt(IdCarte id) const{
    return ToCarteMSL(cGen.lock()->getCarteById(id));
}

CardGame::IdCarte EffetCartePlateauMain::showIdLastByEP(int indPlayer, int EP) const
{
    return mMonitor.lock()->getInfosJoueurs(indPlayer)->showIdLastByEP(EP);
}

//Public
void EffetCartePlateauMain::effetEntrerPlateau(const int indPlayer, _pc_CarteMSL crt, EmplacementsPlateau EP) const
{
    switch( crt->getType() ){
        case CarteType::carteEnfant:
            incStatut(indPlayer,DetailPlateau::NbEnfant,1);
            break;
        case CarteType::carteEtude:
            incStatut(indPlayer,DetailPlateau::NbAnneeEtude,crt->getParam());
            if(EP==EmplacementsPlateau::EEtudes){
                setStatut(indPlayer,DetailPlateau::DerniereEtudeRedoublable,crt->getParam());
            }
            break;
        case CarteType::carteFlirt:
            incStatut(indPlayer,DetailPlateau::NombreFlirt,1);
            if(EP==EFlirt){
                CarteSousType lieuFlirt = crt->getSType();
                setStatut(indPlayer,DetailPlateau::LieuDernierFlirt,lieuFlirt);
            }
            break;
        case CarteType::carteMariage:
            setStatut(indPlayer,DetailPlateau::estMarie,1);
            break;
        case CarteType::carteMetier:
            effetEntrerPlateauMetier(indPlayer,crt);
            break;
        case CarteType::carteSalaire:
            if(EP==ESalairesD){
                incStatut(indPlayer,DetailPlateau::SalairesDisponibles,crt->getParam());
                setStatut(indPlayer,DetailPlateau::DernierSalaireDisponible,crt->getParam());
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
            incStatut(indPlayer,DetailPlateau::NbEnfant,-1);
            break;
        case CarteType::carteEtude:
            changeStatutLast(indPlayer,NbAnneeEtude,DerniereEtudeRedoublable,EP,-crt->getParam());
            break;
        case CarteType::carteFlirt:
            changeStatutLast(indPlayer,NombreFlirt,LieuDernierFlirt,EP,-1);
            break;
        case CarteType::carteSalaire:
            changeStatutLast(indPlayer,SalairesDisponibles,DernierSalaireDisponible,EP,-crt->getParam());
            break;
        case CarteType::carteMariage:
            setStatut(indPlayer,DetailPlateau::estMarie,0);
            break;
        case CarteType::carteMetier:
            effetQuitterPlateauMetier(indPlayer,crt);
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