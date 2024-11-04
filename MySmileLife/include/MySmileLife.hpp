#ifndef TEST_HPP
#define TEST_HPP

#include "CardGame.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>

namespace MySmileLife{
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;
    using std::vector;
    using std::map;
    using std::list;
    using std::set;
    using CardGame::shared_ptr;
    using CardGame::make_shared;
    using CardGame::dynamic_pointer_cast;
    using CardGame::IdCarte;
    enum CarteType:int{
        carteEtude,
        carteMetier,
        carteMalus,
        carteAnimal,
        carteVoyage,
        carteMaison,
        carteFlirt,
        carteEnfant,
        carteSpecial,
        carteSalaire,
        carteMariage
    };
    enum CarteSousType:int{
        //Malus
        csAccidents,
        csAttentat,
        csBurnOut,
        csDivorce,
        csImpotsRevenus,
        csLicenciement,
        csMaladie,
        csPrison,
        csRedoublement,
        //Special
        csAdultere,
        csTroc,
        csCasino,
        csChance,
        csPiston,
        csAnniversaire,
        csArcEnCiel,
        csEtoileFilante,
        csHeritage,
        csTsunami,
        csVengeance,
        csLegionHonneur,
        csGrandPrixExcellence,
        //Metier
        csArchitecte,
        csAstronaute, 
        csAvocat, 
        csBandit, 
        csBarman, 

        csChefDesAchats, 
        csChefDesVentes,
        csChercheur, 
        csChirurgien, 
        csDesigner,

        csEcrivain, 
        csGaragiste, 
        csGourou, 
        csGrandProf, 
        csJardinier, 

        csJournaliste, 
        csMedecin, 
        csMedium, 
        csMilitaire, 
        csPharmacien, 

        csPiloteDeLigne,
        csPizzaiolo,
        csPlombier,
        csPolicier,
        csProf,
        
        csServeur, 
        csStripteaser,
        //TypeMaison
        csMaison6,
        csMaison8,
        csMaison10,
        //TypeEnfant
        csGarcon,
        csFille,
        //LieuFlirt
        csAuParc,
        csAuBar,
        csAuTheatre,
        csAuCinema,
        csEnBoiteDeNuit,
        csAuRestaurant,
        csAuZoo,
        csSurInternet,
        csAuCamping,
        csALHotel,
        //Salaire
        csSalaire1,
        csSalaire2,
        csSalaire3,
        csSalaire4,
        //Etude
        csEtudeSimple,
        csEtudeDouble,
        //Animal Particulier
        csLicorne,
        csAucun = -1
    };
    enum DetailPlateau:int{
        //BonusSpeciaux
        EtudesContinues         = 0,
        FlirtIllimites          = 1,
        Interimaire             = 2,
        Fonctionnaire           = 3,
        ResistantMaladie        = 4,
        ResistantLicenciement   = 5,
        ResistantImpots         = 6,
        ResistantAccident       = 7,
        ResistantDivorce        = 8,
        RisquePrison            = 9,
        VoyagesGratuit          = 10,
        MaisonOfferte           = 11,
        TrocProtege             = 12,
        LimiteCarte6            = 13,
        PistonActif             = 14,
        HeritageDisponible      = 15,
        //Standard
        estMarie                = 16,
        estAdultere            = 17,
        aUnTravail              = 18,
        //Autre
        EtoileFilanteJouee      = 19,
        ArcEnCielJoue           = 20,
        //non booleen
        NbAnneeEtude            = 21,
        NombreFlirt                 = 22,
        NbEnfant                = 23,
        Profession              = 24,
        LieuDernierFlirt        = 25,
        SalairesDisponibles     = 26,
        DernierSalaireDisponible      = 27,
        DerniereEtudeRedoublable      = 28,
        NombreBebePossibleHorsMariage = 29,
        TourAPasser             = 30,
        SalaireMax              = 31,
        //Status generaux
        antiBandit              = 32,
        antiGourou              = 33,
        antiAttentat            = 34,
        casinoOuvert            = 35
    };
    const int MAXSTATUTPLATEAU = DetailPlateau::casinoOuvert;
    const int DEFAULTMAXHANDSIZE = 5;
    const int PRIXVOYAGE = 3;
    enum EmplacementsPlateau:int{
        EFlirt = 0,
        EFlirtAdultere = 1,
        EMariage = 2,
        EMetier = 3,
        ESpecial = 4,
        ESalairesD = 5,
        EMalus = 6,
        EEnfant = 7,
        EEtudes = 8,
        EEtudesContinues = 9,
        EDivers = 10,
        ECasinoSalaire = 11
    };
    const int MAXEMPLACEMENTPLATEAU = EmplacementsPlateau::ECasinoSalaire;

    class CartesAlgoMSL;
    typedef shared_ptr<const CartesAlgoMSL> _pc_CartesAlgoMSL;
    typedef shared_ptr<CartesAlgoMSL> _p_CartesAlgoMSL;

    class BasicBot;
    typedef shared_ptr<const BasicBot> _pc_BasicBot;
    typedef shared_ptr<BasicBot> _p_BasicBot;

    class CarteMSL;
    typedef shared_ptr<const CarteMSL> _pc_CarteMSL;
    typedef shared_ptr<CarteMSL> _p_CarteMSL;

    class CarteGenerateurStandard;
    typedef shared_ptr<const CarteGenerateurStandard> _pc_CarteGenerateurStandard;
    typedef shared_ptr<CarteGenerateurStandard> _p_CarteGenerateurStandard;

    class JouerCarteMSL;
    typedef shared_ptr<const JouerCarteMSL> _pc_JouerCarteMSL;
    typedef shared_ptr<JouerCarteMSL> _p_JouerCarteMSL;

    class JouerMalus;
    typedef shared_ptr<const JouerMalus> _pc_JouerMalus;
    typedef shared_ptr<JouerMalus> _p_JouerMalus;

    class JouerMetier;
    typedef shared_ptr<const JouerMetier> _pc_JouerMetier;
    typedef shared_ptr<JouerMetier> _p_JouerMetier;

    class JouerSpecial;
    typedef shared_ptr<const JouerSpecial> _pc_JouerSpecial;
    typedef shared_ptr<JouerSpecial> _p_JouerSpecial;

    class MSLMechanics;
    typedef shared_ptr<const MSLMechanics> _pc_MSLMechanics;
    typedef shared_ptr<MSLMechanics> _p_MSLMechanics;

    class MSLPlayer;
    typedef shared_ptr<const MSLPlayer> _pc_MSLPlayer;
    typedef shared_ptr<MSLPlayer> _p_MSLPlayer;

}

#endif