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

Attribute::Attribute()
{
    //ctor
}

Attribute::Attribute(string m_name, int m_victory, int m_defeat, float m_ratio, string m_affinities, string m_disaffinities) : m_name(m_name), m_victory(m_victory), m_defeat(m_defeat), m_ratio(m_ratio), m_affinities(m_affinities)
{

}


Attribute::~Attribute()
{
    //dtor
}