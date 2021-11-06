//Gabriel Snider 1310-001


#include <string>
#include <iostream>


using namespace std;

class Creature
{
    private:
        string name, description;
        float cost;
        bool Dangerous;
    
    public:
        Creature()
        {
        }
        Creature(string name, string description, bool Dangerous, float cost)
        {
            this->name = name;
            this->description = description;
            this->Dangerous = Dangerous;
            this->cost = cost;
        }
        string getName()
        {
            return name;
        }
        string getDescription()
        {
            return description;
        }
        bool getDangerous()
        {
            return Dangerous;
        }
        float getCost()
        {
            return cost;
        }
        void setName(string)
        {
            this->name = name;
        }
        void setDescription(string)
        {
            this-> description = description;
        }
        void setDangerous(bool)
        {
            this->Dangerous = Dangerous;
        }
        void setCost(float)
        {
            this->cost = cost;
        }
        void printCreature();
        void printCreatureToFile(string f);
};