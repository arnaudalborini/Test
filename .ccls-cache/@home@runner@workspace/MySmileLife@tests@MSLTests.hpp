#ifndef MSLTESTS_HPP
#define MSLTESTS_HPP

#include "../include/MySmileLife.hpp"

namespace MySmileLife{
    namespace Tests{
        class MSLTests{
            public:
                static void TestCarteUnitaire();
                static void CreationJoueur(CardGame::GameInterface * gI);
                static void MySmileLifeTest();
                class MSLMechanicsTest;
        };
    }
}

#endif