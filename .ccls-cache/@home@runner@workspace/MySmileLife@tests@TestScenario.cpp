#include "TestScenario.hpp"

using MySmileLife::Tests::TestScenario;

void TestScenario::setHand(const vector<int> &vH){
	vecInitHand.clear();
	vecInitHand = vector<int>(vH.begin(),vH.end());
}
void TestScenario::setStatuts(const map<int,int> &vS){
	vecInitStatuts.clear();
	vecInitStatuts = vector<int>(MAXSTATUTPLATEAU);
	for (auto ind = 0; ind < MAXSTATUTPLATEAU; ind++) {vecInitStatuts[ind] = 0;}
	for(auto elt : vS){
		vecInitStatuts[elt.first] = elt.second;
	}
}
void TestScenario::setPlateau(const map<int, vector<CardGame::IdCarte>> &mP){
	vecInitPlateau.clear();
	vecInitPlateau = vector<vector<IdCarte>>(MAXEMPLACEMENTPLATEAU);
	for (auto ind = 0; ind < MAXEMPLACEMENTPLATEAU; ind++) {vecInitPlateau.at(ind) = vector<IdCarte>();}
	for(auto elt : mP){
		vecInitPlateau[elt.first] = elt.second;
	}
}