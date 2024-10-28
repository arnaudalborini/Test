#include "BasicBot.hpp"
#include "Hand.hpp"

using MySmileLife::BasicBot;

void BasicBot::showNCartesPioche(const vector<IdCarte> &vecIdPioche) const
{
    cout << "showNCartesPioche: " << getName() << endl;
    for(auto id : vecIdPioche){
        cout << id << endl;
    }
}

void BasicBot::showHandAutreJoueur(const Hand *h, int indAutrePlayer) const
{
    cout << "showHandAutreJoueur: " << getName() << endl;
    for(int indice=0;indice<h->getNbCarte();indice++){
        cout << h->getIdCarte(indice) << endl;
    }
}
