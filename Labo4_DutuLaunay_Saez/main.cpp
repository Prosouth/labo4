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

string add(string chiffre1, string chiffre2) 
{
    string resultat;
    
    int longueur_chiffre1 = chiffre1.length();
    int longueur_chiffre2 = chiffre2.length();
    
    int j1 = longueur_chiffre1;
    int j2 = longueur_chiffre2;
    
    char char_chiffre1;
    char char_chiffre2;
    
    for (j1 = longueur_chiffre1 ; j1 > 0 ; j1--)
    {
        //affectation a char_chiffre1 et 2 la longueur de la chaine de chiffre1 et 2
        char_chiffre1 = chiffre1[j1];
        int int_chiffre1 = char2int(char_chiffre1);
        
        char_chiffre2 = chiffre1[j2];
        int int_chiffre2 = char2int(char_chiffre1);
        
        // addition du dernier chiffre des 2 chaines
        int resultat_addition = int_chiffre1 + int_chiffre2;
    
        if (resultat_addition > 9)
        {
//            if (chiffre1[j1 - 1] != 0)
//            {
                int_chiffre1 = int_chiffre1 + 1;
//            }
        }
        // affichage du resultat
        cout << resultat_addition;
    }
  
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
  
  // A COMPLETER
  
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
  unsigned int longueur_lhs = lhs.length(),
               longueur_rhs = rhs.length();
  
  char lol = lhs[lhs.length()-1];
  int nb = char2int(lol);
  
  cout << nb << endl;
  
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