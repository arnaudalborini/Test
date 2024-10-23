#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "CarteMSL.hpp"
#include "Hand.hpp"
#include "Player.hpp"

using MySmileLife::MSLMechanics;
using MySmileLife::CarteMSL;

MSLMechanics::MSLMechanics()
{
    cGen = new CarteGenerateurStandard();
}

const CarteMSL* MSLMechanics::getCarteFromId(CardGame::IdCarte id)const{
    return dynamic_cast<const CarteMSL*>(cGen->getCarteById(id));
}
int MSLMechanics::getSmileFromId(CardGame::IdCarte id)const{return getCarteFromId(id)->getNbSmile();}
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
    const CardGame::Player* pp = getPlayer(indPlayer);
    CardGame::Hand* jHand = getJoueurHand(indPlayer);
    cout << "Joueur name: "<< pp->getName() << endl;
    cout << mMonitor->getPioche()->showIdLast() << endl;
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    cout << "nombre de cartes en main: " << nbCarte << endl;
    cout << "Id carte piochee: " << jHand->getIdCarte(nbCarte-1) << endl;
    CardGame::IdCarte idC = jHand->getCarte(0);
    cout << "Id carte defaussee: " << idC << endl;
    addCarteDefausse(idC,indPlayer);
    cout << "fin playTurn::playTurn" << endl;
}