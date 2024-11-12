#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "CarteMSL.hpp"
#include "MSLPlayer.hpp"
#include "CartesAlgoMSL.hpp"
#include "InfosJoueur.hpp"

using MySmileLife::MSLMechanics;

MSLMechanics::MSLMechanics()
{
    cGen = make_shared<CarteGenerateurStandard>();
}

MSLMechanics::~MSLMechanics()
{
}

void MSLMechanics::remplirMain(int indPlayer) const
{
    int nbCarteMax = mMonitor.lock()->getStatut(indPlayer,DetailPlateau::LimiteCarte6)?6:this->getStandardHandNbCarte();
    while( mMonitor.lock()->getNbCarteHand(indPlayer) < nbCarteMax){
        mMonitor.lock()->joueurPioche(indPlayer);
    }
    while( mMonitor.lock()->getNbCarteHand(indPlayer) > nbCarteMax){
        mMonitor.lock()->joueurDefausse(indPlayer);
    }
}

MySmileLife::_pc_CarteMSL MSLMechanics::getCarteFromId(IdCarte id) const { return dynamic_pointer_cast<const CarteMSL>(cGen->getCarteById(id)); }
int  MSLMechanics::countSmile(CardGame::_p_Plateau plateauJoueur)const{
    int s=0;
    for(auto elt : plateauJoueur->showAllIdAllEP() ){
        s += dynamic_pointer_cast<CartesAlgoMSL>(cAlgo)->getNbSmile(plateauJoueur,elt);
    }
    return s;
}

///////////////////////   Methodes virtuelles à réimplémenter si non standard ///////////
void MSLMechanics::initSpeficiGame(){cAlgo = make_shared<CartesAlgoMSL>(cGen,mMonitor);}
int  MSLMechanics::getStandardHandNbCarte() const{return MySmileLife::DEFAULTMAXHANDSIZE;}
int  MSLMechanics::getWinnerPlayer()const{
    int baseSmile = countSmile( mMonitor.lock()->getInfosJoueurs( 0 )->getPlateau() );
    int indBest = 0;
    for(int indPlayer=0;indPlayer<mMonitor.lock()->getNbPlayer();indPlayer++){
        int cSmile = countSmile( mMonitor.lock()->getInfosJoueurs( indPlayer )->getPlateau() );
        if(baseSmile<cSmile){
            baseSmile = cSmile;
            indBest = indPlayer;
        }
    }
    return indBest;
}
void MSLMechanics::playTurn(int indPlayer) const{
    cout << "MSLMechanics::playTurn: " << indPlayer << endl;
    if(mMonitor.lock()->getInfosJoueurs(indPlayer)->getPlateau()->getStatut(TourAPasser)>0){
        mMonitor.lock()->getInfosJoueurs(indPlayer)->getPlateau()->incStatut(TourAPasser,-1);
        return;
    }
    _pc_MSLPlayer pp = dynamic_pointer_cast<const MSLPlayer>( getPlayer(indPlayer) );
    CardGame::_p_Hand jHand = getJoueurHand(indPlayer);
    CardGame::_p_Plateau platJ = getJoueurPlateau(indPlayer);
    CardGame::_p_Plateau platGeneral = getMainPlateau();
    joueurPioche(indPlayer);
    //int nbCarte = jHand->getNbCarteHand();
    //int id = jHand->getIdCarteHand(nbCarte-1);
    IdCarte idC = jHand->getCarteHand(0);
    _pc_CarteMSL crt = dynamic_pointer_cast<const CarteMSL>(cGen->getCarteById(idC));
    cout << "MSLMechanics::playTurn:peutEtreJouee: " << crt->getName() << endl;

    if((peutEtreJouee(pp,idC)) && (jouerCarte(pp,idC)) ){
        cout << "Carte Jouee: "<< getCarteFromId(idC)->getName() << endl;
    }
    else{
        cout << "MSLMechanics::playTurn:addCarteDefausse" << endl;
        addCarteDefausse(idC,indPlayer);
    }
    this->remplirMain(indPlayer);
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
