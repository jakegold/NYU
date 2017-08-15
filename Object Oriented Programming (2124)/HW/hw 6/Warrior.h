#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>
#include "Noble.h"

namespace WarriorCraft{

    class Noble;

    class Warrior{
    public:
        // Constructor
        Warrior(const std::string wNm, const double wStr);
        // Get Strength
        double getStrength() const;
        // Get Name of Warrior
        std::string getWarriorName() const;
        // Set strength
        void setStrength(double newStrength);  
        // Run away
        void runaway();
        // Sets the Noble pointer
        void assign(Noble* myMaster);
    private:
        // Variables
        double strength;
        std::string name;
        Noble* master;
    };
}

#endif