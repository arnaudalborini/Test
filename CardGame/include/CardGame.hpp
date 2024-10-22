#ifndef CARDGAME_H
#define CARDGAME_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <list>

namespace CardGame{
    using std::cout;
    using std::endl;
    using std::string;
    using std::vector;
    using std::map;
    using std::list;
    enum EmplacementPlateau:int;
    enum EmplacementPlateauGeneral:int;
    typedef int IdCarte;
    class CarteGenerator;
    class GameInterface;
    class GameMaster;
    class GameMasterMonitor;
    class GameMechanics;
    class GameMechanicsMonitor;
    class GameMechanicsSpe;
    class Hand;
    class InfosJoueur;
    class Monitor;
    class PaquetCarte;
    class Carte;
    class Plateau;
    class Player;
    class PlayerInterface;
};

#endif