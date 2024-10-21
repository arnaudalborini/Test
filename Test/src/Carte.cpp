#include "Carte.hpp"

using CardGame::Carte;

Carte::Carte():mId(0),mName(""){}
Carte::Carte(int ii,string name):mId(ii),mName(name){}
Carte::~Carte(){}
int Carte::getId()const{return mId;}
std::string Carte::getName()const{return mName;}
