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

MySmileLife::_pc_CarteMSL MSLMechanics::getMSLCarteById(IdCarte id) const
{
    return ToCarteMSL(getCarteById(id));
}

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

MySmileLife::_pc_MSLPlayer MSLMechanics::getMSLPlayer(int indPlayer)const{return dynamic_pointer_cast<const MSLPlayer>( getPlayer(indPlayer) );}

void MSLMechanics::playTurn(int indPlayer) const{
    cout << "MSLMechanics::playTurn: " << indPlayer << endl;
    _pc_MSLPlayer pp = getMSLPlayer(indPlayer);
    string jName = pp->getName();
    if(mMonitor.lock()->getInfosJoueurs(indPlayer)->getPlateau()->getStatut(TourAPasser)>0){
        mMonitor.lock()->incStatut(indPlayer,TourAPasser,-1);
        cout << indPlayer << " - " << jName << "passe son tour. Tour a passer restant: " << mMonitor.lock()->getStatut(indPlayer,DetailPlateau::TourAPasser)<< endl; 
        return;
    }
    cout << "Phase initiale: " << jName << endl;

    CardGame::_p_Hand jHand = getJoueurHand(indPlayer);
    CardGame::_p_Plateau platJ = getJoueurPlateau(indPlayer);
    CardGame::_p_Plateau platGeneral = getMainPlateau();
    joueurPioche(indPlayer);
    //int nbCarte = jHand->getNbCarteHand();
    //int id = jHand->getIdCarteHand(nbCarte-1);
    vector<IdCarte> mainJoueur = mMonitor.lock()->showHand(indPlayer);
    IdCarte idC = mMonitor.lock()->getCarteHand(indPlayer,0);
    _pc_CarteMSL crt = getMSLCarteById(idC);
    cout << "MSLMechanics::playTurn:peutEtreJouee: " << crt->getName() << endl;

    if((peutEtreJouee(pp,idC)) && (jouerCarte(pp,idC)) ){
        cout << "Carte Jouee: "<< getMSLCarteById(idC)->getName() << endl;
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

void MySmileLife::MSLMechanics::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP)
{
    dynamic_pointer_cast<CartesAlgoMSL>(this->cAlgo)->effetQuitterPlateau( indPlayer, idCrt, EP );
}

void MySmileLife::MSLMechanics::effetQuitterHand(const int indPlayer, const IdCarte idCrt)
{
    dynamic_pointer_cast<CartesAlgoMSL>(this->cAlgo)->effetQuitterHand( indPlayer, idCrt );
}

void MySmileLife::MSLMechanics::effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP)
{
    dynamic_pointer_cast<CartesAlgoMSL>(this->cAlgo)->effetEntrerPlateau( indPlayer, idCrt, EP );
}

void MySmileLife::MSLMechanics::effetEntrerHand(const int indPlayer, const IdCarte idCrt)
{
    dynamic_pointer_cast<CartesAlgoMSL>(this->cAlgo)->effetQuitterHand( indPlayer, idCrt );
}
