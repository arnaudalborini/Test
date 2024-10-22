#include "Test.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

void Test::CreationJoueur(CardGame::GameInterface * gI){
    Test::BasicBot bb1 = Test::BasicBot();
    Test::BasicBot bb2 = Test::BasicBot();
    const CardGame::PlayerInterface* indBB1 = gI->login(&bb1);
    cout << "login bot1:" << gI->getIdPlayer(&bb1) << endl;
    const CardGame::PlayerInterface* indBB2 = gI->login(&bb2);
    cout << "login bot2:" << gI->getIdPlayer(&bb2) << endl;
}