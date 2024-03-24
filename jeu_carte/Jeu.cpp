#include "Jeu.h"
#include "Carte.h"
#include "Joueur.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

Jeu::Jeu() {}

Jeu::Jeu(string nom1, string nom2, int NbPrestige1, int NbPrestige2,
         vector<Carte> pile1, vector<Carte> pile2)
    : joueur1(nom1, NbPrestige1, pile1), joueur2(nom2, NbPrestige2, pile2) {}


void Jeu::AfficheRegle(){
  cout << "Le jeu consiste en l’affrontement de deux joueurs très prestigieux (ils ont 25 points de prestige) chacun muni "<< endl;
  cout << " d’une pile de 20 cartes sélectionnées à partir d’une réserve identique. Chaque carte a trois statistiques : "<< endl;
  cout << " une valeur d’attaque physique, une valeur de puissance magique et une valeur de  défense physique " << endl;
  cout << " L’objectif est de réduire les points de prestige de son adversaire et de défendre les siens."<< endl;
  cout << "Le vainqueur est le premier à envoyer son adversaire dans la boue (prestige à zéro) "<< endl;
  cout << " ou d’avoir plus de prestige que son adversaire à la fin de l’affrontement (lorsqu’aucun de vous n'a de cartes ou que vos prestiges sont dans le négatif) " <<   endl;
  
}



void Jeu::insertion(Carte &carte) {
  int index = 0;
  while (index < _reserve.size() && _reserve[index].getnom()< carte.getnom()) {
    index++;
  }
  for (int i = _reserve.size(); i > index; i--) {
        _reserve[i] = _reserve[i-1];
    }
    _reserve[index] = carte;
}


void Jeu::remplirReserve(const string &nomFichier) {
  ifstream ifs(nomFichier);
  string ligne;
  while (getline(ifs, ligne)) {
    Carte carte;
    carte.remplir(ligne);
    insertion(carte);
    /*_reserve.push_back(carte);*/ // Avant la question 3 de la Feuille Lecture de fichiers
  }
}

bool Jeu::fini(Joueur &vainqueur) {
  /* Joueur joueur1; */
  /* Joueur joueur2; */
   if (joueur1.sonPrestige() == 0 && joueur2.sonPrestige() > 0) {
    vainqueur = joueur2;
    return true;
  } else if (joueur1.sonPrestige() > 0 && joueur2.sonPrestige() == 0) {
    vainqueur = joueur1;
    return true;
  } else if (joueur1.sonPrestige() > joueur2.sonPrestige()) {
    vainqueur = joueur1;
    return true;
  } else if (joueur1.sonPrestige() < joueur2.sonPrestige()) {
    vainqueur = joueur2;
    return true;
  } else if (joueur1.Possedecartes() == false || joueur2.Possedecartes() == false) {
    if (joueur1.Possedecartes() == false)
      vainqueur = joueur2;
    else
      vainqueur = joueur1;
    return true;
  }else {
    return false;
  }
}


void Jeu::JoueUnTour() {
   try {
        joueur1.jouentUneCarte(joueur2);
    } catch (string & e) {
        cout << "Erreur pour joueur 1: " << e << endl; // Prend l'erreur et l'affiche  tout en spécifiant le joueur touché
    }

    try {
        joueur2.jouentUneCarte(joueur1);
    } catch (string & e) {
        cout << "Erreur pour joueur 2: " << e << endl;
    }

}

 bool Jeu::partieFini() {
    Joueur vainqueur;
    if(fini(vainqueur)) {
        cout << "Le vainqueur est : " << vainqueur.sonNom() << endl;
        return true;
    }
    else {
        return false;
    }
}

int Jeu::vainqueur() {
  if(joueur1.sonPrestige() > 0 && joueur2.sonPrestige() <= 0) {
    return 1;
  } else if(joueur2.sonPrestige() > 0 && joueur1.sonPrestige() <= 0) {
    return -1;
  } else if(joueur1.sonPrestige() <= 0 && joueur2.sonPrestige() <= 0) {
    return 0;
  } else {
    return -2;
  }
}

void Jeu::trierCarte(vector<Carte> & cartes) {
    for (int i = 0; i < cartes.size() - 1; i++) {
        int indiceMin = i;
        for (int j = i + 1; j < cartes.size(); j++) {
            if (cartes[j].getvalAtt() > cartes[indiceMin].getvalAtt()) {
                indiceMin = j;
            }
            else if (cartes[j].getvalAtt() == cartes[indiceMin].getvalAtt()) {
                if (cartes[j].getvalPM() > cartes[indiceMin].getvalPM()) {
                    indiceMin = j;
                }
                else if (cartes[j].getvalPM()== cartes[indiceMin].getvalPM()) {
                    if (cartes[j].getvalDef()  > cartes[indiceMin].getvalDef() ) {
                        indiceMin = j;
                    }
                }
            }
        }
        if (indiceMin != i) {
            Carte temp = cartes[i];
            cartes[i] = cartes[indiceMin];
            cartes[indiceMin] = temp;
        }
    }
}

vector<int> Jeu::construireRang(vector<Carte> paquet) {
    vector<int> rang;
    for (int i = 0; i < paquet.size(); i++) {
      int maxAttaque = paquet[i].getvalAtt();
      int indexMax = i;
        for (int j = i; j < paquet.size(); j++) {
            if (paquet[j].getvalAtt() > maxAttaque) {
                maxAttaque = paquet[j].getvalAtt();
                indexMax = j;
            }
        }
        rang.push_back(i);
        Carte temp = paquet[i];
        paquet[i] = paquet[indexMax];
        paquet[indexMax] = temp;
    }
    return rang;
}
