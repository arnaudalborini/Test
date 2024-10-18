#ifndef CARTEGENERATOR_HPP
#define CARTEGENERATOR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class CarteGenerator{
        public:
            CarteGenerator();
            ~CarteGenerator();
            virtual void genCartesPioche(const vector<IdCarte> &vecCarte);
            virtual void genCartesDefausse(const vector<IdCarte> &vecCarte);
    };
};

#endif