#ifndef CARTEGENERATEURSTANDARD_HPP
#define CARTEGENERATEURSTANDARD_HPP

#include "MySmileLife.hpp"
#include "CarteGenerator.hpp"
#include "MyMultiMap.hpp"

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
            MyMultiMap<set<IdCarte>> multiMapMSLCarte;
            set<IdCarte> getSetIdCarte(CarteType ct, CarteSousType cst)const{return multiMapMSLCarte[{ct,cst}];}
            map<int,set<IdCarte>> getMapCstSetIdCarte(CarteType ct)const{return multiMapMSLCarte.getMapByKey1(ct);}
            IdCarte getFirstSetIdCarte(CarteType ct, CarteSousType cst)const{return *(multiMapMSLCarte[{ct,cst}].begin());}

        public:
            CarteGenerateurStandard();
            virtual void genCartesPioche(vector<IdCarte> &vecCarte);
    };
};

#endif