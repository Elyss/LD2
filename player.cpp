#include <iostream>
#include <fstream> //utilisation des fichiers
#include <string> // je vais utiliser les strings
#include <cmath> // opérations complexes de math
#include <vector> // tableaux dynamiques
#include <cstdlib> // la librairie pour effecer la console
#include <ctime> // Pour le Random
#include <cstdlib> // Pour le random
#include <map>


#include "attribute.h"
#include "player.h"
#include "functions.h"

using namespace std;



//FONCTIONS INTERNES

int Kdef(int score)  //facteur de variation de score
    {
        int K;
        if(score < 1000)
        {
            K = 80;
        }
        else if (score >= 1000 && score < 2000)
        {
            K = 50;
        }
        else if (score >= 2000 && score < 2400)
        {
            K = 30;
        }
        else if (score >= 2400)
        {
            K = 20;
        }

    return K;
    }


float estimate(float m_score, float adv_m_score) //estimation Elo
    {
        float exp;
        float resultat;

        exp = (adv_m_score-m_score)/400;

        resultat = 1/(1+ pow(10, exp));

        return resultat;
    }


//CONSTRUCTEURS


Player::Player() : m_id(), m_score(2000), m_victory(0), m_defeat(0), m_name("No_name")
    {
        //constructeur défaut
    }

Player::Player(string name) : m_id(), m_score(2000), m_victory(0), m_defeat(0), m_name(name)
    {
        //construteur avec nom
    }

Player::Player(string name, float score) : m_id(), m_score(score), m_victory(0), m_defeat(0), m_name(name)
    {
        //construteur avec nom et score
    }

Player::Player(int id, string name, float score, int victory, int defeat) : m_id(id), m_score(score), m_victory(victory), m_defeat(defeat), m_name(name)
    {
        //construteur avec nom et score
    }

Player::Player(int id, string name, float score, int victory, int defeat, vector<string> attributs) : m_id(id), m_score(score), m_victory(victory), m_defeat(defeat), m_name(name), m_attributs(attributs)
    {
        //construteur avec nom et score
    }

Player::~Player()
{
        //destructeur
}


// METHODES


void Player::victory(Player &adversary)  //Victoire de A sur B
    {
        int K = Kdef(m_score);

        int J = m_score + K*(1 - estimate(m_score, adversary.m_score));

        m_score = round(J);
        m_victory += 1;

        int Ka = Kdef(adversary.m_score);

        int Ja = adversary.m_score + Ka*(0 - estimate(adversary.m_score, m_score));

        adversary.m_score = round(Ja);

        adversary.m_defeat += 1;

        cout << m_name << " gagne contre " << adversary.m_name << endl << endl;

    }


void Player::stats(map<string,Attribute> base_attributs) const //Afficher les stats
    {
        cout <<"\t"<< m_name << " :"<< endl << endl;
        cout << "Score : "<< m_score <<endl;
        cout << "Victoires : "<< m_victory <<endl;
        cout << "Defaites : "<< m_defeat << endl;
        cout << "Attributs : "<< m_attributs.size() << endl;

        if(m_attributs.size() > 0)
        {
            for(int i = 0; i < m_attributs.size();i++)
            {
                string attr = m_attributs[i];
                cout << "\t Attribut " << i+1 << " : ";
                base_attributs[attr].display();
            }
        }
         cout << endl <<endl;
    }

bool Player::estEgal(Player const &adversary) const
    {
        return (m_score == adversary.m_score);
    }


//ACCESSEURS

int Player::getId() const
    {
        return m_id;
    }

string Player::getName() const
    {
        return m_name;
    }

float Player::getScore() const
    {
        return m_score;
    }

int Player::getVictory() const
    {
        return m_victory;
    }

int Player::getDefeat() const
    {
        return m_defeat;
    }

string Player::getAttributs() const
    {

        string recompose_attributs;

        if(m_attributs.size() > 0)
            {
            for(int i = 0; i < m_attributs.size();i++)
                {
                    recompose_attributs += ";" + m_attributs[i];
                }
            }
        return recompose_attributs;
    }


//SETTEURS

string Player::setName(string name)
    {
        m_name = name;
    }

float Player::setScore(float score)
    {
        m_score = score;
    }
