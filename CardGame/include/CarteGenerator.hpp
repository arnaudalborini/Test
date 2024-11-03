#ifndef CARTEGENERATOR_HPP
#define CARTEGENERATOR_HPP

#include "CardGame.hpp"
#include "Carte.hpp"

namespace CardGame{
    class CarteGenerator{
        private:
            map<IdCarte,PCCarte> mapCarte;
        public:
            CarteGenerator();
            ~CarteGenerator();
            PCCarte getCarteById(int id)const{return CardGame::myMapGet(mapCarte,id);}
            void addCarte(PCCarte crt){
                mapCarte[crt->getId()]=crt;
            }

            virtual void genCartesPioche(vector<IdCarte> &vecCarte);
            virtual void genCartesDefausse(vector<IdCarte> &vecCarte);


    };
};

#endif