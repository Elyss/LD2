#include <iostream>
#include <fstream> //utilisation des fichiers
#include <string> // je vais utiliser les strings
#include <cmath> // op�rations complexes de math
#include <vector> // tableaux dynamiques
#include <cstdlib> // la librairie pour effacer la console // Pour le random
#include <ctime> // Pour le Random
#include <fstream> // lecture/ecriture fichiers
#include <sstream>
#include <map>
#include <random>
#include <algorithm>


#include "player.h"
#include "functions.h"
#include "attribute.h"

using namespace std;



int main()
{

    vector<Player> joueur = load_bdd(); //On charge la base de donn�e dans un vecteur

    //map<string, Attribute> attribut = load_attributes();

    for(int i=0; i < joueur.size();i++)
    {
        joueur[i].stats();
    }

    /*  SIMULER x VICTOIRE ALEATOIRES
    int start = 0;
    int bound = joueur.size();

    srand(time(NULL)); // outside the loop
    int nb_simul = 1000;

    for(int n=start; n<=nb_simul; n++)
     {
         int nb1;
         int nb2;

         do
        {
            nb1 = rand()%bound;
            nb2 = rand()%bound;

         }while(nb1==nb2);



         joueur[nb1].victory(joueur[nb2]);
     }

     */


    save_bdd(joueur);


}


