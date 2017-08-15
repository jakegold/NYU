/* 
Jake Goldstein 
CS_1124 10/09/15
This code will take an input of warriors, nobles and transactions
that the nobles are making about the warriors.
The nobles will then fight with eachother using warriors as bait,
HW03
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Warrior Class
class Warrior{
public:
    // Constructor
    Warrior(const string wNm, const double wStr) : name(wNm), strength(wStr){}
    // Get Strength
    double getStrength() const{
        return strength;
    }
    // Get Name of Warrior
    string getWarriorName() const{
        return name;
    }
    // Set strength
    void setStrength(double newStrength){
        strength = newStrength;
    }   
private:
    // Variables
    double strength;
    string name;
};

// Noble Class
class Noble{
public:
    // Constructor
    Noble(const string hisName) :name(hisName) {}
    // Get Noble name
    string getNobleName() const{
        return name;
    }
    // Display 
    void display() const{
        // Prints out the Noble and the size of his army of warriors
        cout << name << " has an army of " << getArmySize() << endl;
        // Loop through the warriors printing each one
        for(size_t i = 0; i < army.size(); ++i){
            cout << "   ";
            cout << army[i]->getWarriorName() << ": " << army[i]->getStrength();
            cout << endl;
        }
    }
    // Get the total strength of a nobles army
    double getArmyStrength() const{
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
    int getArmySize() const{
       return army.size();
    }
    // Add a warrior to the army
    void hire(Warrior & armyMember){
        army.push_back(&armyMember);
    }
    // Remove a warrior from the army
    void fire(Warrior & armyMember){
        cout << armyMember.getWarriorName() << ", you're fired! -- ";
        cout << getNobleName() << endl;
        // Loop through vector of army
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember.getWarriorName()){
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
                cout << "This Warrior was not part of the army" << endl;
            }
        }   
    }
    // Have two nobles battle
    void battle(Noble & challenger){
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
    bool checkForDeath(Noble & challenger) const {
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
    void winner(Noble & loser){
        // Declare a winner
        cout << name << " deafeats ";
        cout << loser.name << endl;
        // Run functions
        hurt(loser);
        loser.destroy();
    }
    // Makes all warriors strengths zero
    void destroy(){
        for(size_t i = 0; i < army.size(); ++i){
            army[i]->setStrength(0);
        }
        // Makes the noble dead so he can no longer fight
        dead = true;
    }
    // The winner is also hurt (loser is passed)
    void hurt(Noble & loser){
        // Establish how hurt the winner is by the following ratio
        double ratio = loser.getArmyStrength()/getArmyStrength();
        // Loop through vector of winner's warriors
        for(size_t i = 0; i < army.size(); ++i){
            // Lower all of the warrior's health
            army[i]->setStrength(army[i]->getStrength() * ratio);
            // Ensure no one has a health lower than zero
            if (army[i]->getStrength() < 0){
                army[i]->setStrength(0);
            }
        }
    }
private:
    // Noble varabiables
    string name;
    bool dead;
    vector<Warrior*> army;
};

int main() {
    // Declare Nobles
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    // Declare Warriors
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    // Hire staff
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    // Display 
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();

    // Fire and display
    art.fire(cheetah);
    art.display();

    // ATTACK
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    return 0;
}
