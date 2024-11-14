#include "MSLTests.hpp"
#include "GameMaster.hpp"
#include "GameMechanicsSpe.hpp"
#include "MSLMechanics.hpp"
using MySmileLifeTests::MSLTests;


    std::string MySmileLife::toStringCT(CarteType ct){
        switch(ct){
            case carteEtude:
                return "carteEtude";
            case carteMetier:
                return "carteMetier";
            case carteMalus:
                return "carteMalus";
            case carteAnimal:
                return "carteAnimal";
            case carteVoyage:
                return "carteVoyage";
            case carteMaison:
                return "carteMaison";
            case carteFlirt:
                return "carteFlirt";
            case carteEnfant:
                return "carteEnfant";
            case carteSpecial:
                return "carteSpecial";
            case carteSalaire:
                return "carteSalaire";
            case carteMariage:
                return "carteMariage";
            default: 
                return std::to_string(int(ct));
        }
    }
    std::string MySmileLife::toStringCST(CarteSousType cst){
        switch(cst){
            case csAccidents:
                return "csAccidents";
            case csAttentat:
                return "csAttentat";
            case csBurnOut:
                return "csBurnOut";
            case csDivorce:
                return "csDivorce";
            case csImpotsRevenus:
                return "csImpotsRevenus";
            case csLicenciement:
                return "csLicenciement";
            case csMaladie:
                return "csMaladie";
            case csPrison:
                return "csPrison";
            case csRedoublement:
                return "csRedoublement";
            case csAdultere:
                return "csAdultere";
            case csTroc:
                return "csTroc";
            case csCasino:
                return "csCasino";
            case csChance:
                return "csChance";
            case csPiston:
                return "csPiston";
            case csAnniversaire:
                return "csAnniversaire";
            case csArcEnCiel:
                return "csArcEnCiel";
            case csEtoileFilante:
                return "csEtoileFilante";
            case csHeritage:
                return "csHeritage";
            case csTsunami:
                return "csTsunami";
            case csVengeance:
                return "csVengeance";
            case csLegionHonneur:
                return "csLegionHonneur";
            case csGrandPrixExcellence:
                return "csGrandPrixExcellence";
            case csArchitecte:
                return "csArchitecte";
            case csAstronaute:
                return "csAstronaute";
            case csAvocat:
                return "csAvocat";
            case csBandit:
                return "csBandit";
            case csBarman:
                return "csBarman";
            case csChefDesAchats:
                return "csChefDesAchats";
            case csChefDesVentes:
                return "csChefDesVentes";
            case csChercheur:
                return "csChercheur";
            case csChirurgien:
                return "csChirurgien";
            case csDesigner:
                return "csDesigner";
            case csEcrivain:
                return "csEcrivain";
            case csGaragiste:
                return "csGaragiste";
            case csGourou:
                return "csGourou";
            case csGrandProf:
                return "csGrandProf";
            case csJardinier:
                return "csJardinier";
            case csJournaliste:
                return "csJournaliste";
            case csMedecin:
                return "csMedecin";
            case csMedium:
                return "csMedium";
            case csMilitaire:
                return "csMilitaire";
            case csPharmacien:
                return "csPharmacien";
            case csPiloteDeLigne:
                return "csPiloteDeLigne";
            case csPizzaiolo:
                return "csPizzaiolo";
            case csPlombier:
                return "csPlombier";
            case csPolicier:
                return "csPolicier";
            case csProf:
                return "csProf";
            case csServeur:
                return "csServeur";
            case csStripteaser:
                return "csStripteaser";
            case csMaison6:
                return "csMaison6";
            case csMaison8:
                return "csMaison8";
            case csMaison10:
                return "csMaison10";
            case csGarcon:
                return "csGarcon";
            case csFille:
                return "csFille";
            case csAuParc:
                return "csAuParc";
            case csAuBar:
                return "csAuBar";
            case csAuTheatre:
                return "csAuTheatre";
            case csAuCinema:
                return "csAuCinema";
            case csEnBoiteDeNuit:
                return "csEnBoiteDeNuit";
            case csAuRestaurant:
                return "csAuRestaurant";
            case csAuZoo:
                return "csAuZoo";
            case csSurInternet:
                return "csSurInternet";
            case csAuCamping:
                return "csAuCamping";
            case csALHotel:
                return "csALHotel";
            case csSalaire1:
                return "csSalaire1";
            case csSalaire2:
                return "csSalaire2";
            case csSalaire3:
                return "csSalaire3";
            case csSalaire4:
                return "csSalaire4";
            case csEtudeSimple:
                return "csEtudeSimple";
            case csEtudeDouble:
                return "csEtudeDouble";
            case csLicorne:
                return "csLicorne";
            case csAucun:
                return "csAucun";
            default: 
                return std::to_string(int(cst));
        }
    }
    std::string MySmileLife::toStringDP(DetailPlateau dp){
        switch(dp){
            case EtudesContinues:
                return "EtudesContinues";
            case FlirtIllimites:
                return "FlirtIllimites";
            case Interimaire:
                return "Interimaire";
            case Fonctionnaire:
                return "Fonctionnaire";
            case ResistantMaladie:
                return "ResistantMaladie";
            case ResistantLicenciement:
                return "ResistantLicenciement";
            case ResistantImpots:
                return "ResistantImpots";
            case ResistantAccident:
                return "ResistantAccident";
            case ResistantDivorce:
                return "ResistantDivorce";
            case RisquePrison:
                return "RisquePrison";
            case VoyagesGratuit:
                return "VoyagesGratuit";
            case MaisonOfferte:
                return "MaisonOfferte";
            case TrocProtege:
                return "TrocProtege";
            case LimiteCarte6:
                return "LimiteCarte6";
            case PistonActif:
                return "PistonActif";
            case HeritageDisponible:
                return "HeritageDisponible";
            case estMarie:
                return "estMarie";
            case estAdultere:
                return "estAdultere";
            case aUnTravail:
                return "aUnTravail";
            case EtoileFilanteJouee:
                return "EtoileFilanteJouee";
            case ArcEnCielJoue:
                return "ArcEnCielJoue";
            case NbAnneeEtude:
                return "NbAnneeEtude";
            case NombreFlirt:
                return "NombreFlirt";
            case NbEnfant:
                return "NbEnfant";
            case Profession:
                return "Profession";
            case LieuDernierFlirt:
                return "LieuDernierFlirt";
            case SalairesDisponibles:
                return "SalairesDisponibles";
            case DernierSalaireDisponible:
                return "DernierSalaireDisponible";
            case DerniereEtudeRedoublable:
                return "DerniereEtudeRedoublable";
            case NombreBebePossibleHorsMariage:
                return "NombreBebePossibleHorsMariage";
            case TourAPasser:
                return "TourAPasser";
            case SalaireMax:
                return "SalaireMax";
            case antiBandit:
                return "antiBandit";
            case antiGourou:
                return "antiGourou";
            case antiAttentat:
                return "antiAttentat";
            case casinoOuvert:
                return "casinoOuvert";
            default: 
                return std::to_string(int(dp));
        }
    }
    std::string MySmileLife::toStringEP(EmplacementsPlateau ep){
        switch(ep){
            case EFlirt:
                return "EFlirt";
            case EMariage:
                return "EMariage";
            case EMetier:
                return "EMetier";
            case ESpecial:
                return "ESpecial";
            case ESalairesD:
                return "ESalairesD";
            case EMalus:
                return "EMalus";
            case EEnfant:
                return "EEnfant";
            case EEtudes:
                return "EEtudes";
            case EEtudesContinues:
                return "EEtudesContinues";
            case EDivers:
                return "EDivers";
            case ECasinoSalaire:
                return "ECasinoSalaire";
            default: 
                return std::to_string(int(ep));
        }
    }

void MSLTests::MySmileLifeTest(){
    TestCarteUnitaire();
    /*
    cout << "creation game master" << endl;
    MSLMechanics gMe = MSLMechanics();
    CardGame::GameMaster gm         = CardGame::GameMaster(2,&gMe);

    CardGame::GameInterface* gI = dynamic_cast<CardGame::GameInterface*>(&gm);
    cout << "creation bots" << endl;
    CreationJoueur(gI);

    cout << "startgame" << endl;
    gm.startGame();

    cout << "getwinner" << endl;
    int vainqueur = gm.getWinner();

    cout << "et le vainqueur est: "<< vainqueur << endl;
    */
}