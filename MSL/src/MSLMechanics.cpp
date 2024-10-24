#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "StatutPlateau.hpp"
#include "CarteMSL.hpp"
#include "Hand.hpp"
#include "Player.hpp"

using MySmileLife::MSLMechanics;
using MySmileLife::CarteMSL;
using CardGame::IdCarte;
using CardGame::Player;
using CardGame::Hand;
using CardGame::Plateau;
using CardGame::StatutPlateau;

MSLMechanics::MSLMechanics()
{
    cGen = new CarteGenerateurStandard();
}

const CarteMSL* MSLMechanics::getCarteFromId(IdCarte id)const{
    return dynamic_cast<const CarteMSL*>(cGen->getCarteById(id));
}
int  MSLMechanics::getSmileFromId(IdCarte id)const{return getCarteFromId(id)->getNbSmile();}
int  MSLMechanics::countSmile(CardGame::Plateau* plateauJoueur)const{
    int s=0;
    for(auto elt : plateauJoueur->showAllId() ){
        s+=getSmileFromId(elt);
    }
    return s;
}

int  MSLMechanics::getStatutPlayer(int indPlayer, DetailPlateau dp)const{return getJoueurPlateau(indPlayer)->getStatut(dp);}
void MSLMechanics::setStatutPlayer(int indPlayer, DetailPlateau dp, int value) {getJoueurPlateau(indPlayer)->setStatut(dp,value);}
void MSLMechanics::incStatutPlayer(int indPlayer, DetailPlateau dp, int inc) {setStatutPlayer( indPlayer, dp, getStatutPlayer( indPlayer, dp ) + inc );}
void MSLMechanics::decStatutPlayer(int indPlayer, DetailPlateau dp, int inc) {incStatutPlayer(indPlayer,dp,-inc);}

///////////////////////   Methodes virtuelles à réimplémenter si non standard ///////////
int MSLMechanics::getStandardHandNbCarte() const{return MySmileLife::DEFAULTMAXHANDSIZE;}
int MSLMechanics::getWinnerPlayer()const{
    int baseSmile = countSmile( mMonitor->getInfosJoueurs( 0 )->getPlateau() );
    int indBest = 0;
    for(int indPlayer=0;indPlayer<mMonitor->getNbPlayer();indPlayer++){
        int cSmile = countSmile( mMonitor->getInfosJoueurs( indPlayer )->getPlateau() );
        if(baseSmile<cSmile){
            baseSmile = cSmile;
            indBest = indPlayer;
        }
    }
    return indBest;
}
void MSLMechanics::playTurn(int indPlayer) const{
    cout << "playTurn::playTurn" << endl;
    const Player* pp = getPlayer(indPlayer);
    Hand* jHand = getJoueurHand(indPlayer);
    Plateau* platJ = getJoueurPlateau(indPlayer);
    Plateau* platGeneral = getMainPlateau();
    StatutPlateau* st = platJ->getStatutPlateau();
    cout << st->getStatut(DetailPlateau::aUnTravail) << endl;
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    int id = jHand->getIdCarte(nbCarte-1);
    IdCarte idC = jHand->getCarte(0);
    addCarteDefausse(idC,indPlayer);
    cout << "fin playTurn::playTurn" << endl;
}
std::vector<int> MSLMechanics::getJoueurInitialStatuts() const
{
    vector<int> initVec = vector<int>(MySmileLife::MAXSTATUTPLATEAU+1);
    //BonusSpeciaux
    for(int indSt=0;indSt<=MySmileLife::MAXSTATUTPLATEAU;indSt++){initVec[indSt] = 0;}
    return initVec;
}