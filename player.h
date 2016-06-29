#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



class Player
{
    public:

    //Constructeurs et destructeurs

    Player();
    Player(std::string name);
    Player(std::string name, float score);
    Player(int id, std::string name, float score, int victory, int defeat);
    Player(int id, std::string name, float score, int victory, int defeat, std::vector<std::string> attributs);

    ~Player();

    //Methodes

    void victory(Player &adversary);
    void stats() const;

    int getId() const;
    std::string getName() const;
    float getScore() const;
    int getVictory() const;
    int getDefeat() const;
    std::string getAttributs() const;

    bool estEgal(Player const &adversary) const;

    std::string setName(std::string name);
    float setScore(float score);

    //Attributs

    protected:

    int m_id;
    int m_victory;
    int m_defeat;
    float m_score;
    std::string m_name;
    std::vector<std::string> m_attributs;



};


#endif // PLAYER_H_INCLUDED
