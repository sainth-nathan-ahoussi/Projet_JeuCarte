#include <iostream>
#include "Jeu.h"
#include "Joueur.h"
#include "Carte.h"
#include <stdexcept>
#include <string>
using namespace std;

int main() {
  // Initialisation des variables pour le jeu
    string nomJoueur1, nomJoueur2;
    vector<Carte> pile1, pile2;
    int nbPrestige1, nbPrestige2;
    int mode;
    Joueur Joueur1, Joueur2, vainqueur;
    Jeu Jeu;
    bool rejouer = true;

  
     while (rejouer) {
        // Proposer entre un mode 2 joueurs humains et un mode humain contre IA
        cout << "Choisissez le mode de jeu :" << endl;
        cout << "1 pour 2 joueurs humains" << endl;
        cout << "2 pour Humain contre IA  :" ; cin >> mode;
        bool contreIA = (mode == 2);

        // Demander le nom du/des joueur(s) humain(s)
        if (contreIA) {
            cout << "Entrez votre nom : ";
            cin >> nomJoueur1;
            nomJoueur2 = "IA";
        } else {
            cout << "Entrez le nom du joueur 1  et du  du joueur 2  : ";
            cin >> nomJoueur1 >> nomJoueur2;
        }

        // Afficher les règles, la liste des cartes disponibles, …
        cout << "Règles du jeu :" << endl;
        Jeu.AfficheRegle();

        // Demander aux joueurs humains via un menu quelle stratégie ils veulent adopter pour constituer leur pile
        int strategieJoueur1, strategieJoueur2;
        if (!contreIA) {
            cout << nomJoueur1 << "choisissez une strategie  pour jouer, ranger vos Cartes dans l'ordre de l'attaque (1), de la magie(2) ou la défense(3)"; cin >>strategieJoueur1;
            if (strategieJoueur1 == 1){
              Joueur1.choisirOrdreCartes(pile1);
            }else if (strategieJoueur1 == 2){
              Joueur1.choisirCarteVariante(pile1);
            }else{
              Joueur1.choisirOrdreCartes(pile1);
              
            }
              
            cout << nomJoueur2 << "choisissez une strategie  pour jouer, ranger vos Cartes dans l'ordre de l'attaque (1), de la magie(2) ou la défense(3) :" ; cin >>strategieJoueur2;
            if (strategieJoueur1 == 1){
              Joueur2.choisirOrdreCartes(pile2);
            }else if (strategieJoueur1 == 2){
              Joueur2.choisirCarteVariante(pile2);
            }else{
              Joueur2.choisirOrdreCartes(pile2);
              
            }
       }
    }
}