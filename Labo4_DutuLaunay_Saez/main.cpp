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



string add(string chiffre1, string chiffre2) 
{
    string resultat;
   /* 
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
  */
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

  int car1;
  int car2;
  string operande1;
  string operande2;
  bool operandes_inversees = false;
  int longueur_lhs = lhs.length();
  int longueur_rhs = rhs.length();
  unsigned int nb_car_op_plus_court;
  unsigned int diff_longeur;
  
  // si la première opérande est plus petite que la seconde, on inverse l'ordre de la
  // soustraction afin de multiplier plus tard le résultat par * (-1)
  if(lhs < rhs)
  {
     operande1 = rhs;
     operande2 = lhs;
     //operandes_inversees = true;     
  }
  else
  {
     operande1 = lhs;
     operande2 = rhs;
  }
  
  if(operande1.length() > operande2.length())
  {
     nb_car_op_plus_court = operande2.length();
     diff_longeur = operande1.length() - operande2.length();// on va l'utiliser dans une boucle for pour rajouter les derniers caractères
  }
  else
  {
     nb_car_op_plus_court = operande1.length();
     diff_longeur = operande2.length() - operande1.length();
  }
  
  int resultat_intermediaire;
  for(int indice = nb_car_op_plus_court; indice > 0; indice--)
  {
       car1 = char2int(operande1[indice]);
       car2 = char2int(operande2[indice]);
       
       resultat_intermediaire = car1 - car2;
       
       //cout << resultat_intermediaire << endl;
       resultat[indice] = int2char(resultat_intermediaire);
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