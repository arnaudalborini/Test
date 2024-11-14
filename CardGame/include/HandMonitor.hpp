#ifndef HANDMONITOR_HPP
#define HANDMONITOR_HPP

#include "CardGame.hpp"

namespace CardGame{
	class HandMonitor{
		public:
			virtual void effetQuitterHand(const int indPlayer, const IdCarte idCrt) = 0;
  			virtual void effetEntrerHand(const int indPlayer, const IdCarte idCrt) = 0;
	};
}

#endif