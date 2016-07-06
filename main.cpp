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


#include "attribute.h"
#include "player.h"
#include "functions.h"
#include "bdd_functions.h"

using namespace std;

void afficher_map(map<string, Attribute>& m)
{
  map<string, Attribute>::iterator p; //Cr�ation d'un it�rator sur le 'map'
  for(p = m.begin(); p != m.end(); p++)
  {
    p->second.display();
  }
  cout<<endl;

}


int main()
{

    vector<Player> joueur = load_bdd(); //On charge la base de donn�e dans un vecteur
    map<string, Attribute> attributs = load_attributes();

    afficher_map(attributs);


    for(int i=0; i < joueur.size();i++)
    {
        joueur[i].stats(attributs);
    }


    int start = 0;
    int bound = joueur.size();

    srand(time(NULL)); // outside the loop
    int nb_simul = 10;

    for(int n=start; n<nb_simul; n++)
     {
         int nb1;
         int nb2;

         do
        {
            nb1 = rand()%bound;
            nb2 = rand()%bound;

         }while(nb1==nb2);



         joueur[nb1].victory(joueur[nb2], attributs);
     }

    afficher_map(attributs);

    save_bdd(joueur);
    save_bdd_attributes(attributs);


}


