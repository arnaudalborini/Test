#ifndef CARDGAME_H
#define CARDGAME_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <list>

#include <memory>

#include "boost/shared_ptr.hpp"

namespace CardGame{
    using std::cout;
    using std::endl;
    using std::string;
    using std::vector;
    using std::map;
    using std::list;
    using std::shared_ptr;
    using std::make_shared;
    using std::dynamic_pointer_cast;
    enum EmplacementPlateau:int;
    typedef int IdCarte;
    class CartesAlgo;
    class CarteGenerator;
    class GameInterface;
    class GameMaster;
    class GameMasterMonitor;
    class GameMechanics;
    class GameMechanicsMonitor;
    class GameMechanicsSpe;
    class HandMonitor;
    class Hand;
    class InfosJoueur;
    class InfosJoueurMonitor;
    class Monitor;
    class PaquetCarte;
    class Carte;
    class Plateau;
    class PlateauMonitor;
    class Player;
    class PlayerInterface;
    class StatutPlateau;

    template <typename Key, typename T> T myMapGet(const std::map<Key,T>& mMap, Key k){
        if(mMap.find(k) != mMap.end()){
            return mMap.at(k);
        }
        return T();
    }

    typedef shared_ptr<const Carte> PCCarte;
    typedef shared_ptr<Carte> PCarte;
    typedef shared_ptr<const Player> PCPlayer;
    typedef shared_ptr<Player> PPlayer;
    typedef shared_ptr<const Plateau> PCPlateau;
    typedef shared_ptr<Plateau> PPlateau;
    typedef shared_ptr<const PlayerInterface> PCPlayerInterface;
    typedef shared_ptr<PlayerInterface> PPlayerInterface;
    typedef shared_ptr<const PaquetCarte> PCPaquetCarte;
    typedef shared_ptr<PaquetCarte> PPaquetCarte;

    typedef shared_ptr<const CartesAlgo> PCCartesAlgo;
    typedef shared_ptr<CartesAlgo> PCartesAlgo;
    typedef shared_ptr<const CarteGenerator> PCCarteGenerator;
    typedef shared_ptr<CarteGenerator> PCarteGenerator;
    typedef shared_ptr<const GameInterface> PCGameInterface;
    typedef shared_ptr<GameInterface> PGameInterface;
    typedef shared_ptr<const GameMaster> PCGameMaster;
    typedef shared_ptr<GameMaster> PGameMaster;
    typedef shared_ptr<const GameMasterMonitor> PCGameMasterMonitor;
    typedef shared_ptr<GameMasterMonitor> PGameMasterMonitor;
    
    typedef shared_ptr<const Monitor> PCMonitor;
    typedef shared_ptr<Monitor> PMonitor;
    typedef shared_ptr<const InfosJoueur> PCInfosJoueur;
    typedef shared_ptr<InfosJoueur> PInfosJoueur;
    typedef shared_ptr<const Hand> PCHand;
    typedef shared_ptr<Hand> PHand;
    typedef shared_ptr<const HandMonitor> PCHandMonitor;
    typedef shared_ptr<HandMonitor> PHandMonitor;
    typedef shared_ptr<const GameMechanics> PCGameMechanics;
    typedef shared_ptr<GameMechanics> PGameMechanics;
    typedef shared_ptr<const GameMechanicsMonitor> PCGameMechanicsMonitor;
    typedef shared_ptr<GameMechanicsMonitor> PGameMechanicsMonitor;
    typedef shared_ptr<const PlateauMonitor> PCPlateauMonitor;
    typedef shared_ptr<PlateauMonitor> PPlateauMonitor;
    typedef shared_ptr<const InfosJoueurMonitor> PCInfosJoueurMonitor;
    typedef shared_ptr<InfosJoueurMonitor> PInfosJoueurMonitor;

     
};

#endif