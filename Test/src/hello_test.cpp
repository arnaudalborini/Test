#include "Test.hpp"
#include "GameMaster.hpp"
#include "GameMechanicsSpe.hpp"

void Test::sayHello(){
    cout << "creation game master" << endl;
    CardGame::GameMechanicsSpe gMe  = CardGame::GameMechanicsSpe();
    CardGame::GameMaster gm         = CardGame::GameMaster(2,&gMe);

    CardGame::GameInterface* gI = dynamic_cast<CardGame::GameInterface*>(&gm);
    cout << "creation bots" << endl;
    CreationJoueur(gI);

    cout << "startgame" << endl;
    gm.startGame();

    cout << "getwinner" << endl;
    int vainqueur = gm.getWinner();

    cout << "et le vainqueur est: "<< vainqueur << endl;

}