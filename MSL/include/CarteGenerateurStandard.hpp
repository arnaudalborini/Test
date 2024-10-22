#ifndef CARTEGENERATEURSTANDARD_HPP
#define CARTEGENERATEURSTANDARD_HPP

#include "MySmileLife.hpp"
#include "CarteGenerator.hpp"

namespace MySmileLife{
    class CarteGenerateurStandard: public CardGame::CarteGenerator{
        private:
            int cptId;
            void addMetier(  );
            void addEtude(   );
            void addSalaire( );
            void addSpecial( );
            void addEnfant(  );
            void addFlirt(   );
            void addMarriage();
            void addMalus(   );
            void addAnimal(  );
            void addVoyage(  );
            void addMaison(  );
            void addCarteMSL(const CarteMSL* crt);
            map<CarteType,map<CarteSousType,set<CardGame::IdCarte>>> mapMSLCarte;
            set<CardGame::IdCarte> getSetIdCarte(CarteType ct, CarteSousType cst)const{return mapMSLCarte.at(ct).at(cst);}
            map<CarteSousType,set<CardGame::IdCarte>> getMapCstSetIdCarte(CarteType ct)const{return mapMSLCarte.at(ct);}
            CardGame::IdCarte getFirstSetIdCarte(CarteType ct, CarteSousType cst)const{return *(mapMSLCarte.at(ct).at(cst).begin());}

        public:
            CarteGenerateurStandard();
            virtual void genCartesPioche(vector<CardGame::IdCarte> &vecCarte);
    };
};

#endif