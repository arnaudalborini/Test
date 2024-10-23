#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "CarteMSL.hpp"

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
bool MSLMechanics::endGameCondition()const{return mMonitor->getPioche()->getNbCarte()==0;}
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
