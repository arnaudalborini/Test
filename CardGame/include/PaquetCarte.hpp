#ifndef PAQUETCARTE_HPP
#define PAQUETCARTE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class PaquetCarte{
        private:
            vector<IdCarte> mCartes;
        public:
            PaquetCarte();
            ~PaquetCarte();
            void initializePaquet(const vector<IdCarte> &vecCartes);
            IdCarte piocher();
            int showIdLast()const;
    };
};

#endif