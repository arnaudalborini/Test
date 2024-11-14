#include "ConcreteMonitor.hpp"
#include "GameMechanics.hpp"
#include "InfosJoueur.hpp"
#include "PaquetCarte.hpp"
#include "Player.hpp"

using CardGame::ConcreteMonitor;

ConcreteMonitor::ConcreteMonitor() {
  mPioche = make_shared<PaquetCarte>();
  mDefausse = make_shared<PaquetCarte>();
  mInfosJoueurs = vector<_p_InfosJoueur>();
  mPlayer = vector<_pc_Player>();
}

ConcreteMonitor::~ConcreteMonitor() {}

CardGame::_p_Plateau ConcreteMonitor::getPlateauGeneral() const { return mPlateau; }
CardGame::_p_Plateau ConcreteMonitor::getPlateauPlayer(int indPlayer) const {
  return getInfosJoueurs(indPlayer)->getPlateau();
}
void CardGame::ConcreteMonitor::addCarteToEP(_pc_Player pp, int EP, IdCarte id) const
{
  return addCarteToEP(getIndPlayer(pp),EP,id);
}
CardGame::_p_Plateau ConcreteMonitor::getPlateauPlayer(_pc_Player pp) const
{
  return getInfosJoueurs(pp)->getPlateau();
}
CardGame::_p_PaquetCarte ConcreteMonitor::getPioche() const { return mPioche; }
CardGame::_p_PaquetCarte ConcreteMonitor::getDefausse() const { return mDefausse; }
CardGame::_p_InfosJoueur ConcreteMonitor::getInfosJoueurs(int ind) const {
  return mInfosJoueurs[ind];
}
CardGame::_p_InfosJoueur ConcreteMonitor::getInfosJoueurs(_pc_Player pp) const {
  return getInfosJoueurs(getIndPlayer(pp));
}
CardGame::_pc_Player ConcreteMonitor::getPlayer(int ind) const { return mPlayer[ind]; }
int ConcreteMonitor::getIndPlayer(_pc_Player pp) const { return mapIdPlayer.at(pp); }

int ConcreteMonitor::getNbPlayer() const { return mNbJoueur; }

void ConcreteMonitor::defausser(IdCarte id, int indPlayer) const {
  mDefausse->addCarte(id, indPlayer);
}

void ConcreteMonitor::defausserDernier(int indPlayer, int EP) const {
  defausser(getInfosJoueurs(indPlayer)->getPlateau()->getLastByEP(EP), indPlayer);
}

void ConcreteMonitor::defausserTout(int indPlayer, int EP) const {
  _p_Plateau p = getInfosJoueurs(indPlayer)->getPlateau();
  int NbCrt = p->getNbCarteByEP(EP);
  for (int ind = 0; ind < NbCrt; ind++) {
    defausser(p->getLastByEP(EP), indPlayer);
  }
}

int ConcreteMonitor::getStatut(int indPlayer, int statut) const
{
  return getInfosJoueurs(indPlayer)->getPlateau()->getStatut(statut);
}

void ConcreteMonitor::incStatut(int indPlayer, int statut, int inc) const {
  getInfosJoueurs(indPlayer)->getPlateau()->incStatut(statut, inc);
}

void ConcreteMonitor::setStatut(int indPlayer, int statut, int value) const {
  getInfosJoueurs(indPlayer)->getPlateau()->setStatut(statut, value);
}

void ConcreteMonitor::incStatutGeneral(int statut, int inc) const
{
  getPlateauGeneral()->incStatut(statut, inc);
}

void ConcreteMonitor::setStatutGeneral(int statut, int value) const
{
  getPlateauGeneral()->setStatut(statut, value);
}

int ConcreteMonitor::getStatutGeneral(int statut) const
{
    return getPlateauGeneral()->getStatut(statut);
}

int ConcreteMonitor::getNbCarteHand(int indPlayer) const
{
    if(indPlayer<static_cast<int>(mInfosJoueurs.size())){
      return mInfosJoueurs[indPlayer]->getNbCarteHand();
    }
    return -1;
}

CardGame::IdCarte ConcreteMonitor::joueurPioche(int indPlayer) const
{
  if(mPioche->getNbCarte()>0){
    if(indPlayer<static_cast<int>(mInfosJoueurs.size())){
      IdCarte id = mPioche->piocher();
      mInfosJoueurs[indPlayer]->addCarteHand(id);
      return id;
    }
  }
  return -1;
}

