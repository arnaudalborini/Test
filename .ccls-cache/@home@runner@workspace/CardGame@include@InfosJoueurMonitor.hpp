#ifndef INFOSJOUEURMONITOR_HPP
#define INFOSJOUEURMONITOR_HPP

#include "CardGame.hpp"
#include "HandMonitor.hpp"
#include "PlateauMonitor.hpp"

namespace CardGame {
class InfosJoueurMonitor : public PlateauMonitor, public HandMonitor {};
}

#endif