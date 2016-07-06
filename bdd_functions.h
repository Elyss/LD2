#ifndef BDD_FUNCTIONS_H_INCLUDED
#define BDD_FUNCTIONS_H_INCLUDED

std::vector<Player> load_bdd();
std::map<std::string,Attribute> load_attributes();

//charger le fichier csv
void save_bdd(std::vector<Player> joueur);//sauver le fichier csv
void save_bdd_attributes(std::map<std::string,Attribute> attributes);


#endif // BDD_FUNCTIONS_H_INCLUDED
