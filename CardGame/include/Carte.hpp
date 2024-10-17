#ifndef CARTE_H
#define CARTE_H

#include "CardGame.hpp"
#include "InfosJoueur.hpp"

namespace CardGame{
    class Carte{
        private:
            InfosJoueur* m_j;
        public:
            Carte();
            Carte(InfosJoueur* jj);
            ~Carte();
    };
};

#endif
