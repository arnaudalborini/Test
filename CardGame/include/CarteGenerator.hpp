#ifndef CARTEGENERATOR_HPP
#define CARTEGENERATOR_HPP

#include "CardGame.hpp"
#include "Carte.hpp"

namespace CardGame{
    class CarteGenerator{
        private:
            map<IdCarte,_pc_Carte> mapCarte;
        public:
            CarteGenerator();
            ~CarteGenerator();
            _pc_Carte getCarteById(int id)const{return CardGame::myMapGet(mapCarte,id);}
            void addCarte(_pc_Carte crt){
                mapCarte[crt->getId()]=crt;
            }

            virtual void genCartesPioche(vector<IdCarte> &vecCarte);
            virtual void genCartesDefausse(vector<IdCarte> &vecCarte);


    };
}

#endif