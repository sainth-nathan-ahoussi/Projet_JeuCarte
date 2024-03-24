#ifndef _JOUEUR_H_INCLUDED
#define _JOUEUR_H_INCLUDED

#include "Carte.h"
#include <string>
#include <vector>

using namespace std;

class Joueur {

  string _nom;
  int _NbPrestige;
  vector<Carte> _pile;

public:
  Joueur();
  /*Constructeur vide initialisant un joueur  */

  Joueur(string, int, vector<Carte>);
  /*Constructeur avec paramètres permettant d’initialiser les données de l’objet
   */

  bool Vie() const;

  string sonNom() const;
  /*Fonction membre permettant d'obtenir le nom du joueur*/

  int sonPrestige() const;
  /*Fonction membre permettant d'obtenir le nombre de point de prestige */

  void affichageJoueur() const;
  /*Fonction membre permettant l’affichage d’un joueur */

  void CreationPile(vector<Carte> &);
  /*Fonction membre permettant à joueur d’initialiser sa pile à partir d’un
   * vecteur de cartes représentant une réserve*/

  bool Possedecartes() const;
  /*Fonction membre booléenne pour savoir si un joueur a encore des cartes */

  bool ToujoursEnJeu() const;
  /*Fonction membre booléenne pour savoir si un joueur est toujours en jeu
   * (c’est-à-dire si son prestige est strictement positif*/

  void carteSuiv(Carte &);
  /*Fonction membre  qui permet de connaître la
prochaine carte de la pile du joueur et qui la retire de la pile. */

  void jouentUneCarte(Joueur &);
  /*Fonction membre  qui met à jour pour chaque joueur leur nombre de points de
   * prestige en fonction du résultat du combat de la prochaine carte pour
   * chaque joueur */

  void melangePile(vector<Carte> & cartes);
/*fonction membre de la classe Joueur qui prend un vecteur de cartes, le mélange
dans un ordre aléatoire et affecte le résultat du mélange à la pile. En utilisant random et le trie par insertion*/

  void choisirOrdreCartes(vector<Carte>& reserve);
/*fonction membre de la classe Joueur qui laisse choisir au joueur l’ordre des
cartes. Le joueur saisit le nom des cartes qu’il veut ajouter à son tas et qui à chaque saisie, le programme va chercher la carte dans la réserve et l’ajoute au
paquet.*/

  void choisirCarteVariante(vector<Carte> &reserve);


  void trierCarteScore(vector<Carte> &paquet);

  void trierCarte(vector<Carte> &paquet);

  




};

#endif