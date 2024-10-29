#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "Plateau.hpp"
#include "StatutPlateau.hpp"
#include "CarteMSL.hpp"
#include "Hand.hpp"
#include "MSLPlayer.hpp"
#include "CartesAlgoMSL.hpp"
#include "InfosJoueur.hpp"

using MySmileLife::MSLMechanics;
using MySmileLife::CarteMSL;

MSLMechanics::MSLMechanics()
{
    cGen = new CarteGenerateurStandard();
}

MySmileLife::MSLMechanics::~MSLMechanics()
{/*
    if(cGen!=nullptr){delete cGen;cGen=nullptr;}
    if(cAlgo!=nullptr){delete cAlgo;cAlgo=nullptr;}*/
}

const CarteMSL* MSLMechanics::getCarteFromId(IdCarte id)const{return dynamic_cast<const CarteMSL*>(cGen->getCarteById(id));}
int  MSLMechanics::countSmile(Plateau* plateauJoueur)const{
    int s=0;
    for(auto elt : plateauJoueur->showAllId() ){
        s += dynamic_cast<CartesAlgoMSL*>(cAlgo)->getNbSmile(plateauJoueur,elt);
    }
    return s;
}

///////////////////////   Methodes virtuelles à réimplémenter si non standard ///////////
void MSLMechanics::initSpeficiGame(){cAlgo = new CartesAlgoMSL(cGen,mMonitor);}
int  MSLMechanics::getStandardHandNbCarte() const{return MySmileLife::DEFAULTMAXHANDSIZE;}
int  MSLMechanics::getWinnerPlayer()const{
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
    cout << "MSLMechanics::playTurn: " << indPlayer << endl;
    const MSLPlayer* pp = dynamic_cast<const MSLPlayer*>( getPlayer(indPlayer) );
    Hand* jHand = getJoueurHand(indPlayer);
    Plateau* platJ = getJoueurPlateau(indPlayer);
    Plateau* platGeneral = getMainPlateau();
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    int id = jHand->getIdCarte(nbCarte-1);
    IdCarte idC = jHand->getCarte(0);
    const CarteMSL* crt = dynamic_cast<const CarteMSL*>(cGen->getCarteById(idC));
    cout << "MSLMechanics::playTurn:peutEtreJouee: " << crt->getName() << endl;

    if((peutEtreJouee(pp,idC)) && (jouerCarte(pp,idC)) ){
        cout << "Carte Jouee: "<< getCarteFromId(idC)->getName() << endl;
    }
    else{
        cout << "MSLMechanics::playTurn:addCarteDefausse" << endl;
        addCarteDefausse(idC,indPlayer);
    }
}
std::vector<int> MSLMechanics::getJoueurInitialStatuts() const
{
    vector<int> initVec = vector<int>(MySmileLife::MAXSTATUTPLATEAU+1);
    //BonusSpeciaux
    for(int indSt=0;indSt<=MySmileLife::MAXSTATUTPLATEAU;indSt++){initVec[indSt] = 0;}
    return initVec;
}

std::vector<int> MSLMechanics::getInitialStatuts() const
{
    vector<int> initVec = vector<int>(MySmileLife::MAXSTATUTPLATEAU+1);
    //BonusSpeciaux
    for(int indSt=0;indSt<=MySmileLife::MAXSTATUTPLATEAU;indSt++){initVec[indSt] = 0;}
    return initVec;
}

std::map<int,std::vector<CardGame::IdCarte>> MSLMechanics::genMapCartePlateauInitial() const
{
return map<int,vector<IdCarte>>();
}
