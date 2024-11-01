#include "GameMechanicsSpe.hpp"
#include "GameMechanicsMonitor.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"
#include "InfosJoueur.hpp"
#include "Hand.hpp"
#include "CarteGenerator.hpp"
#include "CartesAlgo.hpp"

using CardGame::GameMechanicsSpe;
using CardGame::IdCarte;
using std::vector;
using std::map;

GameMechanicsSpe::GameMechanicsSpe()
{
    cGen = new CarteGenerator();
    cAlgo = new CartesAlgo(cGen,mMonitor);
}

GameMechanicsSpe::~GameMechanicsSpe()
{
    if(cGen!=nullptr){delete cGen;cGen=nullptr;}
    if(cAlgo!=nullptr){delete cAlgo;cAlgo=nullptr;}
}

vector<IdCarte> GameMechanicsSpe::genVecCartesPioche() const
{
    cout << "GameMechanicsSpe::genVecCartesPioche" << endl;
    vector<IdCarte> vecCartes = vector<IdCarte>(); 
    cGen->genCartesPioche(vecCartes);
    return vecCartes;
}
vector<IdCarte> GameMechanicsSpe::genVecCartesDefausse() const{
    vector<IdCarte> vecCartes = vector<IdCarte>();
    cGen->genCartesDefausse(vecCartes);
    return vecCartes;
}
vector<vector<IdCarte>> GameMechanicsSpe::genMapCartePlateauInitial()const{return vector<vector<IdCarte>>();}
vector<int> GameMechanicsSpe::getJoueurInitialStatuts() const{return vector<int>();}
vector<int> GameMechanicsSpe::getInitialStatuts() const{return vector<int>();}
bool GameMechanicsSpe::endGameCondition() const { return getNbCartePioche() > 0; }
int GameMechanicsSpe::getWinnerPlayer() const{return 0;}
void GameMechanicsSpe::playTurn(int indPlayer) const{
    cout << "GameMechanicsSpe::playTurn" << endl;
    const Player* pp = getPlayer(indPlayer);
    Hand* jHand = getJoueurHand(indPlayer);
    cout << "Joueur name: "<< pp->getName() << endl;
    cout << mMonitor->getPioche()->showIdLast() << endl;
    joueurPioche(indPlayer);
    int nbCarte = jHand->getNbCarte();
    cout << "nombre de cartes en main: " << nbCarte << endl;
    cout << "Id carte piochee: " << jHand->getIdCarte(nbCarte-1) << endl;
    IdCarte idC = jHand->getCarte(0);
    cout << "Id carte defaussee: " << idC << endl;
    addCarteDefausse(idC,indPlayer);
    cout << "fin GameMechanicsSpe::playTurn" << endl;
}

int GameMechanicsSpe::getStandardHandNbCarte()const{return 1;}
