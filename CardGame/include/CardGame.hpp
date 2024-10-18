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
    class InfosJoueur;
    class Hand;
    class PaquetCarte;
    class Plateau;
    class GameMechanics;
    class Player;
    class CarteGenerator;
    class Monitor;
    class GameMasterMonitor;
    class GameMechanicsMonitor;
};

#endif