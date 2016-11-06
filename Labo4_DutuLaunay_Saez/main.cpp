/* ---------------------------
 Laboratoire : 4 - Arithmétique sur entiers longs
 Fichier :     main.cpp
 Auteur(s) :   Marion Dutu Launay et Sébastien Saez
 Date :
 
 But :         Mise en oeuvre d'opérations arithmétiques simples
               (+,-,*) sur des entiers positifs longs représentés
               sous forme de chaines de caractères en notation
               décimale
 
 Remarque(s) : On part du principe que la saisie utilisateur est correcte.
 
 Compilateur : g++ (GCC) 6.2.1 20160830
 --------------------------- */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int char2int(char c)
{
   return c - '0';
}

int int2char(char c)
{
   return c + '0';
}

/**
 Addition
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return somme des 2 entiers représentée en notation décimale
 */
string add(string chiffre1, string chiffre2)
{
   string resultat;
   string temp_res;
   int retenue = 0;
   if (chiffre2.length() > chiffre1.length())
   {
      string temp = chiffre1;
      chiffre1 = chiffre2;
      chiffre2 = temp;
   }
   int dif = chiffre1.length() - chiffre2.length();
   for (int i = chiffre1.length() - 1; i >= 0; i--) 
   {
      int res = (char2int(chiffre1[i]) + retenue) + 
      ((i - dif >= chiffre2.length()) ? 0 : char2int(chiffre2[i-dif]));
      retenue = res / 10;
      temp_res += int2char(res%10);
   }
   if (retenue > 0)
   {
      temp_res += int2char(retenue);
   }
   bool zero = true;
   for (int i = temp_res.length()-1; i >= 0; i--) 
   {
      if (!(zero && temp_res[i] == '0'))
      {
         resultat += temp_res[i];
         zero = false;
      }
   }
   return resultat == "" ? "0" : resultat;
}

/**
 Multiplication
 
 @param lhs entier >=0 représenté en notation décimale
 @param rhs entier >=0 représenté en notation décimale
 
 @return produit des 2 entiers représenté en notation décimale
 */
string multiply(string chiffre1, string chiffre2)
{
   string resultat = "0";
   
   // On compare les deux opérandes pour mettre la plus courte en bas,
   // de cette manière, on économise des itérations 
   if (chiffre2.length() > chiffre1.length())
   {
      string temp = chiffre1;
      chiffre1 = chiffre2;
      chiffre2 = temp;
   }
   int retenue = 0;
   string resultat_operande2 = "0";
   for (int i = chiffre2.length() - 1; i >= 0; i--) 
   {
      int chiffre_2 = char2int(chiffre2[i]);
      string temp_res;
      
      for (int j = chiffre1.length() - 1; j >= 0; j--)
      {
         int chiffre_1 = char2int(chiffre1[j]);
         int res = retenue + (chiffre_1 * chiffre_2);
         retenue = res / 10;
         temp_res += int2char(res % 10);
      }
      
      string inter = "";
      inter += temp_res;
      if (retenue > 0) 
      {
         inter += int2char(retenue);
      }
      

      
      string interfinal;
      for (int m = inter.length() - 1; m >= 0; m--)
      {
         interfinal += inter[m];
      }
      for (int k = chiffre2.length() - 1; k > i; k--) 
      {
         interfinal += '0';
      }
      
      retenue = 0;
      resultat_operande2 = add(resultat_operande2, interfinal);
   }
   
   resultat = add(resultat, resultat_operande2);
   
   return resultat;
}

/**
 Factorielle
 
 @param n entier >=0 
 
 @return n!, la factorielle de n représentée en notation décimale
 */
string factorial(int n)
{
   string resultat;
   int lol = 1;

   for (int i = n; i > 0; i--) {
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
string subtract(string operande1, string operande2)
{
   string resultat = "";

   long long car1;
   long long car2;
   bool operandes_inversees = false;
   int longeur_op1 = operande1.length();
   int longeur_op2 = operande2.length();
   unsigned int diff_longeur;

   // si la première opérande est plus petite que la seconde, on inverse l'ordre de 
   // la soustraction afin de multiplier plus tard le résultat par * (-1)
   if (longeur_op1 < longeur_op2) 
   {
      operandes_inversees = true;
   } 
   else if (longeur_op1 == longeur_op2)
   {
      int i = 0;
      do 
      {
         operandes_inversees = char2int(operande2[i]) > char2int(operande1[i]);
         i++;
      } 
      while (i < operande1.length() && (operande1[i - 1] == operande2[i - 1]));
   }
   
   if(operandes_inversees)
   {
      string temp = operande1;
      operande1 = operande2;
      operande2 = temp;
   }
   
   diff_longeur = operande1.length() - operande2.length();
   bool retenue = false;
   for (int i = operande2.length() - 1; i >= 0; i--) 
   {
      bool retenue_prec = retenue;
      car1 = char2int(operande1[i + diff_longeur]);
      car2 = char2int(operande2[i]);
      car1 -= retenue_prec ? 1 : 0; 
      retenue = car1 < car2;
      car1 += retenue ? 10 : 0;
      resultat += int2char(car1 - car2);  
   }
   int indice_reste = diff_longeur - 1;
   while (retenue || indice_reste >= 0) 
   {
      int car_reste = char2int(operande1[indice_reste--]) - (retenue ? 1 : 0);
      retenue = car_reste < 0;
      car_reste += retenue ? 10 : 0; 
      resultat += int2char(car_reste);  
   }
   int longeur_resultat = resultat.length();
   bool zero = true;
   string res_final;
   if (operandes_inversees)
   {
      res_final += '-';
   }
   for (int i = longeur_resultat-1; i >= 0; i--) 
   {
      if (!(zero && resultat[i] == '0'))
      {
         res_final += resultat[i]; 
         zero = false;
      }
   }
   longeur_resultat = res_final.length();
   return res_final == "" ? "0" : res_final;
}

/**
12 Fonction principale
 @return Mise en oeuvre d'opérations arithmétiques simples
 (+,-,*) sur des entiers positifs longs représentés
 sous forme de chaines de caractères en notation
 décimale
 */
int main()
{

   cout << "Entrez deux entiers >= 0 \n";
   string entier1, entier2;
   cin >> entier1 >> entier2;

   cout << entier1 << " + " << entier2 << " = " << add(entier1, entier2) << endl;
   cout << entier1 << " * " << entier2 << " = " << multiply(entier1, entier2) << endl;
   cout << entier1 << " - " << entier2 << " = " << subtract(entier1, entier2) << endl;

   cout << "\nEntrez un entier >= 0 \n";
   int entier3;
   cin >> entier3;
   cout << "Factoriel(" << entier3 << ") = " << factorial(entier3) << endl;
  
   return EXIT_SUCCESS;
}