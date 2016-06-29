#include <iostream>
#include <fstream> //utilisation des fichiers
#include <string> // je vais utiliser les strings
#include <cmath> // opérations complexes de math
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

Attribute::Attribute()
{
    //ctor
}

Attribute::Attribute(string m_name, int m_victory, int m_defeat, float m_ratio, string m_affinities, string m_disaffinities) : m_name(m_name), m_victory(m_victory), m_defeat(m_defeat), m_ratio(m_ratio), m_affinities(m_affinities), m_disaffinities(m_disaffinities)
{

}


Attribute::~Attribute()
{
    //dtor
}


void Attribute::stats() const
    {
        cout << "nom : " <<m_name<<endl;
        cout << "Victoires : " <<m_victory<<endl;
        cout << "Defaites : " <<m_defeat<<endl;
        cout << "Ratio : " <<m_ratio<<endl;
        cout << "Affinites : " <<m_affinities<<endl;
        cout << "Non affinites : " <<m_disaffinities<<endl;
    }

void Attribute::display() const
    {
        if(!m_name.empty())
        {

        cout <<m_name;
        cout << " [V: " <<m_victory;
        cout << " D: " <<m_defeat;
        cout << " R: " <<m_ratio;
        cout << " A: " <<m_affinities;
        cout << " N: " <<m_disaffinities<<"]"<<endl;
        }

        else{cout<<"Inconnu"<<endl;}
    }
