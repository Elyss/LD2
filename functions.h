#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "attribute.h"

bool operator==(Player const& a, Player const& b);
bool operator!=(Player const& a, Player const& b);
    bool compare(Player const& A, Player const& B);

std::vector<std::string> split(const std::string& str, const std::string& delim); //spliter un string en vecteur de strings

std::vector<Player> load_bdd();
std::map<std::string,Attribute> load_attributes();

//charger le fichier csv
void save_bdd(std::vector<Player> joueur);//sauver le fichier csv

std::string f_to_string(float val);
std::string i_to_string(int val);

int countSubstring(const std::string& str, const std::string& sub);


#endif // FUNCTIONS_H_INCLUDED
