#include "BasicBot.hpp"
#include "Hand.hpp"

using MySmileLife::BasicBot;

void BasicBot::afficherCarte(const CarteMSL *carte) const {
  cout << "Carte : " << carte->getName() << endl;
  cout << "Nombre de smileys : " << carte->getNbSmile() << endl;
  cout << "Type : " << carte->getType() << endl;
  cout << "Sous-type : " << carte->getSType() << endl;
  cout << endl;
}

void BasicBot::afficherCarte(CardGame::IdCarte id) const {
    afficherCarte(getCarteMSL(id));
}

void BasicBot::showNCartesPioche(const vector<IdCarte> &vecIdPioche) const {
    cout << "showNCartesPioche: " << getName() << endl;
    for (auto id : vecIdPioche) {
        afficherCarte(id);
    }
}

void BasicBot::showHandAutreJoueur(const Hand *h, int indAutrePlayer) const {
  cout << "showHandAutreJoueur: " << getName() << endl;
  for (int indice = 0; indice < h->getNbCarte(); indice++) {
    cout << h->getIdCarte(indice) << endl;
  }
}

int BasicBot::choisirSalairePourPayer(
    const vector<IdCarte> &vecIdSalairesDisponibles) const {
  return 0;
}
/*
void BasicBot::showNCartesPioche(const vector<IdCarte>& vecIdPioche) {
    // Récupérer toutes les informations des cartes dans une structure adaptée
au tri vector<const CarteMSL*> cartes; for (IdCarte id : vecIdPioche) { const
CarteMSL* carte = getCarteById(id); if (carte) { cartes.push_back(carte);
        }
    }

    // Trier les cartes par type puis par sous-type, dans l'ordre croissant
    std::sort(cartes.begin(), cartes.end(), [](const CarteMSL* a, const
CarteMSL* b) {
        // Si les types sont différents, on trie par type
        if (a->getType() != b->getType()) {
            return a->getType() < b->getType();
        } else {
            // Si les types sont égaux, on trie par sous-type
            return a->getSType() < b->getSType();
        }
    });

    // Afficher les cartes triées
    for (const CarteMSL* carte : cartes) {
        cout << "Carte : " << carte->getName() << endl;
        cout << "Nombre de smileys : " << carte->getNbSmile() << endl;
        cout << "Type : " << carte->getType() << endl;
        cout << "Sous-type : " << carte->getSType() << endl;
        cout << endl;
    }
}*/