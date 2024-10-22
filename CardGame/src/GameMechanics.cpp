#include "GameMechanics.hpp"
#include "CarteGenerator.hpp"
#include "Monitor.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"
#include "InfosJoueur.hpp"
#include "Hand.hpp"

using CardGame::GameMechanics;
using CardGame::Player;
using CardGame::Hand;

GameMechanics::GameMechanics() : cGen(nullptr) {}

GameMechanics::~GameMechanics(){}

void GameMechanics::setMonitor(Monitor *mm){
    mMonitor = dynamic_cast<GameMechanicsMonitor*>(mm);
    cout << "GameMechanics::setMonitor::initGame" << endl;
    initGame();
}

void GameMechanics::setCarteGenerator(CarteGenerator *cg){ cGen=cg;}

void GameMechanics::initGame() const{
    cout << "GameMechanics::setMonitor::initGame init pioche" << endl;
    vector<IdCarte> vecCartes = genVecCartesPioche();
    cout << "ici" << endl;
    mMonitor->getPioche()->initializePaquet( vecCartes );
    cout << "GameMechanics::setMonitor::initGame init defausse" << endl;
    vecCartes = genVecCartesDefausse();
    mMonitor->getDefausse()->initializePaquet( vecCartes );
    cout << "GameMechanics::setMonitor::initGame init plateau" << endl;
    map<EmplacementPlateauGeneral,IdCarte> mapCrt = genMapCartePlateauInitial();
    for(auto p:mapCrt){
        mMonitor->getPlateau()->addLast(p.first,p.second);
    }
}

void GameMechanics::startGame()
{
    for(auto indPlayer=0;indPlayer < mMonitor->getNbPlayer(); indPlayer++){
        cout << "Joueur indice: " << indPlayer << endl;
        remplirMain(indPlayer);
        mTourAPasser.at(indPlayer) = 0;
    }
    int indPlayer=0;
    while( endGameCondition() ){
        if(indPlayer >= mMonitor->getNbPlayer()){
            indPlayer=0;
        }
        if( mTourAPasser.at(indPlayer) > 0 ){
            mTourAPasser[indPlayer]--;
        }else{
            playTurn(indPlayer);
        }
        indPlayer++;
    }
}

void GameMechanics::joueurPioche(int indPlayer)const{mMonitor->getInfosJoueurs(indPlayer)->getHand()->addCarte( mMonitor->getPioche()->piocher() );}
void GameMechanics::remplirMain(int indPlayer) const
{
    while( ( mMonitor->getInfosJoueurs(indPlayer)->getHand()->getNbCarte() < getStandardHandNbCarte()) && (mMonitor->getPioche()->getNbCarte()) ){
        joueurPioche( indPlayer );
    }
}
int GameMechanics::getNbCartePioche() const{return mMonitor->getPioche()->getNbCarte();}
int GameMechanics::getNbCarteDefausse() const{return mMonitor->getDefausse()->getNbCarte();}
void GameMechanics::addCarteDefausse(IdCarte idC, int IdPlayer)const{mMonitor->getDefausse()->addCarte(idC,IdPlayer);}
void GameMechanics::addCarteDefausse(IdCarte idC) const{addCarteDefausse(idC,-1);}

const Player *CardGame::GameMechanics::getPlayer(int indPlayer) const{return mMonitor->getPlayer(indPlayer);}

Hand *GameMechanics::getJoueurHand(int indPlayer) const
{
    return mMonitor->getInfosJoueurs(indPlayer)->getHand();;
}
