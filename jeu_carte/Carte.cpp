#include "Carte.h"
#include <iostream>
#include <sstream>

using namespace std;

Carte::Carte() {
  _nom = "Mains nues";
  _valAtt = 2;
  _valDef = 1;
  _valPM = 0;
}

Carte::Carte(const string &nom, const int &valAtt, const int &valDef,
             const int &valPM) {
  _nom = nom;
  _valAtt = valAtt;
  _valDef = valDef;
  _valPM = valPM;
}

void Carte::affichageCarteLong() const {
  cout << "***************" << endl;
  cout << "Nom :" <<   _nom << endl;
  cout << "Attaque :" <<   _valAtt << endl;
  cout << "Defense :" <<   _valDef << endl;
  cout << "Magie :" <<   _valPM << endl;
  cout << "***************" << endl;
}

void Carte::affichageCarteCourt() const {
  cout << _nom << " "
       << "[ " << _valAtt << " ; " << _valDef << " ; " << _valPM << " ]"
       << endl;
}

 string Carte::getnom() const { 
   return _nom;
}

int Carte::getvalAtt() const { 
  return _valAtt;
}

int Carte::getvalPM() const { 
  return _valPM; 
}

int Carte::getvalDef() const {
  return _valDef;
}


int Carte::degatPhysique(const Carte & c) const {
  if(_valAtt > c._valAtt) {
    return c._valAtt; 
    
  } else if(_valAtt < c._valAtt) {
    return -_valAtt;
  }
  
}

int Carte::degatMagique(const Carte & c) const { 
  if(_valPM > c._valAtt) {
    return c._valPM; 
    
  } else if(_valPM < c._valPM) {
    return -_valPM;
  } 
}

void Carte::remplir(const string & ligne) {
    istringstream ss(ligne);
    getline(ss, _nom, ',');
    ss >> _valAtt; ss.ignore(1);
    ss >> _valDef; ss.ignore(1);
    ss >> _valPM;
    
}