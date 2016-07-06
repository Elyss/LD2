#ifndef Attribute_H
#define Attribute_H


class Attribute
{
    public:

        //CONSTRUCTEURS

        Attribute();

        Attribute(std::string m_name, int m_victory, int m_defeat, float m_ratio, std::string m_affinities, std::string m_disaffinities);



        virtual ~Attribute();

        //METHODES

        void stats() const;
        void display() const;


        //GETTERS

        std::string getName() const;
        int getVictory() const;
        int getDefeat() const;
        float getRatio() const;
        std::string getAffinities() const;
        std::string getDisaffinities() const;

        // SETTERS

        void setVictory(int nb);
        void victory();
        void defeat();



        //ATTRIBUTS

    protected:
        std::string m_name;
        int m_victory;
        int m_defeat;
        float m_ratio;
        std::string m_affinities;
        std::string m_disaffinities;
};

#endif // Attribute_H
