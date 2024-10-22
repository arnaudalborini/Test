#include "hello_test.hpp"
#include "Carte.hpp"
#include "InfosJoueur.hpp"
#include "GameMaster.hpp"
#include "GameMechanicsSpe.hpp"
#include "BasicBot.hpp"

#include <iostream>

using std::cout;
using std::endl;

void Test::sayHello(){
    cout << "creation game master" << endl;

    CardGame::GameMaster* gm = new CardGame::GameMaster();
    cout << "creation game mechanics" << endl;
    CardGame::GameMechanicsSpe* gMe = new CardGame::GameMechanicsSpe();
    cout << "initGame" << endl;
    gm->initGame(2,gMe);
    cout << "creation bots" << endl;
    Test::BasicBot bb1 = Test::BasicBot();
    Test::BasicBot bb2 = Test::BasicBot();

    int indBB1 = gm->login(&bb1);
    cout << "login bot1:" << indBB1 << endl;
    int indBB2 = gm->login(&bb2);
    cout << "login bot2:" << indBB2 << endl;

    cout << "startgame" << endl;
    gm->startGame();

    cout << "getwinner" << endl;
    int vainqueur = gm->getWinner();

    cout << "et le vainqueur est: "<< vainqueur << endl;

    delete gm;
    delete gMe;
}