#include "BasicBot.hpp"

using MySmileLife::BasicBot;

void BasicBot::showNCartesPioche(const vector<IdCarte> &vecIdPioche) const
{
    cout << "showNCartesPioche: " << getName() << endl;
    for(auto id : vecIdPioche){
        cout << id << endl;
    }
}