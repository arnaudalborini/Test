#include "GameMechanics.hpp"
#include "CarteGenerator.hpp"
#include "Monitor.hpp"
#include "PaquetCarte.hpp"
#include "InfosJoueur.hpp"
#include "CartesAlgo.hpp"

using CardGame::GameMechanics;

GameMechanics::GameMechanics() : cGen(nullptr), cAlgo(nullptr) {}

GameMechanics::~GameMechanics(){}

void GameMechanics::setMonitor(_p_Monitor mm){
    mMonitor = dynamic_pointer_cast<GameMechanicsMonitor>(mm);
    initGame();
}

void GameMechanics::initGame(){
    vector<int> vecC = genVecCartesPioche();
    mMonitor->getPioche()->initializePaquet( vecC );
    vecC.clear();
    vecC = genVecCartesDefausse();
    mMonitor->getDefausse()->initializePaquet( vecC );
    vector<vector<IdCarte>> vecCrt = genMapCartePlateauInitial();
    mMonitor->getPlateau()->initCartesPlateau(vecCrt);
    vector<int> vecSt = getInitialStatuts();
    mMonitor->getPlateau()->initStatut(vecSt);
    initSpeficiGame();
}

CardGame::_pc_Carte GameMechanics::getCarte(IdCarte idC) const{return cGen->getCarteById(idC);}
int  GameMechanics::getStatutPlayer(int indPlayer, int dp)const{return getJoueurPlateau(indPlayer)->getStatut(dp);}
void GameMechanics::setStatutPlayer(int indPlayer, int dp, int value) {getJoueurPlateau(indPlayer)->setStatut(dp,value);}
void GameMechanics::incStatutPlayer(int indPlayer, int dp, int inc) {setStatutPlayer( indPlayer, dp, getStatutPlayer( indPlayer, dp ) + inc );}
void GameMechanics::decStatutPlayer(int indPlayer, int dp, int inc) {incStatutPlayer(indPlayer,dp,-inc);}
bool GameMechanics::peutEtreJouee(_pc_Player pp, IdCarte id) const{return cAlgo->peutEtreJouee(pp,id);}
bool GameMechanics::jouerCarte(_pc_Player pp, IdCarte id) const{return cAlgo->jouerCarte(pp,id);}

void GameMechanics::startGame()
{
    cout << "GameMechanics::startGame" << endl;
    for(auto indPlayer=0;indPlayer < mMonitor->getNbPlayer(); indPlayer++){
        remplirMain(indPlayer);
    }
    int indPlayer=0;
    cout << "endGameCondition: " << endGameCondition() << endl;
    while( endGameCondition() ){
        if(indPlayer >= mMonitor->getNbPlayer()){
            indPlayer=0;
        }
        playTurn(indPlayer);
        indPlayer++;
    }
    cout << "GameMechanics::startGame fin" << endl;
}

void GameMechanics::joueurPioche(int indPlayer)const{mMonitor->getInfosJoueurs(indPlayer)->addCarteHand( mMonitor->getPioche()->piocher() );}
void GameMechanics::remplirMain(int indPlayer) const
{
    while( ( mMonitor->getInfosJoueurs(indPlayer)->getNbCarteHand() < getStandardHandNbCarte()) && (mMonitor->getPioche()->getNbCarte()) ){
        joueurPioche( indPlayer );
    }
}
int  GameMechanics::getNbCartePioche() const{return mMonitor->getPioche()->getNbCarte();}
int  GameMechanics::getNbCarteDefausse() const{return mMonitor->getDefausse()->getNbCarte();}
void GameMechanics::addCarteDefausse(IdCarte idC, int IdPlayer)const{mMonitor->getDefausse()->addCarte(idC,IdPlayer);}
void GameMechanics::addCarteDefausse(IdCarte idC) const{addCarteDefausse(idC,-1);}
CardGame::_pc_Player GameMechanics::getPlayer(  int indPlayer) const{return mMonitor->getPlayer(indPlayer);}
CardGame::_p_Hand    GameMechanics::getJoueurHand(   int indPlayer) const{return mMonitor->getInfosJoueurs(indPlayer)->getHand();}
CardGame::_p_Plateau GameMechanics::getJoueurPlateau(int indPlayer) const{return mMonitor->getInfosJoueurs(indPlayer)->getPlateau();}
CardGame::_p_Plateau GameMechanics::getMainPlateau() const{return mMonitor->getPlateau();}
