#include <iostream>
#include "Jeu.h"
#include "Joueur.h"
#include "Carte.h"
#include <stdexcept>
#include <algorithm>>
#include <string>
using namespace std;

int maintest() {
/// TESTS AUTOMATIQUES
    cout<<""<<endl;
    cout<<"--------------------Test des fonction Carte------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"**            Test de la fonction Affiches des Cartes     **"<<endl;
    Carte test1;
    test1.affichageCarteCourt();
    cout<<""<<endl;
    cout<<""<<endl;
    test1.affichageCarteLong();
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"--------------------Test de la fonction degatPhysique--------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Cas general 1  degat superieur: "<<endl;
    Carte test2("MainGauche",0,1,0);
    Carte test3("Tete",1,-2,0);
    if ( test2.degatPhysique(test3)==0)
    {
        cout<<" Test Cas general 1  degat superieur, reussi ! "<<endl;
    }
    else
    {
        cout<<" Test Cas general 1  degat superieur,  rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 2 : degat nul"<<endl;
    Carte test4("MainGauche",-1,1,1);
    Carte test5("Tete",0,-2,0);
    if ( test4.degatPhysique(test5)==0)
    {
        cout<<" Test Cas general 2 : degat nul, reussi ! "<<endl;
    }
    else
    {
        cout<<" Test Cas general 2 : degat nul, rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 3 : degat negatif "<<endl;
    Carte test6("MainGauche",1,1,0);
    Carte test7("Tete",1,-2,-1);
    if ( test6.degatPhysique(test7)==0)
    {
        cout<<" Test Cas general 3  degat negatif, reussi ! "<<endl;
    }
    else
    {
        cout<<" Test Cas general 3 degat negatif, rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"--------------------Test de la fonction degatMagique--------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Cas general 1 : degat nul "<<endl;
    if ( test2.degatMagique(test3)==0)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 2 : degat superieur "<<endl;
    if ( test4.degatMagique(test5)==1)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 3 :degat negatif "<<endl;
    if ( test6.degatMagique(test7)==1)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"--------------------Test de la fonction remplir--------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Cas general 1 : degat nul "<<endl;
    if ( test2.degatMagique(test3)==0)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 2 : degat superieur "<<endl;
    if ( test4.degatMagique(test5)==1)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
    cout<<""<<endl;
    cout<<"Cas general 3 :degat negatif "<<endl;
    if ( test6.degatMagique(test7)==1)
    {
        cout<<" Test reussi ! "<<endl;
    }
    else
    {
        cout<<" Test rater ! "<<endl;
    }
  cout << "----------------------TEST CLASSE JOUEUR----------------------"
       << endl;
  // Test vie
  Joueur joueurTest;

 // cout << "test vie : ";
 // if (joueurTest.Vie() != 25) {
  //  cout << "test vie incorrect" << endl;
  //}

  //else {
    //cout << "test vie correct" << endl;
  //}

  // Test des cartes jouer
 // cout << "test carte jouer : ";
  // if (joueurTest.jouentUneCarte() != 4) {
  //  cout << "test carte joueur incorrect " << endl;
  // } else {
   // cout << "test carte joueur correct" << endl;
 // }

  // Test nom du joueur

  cout << "test nom joueur  : ";
  if (joueurTest.sonNom() != "Yugi") {
    cout << "test nom du joueur incorrect" << endl;
  } else {
    cout << "test nom du joueur correct" << endl;
  }

  //test du constructeur joueur 

  
  cout << "----------------------TEST CLASSE JEU----------------------" << endl;
  // Test fin de la partie
 // cout << "test fin de parti : ";
  // if (Jeu.fini(joueurTest) != true) {
   // cout << "test fin de partie incorrect " << endl;
 // } else {
   // cout << "test fin de partie correct" << endl;
  //}

//};
  // Test Remplir reserve
//  cout << "test Reserve remplie : " << endl;
//  if (remplirReserve("cartes.txt")) {
  //  cout << "test remplissage reserve correct" << endl;
 // } else {
   // cout << "test remplissage reserve incorrect" << endl;
  //}
  




  
};
