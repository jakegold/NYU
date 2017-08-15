#ifndef NOBLE_H
#define NOBLE_H

#include <string>
#include <vector>
#include "Warrior.h"

namespace WarriorCraft{

    class String{
        
    };

    class Warrior;

    // Noble Class
    class Noble{
    public:
        // Constructor
        Noble(const std::string hisName);
        // Get Noble name
        std::string getNobleName() const;
        // Display 
        void display() const;
        // Get the total strength of a nobles army
        double getArmyStrength() const;
        // Get the size of the army
        int getArmySize() const;
        // Add a warrior to the army
        void hire(Warrior & armyMember);
        // Remove a warrior from the army
        void fire(Warrior & armyMember);
        // Have two nobles battle
        void battle(Noble & challenger);
        // Checks to see if either or both nobles are dead
        bool checkForDeath(Noble & challenger) const;
        // The losing noble is pased to the winner
        void winner(Noble & loser);
        // Makes all warriors strengths zero
        void destroy();
        // The winner is also hurt (loser is passed)
        void hurt(Noble & loser);
        // Informs Noble that a warrior ran away from his army
        void run(Warrior* armyMember);
        // Overwrite the << operator as a friend
        friend std::ostream & operator <<(std::ostream & os, const Noble & myNoble);

    private:
        // Noble varabiables
        std::string name;
        bool dead;
        std::vector<Warrior*> army;
    };    

// Overwrite the << operator
std::ostream & operator <<(std::ostream & os, const Noble & myNoble);

}
#endif
