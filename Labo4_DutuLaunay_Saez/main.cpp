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
    string ajout_zero = "0";
    string chiffre_long;
    
    int longueur_chiffre1 = chiffre1.length();
    int longueur_chiffre2 = chiffre2.length();
    int lg_chiffre_long;
    
    if (longueur_chiffre1 > longueur_chiffre2)
    {
        lg_chiffre_long = longueur_chiffre1;
        chiffre1 = chiffre_long;
    }
    else
    {
        lg_chiffre_long = longueur_chiffre2;
        chiffre2 = chiffre_long;
    }
    
    int lg_max = lg_chiffre_long;
    
    if (longueur_chiffre1 != longueur_chiffre2)
    {
        for (int indice = 0 ; indice < lg_max ; indice ++)
        {
            ajout_zero[indice] = chiffre_long[indice];
        }
    }
    
    cout << ajout_zero << endl;
    
    int j1 = lg_max;
    int j2 = lg_max;
    
    char char_chiffre1;
    char char_chiffre2;
    char char_chiffre12;
    
    int int_chiffre1;
    int int_chiffre2;
    int int_chiffre12;
    
    const int RETENUE = 1;
    
    bool retenue = false;
    
    for (j1 = lg_max; j1 > 0 ; j1-- && j2--)
    {
        //affectation a char_chiffre1 et 2 la longueur de la chaine de chiffre1 et 2
        char_chiffre1 = chiffre1[j1 - 1];
        
        if (retenue == false)
        {
            int_chiffre1 = char2int(char_chiffre1);
        }
        else
        {
            int_chiffre1 = int_chiffre12;
            retenue = false;
        }
        
        char_chiffre2 = chiffre2[j2 - 1];
        int_chiffre2 = char2int(char_chiffre2);

        char_chiffre2 = chiffre2[j2 - 1];
        int_chiffre2 = char2int(char_chiffre2);
        
        char_chiffre12 = chiffre1[j1 - 2];
        int_chiffre12;
        int_chiffre12 = char2int(char_chiffre12);
        
        // addition du dernier chiffre des 2 chaines
        int resultat_inter = int_chiffre1 + int_chiffre2;
        
        if (resultat_inter > 9)
        {
            int_chiffre12 += RETENUE;
            int_chiffre1 = int_chiffre12;
            resultat_inter %= 10;
            retenue = true;   
        }
        
        // affichage du resultat
        cout << resultat_inter;
        resultat += int2char(resultat_inter);
        
        resultat_inter = 0;
        
    }
  
    return resultat;
}

/**
 Multiplication
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return produit des 2 entiers représenté en notation décimale
 */
string multiply(string chiffre1, string chiffre2) 

{
    string resultat;
    
    int longueur_chiffre1 = chiffre1.length();
    int longueur_chiffre2 = chiffre2.length();
  
    char char_chiffre1;
    char char_chiffre2;
    char char_chiffre12;

    int int_chiffre1;
    int int_chiffre2;
    int int_chiffre12;
    int resultat_inter;
   
    int j1 = longueur_chiffre1;
    int j2 = longueur_chiffre2;
    
    bool retenue = false;
    
    const int RETENUE = 1;
    
    for (int j2 = longueur_chiffre2)
    
    for ( j1 = longueur_chiffre1 ; j1 > 0 ; j1--)
    {
        if (retenue == false)
        {
            int_chiffre1 = char2int(char_chiffre1);
        }
        else
        {
            int_chiffre1 = int_chiffre12;
            retenue = false;
        }
        
        char_chiffre1 = chiffre1[j1 - 1];
        int_chiffre1 = char2int(char_chiffre1);
        
        char_chiffre2 = chiffre2[j2 - 1];
        int_chiffre2 = char2int(char_chiffre1);
        
        char_chiffre12 = chiffre1[j1 - 2];
        int_chiffre12;
        int_chiffre12 = char2int(char_chiffre12);
        
        resultat_inter = int_chiffre1 * int_chiffre2;
        
        
        if (resultat_inter > 9)
        {
            int_chiffre12 += RETENUE;
            int_chiffre1 = int_chiffre12;
            resultat_inter %= 10;
            retenue = true;   
        }
      
    }
  
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
// resultat += to_string(lol);
  
  return resultat;
}

/**
 Soustraction
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return différence (lhs - rhs) des 2 entiers représentée en notation décimale
 */
string subtract(string lhs, string rhs) 
{
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