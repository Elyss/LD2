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


        //GETTERS // SETTERS



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
