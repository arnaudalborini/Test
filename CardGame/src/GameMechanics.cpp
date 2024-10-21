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

void GameMechanics::startGame() const
{
    for(auto indPlayer=0;indPlayer < mMonitor->getNbPlayer(); indPlayer++){
        cout << "Joueur indice: " << indPlayer << endl;
        remplirMain(indPlayer);
    }
    //playTurn(mMonitor->getPlayerP(indPlayer));
}



void GameMechanics::joueurPioche(int indPlayer)const{mMonitor->getInfosJoueursP(indPlayer)->getHand()->addCarte( mMonitor->getPioche()->piocher() );}

void CardGame::GameMechanics::remplirMain(int indPlayer) const
{
    while( ( mMonitor->getInfosJoueursP(indPlayer)->getHand()->getNbCarte() < getStandardHandNbCarte()) && (mMonitor->getPioche()->getNbCarte()) ){
        joueurPioche( indPlayer );
    }
}

void CardGame::GameMechanics::playTurn(const Player *pp) const{
    cout << "Joueur name: " << pp->getName() << endl;
}

// à personnaliner en fonction du jeu
std::vector<CardGame::IdCarte> GameMechanics::genVecCartesPioche() const{return vector<IdCarte>();}
std::vector<CardGame::IdCarte> GameMechanics::genVecCartesDefausse() const{return vector<IdCarte>();}
std::map<CardGame::EmplacementPlateauGeneral,IdCarte> GameMechanics::genMapCartePlateauInitial()const{return std::map<CardGame::EmplacementPlateauGeneral,IdCarte>();}

