#ifndef INFOSJOUEURMONITOR_HPP
#define INFOSJOUEURMONITOR_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"
#include "PlateauMonitor.hpp"

namespace CardGame {
class InfosJoueurMonitor : public PlateauMonitor, public HandMonitor {
    public:
        //PlateauMonitor
        virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt)=0;
        //HandMonitor
        virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) = 0;
};
}

#endif