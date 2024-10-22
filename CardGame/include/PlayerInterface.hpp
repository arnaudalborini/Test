#ifndef PLAYERINTERFACE_HPP
#define PLAYERINTERFACE_HPP

#include "CardGame.hpp"

namespace CardGame{
    class PlayerInterface{
        public:
            virtual const InfosJoueur* getInfosJoueurs(int indPlayer)const=0;
            virtual const Plateau* getPlateau()const=0;
            virtual const PaquetCarte* getPioche()const=0;
            virtual const PaquetCarte* getDefausse()const=0;
            virtual const ParamCarte* getDescriptionCarte(IdCarte idC)const=0;
    };
}

#endif