#ifndef _JEU_H_INCLUDED
#define _JEU_H_INCLUDED

#include "Carte.h"
#include "Joueur.h"
#include <string>
#include <vector>

using namespace std;

class Jeu {
  vector<Carte> _reserve;  
  /* vecteur d’objets Carte, représentant la liste des cartes disponibles pour la création des piles de chaque joueur*/

  Joueur joueur1;
  Joueur joueur2;

public:
  Jeu();
  /*Constructeur vide initialisant un Jeu */

  Jeu(string, string, int, int, vector<Carte>, vector<Carte>);
  /*Constructeur avec paramètres permettant d’initialiser les données du Jeu */

  void remplirReserve(const string & ligne);
  /*fonction membre qui prend en paramètre une chaîne de caractère représentant une ligne du fichier et qui remplit une carte avec les valeurs stockée dans la ligne du fichier.*/

  bool fini(Joueur & vainqueur);
  /*fonction membre booléenne pour savoir si le jeu est fini et qui renvoie dans un paramètre le joueur vainqueur*/

   bool partieFini();
  /*fonction  fonction interne de la classe Jeu qui retourne vraie si la partie est finie et faux
  sinon en utilisant la fonction fini*/

  void insertion(Carte &carte);
/*sous-programme qui parcourt un vecteur trié,
cherche la case où il faut placer la nouvelle carte, insère la nouvelle carte dans cette case
tout en décalant toutes les valeurs suivantes d’une case vers la droite. */


  void JoueUnTour();
/*une fonction interne de la classe Jeu qui fait jouer une carte de chaque paquet (une de
chaque joueur) et met à jour les points de prestige de chaque joueur*/


  int vainqueur();
/*fonction interne de la classe Jeu qui retourne le vainqueur de la façon suivante :
elle retourne +1 si le vainqueur est le joueur1, -1 si le vainqueur est le joueur2 et 0 s’il y
a match nul.*/

  void trierCarte(vector<Carte> & cartes);
 /*sous-programme qui range un vecteur de cartes d’abord en fonction de l’attaque
décroissante, en cas d’égalité sur la valeur d’attaque le rang se calculera en fonction de la
puissance magique décroissante, et en cas d’égalité sur la magie cela sera en fonction de la défense décroissante.*/

/*J'ai choisi de le mettre là carles cartes font partie intégrante de la logique de jeu donc ça pourrait être plus approprié de les inclure dans la classe Jeu*/



  void AfficheRegle();
/*fonction qui affiche les règles du jeu.*/

vector<int>construireRang(vector<Carte> paquet);
};

#endif