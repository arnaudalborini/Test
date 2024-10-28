#ifndef PAQUETCARTE_HPP
#define PAQUETCARTE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class PaquetCarte{
        private:
            vector<IdCarte> mCartes;
            vector<int> mPlayedBy;
        public:
            PaquetCarte();
            ~PaquetCarte();
            void initializePaquet(vector<IdCarte> &vecCartes);
            void initializePaquet(const vector<IdCarte> &vecCartes, const vector<int> &playedBy);
            IdCarte piocher();
            IdCarte piocherNeme(int N);
            IdCarte showIdLast()const;
            IdCarte showNeme(int n)const;
            int getNbCarte()const;
            void addCarte(IdCarte idC);
            void addCarte(IdCarte idC,int playedBy);
            int showLastPlayedBy()const;
    };
};

#endif