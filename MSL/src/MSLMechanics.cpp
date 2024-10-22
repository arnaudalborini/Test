#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"

using MySmileLife::MSLMechanics;

MSLMechanics::MSLMechanics()
{
    cGen = new CarteGenerateurStandard();
}

std::vector<CardGame::IdCarte> MSLMechanics::genVecCartesPioche() const
{
    vector<CardGame::IdCarte> vecCartes;
    cout << "MSLMechanics::genVecCartesPioche" << endl;
    cGen->genCartesPioche(vecCartes);
    return vecCartes;
}
