#include "MySmileLife.hpp"
#include "CarteGenerateurStandard.hpp"

#include "CarteMSL.hpp"
#include "Carte.hpp"
#include "MyShuffle.hpp"

using namespace MySmileLife;
using CardGame::IdCarte;

CarteGenerateurStandard::CarteGenerateurStandard():cptId(0)
{   
    cout << "CarteGenerateurStandard::CarteGenerateurStandard" << endl;
    addMetier();
    addEtude();
    addSalaire();
    addSpecial();
    addEnfant();
    addFlirt();;
    addMarriage();
    addMalus();
    addAnimal();
    addVoyage();
    addMaison();
}

void CarteGenerateurStandard::genCartesPioche( vector<IdCarte> &vecCartes)
{
    cout << "CarteGenerateurStandard::genCartesPioche" << endl;
    IdCarte id;
    map<CarteSousType,set<IdCarte>> mapCT = mapMSLCarte[carteMetier];
    for(auto sIC: mapCT){vecCartes.push_back(*sIC.second.begin());}
    id = getFirstSetIdCarte(carteEtude,EtudeSimple);
    for(int i=0;i<22;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteEtude,EtudeDouble);
    for(int i=0;i<3;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteSalaire,Salaire1);
    for(int i=0;i<10;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteSalaire,Salaire2);
    for(int i=0;i<10;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteSalaire,Salaire3);
    for(int i=0;i<10;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteSalaire,Salaire4);
    for(int i=0;i<10;i++){vecCartes.push_back( id );}
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Anniversaire) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,ArcEnCiel) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,cCasino) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Chance) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,EtoileFilante) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Heritage) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Piston) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Troc) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Tsunami) );
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,Vengeance) );
    id = getFirstSetIdCarte(carteSpecial,Adultere);
    for(int i=0;i<3;i++){vecCartes.push_back( id );}
    vecCartes.push_back( getFirstSetIdCarte(carteSpecial,LegionHonneur) );
    id = getFirstSetIdCarte(carteSpecial,GrandPrixExcellence);
    for(int i=0;i<2;i++){vecCartes.push_back( id );}
    mapCT = mapMSLCarte[carteEnfant];
    for(auto mapS: mapCT){
        for(IdCarte idC: mapS.second){
            vecCartes.push_back(idC);
        }
    }
    mapCT = mapMSLCarte[carteFlirt];
    for(auto mapS: mapCT){
        for(IdCarte idC: mapS.second){
            for(int i=0;i<2;i++){vecCartes.push_back( idC );}
        }
    }
    id = getFirstSetIdCarte(carteMariage,AucunSousType);
    for(int i=0;i<7;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,Accidents);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,BurnOut);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,Divorce);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,ImpotsRevenus);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,Licenciement);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,Maladie);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMalus,Redoublement);
    for(int i=0;i<5;i++){vecCartes.push_back( id );}
    vecCartes.push_back( getFirstSetIdCarte(carteMalus,Prison) );
    vecCartes.push_back( getFirstSetIdCarte(carteMalus,Attentat) );
    for(auto id: mapMSLCarte[carteAnimal][AucunSousType]){vecCartes.push_back(id);}
    vecCartes.push_back( getFirstSetIdCarte(carteAnimal,Licorne) );
    for(auto id: mapMSLCarte[carteVoyage][AucunSousType]){vecCartes.push_back(id);}
    id = getFirstSetIdCarte(carteMaison,Maison6);
    for(int i=0;i<2;i++){vecCartes.push_back( id );}
    id = getFirstSetIdCarte(carteMaison,Maison8);
    for(int i=0;i<2;i++){vecCartes.push_back( id );}
    vecCartes.push_back( getFirstSetIdCarte(carteMaison,Maison10) );

    CardGame::myShuffle(vecCartes);
    cout << "Fin CarteGenerateurStandard::genCartesPioche" << endl;
}

