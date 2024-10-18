#ifndef CARTE_H
#define CARTE_H

#include "CardGame.hpp"
#include "InfosJoueur.hpp"

namespace CardGame{
    class Carte{
        private:
            int mId;
            string mName;
        public:
            Carte();
            Carte(int ii,string name);
            ~Carte();
            int getId()const;
            string getName()const;
    };
};

#endif
