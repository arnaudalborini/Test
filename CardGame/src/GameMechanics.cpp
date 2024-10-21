#include "GameMechanics.hpp"
#include "CarteGenerator.hpp"
#include "Monitor.hpp"
#include "GameMechanicsMonitor.hpp"
#include "Plateau.hpp"

using CardGame::GameMechanics;
using CardGame::IdCarte;

GameMechanics::GameMechanics():cGen(nullptr){}

GameMechanics::~GameMechanics(){}

void GameMechanics::setMonitor(Monitor *mm){
    mMonitor = dynamic_cast<GameMechanicsMonitor*>(mm);
    initGame();
}

void GameMechanics::setCarteGenerator(CarteGenerator *cg){ cGen=cg;}


void GameMechanics::initGame() const
{
    mMonitor->initiatePioche( genVecCartesPioche() );
    mMonitor->initiateDefausse( genVecCartesDefausse() );
    map<EmplacementPlateauGeneral,IdCarte> mapCrt = genMapCartePlateauInitial();
    for(auto p:mapCrt){
        mMonitor->getPlateau()->addLast(p.first,p.second);
    }
}

// à personnaliner en fonction du jeu
std::vector<CardGame::IdCarte> GameMechanics::genVecCartesPioche() const{return vector<IdCarte>();}
std::vector<CardGame::IdCarte> GameMechanics::genVecCartesDefausse() const{return vector<IdCarte>();}
std::map<CardGame::EmplacementPlateauGeneral,IdCarte> GameMechanics::genMapCartePlateauInitial()const{return std::map<CardGame::EmplacementPlateauGeneral,IdCarte>();}
