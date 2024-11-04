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
using MySmileLife::PCCarteMSL;

MSLMechanics::MSLMechanics()
{
    cGen = make_shared<CarteGenerateurStandard>();
}

MSLMechanics::~MSLMechanics()
{
}

PCCarteMSL MSLMechanics::getCarteFromId(IdCarte id)const{return dynamic_pointer_cast<const CarteMSL>(cGen->getCarteById(id));}
int  MSLMechanics::countSmile(PPlateau plateauJoueur)const{
    int s=0;
    for(auto elt : plateauJoueur->showAllId() ){
        s += dynamic_pointer_cast<CartesAlgoMSL>(cAlgo)->getNbSmile(plateauJoueur,elt);
    }
    return s;
}

///////////////////////   Methodes virtuelles à réimplémenter si non standard ///////////
void MSLMechanics::initSpeficiGame(){cAlgo = make_shared<CartesAlgoMSL>(cGen,mMonitor);}
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
    if(mMonitor->getInfosJoueurs(indPlayer)->getPlateau()->getStatut(TourAPasser)>0){
        mMonitor->getInfosJoueurs(indPlayer)->getPlateau()->incStatut(TourAPasser,-1);
        return;
    }
    PCMSLPlayer pp = dynamic_pointer_cast<const MSLPlayer>( getPlayer(indPlayer) );
    PHand jHand = getJoueurHand(indPlayer);
    PPlateau platJ = getJoueurPlateau(indPlayer);
    PPlateau platGeneral = getMainPlateau();
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    int id = jHand->getIdCarte(nbCarte-1);
    IdCarte idC = jHand->getCarte(0);
    PCCarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen->getCarteById(idC));
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

std::vector<std::vector<CardGame::IdCarte>> MSLMechanics::genMapCartePlateauInitial() const
{
return vector<vector<IdCarte>>();
}
