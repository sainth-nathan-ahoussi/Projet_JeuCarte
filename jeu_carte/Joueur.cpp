#include "Joueur.h"
#include "Carte.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>>
#include <string>

using namespace std;

Joueur::Joueur() {
  Carte MainDroite{"MainDroite", 1, 0, 0};
  Carte MainGauche{"MainGauche", 0, 1, 0};
  Carte Tete{"Tête", 1, -2, 0};
  Carte Bouche{"Bouche", 1, -1, 2};
  Carte Genou{"Genou", 2, 0, 0};

  _nom = "Yugi";
  _NbPrestige = 25;
  _pile = {MainDroite, MainGauche, Tete, Bouche, Genou};
}

Joueur::Joueur(string nom, int NbPrestige, vector<Carte> tab) {
  _nom = nom;
  _NbPrestige = NbPrestige;
  _pile = tab;
}

string Joueur::sonNom() const { return _nom; }

int Joueur::sonPrestige() const { return _NbPrestige; }

void Joueur::affichageJoueur() const {
  cout << "Le joueur" << _nom << "a" << _NbPrestige
       << "points de prestige, il lui reste " << _pile.size()
       << "carte dans sa manche" << endl;
}

void Joueur::CreationPile(vector<Carte> &reserve) {
  for (int i = 0; i < 20; i++) {
    _pile.push_back(reserve[i]);
  }
}

bool Joueur::Possedecartes() const {
  bool possedeCartes = (_pile.size() != 0);
  return possedeCartes;
}

bool Joueur::ToujoursEnJeu() const {
  bool toujourEnJeu = (_NbPrestige > 0);
  return toujourEnJeu;
}

void Joueur::carteSuiv(Carte &c) {
  /*int i = _pile.size();
  c = _pile[i - 1]; */
  c = _pile[_pile.size()-1];
  _pile.pop_back();
  if (_pile.size() == 0)
    throw(string("Le joueur n’a plus de carte"));
}

void Joueur::jouentUneCarte(Joueur & j) {
  try {
    Carte Joueur1;
    carteSuiv(Joueur1);
    Carte Joueur2;
    j.carteSuiv(Joueur2);

    if (Joueur1.degatPhysique(Joueur2) < 0) {
      j._NbPrestige += Joueur2.degatPhysique(Joueur1);
    } else {
      _NbPrestige += Joueur1.degatPhysique(Joueur2);
    }

    if (Joueur1.degatMagique(Joueur2) < 0) {
      j._NbPrestige += Joueur2.degatMagique(Joueur1);
    } else {
      _NbPrestige += Joueur1.degatMagique(Joueur2);
    }
  } catch (string e) {
    if (_pile.size() == 0) {
      throw(string("Le joueur n’a plus de carte"));

    if (j._pile.size() == 0) {
      throw(string("L'autre joueur n’a plus de carte"));
      
    }else {
      throw e;
      }
    }
  }  
}

void Joueur::melangePile(vector<Carte> & cartes) {
    srand(time(0));
    for (int i = cartes.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temporaire = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temporaire;
    }
    _pile = cartes;
}

void Joueur::choisirOrdreCartes(vector<Carte>& reserve) {
    string nomCarte;
    bool carteTrouvee;
    while (true) {
        carteTrouvee = false;
        cout << "Saisissez le nom d'une carte que vous voulez ajouter à votre tas (ou tapez 'fin' pour terminer) : ";
        cin >> nomCarte;
        if (nomCarte == "fin") {
            break;
        }
        for (int i = 0; i < reserve.size(); i++) {
            if (reserve[i].getnom() == nomCarte) {
                _pile.push_back(reserve[i]);
                for (int j = i; j <  reserve.size() - 1; j++) {
                    reserve[j] = reserve[j + 1];
                }
                reserve.pop_back();
                carteTrouvee = true;
                break;
            }
        }
        if (!carteTrouvee) cout << "Carte introuvable dans la réserve. Réessayez s'il vous plaît." << endl;
    }
}

void Joueur::choisirCarteVariante(vector<Carte> &reserve) {
  string nomCarte;
  while (true) {
    cout << "Saisissez le nom de la carte que vous souhaitez ajouter à votre "
            "pile (ou saisissez « done » pour terminer) : ";
    cin >> nomCarte;
    if (nomCarte == "done") {
      break;
    }
    int left = 0, right = reserve.size() - 1;
    while (left <= right) {
      int middle = (left + right) / 2;
      if (reserve[middle].getnom() == nomCarte) {
        _pile.push_back(reserve[middle]);
        break;
      } else if (reserve[middle].getnom() < nomCarte) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  }
}

//range un vecteur de carte en sous-programme du
//score décroissant de chaque carte.
//void Joueur::trierCarteScore(vector<Carte> &paquet) {
 // sort(paquet.begin(), paquet.end(),
     //  [](Carte c1, Carte c2) { return c1.getScore() > c2.getScore(); });
//}

// chaque carte un score valant la somme de la valeur d’attaque, de la valeur de
// défense et de la puissance magique.
void Joueur::trierCarte(vector<Carte> &paquet) {
  sort(paquet.begin(), paquet.end(), [](Carte c1, Carte c2) {
    if (c1.getvalAtt() == c2.getvalAtt()) {
      if (c1.getvalPM() == c2.getvalPM()) {
        return c1.getvalDef() > c2.getvalDef();
      } else {
        return c1.getvalPM() > c2.getvalPM();
      }
    } else {
      return c1.getvalAtt() > c2.getvalAtt();
    }
  });
}
