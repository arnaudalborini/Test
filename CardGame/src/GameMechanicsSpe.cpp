#include "GameMechanicsSpe.hpp"
#include "GameMechanicsMonitor.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"
#include "InfosJoueur.hpp"
#include "Hand.hpp"

using CardGame::GameMechanicsSpe;
using CardGame::IdCarte;
using std::vector;
using std::map;

vector<IdCarte> GameMechanicsSpe::genVecCartesPioche() const{return vector<IdCarte>();}
vector<IdCarte> GameMechanicsSpe::genVecCartesDefausse() const{return vector<IdCarte>();}
map<CardGame::EmplacementPlateauGeneral,IdCarte> GameMechanicsSpe::genMapCartePlateauInitial()const{return map<EmplacementPlateauGeneral,IdCarte>();}
bool GameMechanicsSpe::endGameCondition()const{return getNbCartePioche()>0;}
int GameMechanicsSpe::getWinnerPlayer() const{return 0;}
void GameMechanicsSpe::playTurn(int indPlayer) const{
    const Player* pp = getPlayer(indPlayer);
    cout << "Joueur name: " << pp->getName() << endl;
    joueurPioche(indPlayer);
    Hand* jHand = getJoueurHand(indPlayer);
    int nbCarte = jHand->getNbCarte();
    cout << "Id carte piochee: " << jHand->getIdCarte(nbCarte) << endl;
    IdCarte idC = jHand->getCarte(0);
    cout << "Id carte defaussee: " << jHand->getIdCarte(nbCarte) << endl;
    addCarteDefausse(idC,indPlayer);
}

int GameMechanicsSpe::getStandardHandNbCarte()const{return 1;}