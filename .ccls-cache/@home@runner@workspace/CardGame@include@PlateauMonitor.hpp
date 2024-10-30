#ifndef PLATEAUMONITOR_HPP
#define PLATEAUMONITOR_HPP

#include "CardGame.hpp"
namespace CardGame {
class PlateauMonitor {
public:
    virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt)=0;
};
} // namespace CardGame

#endif