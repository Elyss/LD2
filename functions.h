#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//COMPARATEURS DE JOUEURS

bool operator==(Player const& a, Player const& b);
bool operator!=(Player const& a, Player const& b);
    bool compare(Player const& A, Player const& B);

//FONCTIONS

std::vector<std::string> split(const std::string& str, const std::string& delim); //spliter un string en vecteur de strings
int countSubstring(const std::string& str, const std::string& sub); //compter les occurences d'une chaine dans un string

//CASTEURS

std::string f_to_string(float val);
std::string i_to_string(int val);



#endif // FUNCTIONS_H_INCLUDED
