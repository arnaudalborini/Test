#ifndef CARTE_H
#define CARTE_H

#include "CardGame.hpp"
#include "Joueur.hpp"

namespace CardGame{
    class Carte{
        private:
            Joueur* m_j;
        public:
            Carte();
            Carte(Joueur* jj);
            ~Carte();
    };
};

#endif
