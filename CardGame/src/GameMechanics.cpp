#include "GameMechanics.hpp"
#include "CarteGenerator.hpp"
#include "Monitor.hpp"
#include "GameMechanicsMonitor.hpp"

using CardGame::GameMechanics;

GameMechanics::GameMechanics():cGen(nullptr){}

GameMechanics::~GameMechanics(){}

void GameMechanics::setMonitor(Monitor *mm){
    mMonitor=dynamic_cast<GameMechanicsMonitor*>(mm);
    vector<CardGame::IdCarte> vecPioche   = genVecCartesPioche();
    vector<CardGame::IdCarte> vecDefausse = genVecCartesDefausse();
    mMonitor->initiatePioche( vecPioche );
    mMonitor->initiateDefausse( vecDefausse );
}

void GameMechanics::setCarteGenerator(CarteGenerator *cg){ cGen=cg;}
std::vector<CardGame::IdCarte> GameMechanics::genVecCartesPioche() const{return vector<IdCarte>();}

std::vector<CardGame::IdCarte> GameMechanics::genVecCartesDefausse() const{return vector<IdCarte>();}

void GameMechanics::initiatePlateau() const
{
}
