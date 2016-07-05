#include <iostream>
#include <fstream> //utilisation des fichiers
#include <string> // je vais utiliser les strings
#include <cmath> // opérations complexes de math
#include <vector> // tableaux dynamiques
#include <cstdlib> // la librairie pour effacer la console // Pour le random
#include <ctime> // Pour le Random
#include <sstream>
#include <map>

#include "attribute.h"
#include "player.h"
#include "functions.h"

using namespace std;

bool operator==(Player const& a, Player const& b)
    {
        return a.estEgal(b);
    }

bool operator!=(Player const& a, Player const& b)
    {
        return !(a.estEgal(b));
    }

bool compare(Player const& A, Player const& B)
    {
        if(A == B)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



vector<string> split(const string& str, const string& delim) //Parser un string en vector de string avec le séparateur précisé
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

vector<Player> load_bdd()
{
        cout << "Chargement de la base" << endl<< endl;
        vector<Player> joueur; //un vecteur de joueurs


        int id;
        string name;
        float score;
        int victory;
        int defeat;

        Player *Jtemp; //un objet joueur


        ifstream file_joueur("joueurs.csv", ios::in);  // on ouvre le fichier en lecture

        if(file_joueur)  // si l'ouverture a réussi
        {



                string line;


                while(getline(file_joueur,line)) //pour chaque ligne du fichier
                {

                    vector<string> attributs;
                    vector <string>splitted = split(line,";"); //splitter chaque ligne selon séparateur ";"

                    //stocker les info splittées dans les variables correspondantes
                    id = std::stoi(splitted[0]);
                    name = splitted[1];
                    score = std::stof(splitted[2]); //on passe les string en int ou float
                    victory = std::stoi(splitted[3]);
                    defeat = std::stoi(splitted[4]);



                    if(splitted.size() > 5)
                    {

                        for(int i = 5; i < splitted.size(); i++)
                        {
                            attributs.push_back(splitted[i]);
                        }
                    }

                                        //on crée un objet joueur avec et on le met dans un array de joueurs
                    Jtemp = new Player(id,name,score,victory,defeat,attributs);
                    joueur.push_back(*Jtemp);

                }



                file_joueur.close();  // on ferme le fichier

                cout << "Base de donnée chargée" << endl<< endl;
                return joueur; //on renvoie au main le vecteur qui contient tous les joueurs en objet

        }
        else  // sinon
                cout << "Impossible d'ouvrir le fichier !" << endl;
}

void save_bdd(vector<Player> joueur)
    {
        ofstream fichier_save("joueurs.csv", ios::out | ios::trunc);
            if(fichier_save)
            {
                for(int i=0; i < joueur.size();i++)
                {
                    string recompose = i_to_string(joueur[i].getId()) + ";" + joueur[i].getName() + ";" + f_to_string(joueur[i].getScore()) + ";" + i_to_string(joueur[i].getVictory()) + ";" + f_to_string(joueur[i].getDefeat()) + joueur[i].getAttributs();



                    fichier_save << recompose << endl;
                }

                fichier_save.close();
                cout << "Base mise a jour" <<endl;
            }

            else
            {
                cout << "echec de la sauvegarde" <<endl;
            }

    }


string f_to_string(float val)
    {
          stringstream ss (stringstream::in | stringstream::out);
          ss << val;
          string result = ss.str();

          return result;
    }

string i_to_string(int val)
    {
          stringstream ss (stringstream::in | stringstream::out);
          ss << val;
          string result = ss.str();

          return result;
    }

int countSubstring(const string& str, const string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}


map<string, Attribute> load_attributes()
{
        cout << "Chargement de la base Attributs" << endl<< endl;
        map<string, Attribute> map_attribut; //un vecteur d'attribut


        string name;
        float m_ratio;
        int victory;
        int defeat;
        string affinities;
        string disaffinities;

        Attribute *Atemp; //un objet joueur


        ifstream attr("attributes.csv", ios::in);  // on ouvre le fichier en lecture

        if(attr)  // si l'ouverture a réussi
        {



                string line;


                while(getline(attr,line)) //pour chaque ligne du fichier
                {

                    vector <string>splitted = split(line,";"); //splitter chaque ligne selon séparateur ";"

                    //stocker les info splittées dans les variables correspondantes

                    name = splitted[0];
                    victory = stoi(splitted[1]);
                    defeat = stoi(splitted[2]);
                    m_ratio = stof(splitted[3]);
                    affinities = splitted[4];
                    disaffinities = splitted[5];

                                        //on crée un objet attribut avec et on le met dans une map de joueurs
                    Atemp = new Attribute(name,victory,defeat,m_ratio,affinities,disaffinities);
                    map_attribut[name]= *Atemp;

                }



                attr.close();  // on ferme le fichier

                cout << "Base de donnée attributs chargée" << endl<< endl;
                return map_attribut; //on renvoie au main la map des attributs

        }
        else  // sinon
                cout << "Impossible d'ouvrir le fichier attributs!" << endl;
}


void save_bdd_attributes(map<string,Attribute> attributs)
    {
        ofstream fichier_save("attributes.csv", ios::out | ios::trunc);
            if(fichier_save)
            {

                map<string, Attribute>::iterator p; //Création d'un itérator sur le 'map'
                for(p = attributs.begin(); p != attributs.end(); p++)
                    {
                        string recompose = p->second.getName() + ";" + i_to_string(p->second.getVictory()) + ";" + i_to_string(p->second.getDefeat()) + ";" + f_to_string(p->second.getRatio()) + ";" + p->second.getAffinities() + ";" + p->second.getDisaffinities();
                        fichier_save << recompose <<endl;

                    }

                fichier_save.close();
                cout << "Base attributs mise a jour" <<endl;
            }

            else
            {
                cout << "echec de la sauvegarde des attributs" <<endl;
            }
    }

