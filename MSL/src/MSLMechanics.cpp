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
int MSLMechanics::getSmileFromId(IdCarte id)const{return getCarteFromId(id)->getNbSmile();}
int MSLMechanics::countSmile(CardGame::Plateau* plateauJoueur)const{
    int s=0;
    for(auto elt : plateauJoueur->showAllId() ){
        s+=getSmileFromId(elt);
    }
    return s;
}


///////////////////////   Methodes virtuelles à réimplémenter si non standard ///////////
int MSLMechanics::getStandardHandNbCarte() const{return 5;}
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
    StatutPlateau* st = platJ->getStatut();
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    int id = jHand->getIdCarte(nbCarte-1);
    IdCarte idC = jHand->getCarte(0);
    addCarteDefausse(idC,indPlayer);
    cout << "fin playTurn::playTurn" << endl;
}