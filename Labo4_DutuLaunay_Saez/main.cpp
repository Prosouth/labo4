/* ---------------------------
 Laboratoire : 4
 Fichier :     main.cpp
 Auteur(s) :
 Date :
 
 But :         Mise en oeuvre d'opérations arithmétiques simples
 (+,-,*) sur des entiers positifs longs représentés
 sous forme de chaines de caractères en notation
 décimale
 
 Remarque(s) :
 
 Compilateur :
 --------------------------- */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/**
 Addition
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return somme des 2 entiers représentée en notation décimale
 */

int char2int(char c)
{
    return c -'0';
}

int int2char(char c)
{
    return c +'0';
}



string add(string lhs, string rhs) {
  string resultat;
  
  // A COMPLETER
  
  return resultat;
}


/**
 Multiplication
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return produit des 2 entiers représenté en notation décimale
 */
string multiply(string lhs, string rhs) {
  string resultat;
  
  // A COMPLETER
  
  return resultat;
}

/**
 Factorielle
 
 @param n entier >=0 
 
 @return n!, la factorielle de n représentée en notation décimale
 */
string factorial(int n) {
  string resultat;
  int lol = 1;
  
  for (int i = n; i > 0; i--)
  {
     lol *= i;
  }
  
  // à remplacer par une boucle qui met chaque caractère dans une string (relou)
  resultat += to_string(lol);
  
  return resultat;
}

/**
 Soustraction
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return différence (lhs - rhs) des 2 entiers représentée en notation décimale
 */
string subtract(string lhs, string rhs) {
  string resultat;
  int longueur_lhs = lhs.length();
  int longueur_rhs = rhs.length();
  int car1;
  int car2;
  
  int resultat_intermediaire;
  
  for(int indice = lhs.length(); indice >= 0; indice--)
  {
       car1 = char2int(lhs[indice]);
       car2 = char2int(rhs[indice]);
       
       resultat_intermediaire = car1 - car2;
       
       cout << resultat_intermediaire << endl;
       resultat += int2char(resultat_intermediaire);
       car1 = car2 = resultat_intermediaire = 0;
       
  }
  
  
  return resultat;
}


/**
 Fonction principale
 
 @return Mise en oeuvre d'opérations arithmétiques simples
 (+,-,*) sur des entiers positifs longs représentés
 sous forme de chaines de caractères en notation
 décimale
 */
int main() {
  
  cout << "Entrez deux entiers >= 0 \n";
  string i1, i2;
  cin >> i1 >> i2;
  
  cout << i1 << " + " << i2 << " = " << add(i1,i2) << endl;
  cout << i1 << " * " << i2 << " = " << multiply(i1,i2) << endl;
  cout << i1 << " - " << i2 << " = " << subtract(i1,i2) << endl;
  
  cout << "\nEntrez un entier >= 0 \n";
  int i3;
  cin >> i3;
  cout << "Factoriel(" << i3 << ") = " << factorial(i3) << endl;
  
  return EXIT_SUCCESS;
}