CardGame::IdCarte ConcreteMonitor::joueurDefausse(int indPlayer) const
{
  if(indPlayer<static_cast<int>(mInfosJoueurs.size())){
    _pc_Player pp = getPlayer(indPlayer);
    _p_Hand hh = mInfosJoueurs[indPlayer]->getHand();
    int ind = pp->choisirIndiceCarteAJouerMain( hh );
    IdCarte id = hh->getCarteHand(ind);
    defausser(id,indPlayer);
    return id;
  }
  return -1;
}

void ConcreteMonitor::voirMainAutresJoueur(_pc_Player pp) const
{    
    voirMainAutresJoueur( getIndPlayer(pp) );
}


void ConcreteMonitor::voirMainAutresJoueur(int indPlayer) const
{    
  for(int indice=0;indice<this->getNbPlayer();indice++){
      if(indice==indPlayer){
          continue;
      }
      CardGame::_pc_Hand jH = this->getInfosJoueurs(indice)->getHand();
      getPlayer(indPlayer)->showHandAutreJoueur(jH,indice);
  }
}


void ConcreteMonitor::voirNProchainesCartesPioche(_pc_Player pp, int N) const
{
  CardGame::_p_PaquetCarte pioche = this->getPioche();
  int nbcarte = pioche->getNbCarte();
  int indDebut = (nbcarte>=N)?nbcarte-1-N:0;
  std::vector<CardGame::IdCarte> vecId;
  for(int indice = indDebut;indice<nbcarte;indice++){
      vecId.push_back(pioche->showNeme(indice));
  }
  pp->showNCartesPioche(vecId);
}

int ConcreteMonitor::getStatut(_pc_Player pp, int statut) const
{
    return getStatut(getIndPlayer(pp),statut);
}

void ConcreteMonitor::incStatut(_pc_Player pp, int statut, int inc) const
{
  incStatut(getIndPlayer(pp),statut,inc);
}

void ConcreteMonitor::setStatut(_pc_Player pp, int statut, int inc) const
{
  setStatut(getIndPlayer(pp),statut,inc);
}

void ConcreteMonitor::voirNProchainesCartesPioche(int indPlayer, int N) const
{
  voirNProchainesCartesPioche(getPlayer(indPlayer),N);
}

void ConcreteMonitor::addCarteToEP(int indPlayer, int EP, IdCarte id) const
{
  if(indPlayer<static_cast<int>(mInfosJoueurs.size())){
    mInfosJoueurs[indPlayer]->getPlateau()->addCarteToEP(EP,id);
  }
}

void ConcreteMonitor::initiateElements(int nbJoueurs, _p_GameMechanics gm) {
  shared_ptr<ConcreteMonitor> tmp = shared_from_this();
  mPlateau = make_shared<Plateau>(tmp);
  mNbJoueur = nbJoueurs;
  mGameMechanics = gm;
  mPlayer = vector<_pc_Player>(nbJoueurs);
  mInfosJoueurs = vector<_p_InfosJoueur>(nbJoueurs);
  for (auto ind = 0; ind < nbJoueurs; ind++) {
    mInfosJoueurs[ind] = make_shared<InfosJoueur>(shared_from_this(),mGameMechanics->getJoueurInitialStatuts(), ind);
  }
  mGameMechanics->setMonitor(shared_from_this());
}

void ConcreteMonitor::addPlayer(_pc_Player pp, int index) {
  cout << "Monitor::addPlayer: " << pp << " " << index << endl;
  mPlayer[index] = pp;
  mapIdPlayer[pp] = index;
}
void ConcreteMonitor::removePlayer(int index) { mPlayer[index] = nullptr; }
void ConcreteMonitor::startGame() { mGameMechanics->startGame(); }
int ConcreteMonitor::getWinner() const { return mGameMechanics->getWinnerPlayer(); }

CardGame::_pc_Carte ConcreteMonitor::getCarte(IdCarte idC) const {
  return mGameMechanics->getCarte(idC);
}

void ConcreteMonitor::effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP) {
  mGameMechanics->effetQuitterPlateau(indPlayer, idCrt,EP);
}

void CardGame::ConcreteMonitor::effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP)
{
}

void ConcreteMonitor::effetQuitterHand(const int indPlayer, const IdCarte idCrt) {
  mGameMechanics->effetQuitterHand(indPlayer, idCrt);
}

void CardGame::ConcreteMonitor::effetEntrerHand(const int indPlayer, const IdCarte idCrt)
{
}
