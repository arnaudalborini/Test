#include "MySmileLife.hpp"

#include "BasicBot.hpp"
#include "GameInterface.hpp"

void MySmileLife::CreationJoueur(CardGame::GameInterface * gI){
    BasicBot* bb1 = new BasicBot();
    BasicBot* bb2 = new BasicBot();
    const CardGame::PlayerInterface* indBB1 = gI->login(bb1);
    cout << "login bot1:" << gI->getIdPlayer(bb1) << endl;
    const CardGame::PlayerInterface* indBB2 = gI->login(bb2);
    cout << "login bot2:" << gI->getIdPlayer(bb2) << endl;
}