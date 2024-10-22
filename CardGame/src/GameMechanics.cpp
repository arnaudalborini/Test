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
using CardGame::IdCarte;
using std::vector;
using std::map;

GameMechanics::GameMechanics() : cGen(nullptr) {}

GameMechanics::~GameMechanics(){}

void GameMechanics::setMonitor(Monitor *mm){
    mMonitor = dynamic_cast<GameMechanicsMonitor*>(mm);
    initGame();
}

void GameMechanics::setCarteGenerator(CarteGenerator *cg){ cGen=cg;}

void GameMechanics::initGame() const{
    mMonitor->getPioche()->initializePaquet( genVecCartesPioche() );
    mMonitor->getDefausse()->initializePaquet( genVecCartesDefausse() );
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
            playTurn(mMonitor->getPlayer(indPlayer));
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

// à personnaliner en fonction du jeu
vector<IdCarte> GameMechanics::genVecCartesPioche() const{return vector<IdCarte>();}
vector<IdCarte> GameMechanics::genVecCartesDefausse() const{return vector<IdCarte>();}
map<CardGame::EmplacementPlateauGeneral,IdCarte> GameMechanics::genMapCartePlateauInitial()const{return map<EmplacementPlateauGeneral,IdCarte>();}
bool GameMechanics::endGameCondition()const{return mMonitor->getPioche()->getNbCarte();}

void GameMechanics::playTurn(const Player *pp) const{
    cout << "Joueur name: " << pp->getName() << endl;
}

int GameMechanics::getStandardHandNbCarte()const{return 1;}