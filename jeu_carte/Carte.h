#ifndef CARTE_H
#define CARTE_H


#include <string>
#include <vector>
using namespace std;

class Carte {
private:
  string _nom;
  int _valAtt;
  int _valDef;
  int _valPM;

public:
  Carte();
  /*constructeur vide initialisant une carte à des valeurs par défaut*/

  Carte(const string &nom, const int &valAtt, const int &valDef,
        const int &valPM);
  /*constructeur qui prend quatre arguments : une chaîne de caractères et trois
   * entiers pour initialiser les différents champs d’une carte*/

  void affichageCarteLong() const;
  /* fonction membre permettant un affichage long d’une carte.*/

  void affichageCarteCourt() const;
  /*fonction membre permettant un affichage court d’une carte.*/

  string getnom() const; 
  /*fonction membre permettant d'avoir le nom de la carte*/

  int getvalAtt() const;
  /*fonction membre permettant d'avoir la valeur d'attaque*/

  int getvalPM() const;
  /*fonction membre permettant d'avoir la valeur de la puissance magique*/

  int getvalDef() const;
  /*fonction membre permettant d'avoir la valeur de la puissance défense*/

  int degatPhysique(const Carte &) const;
  /*fonction membre qui retourne les dégâts physiques subis, en positif si c’est
   * le joueur qui a joué la carte cible qui les subit et en négatif si c’est
   * l’autre joueur qui les subit*/

  int degatMagique(const Carte &) const;
  /*fonction membre  qui retourne les dégâts magiques subis, en positif si c’est
   * le joueur ayant joué la carte cible qui subit les dégâts et en négatif si
   * c’est l’autre joueur qui subit les dégâts.*/


  void remplir(const string & ligne);
  /*fonction membre qui prend en paramètre une chaîne de caractère représentant une ligne du fichier et qui
  remplit une carte avec les valeurs stockée dans la ligne du fichier*/
  


};

#endif
