#include "MSLMechanics.hpp"
#include "CarteGenerateurStandard.hpp"
#include "CardGame.hpp"

using MySmileLife::MSLMechanics;

MSLMechanics::MSLMechanics()
{
    cGen = new CarteGenerateurStandard();
}