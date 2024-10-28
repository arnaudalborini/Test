#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace CardGame{
    class Player{
        public:
            virtual string getName()const=0;
            virtual int choisirUneCarteAJouer(PaquetCarte* paq)const=0;
    };
};

#endif