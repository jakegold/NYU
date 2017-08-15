#include "Noble.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{

	// Constructor
    Noble::Noble(const string hisName) :name(hisName) {}

    // Display 
    void Noble::display() const{
        // Prints out the Noble and the size of his army of warriors
        cout << name << " has an army of " << getArmySize() << endl;
        // Loop through the warriors printing each one
        for(size_t i = 0; i < army.size(); ++i){
            cout << "   ";
            cout << army[i]->getWarriorName();
            cout << ": " << army[i]->getStrength();
            cout << endl;
        }
    }

    // Get the total strength of a nobles army
    double Noble::getArmyStrength() const{
        double totalStrength = 0;
        // Loop through all warriors
        for(size_t i = 0; i < army.size(); ++i){
            // Add each strength to a total
            totalStrength += army[i]->getStrength();
        }
        // Return that total
        return totalStrength;
    }

    // Get the size of the army
    int Noble::getArmySize() const { return army.size(); }

    // Add a warrior to the army
    void Noble::hire(Warrior & armyMember) {
        armyMember.assign(this); 
        army.push_back(&armyMember);
    }

    // Remove a warrior from the army
    void Noble::fire(Warrior & armyMember){
        // Loop through vector of army
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember.getWarriorName()){
                cout << armyMember.getWarriorName() << ", you're fired! -- ";
                cout << name << endl;
                size_t j = i;
                // Loop through the remaining parts of the vector
                while(j < army.size()-1){
                    // Get rid of warrior and push everyone else back one spot
                    army[j] = army[j+1];
                    ++j;
                }
                // Get rid of the doubles
                army.pop_back();
                return;
            }
            // If the warrior was not part of the army originally
            else{
                cout << "This Warrior, " << armyMember.getWarriorName();
                cout << ", was not part of the army" << endl;
            }
        }   
    }

    // Have two nobles battle
    void Noble::battle(Noble & challenger){
    	cout << name << " battles " << challenger.name << endl;
        // Declare variables
        double totalStrength = getArmyStrength();
        double challengerTotalStrength = challenger.getArmyStrength();
        // Check to see if any nobles are dead
        if (!checkForDeath(challenger)){
            return;
        }
        // Check to see if first noble wins
        else if (totalStrength > challengerTotalStrength){
            winner(challenger);
        }
		// If the challenger noble wins
		else if (totalStrength < challengerTotalStrength){
            challenger.winner(*this);
        }
		// If there is a tie
        else {
            cout << "Mutual Annihalation: " << name << " and ";
            cout << challenger.name << "die at each other's hands" << endl;
            // Run functions
            destroy();
            challenger.destroy();
        }
    }

    // Checks to see if either or both nobles are dead
    bool Noble::checkForDeath(Noble & challenger) const {
        // If they are both dead
        if (challenger.dead && dead){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
            return false;
        }
        // If the challenger is dead
        else if (challenger.dead && !dead){
            cout << "He's dead " << name << endl;
            return false;
        }
        // If the first noble is dead
        else if (!challenger.dead && dead){
            cout << "He's dead " << challenger.name << endl;
            return false;
        }
        // If no one is dead
        else return true;
    }

    // The losing noble is pased to the winner
    void Noble::winner(Noble & loser){
        // Declare a winner
        cout << name << " deafeats ";
        cout << loser.name << endl;
        // Run functions
        hurt(loser);
        loser.destroy();
    }

    // Makes all warriors strengths zero
    void Noble::destroy(){
        for(size_t i = 0; i < army.size(); ++i){
            army[i]->setStrength(0);
        }
        // Makes the noble dead so he can no longer fight
        dead = true;
    }

    // The winner is also hurt (loser is passed)
    void Noble::hurt(Noble & loser){
        // Establish how hurt the winner is by the following ratio
        double ratio = loser.getArmyStrength()/getArmyStrength();
        // Loop through vector of winner's warriors
        for(size_t i = 0; i < army.size(); ++i){
            // Lower all of the warrior's health
            army[i]->setStrength(army[i]->getStrength() * (1-ratio));
            // Ensure no one has a health lower than zero
            if (army[i]->getStrength() < 0){
                army[i]->setStrength(0);
            }
        }
    }

    // Informs Noble that a warrior ran away from his army
    void Noble::run(Warrior* armyMember){
        cout << armyMember->getWarriorName();
        cout << " flees in terror, abandoning his lord, ";
        cout << name << endl;
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember->getWarriorName()){
                size_t j = i;
                // Loop through the remaining parts of the vector
                while(j < army.size()-1){
                    // Get rid of warrior and push everyone else back one spot
                    army[j] = army[j+1];
                    ++j;
                }
                // Get rid of the doubles
                army.pop_back();
                return;
            }
        }
    }

    // Overwrite the << operator   
    ostream & operator <<(ostream & os, const Noble & myNoble){
        // Print out message
        os << myNoble.name << " has an army of ";
        cout << myNoble.army.size() << endl;
        // Loop through the warriors printing each one
        for(size_t i = 0; i < myNoble.army.size(); ++i){
            os << "   ";
            os << myNoble.army[i]->getWarriorName() << ": ";
            cout << myNoble.army[i]->getStrength() << endl;
            
        }
        return os;

    }
}