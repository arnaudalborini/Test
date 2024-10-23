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
        EtudesContinues,
        FlirtIllimites,
        Interimaire,
        Fonctionnaire,
        ResistantMaladie,
        ResistantLicenciement,
        ResistantImpots,
        ResistantAccident,
        ResistantDivorce,
        RisquePrison,
        VoyagesGratuit,
        MaisonOfferte,
        TrocProtege,
        LimiteCarte6,
        PistonActif,
        HeritageDisponible,
        //Standard
        estMarie,
        estAdultere,
        aUnTravail,
        //Autre
        EtoileFilanteJouee,
        ArcEnCielJoue
    };
    enum DetailPlateau:int{
        NbAnneeEtude,
        NbFlirt,
        NbEnfant,
        TypeMetier,
        LieuDernierFlirt,
        SalairesDisponibles,
        DernierSalaireDisponible,
        DerniereEtudeRedoublable,
        NombreBebePossibleHorsMariage,
        TourAPasser,
        SalaireMax
    };
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