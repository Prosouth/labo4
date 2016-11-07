/* ---------------------------
 Laboratoire : 4 - Arithmétique sur entiers longs
 Fichier :     Labo4_dutu_saez.cpp
 Auteur(s) :   Marion Dutu Launay et Sébastien Saez
 Date :        6 novembre 2016
 
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

// Constantes   
const int BASE10 = 10;



/**
 Conversion char en entier
 
 @param caractère 
 
 @return caractère converti en entier
 */
int char2int(char c)
{
   return c - '0';
}

/**
 Conversion entier en caractère 
 
 @param entier >= 0 
 
 @return entier converti en caractère
 */
int int2char(char c)
{
   return c + '0';
}

/**
 Conversion entier en string 
 
 @param entier >= 0 
 
 @return entier converti en string
 */
string int2string(int nombre)
{
   // Déterminer la longueur de l'entier
    if (nombre == 0)
    {
       return "0";
    }
        
    string temp = "";
    string int_converti = "";
    
    while (nombre > 0) 
    {
        temp += int2char(nombre % BASE10);
        
        nombre /= BASE10;
    }
    
    for (int i = 0; i < temp.length(); i++) {
        int_converti += temp[temp.length()-i-1];
    }
    return int_converti;
}

/**
 Addition
 
 @param chiffre1 entier >=0 représenté en notation décimale
 @param chiffre2 entier >=0 représenté en notation décimale
 
 @return somme des 2 entiers représentée en notation décimale
 */
string add(string chiffre1, string chiffre2)
{
   int retenue = 0; // on initialise la retenue à 0 pour la première addition
   string resultat, // afin de stocker le resultat final et le renvoyer
          temp_res; // valeur utilisée pour 
   
   // si le chiffre 2 est plus grand que le chiffre 1, on l'inverse
   if (chiffre2.length() > chiffre1.length())
   {
      string temp = chiffre1;
      chiffre1 = chiffre2;
      chiffre2 = temp;
   }
   int difference = chiffre1.length() - chiffre2.length(); // on stocke la différence 
   for (int i = chiffre1.length() - 1; i >= 0; i--)        // afin de l'utiliser comme index
   {
      int res = (char2int(chiffre1[i]) + retenue) + 
      ((i - difference >= chiffre2.length()) ? 0 : char2int(chiffre2[i-difference]));
      retenue = res / BASE10;
      temp_res += int2char(res % BASE10);
   }
   
   // si la retenue est supérieure à 0, on la stocke dans le résultat temporaire
   if (retenue > 0)
   {
      temp_res += int2char(retenue);
   }
   bool zero = true; // utilisé pour déterminer s'il y a des 0 à traiter
   for (int i = temp_res.length()-1; i >= 0; i--) 
   {
      if (!(zero && temp_res[i] == '0'))
      {
         resultat += temp_res[i]; 
         zero = false;
      }
   }
   // on retourne 0 si la chaîne est vide, autrement on retourne le résultat
   return resultat == "" ? "0" : resultat;
}

/**
 Multiplication
 
 @param chiffre1 entier >=0 représenté en notation décimale
 @param chiffre2 entier >=0 représenté en notation décimale
 
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
      
      // boucle qui itère pour calculer la valeur du résultat intermédiaire
      for (int j = chiffre1.length() - 1; j >= 0; j--)
      {
         int chiffre_1 = char2int(chiffre1[j]);
         int res = retenue + (chiffre_1 * chiffre_2);
         retenue = res / BASE10;
         temp_res += int2char(res % BASE10);
      }
      
      string resultat_intermediaire = "";
      resultat_intermediaire += temp_res;
      
      // si la retenue est à 0, on l'intégre dans le résultat intermédiaire
      if (retenue > 0) 
      {
         resultat_intermediaire += int2char(retenue);
      }

      string inversion_finale; // va contenir le resultat inversé des opérandes
      // boucle  qui va 
      for (int m = resultat_intermediaire.length() - 1; m >= 0; m--)
      {
         inversion_finale += resultat_intermediaire[m];
      }
      // on doit rajouter un 0 au 2ème opérateur,3 au 3ème, etc...
      for (int k = chiffre2.length() - 1; k > i; k--) 
      {
         inversion_finale += '0';
      }
      
      retenue = 0; // on remet la retenue à 0
      resultat_operande2 = add(resultat_operande2, inversion_finale);
   }
   resultat = add(resultat, resultat_operande2); // addition finale
   
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

   int car1; // pour stocker le caractère de l'opérande 1
   int car2; // pour stocker le caractère de l'opérande 2
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
   else if (longeur_op1 == longeur_op2) // si les deux opérandes sont égales,
   {                                   
      int i = 0;                        
      do 
      {
         // on compare caractère par caractère pour déterminer si on doit inverser
         operandes_inversees = char2int(operande2[i]) > char2int(operande1[i]);
         i++;
      } 
      while (i < operande1.length() && (operande1[i - 1] == operande2[i - 1]));
      // tant qu'on a pas atteint la fin de chaine ET opérande 1 similaire à opérande 2
   }
   // si le boolean est vrai, on inverse les opérandes
   if(operandes_inversees)
   {
      string temp = operande1;
      operande1 = operande2;
      operande2 = temp;
   }
   
   // on détermine la différence de longueur
   diff_longeur = operande1.length() - operande2.length();
   
   bool retenue = false; // pas de retenue avant de rentrer dans la boucle
   for (int i = operande2.length() - 1; i >= 0; i--) 
   {
      bool retenue_prec = retenue; // on affecte la retenue actuelle à la précédente
      car1 = char2int(operande1[i + diff_longeur]);
      car2 = char2int(operande2[i]);
      car1 -= retenue_prec ? 1 : 0; // on soustrait la retenue_prec s'il y en avait une
      retenue = car1 < car2; // on détermine s'il y'a une retenue
      car1 += retenue ? BASE10 : 0; 
      resultat += int2char(car1 - car2);  
   }
   
   int indice_reste = diff_longeur - 1; 
   while (retenue || indice_reste >= 0) // tant qu'il y a une retenue OU indice_reste >= 0
   {
      int car_reste = char2int(operande1[indice_reste--]) - (retenue ? 1 : 0);
      retenue = car_reste < 0; 
      car_reste += retenue ? BASE10 : 0; 
      resultat += int2char(car_reste);  
   }
   int longeur_resultat = resultat.length();
   bool zero = true;
   string resultat_final;
   // si les opérandes ont été inversées, on rajouter simplement un - devant :)
   if (operandes_inversees)
   {
      resultat_final += '-';
   }
   
   // boucle pour traiter les 0 parasites
   for (int i = longeur_resultat-1; i >= 0; i--) 
   {
      if (!(zero && resultat[i] == '0'))
      {
         resultat_final += resultat[i]; 
         zero = false;
      }
   }
   // si le résultat est vide, on retourne 0 autrement, le résultat calculé
   return resultat_final == "" ? "0" : resultat_final;
}

/**
 Factorielle
 
 @param n entier >=0 
 
 @return n!, la factorielle de n représentée en notation décimale
 */
string factorial(int n)
{
   // Si n vaut 1, on retourne 1 autrement on fait la formule de factorielle
   // n * (n-1)!
   return (n == 0) ? "1" : multiply(int2string(n), factorial(n - 1));
}

/*
 Fonction principale
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