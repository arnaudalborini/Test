#ifndef MSLTESTS_HPP
#define MSLTESTS_HPP

#include "../include/MySmileLife.hpp"

namespace MySmileLife{
    string toStringDP(DetailPlateau dp);
    string toStringEP(EmplacementsPlateau ep);
    string toStringCST(CarteSousType cst);
    string toStringCT(CarteType ct);
    namespace Tests{
        class MSLTests{
            public:
                static void TestCarteUnitaire();
                static void CreationJoueur(CardGame::_p_GameInterface gI);
                static void MySmileLifeTest();
                class MSLMechanicsTest;
        };
        
    }
}

#endif