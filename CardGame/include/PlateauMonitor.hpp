#ifndef PLATEAUMONITOR_HPP
#define PLATEAUMONITOR_HPP

#include "CardGame.hpp"
namespace CardGame {
class PlateauMonitor {
public:
    virtual void effetQuitterPlateau(const int indPlayer, const IdCarte idCrt, int EP)=0;
    virtual void effetEntrerPlateau(const int indPlayer, const IdCarte idCrt, int EP)=0;
};
} // namespace CardGame

#endif