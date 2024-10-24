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
        Accidents,
        Attentat,
        BurnOut,
        Divorce,
        ImpotsRevenus,
        Licenciement,
        Maladie,
        Prison,
        Redoublement,
        //Special
        Adultere,
        Troc,
        cCasino,
        Chance,
        Piston,
        Anniversaire,
        ArcEnCiel,
        EtoileFilante,
        Heritage,
        Tsunami,
        Vengeance,
        LegionHonneur,
        GrandPrixExcellence,
        //Metier
        Architecte,
        Astronaute, 
        Avocat, 
        Bandit, 
        Barman, 
        ChefDesAchats, 
        ChefDesVentes,
        Chercheur, 
        Chirurgien, 
        Designer,
        Ecrivain, 
        Garagiste, 
        Gourou, 
        GrandProf, 
        Jardinier, 
        Journaliste, 
        Medecin, 
        Medium, 
        Militaire, 
        Pharmacien, 
        PiloteDeLigne,
        Pizzaiolo,
        Plombier,
        Policier,
        Prof,
        Serveur, 
        Stripteaser,
        //TypeMaison
        Maison6,
        Maison8,
        Maison10,
        //TypeEnfant
        Garcon,
        Fille,
        //LieuFlirt
        AuParc,
        AuBar,
        AuTheatre,
        AuCinema,
        EnBoiteDeNuit,
        AuRestaurant,
        AuZoo,
        SurInternet,
        AuCamping,
        ALHotel,
        //Salaire
        Salaire1,
        Salaire2,
        Salaire3,
        Salaire4,
        //Etude
        EtudeSimple,
        EtudeDouble,
        //Animal Particulier
        Licorne,
        AucunSousType = -1
    };
    enum StatuGeneral:int{
        antiBandit,
        antiGourou,
        antiAttentat,
        casinoOuvert
    };
    enum StatuPlateau:int{
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
        estAdultereb            = 17,
        aUnTravail              = 18,
        //Autre
        EtoileFilanteJouee      = 19,
        ArcEnCielJoue           = 20,
        //non booleen
        NbAnneeEtude            = 21,
        NbFlirt                 = 22,
        NbEnfant                = 23,
        TypeMetier              = 24,
        LieuDernierFlirt        = 25,
        SalairesDisponibles     = 26,
        DernierSalaireDisponible      = 27,
        DerniereEtudeRedoublable      = 28,
        NombreBebePossibleHorsMariage = 29,
        TourAPasser             = 30,
        SalaireMax              = 31
    };
    const int MAXSTATUTPLATEAU = StatuPlateau::SalaireMax;
    const int DEFAULTMAXHANDSIZE = 5;
    enum EmplacementsPlateau:int{
        EFlirt,
        EFlirtAdultere,
        EMariage,
        EMetier,
        ESpecial,
        ESalairesD,
        EMalus,
        EEnfant,
        EEtudes,
        EEtudesContinues,
        EDivers
    };
    enum EmplacementsPlateauPartages:int{
        ECasinoSalaire
    };
    class BasicBot;
    class CarteMSL;
    void CreationJoueur(CardGame::GameInterface* gI);
    void MySmileLifeTest();
}

#endif