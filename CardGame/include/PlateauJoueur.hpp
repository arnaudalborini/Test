#ifndef PLATEAUJOUEUR_HPP
#define PLATEAUJOUEUR_HPP

#include "CardGame.hpp"

namespace CardGame{
    class PlateauJoueur{
        private:
            map<EmplacementPlateau,vector<const Carte*>> mMapCarte;
        public:
            PlateauJoueur();
            ~PlateauJoueur();

            void addLast(EmplacementPlateau EP, const Carte* crt);
            int getNbCarte(EmplacementPlateau EP)const;

            int getIdLast(EmplacementPlateau EP)const;
            const Carte* getLast(EmplacementPlateau EP);
            int getIdN(EmplacementPlateau EP,int N)const;
            const Carte* getN(EmplacementPlateau EP,int N);
    };
};

#endif