void CarteGenerateurStandard::addMetier(  ){
    addCarteMSL( new CarteMSL(++cptId,"Architecte",     2,carteMetier, Architecte) );
    addCarteMSL( new CarteMSL(++cptId,"Astronaute",     2,carteMetier, Astronaute) );
    addCarteMSL( new CarteMSL(++cptId,"Avocat",         2,carteMetier, Avocat) );
    addCarteMSL( new CarteMSL(++cptId,"Bandit",         2,carteMetier, Bandit) );
    addCarteMSL( new CarteMSL(++cptId,"Barman",         2,carteMetier, Barman) );
    addCarteMSL( new CarteMSL(++cptId,"ChefDesAchats",  2,carteMetier, ChefDesAchats) );
    addCarteMSL( new CarteMSL(++cptId,"ChefDesVentes",  2,carteMetier, ChefDesVentes) );
    addCarteMSL( new CarteMSL(++cptId,"Chercheur",      2,carteMetier, Chercheur) );
    addCarteMSL( new CarteMSL(++cptId,"Chirurgien",     2,carteMetier, Chirurgien) );
    addCarteMSL( new CarteMSL(++cptId,"Designer",       2,carteMetier, Designer) );
    addCarteMSL( new CarteMSL(++cptId,"Ecrivain",       2,carteMetier, Ecrivain) );
    addCarteMSL( new CarteMSL(++cptId,"Garagiste",      2,carteMetier, Garagiste) );
    addCarteMSL( new CarteMSL(++cptId,"GrandProf",      2,carteMetier, GrandProf) );
    addCarteMSL( new CarteMSL(++cptId,"Gourou",         2,carteMetier, Gourou) );
    addCarteMSL( new CarteMSL(++cptId,"Jardinier",      2,carteMetier, Jardinier) );
    addCarteMSL( new CarteMSL(++cptId,"Journaliste",    2,carteMetier, Journaliste) );
    addCarteMSL( new CarteMSL(++cptId,"Medecin",        2,carteMetier, Medecin) );
    addCarteMSL( new CarteMSL(++cptId,"Medium",         2,carteMetier, Medium) );
    addCarteMSL( new CarteMSL(++cptId,"Militaire",      2,carteMetier, Militaire) );
    addCarteMSL( new CarteMSL(++cptId,"Pharmacien",     2,carteMetier, Pharmacien) );
    addCarteMSL( new CarteMSL(++cptId,"PiloteDeLigne",  2,carteMetier, PiloteDeLigne) );
    addCarteMSL( new CarteMSL(++cptId,"Pizzaiolo",      2,carteMetier, Pizzaiolo) );
    addCarteMSL( new CarteMSL(++cptId,"Plombier",       2,carteMetier, Plombier) );
    addCarteMSL( new CarteMSL(++cptId,"Policier",       2,carteMetier, Policier) );
    addCarteMSL( new CarteMSL(++cptId,"ProfDeFrancais", 2,carteMetier, Prof) );
    addCarteMSL( new CarteMSL(++cptId,"ProfDeMaths",    2,carteMetier, Prof) );
    addCarteMSL( new CarteMSL(++cptId,"ProfDHistoire",  2,carteMetier, Prof) );
    addCarteMSL( new CarteMSL(++cptId,"ProfDAnglais",   2,carteMetier, Prof) );
    addCarteMSL( new CarteMSL(++cptId,"Serveur",        2,carteMetier, Serveur) );
    addCarteMSL( new CarteMSL(++cptId,"Stripteaser",    2,carteMetier, Stripteaser) );

    //Metier à promotion
    addCarteMSL( new CarteMSL(++cptId,"GrandProf",      2,carteMetier, GrandProf) );
}
void CarteGenerateurStandard::addEtude(   ){
    addCarteMSL( new CarteMSL(++cptId,"Etude Simple", 1,carteEtude, EtudeSimple) );
    addCarteMSL( new CarteMSL(++cptId,"Etude Double", 1,carteEtude, EtudeDouble) );
}
void CarteGenerateurStandard::addSalaire( ){
    addCarteMSL( new CarteMSL(++cptId,"Salaire 1", 1,carteSalaire, Salaire1) );
    addCarteMSL( new CarteMSL(++cptId,"Salaire 2", 1,carteSalaire, Salaire2) );
    addCarteMSL( new CarteMSL(++cptId,"Salaire 3", 1,carteSalaire, Salaire3) );
    addCarteMSL( new CarteMSL(++cptId,"Salaire 4", 1,carteSalaire, Salaire4) );
}
void CarteGenerateurStandard::addSpecial( ){
    //special 10
    addCarteMSL( new CarteMSL(++cptId,"Anniversaire",  0,carteSpecial, Anniversaire) );
    addCarteMSL( new CarteMSL(++cptId,"ArcEnCiel",     0,carteSpecial, ArcEnCiel) );
    addCarteMSL( new CarteMSL(++cptId,"cCasino",       0,carteSpecial, cCasino) );
    addCarteMSL( new CarteMSL(++cptId,"Chance",        0,carteSpecial, Chance) );
    addCarteMSL( new CarteMSL(++cptId,"EtoileFilante", 0,carteSpecial, EtoileFilante) );
    addCarteMSL( new CarteMSL(++cptId,"Heritage",      0,carteSpecial, Heritage) );
    addCarteMSL( new CarteMSL(++cptId,"Piston",        0,carteSpecial, Piston) );
    addCarteMSL( new CarteMSL(++cptId,"Troc",          0,carteSpecial, Troc) );
    addCarteMSL( new CarteMSL(++cptId,"Tsunami",       0,carteSpecial, Tsunami) );
    addCarteMSL( new CarteMSL(++cptId,"Vengeance",     0,carteSpecial, Vengeance) );

    //Adulteres 3
    addCarteMSL( new CarteMSL(++cptId,"Adultere",     0,carteSpecial, Adultere) );

    // Les distinctions 3
    addCarteMSL( new CarteMSL(++cptId,"LegionHonneur",       3,carteSpecial, LegionHonneur) );
    addCarteMSL( new CarteMSL(++cptId,"GrandPrixExcellence", 4,carteSpecial, GrandPrixExcellence) );
}
void CarteGenerateurStandard::addEnfant(  ){
    //10: 5 de chaque sexe
    vector<std::string> vecStr = {"Leïa","Hermione","Lara","Diana","Zelda"};
    for(auto str:vecStr){
        addCarteMSL( new CarteMSL(++cptId,str, 2,carteEnfant, Fille) );
    }
    vecStr.clear();
    vecStr = {"Luke","Mario","Luigi","Harry","Rocky"};
     for(auto str:vecStr){
        addCarteMSL( new CarteMSL(++cptId,str, 2,carteEnfant, Garcon) );
    }
}
void CarteGenerateurStandard::addFlirt(   ){
    //total 20
    // Sans bébé possible 8*2
    vector<CarteSousType> vecStr = {AuParc,AuBar,AuTheatre,AuCinema,EnBoiteDeNuit,AuRestaurant,AuZoo,SurInternet};
    for(auto lieu:vecStr){
        addCarteMSL( new CarteMSL(++cptId,"Flirt", 1,carteFlirt, lieu) );
    }
    // avec bébé possible 2*2
    addCarteMSL( new CarteMSL(++cptId,"Flirt", 1,carteFlirt, AuCamping) );
    addCarteMSL( new CarteMSL(++cptId,"Flirt", 1,carteFlirt, ALHotel) );
}
void CarteGenerateurStandard::addMarriage(){
    addCarteMSL( new CarteMSL(++cptId,"Mariage", 3,carteMariage, AucunSousType) );
}
void CarteGenerateurStandard::addMalus(   ){
    addCarteMSL( new CarteMSL(++cptId,"Accidents",         0,carteMalus, Accidents) );
    addCarteMSL( new CarteMSL(++cptId,"Burne Out",         0,carteMalus, BurnOut) );
    addCarteMSL( new CarteMSL(++cptId,"Dit Vorce",         0,carteMalus, Divorce) );
    addCarteMSL( new CarteMSL(++cptId,"Un pot",            0,carteMalus, ImpotsRevenus) );
    addCarteMSL( new CarteMSL(++cptId,"Lit 100 ciments",   0,carteMalus, Licenciement) );
    addCarteMSL( new CarteMSL(++cptId,"Mâle à dit",        0,carteMalus, Maladie) );
    addCarteMSL( new CarteMSL(++cptId,"Redoublement",      0,carteMalus, Redoublement) );
    addCarteMSL( new CarteMSL(++cptId,"Prison",            0,carteMalus, Prison) );
    addCarteMSL( new CarteMSL(++cptId,"Attentat",          0,carteMalus, Attentat) );
}
void CarteGenerateurStandard::addAnimal(  ){
    for(auto str: {"Chat","chien","Lapin","Oiseau"} ){
        addCarteMSL( new CarteMSL(++cptId,str, 1,carteAnimal, AucunSousType) );
    }
    addCarteMSL( new CarteMSL(++cptId,"Licorne", 3,carteAnimal, Licorne) );
}
void CarteGenerateurStandard::addVoyage(  ){
    for(auto str: {"Londres","New York","Rio de Janeiro","Sydney","Le Caire"}){
        addCarteMSL( new CarteMSL(++cptId,str, 1,carteVoyage, AucunSousType) );
    }
}
void CarteGenerateurStandard::addMaison(  ){
    addCarteMSL( new CarteMSL(++cptId,"Maison 6", 1,carteMaison, Maison6) );
    addCarteMSL( new CarteMSL(++cptId,"Maison 8", 2,carteMaison, Maison8) );
    addCarteMSL( new CarteMSL(++cptId,"Maison 10", 3,carteMaison, Maison10) );
}

void MySmileLife::CarteGenerateurStandard::addCarteMSL(const CarteMSL *crt)
{
    IdCarte id = crt->getId();
    CarteType ct = crt->getType();
    CarteSousType cst = crt->getSType();
    mapMSLCarte[ct][cst].insert(id);
    addCarte(dynamic_cast<const CardGame::Carte*>(crt));
}
