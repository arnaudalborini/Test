#include "MSLTests.hpp"
#include "GameMaster.hpp"
#include "GameMechanicsSpe.hpp"
#include "MSLMechanics.hpp"
using MySmileLife::Tests::MSLTests;

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