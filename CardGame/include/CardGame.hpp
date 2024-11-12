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
    using std::weak_ptr;
    using std::dynamic_pointer_cast;
    enum EmplacementPlateau:int;
    typedef int IdCarte;
    class Carte;
    typedef shared_ptr<const Carte> _pc_Carte;
    typedef shared_ptr<Carte> _p_Carte;
    class CartesAlgo;
    typedef shared_ptr<const CartesAlgo> _pc_CartesAlgo;
    typedef shared_ptr<CartesAlgo> _p_CartesAlgo;
    class CarteGenerator;
    typedef shared_ptr<const CarteGenerator> _pc_CarteGenerator;
    typedef shared_ptr<CarteGenerator> _p_CarteGenerator;
    class ConcreteMonitor;
    typedef shared_ptr<const ConcreteMonitor> _pc_ConcreteMonitor;
    typedef shared_ptr<ConcreteMonitor> _p_ConcreteMonitor;
    class GameInterface;
    typedef shared_ptr<const GameInterface> _pc_GameInterface;
    typedef shared_ptr<GameInterface> _p_GameInterface;
    class GameMaster;
    typedef shared_ptr<const GameMaster> _pc_GameMaster;
    typedef shared_ptr<GameMaster> _p_GameMaster;
    class GameMasterMonitor;
    typedef shared_ptr<const GameMasterMonitor> _pc_GameMasterMonitor;
    typedef shared_ptr<GameMasterMonitor> _p_GameMasterMonitor;
    class GameMechanics;
    typedef shared_ptr<const GameMechanics> _pc_GameMechanics;
    typedef shared_ptr<GameMechanics> _p_GameMechanics;
    class GameMechanicsMonitor;
    typedef shared_ptr<const GameMechanicsMonitor> _pc_GameMechanicsMonitor;
    typedef shared_ptr<GameMechanicsMonitor> _p_GameMechanicsMonitor;
    class GameMechanicsSpe;
    typedef shared_ptr<const GameMechanicsSpe> _pc_GameMechanicsSpe;
    typedef shared_ptr<GameMechanicsSpe> _p_GameMechanicsSpe;
    class HandMonitor;
    typedef shared_ptr<const HandMonitor> _pc_HandMonitor;
    typedef shared_ptr<HandMonitor> _p_HandMonitor;
    class Hand;
    typedef shared_ptr<const Hand> _pc_Hand;
    typedef shared_ptr<Hand> _p_Hand;
    class InfosJoueur;
    typedef shared_ptr<const InfosJoueur> _pc_InfosJoueur;
    typedef shared_ptr<InfosJoueur> _p_InfosJoueur;
    class InfosJoueurMonitor;
    typedef shared_ptr<const InfosJoueurMonitor> _pc_InfosJoueurMonitor;
    typedef shared_ptr<InfosJoueurMonitor> _p_InfosJoueurMonitor;
    class Monitor;
    typedef shared_ptr<const Monitor> _pc_Monitor;
    typedef shared_ptr<Monitor> _p_Monitor;
    class PaquetCarte;
    typedef shared_ptr<const PaquetCarte> _pc_PaquetCarte;
    typedef shared_ptr<PaquetCarte> _p_PaquetCarte;
    class Plateau;
    typedef shared_ptr<const Plateau> _pc_Plateau;
    typedef shared_ptr<Plateau> _p_Plateau;
    class PlateauMonitor;
    typedef shared_ptr<const PlateauMonitor> _pc_PlateauMonitor;
    typedef shared_ptr<PlateauMonitor> _p_PlateauMonitor;
    class Player;
    typedef shared_ptr<const Player> _pc_Player;
    typedef shared_ptr<Player> _p_Player;
    class PlayerInterface;
    typedef shared_ptr<const PlayerInterface> _pc_PlayerInterface;
    typedef shared_ptr<PlayerInterface> _p_PlayerInterface;

    template <typename Key, typename T> T myMapGet(const std::map<Key,T>& mMap, Key k){
        if(mMap.find(k) != mMap.end()){
            return mMap.at(k);
        }
        return T();
    }    
}

#endif