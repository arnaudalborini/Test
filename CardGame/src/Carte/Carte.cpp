#include "Carte.hpp"
#include "hello.hpp"

using CardGame::Carte;

CardGame::Carte::Carte():m_j(nullptr)
{
    cout << "carte cree sans joueur" << endl;
}

Carte::Carte(Joueur *jj) : m_j(jj)
{
    cout << "carte cree avec joueur" << endl;
}

Carte::~Carte()
{
    cout << "destructeur carte" << endl;
}
