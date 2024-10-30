#ifndef CARTEGENERATOR_HPP
#define CARTEGENERATOR_HPP

#include "CardGame.hpp"
#include "Carte.hpp"

namespace CardGame{
    class CarteGenerator{
        private:
            map<IdCarte,const Carte*> mapCarte;
        public:
            CarteGenerator();
            ~CarteGenerator();
            const Carte* getCarteById(int id)const{return CardGame::myMapGet(mapCarte,id);}
            void addCarte(const Carte* crt){
                mapCarte[crt->getId()]=crt;
            }

            virtual void genCartesPioche(vector<IdCarte> &vecCarte);
            virtual void genCartesDefausse(vector<IdCarte> &vecCarte);


    };
};

#endif