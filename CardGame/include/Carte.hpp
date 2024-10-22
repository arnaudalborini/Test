#ifndef PARAMCARTE_HPP
#define PARAMCARTE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class Carte{
        private:
            IdCarte mId;
        public:
            Carte(int id):mId(id){}
            IdCarte getId()const{return mId;}
            virtual ~Carte(){};
    };
}

#endif