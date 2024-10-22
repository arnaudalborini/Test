#ifndef TEST_HPP
#define TEST_HPP

#include "CardGame.hpp"

#include <iostream>

namespace Test{
    using std::cout;
    using std::endl;
    using std::cin;

    class BasicBot;
    void CreationJoueur(CardGame::GameInterface* gI);
    void sayHello();
}

#endif