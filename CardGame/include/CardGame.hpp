#ifndef CARDGAME_H
#define CARDGAME_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <list>

#include <memory>

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

    typedef shared_ptr<const Carte> _pc_Carte;
    typedef shared_ptr<Carte> _p_Carte;
    typedef shared_ptr<const Player> _pc_Player;
    typedef shared_ptr<Player> _p_Player;
    typedef shared_ptr<const Plateau> _pc_Plateau;
    typedef shared_ptr<Plateau> _p_Plateau;
    typedef shared_ptr<const PlayerInterface> _pc_PlayerInterface;
    typedef shared_ptr<PlayerInterface> _p_PlayerInterface;
    typedef shared_ptr<const PaquetCarte> _pc_PaquetCarte;
    typedef shared_ptr<PaquetCarte> _p_PaquetCarte;

    typedef shared_ptr<const CartesAlgo> _pc_CartesAlgo;
    typedef shared_ptr<CartesAlgo> _p_CartesAlgo;
    typedef shared_ptr<const CarteGenerator> _pc_CarteGenerator;
    typedef shared_ptr<CarteGenerator> _p_CarteGenerator;
    typedef shared_ptr<const GameInterface> _pc_GameInterface;
    typedef shared_ptr<GameInterface> _p_GameInterface;
    typedef shared_ptr<const GameMaster> _pc_GameMaster;
    typedef shared_ptr<GameMaster> _p_GameMaster;
    typedef shared_ptr<const GameMasterMonitor> _pc_GameMasterMonitor;
    typedef shared_ptr<GameMasterMonitor> _p_GameMasterMonitor;
    
    typedef shared_ptr<const Monitor> _pc_Monitor;
    typedef shared_ptr<Monitor> _p_Monitor;
    typedef shared_ptr<const InfosJoueur> _pc_InfosJoueur;
    typedef shared_ptr<InfosJoueur> _p_InfosJoueur;
    typedef shared_ptr<const Hand> _pc_Hand;
    typedef shared_ptr<Hand> _p_Hand;
    typedef shared_ptr<const HandMonitor> _pc_HandMonitor;
    typedef shared_ptr<HandMonitor> _p_HandMonitor;
    typedef shared_ptr<const GameMechanics> _pc_GameMechanics;
    typedef shared_ptr<GameMechanics> _p_GameMechanics;
    typedef shared_ptr<const GameMechanicsMonitor> _pc_GameMechanicsMonitor;
    typedef shared_ptr<GameMechanicsMonitor> _p_GameMechanicsMonitor;
    typedef shared_ptr<const PlateauMonitor> _pc_PlateauMonitor;
    typedef shared_ptr<PlateauMonitor> _p_PlateauMonitor;
    typedef shared_ptr<const InfosJoueurMonitor> _pc_InfosJoueurMonitor;
    typedef shared_ptr<InfosJoueurMonitor> _p_InfosJoueurMonitor;

     
};

#endif