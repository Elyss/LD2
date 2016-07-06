#include <iostream>
#include <fstream> //utilisation des fichiers
#include <string> // je vais utiliser les strings
#include <cmath> // opérations complexes de math
#include <vector> // tableaux dynamiques
#include <cstdlib> // la librairie pour effacer la console // Pour le random
#include <ctime> // Pour le Random
#include <sstream>
#include <map>
#include <algorithm>

#include "attribute.h"
#include "player.h"
#include "functions.h"
#include "bdd_functions.h"

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




