#ifndef TESTSCENARIO_HPP
#define TESTSCENARIO_HPP

#include "../include/MySmileLife.hpp"

namespace MySmileLife{
	namespace Tests{
		class TestScenario{
			private:
				vector<int> vecInitHand;
				vector<int> vecInitStatuts;
				vector<vector<CardGame::IdCarte>> vecInitPlateau;
			public:
				void setHand(const vector<int> &vH);
				void setStatuts(const map<int,int> &vS);
				void setPlateau(const map<int, vector<CardGame::IdCarte>> &mP);
				vector<int> getInitHand(){return vecInitHand;}
				vector<int> getInitStatuts(){return vecInitStatuts;}
				vector<vector<CardGame::IdCarte>> getInitPlateau(){return vecInitPlateau;}
		};
	}
}

#endif